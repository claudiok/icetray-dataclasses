/**
 *  $Id$
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#include "dataclasses/I3MapOMKeyMask.h"
#include "dataclasses/physics/I3RecoPulse.h"
#include "boost/make_shared.hpp"
#include <boost/serialization/binary_object.hpp>

I3RecoPulseSeriesMapMask::I3RecoPulseSeriesMapMask(const I3Frame &frame, const std::string &key) : key_(key)
{
	source_ = frame.Get<boost::shared_ptr<const I3RecoPulseSeriesMap> >(key_);

	if (!source_)
		log_fatal("The map named '%s' doesn't exist in the frame!\n", key_.c_str());

	I3RecoPulseSeriesMap::const_iterator it = source_->begin();
	if (source_->size() == 0)
		return;

	omkey_mask_ = bitmask(source_->size());
	for ( ; it != source_->end(); it++) {
		if (it->second.size() > 0)
			element_masks_.push_back(bitmask(it->second.size()));
		else
			omkey_mask_.set(std::distance(source_->begin(), it),
			    false);
	}
}

void
I3RecoPulseSeriesMapMask::FillSubsetMask(bitmask &mask,
    const I3RecoPulseSeriesMap::mapped_type &superset,
    const I3RecoPulseSeriesMap::mapped_type &subset)
{
	unsigned idx = 0;
	unsigned midx = 0;
	I3RecoPulseSeriesMap::mapped_type::const_iterator sup_vit = superset.begin();
	I3RecoPulseSeriesMap::mapped_type::const_iterator sub_vit = subset.begin();
	
	for ( ; sup_vit != superset.end(); sup_vit++, idx++) {
		if (idx > 0 && (idx % (8*sizeof(mask_t)) == 0))
			midx++;
		
		assert(midx < mask.size_);
		if ((*sub_vit) == (*sup_vit)) {
			sub_vit++; /* We have a match, do nothing. */
		} else {
			/* Unset the corresponding bit. */
			mask.mask_[midx] &= ~(1 << (idx % (8*sizeof(mask_t))));
		}
	}
}

I3RecoPulseSeriesMapMask::I3RecoPulseSeriesMapMask(const I3Frame &frame,
    const std::string &key, const I3RecoPulseSeriesMap &subset) : key_(key)
{
	source_ = frame.Get<boost::shared_ptr<const I3RecoPulseSeriesMap> >(key_);
	
	if (!source_)
		log_fatal("The map named '%s' doesn't exist in the frame!", key_.c_str());
	
	if (!IsOrderedSubset(*source_, subset))
		log_fatal("The passed map is not an ordered subset of map '%s'!", key_.c_str());
	
	omkey_mask_ = bitmask(source_->size());
	
	I3RecoPulseSeriesMap::const_iterator sup_mit = source_->begin();
	I3RecoPulseSeriesMap::const_iterator sub_mit = subset.begin();
	unsigned idx = 0;
	for ( ; sup_mit != source_->end(); sup_mit++, idx++) {
		/* 
		 * NB: since the subset is ordered, we can wait until the
		 * superset catches up to increment its iterator.
		 */
		if (sub_mit->first == sup_mit->first) {
			bitmask mask = bitmask(sup_mit->second.size(), true);			
			
			FillSubsetMask(mask, sup_mit->second, sub_mit->second);
			element_masks_.push_back(mask);
			
			sub_mit++;
		} else {
			omkey_mask_.set(idx, false); /* Note absence. */
		}
	}
}


void
I3RecoPulseSeriesMapMask::SetNone()
{
	omkey_mask_.unset_all();
	element_masks_.clear();
	
	ResetCache();
}


unsigned
I3RecoPulseSeriesMapMask::GetSum() const
{
	unsigned sum = 0;
	std::list<bitmask>::const_iterator list_it = element_masks_.begin();
	
	for ( ; list_it != element_masks_.end(); list_it++)
		sum += list_it->sum();
	
	return sum;
}

bool
I3RecoPulseSeriesMapMask::GetAnySet() const
{
	return (omkey_mask_.any());
}

