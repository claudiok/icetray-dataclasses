/**
 *  $Id$
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#ifndef DATACLASSES_I3MAPOMKEYMASK_H_INCLUDED
#define DATACLASSES_I3MAPOMKEYMASK_H_INCLUDED

#include <functional>
#include <string>
#include <list>
#include <boost/foreach.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits/is_same.hpp>

#include "icetray/I3FrameObject.h"
#include "icetray/OMKey.h"
#include "icetray/I3Frame.h"
#include "icetray/serialization.h"
#include "dataclasses/physics/I3RecoPulse.h"


static const unsigned i3recopulseseriesmapmask_version_ = 0;

class I3RecoPulseSeriesMapMask : public I3FrameObject {
public:
	/* 
	 * Construct a mask for the map stored at "key." All bits are set.
	 */
	I3RecoPulseSeriesMapMask(const I3Frame&, const std::string &key);
	/*
	 * Construct a mask for the map stored at "key," corresponding to
	 * the map `subset.' The subset must be an ordered subset of the map
	 * stored at `key'.
	 */
	I3RecoPulseSeriesMapMask(const I3Frame&, const std::string &key,
	    const I3RecoPulseSeriesMap &subset);
	
	/*
	 * Construct a mask by predicate that defines
	 * bool operator()(const OMKey&, size_t, const I3RecoPulse&)
	 */
	template <typename Predicate>
	I3RecoPulseSeriesMapMask(const I3Frame&, const std::string &key,
	    Predicate &predicate,
	    typename boost::disable_if<boost::is_same<Predicate, I3RecoPulseSeriesMap> >::type* = 0);
	
	/*
	 * Set/unset all elements for an OMKey.
	 */
	void Set(const OMKey&, bool);
	/*
	 * Set/unset an element for OMKey by index.
	 */
	void Set(const OMKey&, const unsigned idx, bool);
	/*
	 * Set/unset an element for OMKey by value.
	 */
	void Set(const OMKey&, const I3RecoPulse&, bool);
	/*
	 * Clear all elements of the mask.
	 */
	void SetNone();
	
	/*
	 * Apply the mask to the target map in the frame.
	 */
	boost::shared_ptr<const I3RecoPulseSeriesMap> Apply(const I3Frame &frame) const;
	
	std::string GetSource() const { return key_; }
	
	/*
	 * Get the number of set bits in the mask.
	 */
	unsigned GetSum() const;
	
	/*
	 * Are any bits set?
	 */
	bool GetAnySet() const;
	
	/*
	 * Are all bits set?
	 */
	bool GetAllSet() const;
	
	/*
	 * Logical operators, applied elementwise.
	 */
	I3RecoPulseSeriesMapMask operator&(const I3RecoPulseSeriesMapMask&) const;
	I3RecoPulseSeriesMapMask operator|(const I3RecoPulseSeriesMapMask&) const;
	I3RecoPulseSeriesMapMask operator^(const I3RecoPulseSeriesMapMask&) const;
	
	/* Default ctor. */
	I3RecoPulseSeriesMapMask() {};
		
private:
	typedef uint8_t mask_t;
	
	struct bitmask {
		uint16_t size_;
		uint8_t padding_;
		mask_t *mask_;
		
		bitmask() : size_(0), padding_(0), mask_(NULL) {};
		bitmask(unsigned length, bool set=true);
		bitmask(const bitmask& other);
		bitmask& operator=(const bitmask& other);
		~bitmask();
		void set_all();
		void unset_all();
		inline bool any() const;
		inline bool all() const;
		inline void set(const unsigned, bool);
		
		inline bool get(const unsigned) const;
		unsigned sum() const;
		size_t size() const;
		
		friend class boost::serialization::access;
		
		template <class Archive> void load(Archive & ar, unsigned version);
		template <class Archive> void save(Archive & ar, unsigned version) const;
		
		BOOST_SERIALIZATION_SPLIT_MEMBER();
	};
		
	std::string key_;
	bitmask omkey_mask_;
	std::list<bitmask> element_masks_;
	I3RecoPulseSeriesMapConstPtr source_;
	mutable I3RecoPulseSeriesMapPtr masked_;
	
	inline void ResetCache() { masked_.reset(); }

	int FindKey(const OMKey &key, std::list<bitmask>::iterator &list_it,
	    const I3RecoPulseSeriesMap::mapped_type **vec);
	
	static bool IsOrderedSubset(const I3RecoPulseSeriesMap&, const I3RecoPulseSeriesMap&);
	static void FillSubsetMask(bitmask&, const I3RecoPulseSeriesMap::mapped_type&,
	    const I3RecoPulseSeriesMap::mapped_type&);
	
	template <typename BinaryOperator>
	I3RecoPulseSeriesMapMask ApplyBinaryOperator(const I3RecoPulseSeriesMapMask&) const;
	
	struct operator_and : public std::binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs & rhs; }
	};
	
	struct operator_or : public std::binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs | rhs; }
	};
	
	struct operator_xor : public std::binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs ^ rhs; }
	};
	
	friend class boost::serialization::access;
	template <class Archive> void load(Archive & ar, unsigned version);
	template <class Archive> void save(Archive & ar, unsigned version) const;
	
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	
	SET_LOGGER("I3RecoPulseSeriesMapMask");
};

template<> void I3RecoPulseSeriesMapMask::bitmask::load(boost::archive::xml_iarchive& ar, unsigned version);
template<> void I3RecoPulseSeriesMapMask::bitmask::save(boost::archive::xml_oarchive& ar, unsigned version) const;

BOOST_CLASS_VERSION(I3RecoPulseSeriesMapMask, i3recopulseseriesmapmask_version_);
I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMapMask);

inline void
I3RecoPulseSeriesMapMask::bitmask::set(const unsigned idx, bool set_it)
{
	assert(idx < (8*sizeof(mask_t)*size_ - padding_));
	if (set_it)
		mask_[idx/(8*sizeof(mask_t))] |= (1 << (idx % (8*sizeof(mask_t))));
	else
		mask_[idx/(8*sizeof(mask_t))] &= ~(1 << (idx % (8*sizeof(mask_t))));
}

template <typename Predicate>
I3RecoPulseSeriesMapMask::I3RecoPulseSeriesMapMask(const I3Frame &frame,
    const std::string &key, Predicate &predicate,
    typename boost::disable_if<boost::is_same<Predicate, I3RecoPulseSeriesMap> >::type*)
    : key_(key)
{
	source_ = frame.Get<boost::shared_ptr<const I3RecoPulseSeriesMap> >(key_);
	
	if (!source_)
		log_fatal("The map named '%s' doesn't exist in the frame!\n", key_.c_str());
	
	omkey_mask_ = bitmask(source_->size(), false);
	assert(omkey_mask_.size() == source_->size());
	
	size_t om_idx(0);
	BOOST_FOREACH(const I3RecoPulseSeriesMap::value_type &pair, *source_) {
		bitmask mask = bitmask(pair.second.size(), true);
		
		size_t pulse_idx(0);
		BOOST_FOREACH(const I3RecoPulseSeriesMap::mapped_type::value_type &pulse, pair.second) {
			mask.set(pulse_idx, predicate(pair.first, pulse_idx, pulse));
			pulse_idx++;
		}
		
		if (mask.sum() > 0) {
			omkey_mask_.set(om_idx, true);
			element_masks_.push_back(mask);
		}
		om_idx++;
	}
}

#endif /* DATACLASSES_I3MAPOMKEYMASK_H_INCLUDED */

