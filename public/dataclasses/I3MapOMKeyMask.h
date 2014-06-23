/**
 *  $Id$
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  Marcel Zoll <marcel.zoll@fysik.su.se>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#ifndef DATACLASSES_I3MAPOMKEYMASK_H_INCLUDED
#define DATACLASSES_I3MAPOMKEYMASK_H_INCLUDED

#include <functional>
#include <string>
#include <list>
#include <boost/foreach.hpp>
#include <boost/function.hpp>
#include <boost/dynamic_bitset.hpp> 

#include "icetray/I3FrameObject.h"
#include "icetray/OMKey.h"
#include "icetray/I3Frame.h"
#include "icetray/serialization.h"

#include "dataclasses/I3Map.h"

template <class Response>
class I3MapOMKeyMask : public I3FrameObject {
private:
  typedef std::vector<Response> ResponseSeries;
  typedef I3Map<OMKey, ResponseSeries> ResponseSeriesMap;
  typedef boost::shared_ptr<ResponseSeriesMap> ResponseSeriesMapPtr;
  typedef boost::shared_ptr<const ResponseSeriesMap> ResponseSeriesMapConstPtr;
  
public:
	/* 
	 * Construct a mask for the map stored at "key." All bits are set.
	 */
	I3MapOMKeyMask(const I3Frame&, const std::string &key);
	/*
	 * Construct a mask for the map stored at "key," corresponding to
	 * the map `subset.' The subset must be an ordered subset of the map
	 * stored at `key'.
	 */
	I3MapOMKeyMask(const I3Frame&, const std::string &key,
	    const ResponseSeriesMap &subset);
	/*
	 * Construct a mask by predicate. This may be either a free function
	 * or an instance of a class that implements
	 * bool operator()(const OMKey&, size_t, const Response&).
	 */
 	I3MapOMKeyMask(const I3Frame&, const std::string &key,
 	    boost::function<bool (const OMKey&, size_t, const Response&)> predicate);
	
	I3MapOMKeyMask();
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
	void Set(const OMKey&, const Response&, bool);
	/*
	 * Clear all elements of the mask.
	 */
	void SetNone();
	
	/*
	 * Apply the mask to the target map in the frame.
	 */
	boost::shared_ptr<const ResponseSeriesMap> Apply(const I3Frame &frame) const;
	
	/**
	 * Return true if this mask is derived from key
	 */
	bool HasAncestor(const I3Frame &frame, const std::string &key) const;
	
	/**
	 * Convert this mask into a form that can be applied directly to key
	 * without resort to intermediate masks.
	 */
	boost::shared_ptr<I3MapOMKeyMask> Repoint(const I3Frame &frame, const std::string &key) const;
	
	/*
	 * Get the name of the frame object the mask was made from.
	 */
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
	 
	 
	std::vector<boost::dynamic_bitset<uint8_t> > GetBits() const;
	
	/*
	 * Logical operators, applied elementwise.
	 */
	I3MapOMKeyMask operator&(const I3MapOMKeyMask&) const;
	I3MapOMKeyMask operator|(const I3MapOMKeyMask&) const;
	I3MapOMKeyMask operator^(const I3MapOMKeyMask&) const;
	/** Equivalent to this & ~other */
	I3MapOMKeyMask Remove(const I3MapOMKeyMask&) const;
	
	I3MapOMKeyMask& operator&=(const I3MapOMKeyMask&);
	I3MapOMKeyMask& operator|=(const I3MapOMKeyMask&);
	I3MapOMKeyMask& operator^=(const I3MapOMKeyMask&);
		
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
	ResponseSeriesMapConstPtr source_;
	mutable ResponseSeriesMapPtr masked_;
	
	inline void ResetCache() { masked_.reset(); }

	int FindKey(const OMKey &key, typename std::list<bitmask>::iterator &list_it,
	    const typename ResponseSeriesMap::mapped_type **vec);
	
	static bool IsOrderedSubset(const ResponseSeriesMap&, const ResponseSeriesMap&);
	static void FillSubsetMask(bitmask&, const typename ResponseSeriesMap::mapped_type&,
	    const typename ResponseSeriesMap::mapped_type&);
	
	/**
	 * Collapse this mask with its source, making it depend only on its grandparent.
	 */
	boost::shared_ptr<I3MapOMKeyMask> CollapseLevel(const I3Frame &frame) const;
	
	template <typename BinaryOperator>
	I3MapOMKeyMask ApplyBinaryOperator(const I3MapOMKeyMask&) const;
	
	struct operator_and : public std::binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs & rhs; }
	};
	
	struct operator_andnot : public std::binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs & ~rhs; }
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
	
	SET_LOGGER("I3MapOMKeyMask");
};