bool
I3RecoPulseSeriesMapMask::GetAllSet() const
{
	if (omkey_mask_.all()) {
		bool all = true;
		std::list<bitmask>::const_iterator list_it = element_masks_.begin();
		for ( ; list_it != element_masks_.end(); list_it++)
			all = (all && list_it->all());
		
		return all;
	} else {
		return false;
	}
}

int
I3RecoPulseSeriesMapMask::FindKey(const OMKey &key,
    std::list<bitmask>::iterator &list_it, const I3RecoPulseSeriesMap::mapped_type **vec)
{
	if (!source_) {
		log_error("This mask cannot be modified.");
		return -1;
	}
	
	I3RecoPulseSeriesMap::const_iterator source_it = source_->find(key);
	
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

void
I3RecoPulseSeriesMapMask::Set(const OMKey &key,
    const I3RecoPulseSeriesMap::mapped_type::value_type &target, bool set_it)
{
	int omkey_idx;
	std::list<bitmask>::iterator list_it;
	const I3RecoPulseSeriesMap::mapped_type *vec;
	
	ResetCache();
	
	if ((omkey_idx = FindKey(key, list_it, &vec)) < 0)
		return;
	
	/* Insert a new bitmask if necessary. */
	if (!omkey_mask_.get(omkey_idx))
		if (set_it) {
			list_it = element_masks_.insert(list_it,
			     bitmask(vec->size(), false));
			omkey_mask_.set(omkey_idx, true);
		} else
			return;
		
	I3RecoPulseSeriesMap::mapped_type::const_iterator vec_it = vec->begin();
	unsigned idx = 0;
	for ( ; vec_it != vec->end(); vec_it++, idx++)
		if (*vec_it == target) {
			list_it->set(idx, set_it);
			break;
		}	
}


void
I3RecoPulseSeriesMapMask::Set(const OMKey &key, const unsigned idx, bool set_it)
{
	int omkey_idx;
	std::list<bitmask>::iterator list_it;
	const I3RecoPulseSeriesMap::mapped_type *vec;
	
	ResetCache();
	
	if ((omkey_idx = FindKey(key, list_it, &vec)) < 0)
		return;
	
	/* Insert a new bitmask if necessary. */
	if (!omkey_mask_.get(omkey_idx))
		if (set_it) {
			list_it = element_masks_.insert(list_it,
			     bitmask(vec->size(), false));
			omkey_mask_.set(omkey_idx, true);
		} else
			return;
			
	list_it->set(idx, set_it);
}

void
I3RecoPulseSeriesMapMask::Set(const OMKey &key, bool set_it)
{
	int omkey_idx;
	std::list<bitmask>::iterator list_it;
	const I3RecoPulseSeriesMap::mapped_type *vec;
	
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

bool
I3RecoPulseSeriesMapMask::IsOrderedSubset(const I3RecoPulseSeriesMap &super,
    const I3RecoPulseSeriesMap &sub)
{
	I3RecoPulseSeriesMap::const_iterator sup_mit = super.begin();
	I3RecoPulseSeriesMap::const_iterator sub_mit = sub.begin();
	for ( ; sub_mit != sub.end(); sub_mit++) {
		while (sup_mit != super.end() && sup_mit->first != sub_mit->first)
			sup_mit++;
		if (sup_mit == super.end())
			return false;
		
		/* 
		 * NB: even in the vector portion, we expect elements in the subset
		 * to appear in order relative to their order in the superset.
		 */
		I3RecoPulseSeriesMap::mapped_type::const_iterator sup_vit = sup_mit->second.begin();
		I3RecoPulseSeriesMap::mapped_type::const_iterator sub_vit = sub_mit->second.begin();
		for ( ; sub_vit != sub_mit->second.end(); sub_vit++) {
			while (sup_vit == sup_mit->second.end() && !(*sup_vit == *sub_vit))
				sup_vit++;
			if (sup_vit == sup_mit->second.end())
				return false;
		}
	}
	
	return true;
}

I3RecoPulseSeriesMapMask
I3RecoPulseSeriesMapMask::operator&(const I3RecoPulseSeriesMapMask &other) const
{
	return ApplyBinaryOperator<operator_and>(other);
}

I3RecoPulseSeriesMapMask
I3RecoPulseSeriesMapMask::operator|(const I3RecoPulseSeriesMapMask &other) const
{
	return ApplyBinaryOperator<operator_or>(other);
}

I3RecoPulseSeriesMapMask
I3RecoPulseSeriesMapMask::operator^(const I3RecoPulseSeriesMapMask &other) const
{
	return ApplyBinaryOperator<operator_xor>(other);
}

template <typename BinaryOperator>
I3RecoPulseSeriesMapMask
I3RecoPulseSeriesMapMask::ApplyBinaryOperator(const I3RecoPulseSeriesMapMask &other) const
{
	if (key_ != other.key_)
		log_fatal("Masks cannot be combined!");
	
	I3RecoPulseSeriesMapMask newmask;
	BinaryOperator op;
	
	newmask.key_ = key_;
	newmask.source_ = source_;
	newmask.omkey_mask_ = omkey_mask_;
	newmask.omkey_mask_.unset_all();
	
	const unsigned n_omkeys = omkey_mask_.size_*8*sizeof(mask_t) - omkey_mask_.padding_;
	std::list<bitmask>::const_iterator lit = element_masks_.begin();
	std::list<bitmask>::const_iterator rit = other.element_masks_.begin();
	
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

boost::shared_ptr<const I3RecoPulseSeriesMap>
I3RecoPulseSeriesMapMask::Apply(const I3Frame &frame) const
{
	if (masked_)
		return masked_;
	
	boost::shared_ptr<const I3RecoPulseSeriesMap> source =
	    frame.Get<boost::shared_ptr<const I3RecoPulseSeriesMap> >(key_);
	
	if (!source)
		log_fatal("The map named '%s' doesn't exist in the frame!\n", key_.c_str());
	
	masked_ = boost::make_shared<I3RecoPulseSeriesMap>();
	
	I3RecoPulseSeriesMap::const_iterator source_it = source->begin();
	I3RecoPulseSeriesMap::iterator inserter = masked_->begin();
	std::list<bitmask>::const_iterator list_it = element_masks_.begin();
	unsigned omkey_idx = 0;
	
	for ( ; source_it != source->end(); source_it++, omkey_idx++) {
		
		if (!omkey_mask_.get(omkey_idx))
			continue;
		else if (list_it->sum() == 0) {
			list_it++;
			continue;
		}
		
		unsigned idx = 0;
		I3RecoPulseSeriesMap::mapped_type target_vec;
		I3RecoPulseSeriesMap::mapped_type::const_iterator source_vit =
		    source_it->second.begin();
		for ( ; source_vit != source_it->second.end(); source_vit++, idx++)
			if (list_it->get(idx))
				target_vec.push_back(*source_vit);
				
		inserter = masked_->insert(inserter,
		    std::make_pair(source_it->first, target_vec));
			
		list_it++;
	}
	
	return masked_;
}


#define ROUND_UP(num, denom) (num % denom == 0) ? num/denom : (num/denom) + 1

I3RecoPulseSeriesMapMask::bitmask::bitmask(unsigned length, bool set)
{
	size_ = ROUND_UP(length, 8*sizeof(mask_t));
	assert(size_ > 0);
	mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
	padding_ = length % (8*sizeof(mask_t));
	if (padding_ != 0)
		padding_ = 8*sizeof(mask_t) - padding_;
	
	if (set)
		set_all();
	else
		unset_all();
};

#undef ROUND_UP

I3RecoPulseSeriesMapMask::bitmask::bitmask(const bitmask& other) : size_(other.size_), padding_(other.padding_), mask_(NULL)
{
	if (size_ != 0) {
		mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
		memcpy(mask_, other.mask_, size_*sizeof(mask_t));
	}
}

I3RecoPulseSeriesMapMask::bitmask&
I3RecoPulseSeriesMapMask::bitmask::operator=(const bitmask& other)
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

I3RecoPulseSeriesMapMask::bitmask::~bitmask()
{
	if (mask_)
		free(mask_);
};

inline bool
I3RecoPulseSeriesMapMask::bitmask::any() const
{
	mask_t test = 0;
	for (unsigned i = 0; i < size_; i++)
		test |= mask_[i];
	
	return (test != 0);
}

inline bool
I3RecoPulseSeriesMapMask::bitmask::all() const
{
	bool test = true;
	const mask_t all = std::numeric_limits<mask_t>::max();
	
	const unsigned max_i = (size_ == 0) ? 0 : size_-1;
	for (unsigned i = 0; i < max_i; i++)
		test = test && (mask_[i] == all);
	
	return (test && ((mask_[size_-1] == (all >> padding_))));
}

void
I3RecoPulseSeriesMapMask::bitmask::set_all()
{
	/* All bits set. */
	const mask_t all = std::numeric_limits<mask_t>::max();
	
	assert(size_ > 0);
	memset(mask_, all, (size_-1)*sizeof(mask_t));
	mask_[size_-1] = (all >> padding_); /* Unset unused top bits. */
}

void
I3RecoPulseSeriesMapMask::bitmask::unset_all()
{
	memset(mask_, 0, size_*sizeof(mask_t));
}

inline void
I3RecoPulseSeriesMapMask::bitmask::set(const unsigned idx, bool set_it)
{
	assert(idx < (8*sizeof(mask_t)*size_ - padding_));
	if (set_it)
		mask_[idx/(8*sizeof(mask_t))] |= (1 << (idx % (8*sizeof(mask_t))));
	else
		mask_[idx/(8*sizeof(mask_t))] &= ~(1 << (idx % (8*sizeof(mask_t))));
}

inline bool
I3RecoPulseSeriesMapMask::bitmask::get(const unsigned idx) const
{
	assert(idx < (8*sizeof(mask_t)*size_ - padding_));
	
	return mask_[idx/(8*sizeof(mask_t))] & (1 << (idx % (8*sizeof(mask_t))));
}

unsigned
I3RecoPulseSeriesMapMask::bitmask::sum() const
{
	unsigned sum = 0;
	
	for (unsigned i = 0; i < size_; i++)
		for (unsigned j = 0; j < 8*sizeof(mask_t); j++)
			if (mask_[i] & (1 << j))
				sum++;
	
	return sum;
}

template <class Archive>
void
I3RecoPulseSeriesMapMask::bitmask::load(Archive & ar, unsigned version)
{
	ar & make_nvp("Size", size_);
	ar & make_nvp("Padding", padding_);
	
	mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
	ar & make_nvp("Bitmask", boost::serialization::make_binary_object(
	    mask_, size_*sizeof(mask_t)));
}

template <class Archive>
void
I3RecoPulseSeriesMapMask::bitmask::save(Archive & ar, unsigned version) const
{
	ar & make_nvp("Size", size_);
	ar & make_nvp("Padding", padding_);
	ar & make_nvp("Bitmask", boost::serialization::make_binary_object(
	    mask_, size_*sizeof(mask_t)));
}

/*
 * FIXME: the number of the element masks is implicit in the omkey mask.
 * Compactify the serialization.
 */
template <class Archive>
void
I3RecoPulseSeriesMapMask::load(Archive & ar, unsigned version)
{
	std::vector<bitmask> elements;
	
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	ar & make_nvp("Key", key_);
	ar & make_nvp("OMKeyMask", omkey_mask_);
	ar & make_nvp("ElementMasks", elements);
	
	std::copy(elements.begin(), elements.end(), std::back_inserter(element_masks_));
}

template <class Archive>
void
I3RecoPulseSeriesMapMask::save(Archive & ar, unsigned version) const
{
	std::vector<bitmask> elements;
	std::copy(element_masks_.begin(), element_masks_.end(), std::back_inserter(elements));
	
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	ar & make_nvp("Key", key_);
	ar & make_nvp("OMKeyMask", omkey_mask_);
	ar & make_nvp("ElementMasks", elements);
}

I3_SERIALIZABLE(I3RecoPulseSeriesMapMask);
