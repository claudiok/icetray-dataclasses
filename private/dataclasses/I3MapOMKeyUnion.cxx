/**
 *  $Id$
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#include "dataclasses/I3MapOMKeyUnion.h"
#include "dataclasses/I3MapOMKeyMask.h"
#include "dataclasses/physics/I3RecoPulse.h"
#include "boost/make_shared.hpp"
#include "boost/foreach.hpp"

I3RecoPulseSeriesMapUnion::I3RecoPulseSeriesMapUnion() : keys_(), unified_() {}

I3RecoPulseSeriesMapUnion::I3RecoPulseSeriesMapUnion(const I3Frame &frame,
    const std::vector<std::string> &keys) : keys_(keys), unified_() {}

static bool PulseCompare(const I3RecoPulse &p1, const I3RecoPulse &p2)
{
	return p1.GetTime() < p2.GetTime();
}

I3RecoPulseSeriesMapConstPtr
I3RecoPulseSeriesMapUnion::Apply(const I3Frame &frame) const
{
	typedef I3RecoPulseSeriesMap Map;
	typedef boost::shared_ptr<const Map> MapConstPtr;
	typedef Map::value_type Pair;
	typedef Pair::second_type Series;
	typedef Series::value_type Element;
	
	if (unified_)
		return unified_;
	
	unified_ = boost::make_shared<Map>();
	
	BOOST_FOREACH(const std::string &key, keys_) {
		MapConstPtr pmap = frame.Get<MapConstPtr>(key);
		if (!pmap)
			log_fatal("Couldn't find '%s' in the frame!",
			    key.c_str());
		
		BOOST_FOREACH(const Pair &pair, *pmap) {
			Series &univec = (*unified_)[pair.first];
			BOOST_FOREACH(const Element &element, pair.second)
				univec.push_back(element);
		}
	}
	
	BOOST_FOREACH(Pair &pair, *unified_)
		std::sort(pair.second.begin(), pair.second.end(),
		    PulseCompare);
	
	return unified_;
}

I3TimeWindowSeriesMapPtr
I3RecoPulseSeriesMapUnion::GetComplement(const I3Frame &frame) const
{
	typedef I3RecoPulseSeriesMap Map;
	typedef boost::shared_ptr<const Map> MapConstPtr;
	typedef Map::value_type Pair;
	typedef Pair::second_type Series;
	typedef Series::value_type Element;
	
	std::vector<I3TimeWindowSeriesMapPtr> exclusions(keys_.size());
	std::vector<I3TimeWindowSeriesMapPtr>::iterator ex_it = exclusions.begin();
	BOOST_FOREACH(const std::string &key, keys_) {
		MapConstPtr pmap = frame.Get<MapConstPtr>(key);
		if (!pmap)
			log_fatal("Couldn't find '%s' in the frame!",
			    key.c_str());
		
		// Recurse if necessary
		I3FrameObjectConstPtr focp = frame.Get<I3FrameObjectConstPtr>(key);
		I3TimeWindowSeriesMapPtr exclusions;
		if (I3RecoPulseSeriesMapMaskConstPtr mask =
		    boost::dynamic_pointer_cast<const I3RecoPulseSeriesMapMask>(focp)) {
			*ex_it = mask->GetComplement(frame);
		} else if (I3RecoPulseSeriesMapUnionConstPtr uni = 
		    boost::dynamic_pointer_cast<const I3RecoPulseSeriesMapUnion>(focp)) {
			*ex_it = uni->GetComplement(frame);
		} else {
			*ex_it = boost::make_shared<I3TimeWindowSeriesMap>();
		}
		
		assert(*ex_it);
		ex_it++;
		
		// The set of valid regions is the complement of the set of
		// exclusions, so for the union of the sources, the exclusions
		// are given by the complement of the union of valid regions.
		// Whew.
	}
	
}


template <class Archive>
void
I3RecoPulseSeriesMapUnion::serialize(Archive& ar, unsigned version)
{
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	ar & make_nvp("Keys", keys_);
}

I3_SERIALIZABLE(I3RecoPulseSeriesMapUnion);