//specialize serialization access
template<> template<> void I3MapOMKeyMask<class Response>::bitmask::load(boost::archive::xml_iarchive& ar, unsigned version);
template<> template<> void I3MapOMKeyMask<class Response>::bitmask::save(boost::archive::xml_oarchive& ar, unsigned version) const;


//Make bindings to responses

#include "dataclasses/physics/I3RecoPulse.h"
static const unsigned i3recopulseseriesmapmask_version_ = 2;
typedef I3MapOMKeyMask<I3RecoPulse> I3RecoPulseSeriesMapMask;

#include "dataclasses/physics/I3MCHit.h"
static const unsigned i3mchitseriesmapmask_version_ = 1;
typedef I3MapOMKeyMask<I3MCHit> I3MCHitSeriesMapMask;


/// ======================== IMPLEMENTATIONS =====================

#include "boost/make_shared.hpp"
#include <boost/serialization/binary_object.hpp>

template <class Response>
I3MapOMKeyMask<Response>::I3MapOMKeyMask() {}

template <class Response>
I3MapOMKeyMask<Response>::I3MapOMKeyMask(const I3Frame &frame,
                                         const std::string &key)
    : key_(key)
{
  source_ = frame.Get<ResponseSeriesMapConstPtr>(key_);

  if (!source_)
    log_fatal("The map named '%s' doesn't exist in the frame!\n", key_.c_str());

  typename ResponseSeriesMap::const_iterator it = source_->begin();
  if (source_->size() == 0)
    return;

  omkey_mask_ = bitmask(source_->size());
  for ( ; it != source_->end(); it++) {
    if (it->second.size() > 0)
      element_masks_.push_back(bitmask(it->second.size()));
    else
      omkey_mask_.set(std::distance(source_->begin(), it), false);
  }
}

template <class Response>
I3MapOMKeyMask<Response>::I3MapOMKeyMask(const I3Frame &frame,
    const std::string &key, const ResponseSeriesMap &subset)
    : key_(key)
{
  source_ = frame.Get<ResponseSeriesMapConstPtr>(key_);
  
  if (!source_)
    log_fatal("The map named '%s' doesn't exist in the frame!", key_.c_str());
  
  if (!IsOrderedSubset(*source_, subset))
    log_fatal("The passed map is not an ordered subset of map '%s'!", key_.c_str());
  
  omkey_mask_ = bitmask(source_->size());
  assert(omkey_mask_.size() == source_->size());
  
  typename ResponseSeriesMap::const_iterator sup_mit = source_->begin();
  typename ResponseSeriesMap::const_iterator sub_mit = subset.begin();
  unsigned idx = 0;
  for ( ; sup_mit != source_->end(); sup_mit++, idx++) {
    /* 
     * NB: since the subset is ordered, we can wait until the
     * superset catches up to increment its iterator.
     */
    if ((sub_mit != subset.end()) && (sub_mit->first == sup_mit->first)) {
      bitmask mask = bitmask(sup_mit->second.size(), sub_mit->second.size() != 0);
      
      FillSubsetMask(mask, sup_mit->second, sub_mit->second);
      element_masks_.push_back(mask);
      
      sub_mit++;
    } else {
      omkey_mask_.set(idx, false); /* Note absence. */
    }
  }
}

