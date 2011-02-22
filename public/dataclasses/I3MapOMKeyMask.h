
#include "icetray/I3FrameObject.h"
#include "icetray/OMKey.h"
#include "icetray/I3Frame.h"
#include "icetray/serialization.h"
#include "dataclasses/physics/I3RecoPulse.h"

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
	boost::shared_ptr<I3RecoPulseSeriesMap> Apply(const I3Frame &frame) const;
	
	/*
	 * Get the number of set bits in the mask.
	 */
	unsigned GetSum() const;
	
	/*
	 * Logical operators, applied elementwise.
	 */
	I3RecoPulseSeriesMapMask operator&(const I3RecoPulseSeriesMapMask&) const;
	I3RecoPulseSeriesMapMask operator|(const I3RecoPulseSeriesMapMask&) const;
	I3RecoPulseSeriesMapMask operator^(const I3RecoPulseSeriesMapMask&) const;
	I3RecoPulseSeriesMapMask operator~() const;
	
	/* Default ctor. */
	I3RecoPulseSeriesMapMask() {};
		
private:
	typedef uint8_t mask_t;
	
	struct bitmask {
		uint16_t size_;
		uint8_t padding_;
		mask_t *mask_;
		
		bitmask() : mask_(NULL) {};
		bitmask(unsigned length, bool set=true);
		bitmask(const bitmask& other);
		bitmask& operator=(const bitmask& other);
		~bitmask();
		void set_all();
		void unset_all();
		inline void set(const unsigned, bool);
		
		inline bool get(const unsigned) const;
		unsigned sum() const;
		unsigned capacity() const;
		
		friend class boost::serialization::access;
		
		template <class Archive> void load(Archive & ar, unsigned version);
		template <class Archive> void save(Archive & ar, unsigned version) const;
		
		BOOST_SERIALIZATION_SPLIT_MEMBER();
	};
		
	std::string key_;
	bitmask omkey_mask_;
	std::list<bitmask> element_masks_;
	boost::shared_ptr<const I3RecoPulseSeriesMap> source_;

	int FindKey(const OMKey &key, std::list<bitmask>::iterator &list_it,
	    const I3RecoPulseSeriesMap::mapped_type **vec);
	
	static bool IsOrderedSubset(const I3RecoPulseSeriesMap&, const I3RecoPulseSeriesMap&);
	static void FillSubsetMask(bitmask&, const I3RecoPulseSeriesMap::mapped_type&,
	    const I3RecoPulseSeriesMap::mapped_type&);
	
	template <typename BinaryOperator>
	I3RecoPulseSeriesMapMask ApplyBinaryOperator(const I3RecoPulseSeriesMapMask&) const;
	
	struct operator_and : public binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs & rhs; }
	};
	
	struct operator_or : public binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs | rhs; }
	};
	
	struct operator_xor : public binary_function<mask_t, mask_t, mask_t> {
		inline mask_t operator()(mask_t lhs, mask_t rhs) { return lhs ^ rhs; }
	};
	
	friend class boost::serialization::access;
	template <class Archive> void load(Archive & ar, unsigned version);
	template <class Archive> void save(Archive & ar, unsigned version) const;
	
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	
	SET_LOGGER("I3RecoPulseSeriesMapMask");
};