template <class Response>
I3MapOMKeyMask<Response>::I3MapOMKeyMask(const I3Frame &frame,
    const std::string &key, boost::function<bool (const OMKey&, size_t, const Response&)> predicate)
    : key_(key)
{
  source_ = frame.Get<ResponseSeriesMapConstPtr>(key_);
  
  if (!source_)
    log_fatal("The map named '%s' doesn't exist in the frame!\n", key_.c_str());
  
  omkey_mask_ = bitmask(source_->size(), false);
  assert(omkey_mask_.size() == source_->size());
  
  size_t om_idx(0);
  BOOST_FOREACH(const typename ResponseSeriesMap::value_type &pair, *source_) {
    bitmask mask = bitmask(pair.second.size(), true);
    
    size_t pulse_idx(0);
    BOOST_FOREACH(const typename ResponseSeriesMap::mapped_type::value_type &pulse, pair.second) {
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

template <class Response>
void
I3MapOMKeyMask<Response>::FillSubsetMask(bitmask &mask,
    const typename ResponseSeriesMap::mapped_type &superset,
    const typename ResponseSeriesMap::mapped_type &subset)
{
  unsigned idx = 0;
  unsigned midx = 0;
  typename ResponseSeriesMap::mapped_type::const_iterator sup_vit = superset.begin();
  typename ResponseSeriesMap::mapped_type::const_iterator sub_vit = subset.begin();
  
  for ( ; sup_vit != superset.end(); sup_vit++, idx++) {
    if (idx > 0 && (idx % (8*sizeof(mask_t)) == 0))
      midx++;
    
    assert(midx < mask.size_);
    if ((sub_vit != subset.end()) && ((*sub_vit) == (*sup_vit))) {
      sub_vit++; /* We have a match, do nothing. */
    } else {
      /* Unset the corresponding bit. */
      mask.mask_[midx] &= ~(1 << (idx % (8*sizeof(mask_t))));
    }
  }
}

template <class Response>
void
I3MapOMKeyMask<Response>::SetNone()
{
  omkey_mask_.unset_all();
  element_masks_.clear();
  
  ResetCache();
}

template <class Response>
unsigned
I3MapOMKeyMask<Response>::GetSum() const
{
  unsigned sum = 0;
  typename std::list<bitmask>::const_iterator list_it = element_masks_.begin();
  
  for ( ; list_it != element_masks_.end(); list_it++)
    sum += list_it->sum();
  
  return sum;
}

template <class Response>
bool
I3MapOMKeyMask<Response>::GetAnySet() const
{
  return (omkey_mask_.any());
}

template <class Response>
bool
I3MapOMKeyMask<Response>::GetAllSet() const
{
  if (omkey_mask_.all()) {
    bool all = true;
    typename std::list<bitmask>::const_iterator list_it = element_masks_.begin();
    for ( ; list_it != element_masks_.end(); list_it++)
      all = (all && list_it->all());
    
    return all;
  } else {
    return false;
  }
}

template <class Response>
std::vector<boost::dynamic_bitset<uint8_t> >
I3MapOMKeyMask<Response>::GetBits() const
{
  typedef boost::dynamic_bitset<uint8_t> bitset;
  std::vector<bitset> bits;
  
  typename std::list<bitmask>::const_iterator list_it = element_masks_.begin(); 
  for (unsigned i = 0; i < omkey_mask_.size(); i++)
    if (omkey_mask_.get(i)) {
      const bitmask &privmask = *(list_it++);
      bitset pubmask(privmask.size());
      for (unsigned j = 0; j < privmask.size(); j++)
        pubmask.set(j, privmask.get(j));
      bits.push_back(pubmask);
    } else {
      bits.push_back(bitset(0));
    }
  
  return bits;
}


template <class Response>
int
I3MapOMKeyMask<Response>::FindKey(const OMKey &key,
    typename std::list<bitmask>::iterator &list_it, const typename ResponseSeriesMap::mapped_type **vec)
{
  if (!source_) {
    log_error("This mask cannot be modified.");
    return -1;
  }
  
  typename ResponseSeriesMap::const_iterator source_it = source_->find(key);
  
  if (source_it == source_->end())
    log_fatal("Key doesn't exist in the source map!");
    
  *vec = &(source_it->second);
  
  /* Find the bitmask corresponding to this OM. */
  list_it = element_masks_.begin();
  unsigned omkey_idx = std::distance(source_->begin(), source_it);
  for (unsigned i = 0; i < omkey_idx; i++)
    if (omkey_mask_.get(i))
      list_it++;
  
  return omkey_idx;
}


template <class Response>
void
I3MapOMKeyMask<Response>::Set(const OMKey &key,
    const Response &target, bool set_it)
{
  int omkey_idx;
  typename std::list<bitmask>::iterator list_it;
  const typename ResponseSeriesMap::mapped_type *vec;
  
  ResetCache();
  
  if ((omkey_idx = FindKey(key, list_it, &vec)) < 0)
    return;
  
  /* Insert a new bitmask if necessary. */
  if (!omkey_mask_.get(omkey_idx)) {
    if (set_it) {
      list_it = element_masks_.insert(list_it,
           bitmask(vec->size(), false));
      omkey_mask_.set(omkey_idx, true);
    } else {
      return;
    }
  }
    
  typename ResponseSeriesMap::mapped_type::const_iterator vec_it = vec->begin();
  unsigned idx = 0;
  for ( ; vec_it != vec->end(); vec_it++, idx++)
    if (*vec_it == target) {
      list_it->set(idx, set_it);
      break;
    } 
}


template <class Response>
void
I3MapOMKeyMask<Response>::Set(const OMKey &key, const unsigned idx, bool set_it)
{
  int omkey_idx;
  typename std::list<bitmask>::iterator list_it;
  const typename ResponseSeriesMap::mapped_type *vec;
  
  ResetCache();
  
  if ((omkey_idx = FindKey(key, list_it, &vec)) < 0)
    return;
  
  /* Insert a new bitmask if necessary. */
  if (!omkey_mask_.get(omkey_idx)) {
    if (set_it) {
      list_it = element_masks_.insert(list_it,
           bitmask(vec->size(), false));
      omkey_mask_.set(omkey_idx, true);
    } else {
      return;
    }
  }
      
  list_it->set(idx, set_it);
}


template <class Response>
void
I3MapOMKeyMask<Response>::Set(const OMKey &key, bool set_it)
{
  int omkey_idx;
  typename std::list<bitmask>::iterator list_it;
  const typename ResponseSeriesMap::mapped_type *vec;
  
  ResetCache();
  
  if ((omkey_idx = FindKey(key, list_it, &vec)) < 0)
    return;
  
  /* Insert a new bitmask if necessary. */
  if (!omkey_mask_.get(omkey_idx)) {
    if (set_it && vec->size() > 0) {
      list_it = element_masks_.insert(list_it,
           bitmask(vec->size(), true));
      omkey_mask_.set(omkey_idx, true);
    }
    return;
  }
  
  if (set_it && vec->size() > 0) {
    list_it->set_all();
  } else {
    omkey_mask_.set(omkey_idx, false);

    if (!set_it)
      element_masks_.erase(list_it);
  }
}


template <class Response>
bool
I3MapOMKeyMask<Response>::IsOrderedSubset(const ResponseSeriesMap &super,
    const ResponseSeriesMap &sub)
{
  typename ResponseSeriesMap::const_iterator sup_mit = super.begin();
  typename ResponseSeriesMap::const_iterator sub_mit = sub.begin();
  for ( ; sub_mit != sub.end(); sub_mit++) {
    while (sup_mit != super.end() && sup_mit->first != sub_mit->first)
      sup_mit++;
    if (sup_mit == super.end())
      return false;
    
    /* 
     * NB: even in the vector portion, we expect elements in the subset
     * to appear in order relative to their order in the superset.
     */
    typename ResponseSeriesMap::mapped_type::const_iterator sup_vit = sup_mit->second.begin();
    typename ResponseSeriesMap::mapped_type::const_iterator sub_vit = sub_mit->second.begin();
    for ( ; sub_vit != sub_mit->second.end(); sub_vit++) {
      while (sup_vit == sup_mit->second.end() && !(*sup_vit == *sub_vit))
        sup_vit++;
      if (sup_vit == sup_mit->second.end())
        return false;
    }
  }
  
  return true;
}

template <class Response>
I3MapOMKeyMask<Response>
I3MapOMKeyMask<Response>::operator&(const I3MapOMKeyMask<Response> &other) const
{
  return ApplyBinaryOperator<operator_and>(other);
}

template <class Response>
I3MapOMKeyMask<Response>
I3MapOMKeyMask<Response>::operator|(const I3MapOMKeyMask<Response> &other) const
{
  return ApplyBinaryOperator<operator_or>(other);
}

template <class Response>
I3MapOMKeyMask<Response>
I3MapOMKeyMask<Response>::operator^(const I3MapOMKeyMask<Response> &other) const
{
  return ApplyBinaryOperator<operator_xor>(other);
}

template <class Response>
I3MapOMKeyMask<Response>
I3MapOMKeyMask<Response>::Remove(const I3MapOMKeyMask<Response> &other) const
{
  return ApplyBinaryOperator<operator_andnot>(other);
}

template <class Response>
I3MapOMKeyMask<Response>&
I3MapOMKeyMask<Response>::operator&=(const I3MapOMKeyMask<Response> &other)
{
  (*this) = ApplyBinaryOperator<operator_and>(other);
  return *this;
}

template <class Response>
I3MapOMKeyMask<Response>&
I3MapOMKeyMask<Response>::operator|=(const I3MapOMKeyMask<Response> &other)
{
  (*this) = ApplyBinaryOperator<operator_or>(other);
  return *this;
}

template <class Response>
I3MapOMKeyMask<Response>&
I3MapOMKeyMask<Response>::operator^=(const I3MapOMKeyMask<Response> &other)
{
  (*this) = ApplyBinaryOperator<operator_xor>(other);
  return *this;
}

template <class Response> template <typename BinaryOperator>
I3MapOMKeyMask<Response>
I3MapOMKeyMask<Response>::ApplyBinaryOperator(const I3MapOMKeyMask<Response> &other) const
{
  if (key_ != other.key_)
    log_fatal("Masks cannot be combined!");
  
  I3MapOMKeyMask<Response> newmask;
  BinaryOperator op;
  
  newmask.key_ = key_;
  newmask.source_ = source_;
  newmask.omkey_mask_ = omkey_mask_;
  newmask.omkey_mask_.unset_all();
  
  const unsigned n_omkeys = omkey_mask_.size_*8*sizeof(mask_t) - omkey_mask_.padding_;
  typename std::list<bitmask>::const_iterator lit = element_masks_.begin();
  typename std::list<bitmask>::const_iterator rit = other.element_masks_.begin();
  
  for (unsigned omkey_idx = 0; omkey_idx < n_omkeys; omkey_idx++) {
    bitmask lhs, rhs;
    
    const bool l_exists = omkey_mask_.get(omkey_idx);
    const bool r_exists = other.omkey_mask_.get(omkey_idx);
    if (!(l_exists || r_exists)) {
      lhs = rhs = bitmask(8, false);
    } else if (l_exists && r_exists) {
      lhs = *lit;
      rhs = *rit;
      lit++; rit++;
    } else if (l_exists) {
      lhs = rhs = *lit;
      rhs.unset_all();
      lit++;
    } else {
      lhs = rhs = *rit;
      lhs.unset_all();
      rit++;
    }
    
    assert(lhs.size_ == rhs.size_);
    assert(lhs.padding_ == rhs.padding_);
    for (unsigned i = 0; i < lhs.size_; i++)
      lhs.mask_[i] = op(lhs.mask_[i], rhs.mask_[i]);
      
    if (lhs.sum() != 0) {
      newmask.element_masks_.push_back(lhs);
      newmask.omkey_mask_.set(omkey_idx, true);
    }   
  }
  
  return newmask;
}

template <class Response>
typename I3MapOMKeyMask<Response>::ResponseSeriesMapConstPtr
I3MapOMKeyMask<Response>::Apply(const I3Frame &frame) const
{
  if (masked_)
    return masked_;
  
  ResponseSeriesMapConstPtr source =
      frame.Get<ResponseSeriesMapConstPtr >(key_);
  
  if (!source)
    log_fatal("The map named '%s' doesn't exist in the frame!\n", key_.c_str());
  if (source->size() != omkey_mask_.size())
    log_fatal("This mask was made from a map with %zu keys, but "
        "the map named '%s' has %zu keys.", omkey_mask_.size(),
        key_.c_str(), source->size());
  
  masked_ = boost::make_shared<ResponseSeriesMap>();
  
  typename ResponseSeriesMap::const_iterator source_it = source->begin();
  typename ResponseSeriesMap::iterator inserter = masked_->begin();
  typename std::list<bitmask>::const_iterator list_it = element_masks_.begin();
  unsigned omkey_idx = 0;
  
  for ( ; source_it != source->end(); source_it++, omkey_idx++) {
    
    if (!omkey_mask_.get(omkey_idx))
      continue;
    else if (list_it->sum() == 0) {
      list_it++;
      continue;
    }
    
    unsigned idx = 0;
    typename ResponseSeriesMap::mapped_type target_vec;
    typename ResponseSeriesMap::mapped_type::const_iterator source_vit =
        source_it->second.begin();

    if (source_it->second.size() != list_it->size())
      log_fatal("The mask for OM(%d,%d) has %zu entries, but source "
          "pulse vector has %zu entries!", source_it->first.GetString(),
          source_it->first.GetOM(), list_it->size(),
          source_it->second.size());

    for ( ; source_vit != source_it->second.end(); source_vit++, idx++)
      if (list_it->get(idx))
        target_vec.push_back(*source_vit);
        
    inserter = masked_->insert(inserter,
        std::make_pair(source_it->first, target_vec));
      
    list_it++;
  }
  
  return masked_;
}

struct null_deleter
{
  void operator()(void const *) const {}
};

template <class Response>
bool 
I3MapOMKeyMask<Response>::HasAncestor(const I3Frame &frame, const std::string &key) const
{
  if (key == GetSource())
    return true;
  boost::shared_ptr<const I3MapOMKeyMask<Response> > source(this, null_deleter());
  while (source = frame.Get<boost::shared_ptr<const I3MapOMKeyMask<Response> > >(source->GetSource())) {
    if (source->GetSource() == key)
      return true;
  }
  return false;
}

template <class Response>
boost::shared_ptr<I3MapOMKeyMask<Response> >
I3MapOMKeyMask<Response>::Repoint(const I3Frame &frame, const std::string &key) const
{
  if (!HasAncestor(frame, key))
    log_fatal_stream(key << " is not an ancestor of this mask");
  if (key == GetSource())
    return  boost::make_shared<I3MapOMKeyMask<Response> >(*this);
  
  boost::shared_ptr<const I3MapOMKeyMask<Response> > source(this, null_deleter());
  while (source->GetSource() != key)
    source = source->CollapseLevel(frame);
  return boost::const_pointer_cast<I3MapOMKeyMask<Response> >(source);
}

template <class Response>
boost::shared_ptr<I3MapOMKeyMask<Response> >
I3MapOMKeyMask<Response>::CollapseLevel(const I3Frame &frame) const
{
  boost::shared_ptr<const I3MapOMKeyMask<Response> > source =
      frame.Get< boost::shared_ptr<const I3MapOMKeyMask<Response> > >(key_);
  if (!source)
    log_fatal_stream(key_ << " is not a mask in the frame");
  
  boost::shared_ptr<I3MapOMKeyMask<Response> > collapsed
      = boost::make_shared<I3MapOMKeyMask<Response> >(*source);
  collapsed->ResetCache();
  
  typename std::list<bitmask>::const_iterator source_element = source->element_masks_.begin();
  typename std::list<bitmask>::const_iterator element = element_masks_.begin();
  typename std::list<bitmask>::iterator dest_element = collapsed->element_masks_.begin();
  
  // Perform an unaligned logical AND between the parent and daughter masks
  unsigned idx = 0;
  for (unsigned source_idx = 0; source_idx < source->omkey_mask_.size();
      source_idx++) {
    if (source->omkey_mask_.get(source_idx)) {
      if (source_element->any()) {
        if (omkey_mask_.get(idx)) {
          unsigned pidx = 0;
          for (unsigned source_pidx = 0; source_pidx < source_element->size(); source_pidx++) {
            if (source_element->get(source_pidx)) {
              if (!element->get(pidx))
                dest_element->set(source_pidx, false);
              pidx++;
            }
          }
          element++;
          dest_element++;
        } else {
          collapsed->omkey_mask_.set(source_idx, false);
          dest_element = collapsed->element_masks_.erase(dest_element);
        }
        
        idx++;
      // If no bits are set in the parent mask, the daughter 
      // mask may not event exist. Compactify the output.
      } else {
        collapsed->omkey_mask_.set(source_idx, false);
        dest_element = collapsed->element_masks_.erase(dest_element);
      }
      
      source_element++;
    }
  }
  
  return collapsed;
}


template <class Response>
I3MapOMKeyMask<Response>::bitmask::bitmask(unsigned length, bool set)
{
  size_ = (length != 0) ? (length-1u)/(8*sizeof(mask_t)) + 1 : 1;
  padding_ = size_*8*sizeof(mask_t) - length;
  mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
  
  if (set)
    set_all();
  else
    unset_all();
};

template <class Response>
I3MapOMKeyMask<Response>::bitmask::bitmask(const bitmask& other) :
  size_(other.size_),
  padding_(other.padding_),
  mask_(NULL)
{
  if (size_ != 0) {
    mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
    memcpy(mask_, other.mask_, size_*sizeof(mask_t));
  }
}

template <class Response>
typename I3MapOMKeyMask<Response>::bitmask&
I3MapOMKeyMask<Response>::bitmask::operator=(const bitmask& other)
{
  size_ = other.size_;
  padding_ = other.padding_;
  if (mask_)
    mask_ = (mask_t*)realloc(mask_, size_*sizeof(mask_t));
  else
    mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
  memcpy(mask_, other.mask_, size_*sizeof(mask_t));
  
  return *this;
}

template <class Response>
I3MapOMKeyMask<Response>::bitmask::~bitmask()
{
  if (mask_)
    free(mask_);
};

template <class Response>
inline bool
I3MapOMKeyMask<Response>::bitmask::any() const
{
  mask_t test = 0;
  for (unsigned i = 0; i < size_; i++)
    test |= mask_[i];
  
  return (test != 0);
}

template <class Response>
inline bool
I3MapOMKeyMask<Response>::bitmask::all() const
{
  bool test = true;
  const mask_t all = std::numeric_limits<mask_t>::max();
  
  const unsigned max_i = (size_ == 0) ? 0 : size_-1;
  for (unsigned i = 0; i < max_i; i++)
    test = test && (mask_[i] == all);
  
  return (test && ((mask_[size_-1] == (all >> padding_))));
}

template <class Response>
void
I3MapOMKeyMask<Response>::bitmask::set_all()
{
  /* All bits set. */
  const mask_t all = std::numeric_limits<mask_t>::max();
  
  assert(size_ > 0);
  memset(mask_, all, (size_-1)*sizeof(mask_t));
  mask_[size_-1] = (all >> padding_); /* Unset unused top bits. */
}

template <class Response>
void
I3MapOMKeyMask<Response>::bitmask::unset_all()
{
  memset(mask_, 0, size_*sizeof(mask_t));
}

template <class Response>
inline void
I3MapOMKeyMask<Response>::bitmask::set(const unsigned idx, bool set_it)
{
  assert(idx < (8*sizeof(mask_t)*size_ - padding_));
  if (set_it)
    mask_[idx/(8*sizeof(mask_t))] |= (1 << (idx % (8*sizeof(mask_t))));
  else
    mask_[idx/(8*sizeof(mask_t))] &= ~(1 << (idx % (8*sizeof(mask_t))));
}

template <class Response>
inline bool
I3MapOMKeyMask<Response>::bitmask::get(const unsigned idx) const
{
  assert(idx < (8*sizeof(mask_t)*size_ - padding_));
  
  return mask_[idx/(8*sizeof(mask_t))] & (1 << (idx % (8*sizeof(mask_t))));
}

template <class Response>
unsigned
I3MapOMKeyMask<Response>::bitmask::sum() const
{
  unsigned sum = 0;
  
  for (unsigned i = 0; i < size_; i++)
    for (unsigned j = 0; j < 8*sizeof(mask_t); j++)
      if (mask_[i] & (1 << j))
        sum++;
  
  return sum;
}

template <class Response>
size_t
I3MapOMKeyMask<Response>::bitmask::size() const
{
  return 8*sizeof(mask_t)*size_ - padding_;
}

template <class Response> template <class Archive>
void
I3MapOMKeyMask<Response>::bitmask::load(Archive & ar, unsigned version)
{
  ar & make_nvp("Size", size_);
  ar & make_nvp("Padding", padding_);
  
  mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
  ar & make_nvp("Bitmask", boost::serialization::make_binary_object(
      mask_, size_*sizeof(mask_t)));
}

template <class Response> template <class Archive>
void
I3MapOMKeyMask<Response>::bitmask::save(Archive & ar, unsigned version) const
{
  ar & make_nvp("Size", size_);
  ar & make_nvp("Padding", padding_);
  ar & make_nvp("Bitmask", boost::serialization::make_binary_object(
      mask_, size_*sizeof(mask_t)));
}


template <class Response> template <class Archive>
void
I3MapOMKeyMask<Response>::load(Archive & ar, unsigned version)
{
  std::vector<bitmask> elements;
  float time_reference;
  
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("Key", key_);
  if (version == 1)
    ar & make_nvp("TimeReference", time_reference);
  ar & make_nvp("OMKeyMask", omkey_mask_);
  ar & make_nvp("ElementMasks", elements);
  
  std::copy(elements.begin(), elements.end(), std::back_inserter(element_masks_));
  /* Fix up a padding bug in bitmask::bitmask() */
  if (version == 0 && element_masks_.size() == 0 && omkey_mask_.size() == 64u && omkey_mask_.all())
    omkey_mask_ = bitmask(0, false);
}

template <class Response> template <class Archive>
void
I3MapOMKeyMask<Response>::save(Archive & ar, unsigned version) const
{
  /* Remove trivial elements before serializing */
  std::vector<bitmask> elements;
  bitmask omkey_mask = omkey_mask_;
  typename std::list<bitmask>::const_iterator list_it = element_masks_.begin();
  for (unsigned idx = 0; idx != omkey_mask_.size(); idx++) {
    if (omkey_mask_.get(idx)) {
      if (!list_it->any()) {
        omkey_mask.set(idx, false);
        list_it++;
      } else {
        elements.push_back(*list_it++);
      }
    }
  }

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("Key", key_);
  ar & make_nvp("OMKeyMask", omkey_mask);
  ar & make_nvp("ElementMasks", elements);
}


BOOST_CLASS_VERSION(I3RecoPulseSeriesMapMask, i3recopulseseriesmapmask_version_);
I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMapMask);

#endif /* DATACLASSES_I3MAPOMKEYMASK_H_INCLUDED */

