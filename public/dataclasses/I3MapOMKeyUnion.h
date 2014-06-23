/**
 *  $Id$
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  Marcel Zoll <marcel.zoll@fysik.su.se>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *
 */

#ifndef DATACLASSES_I3MAPOMKEYUNION_H_INCLUDED
#define DATACLASSES_I3MAPOMKEYUNION_H_INCLUDED

#include <functional>
#include <string>
#include <list>
#include "icetray/I3FrameObject.h"
#include "icetray/OMKey.h"
#include "icetray/I3Frame.h"
#include "icetray/serialization.h"

#include "dataclasses/I3Map.h"

static const unsigned i3mapomkeyunion_version_ = 0;

template <class Response>
class I3MapOMKeyUnion : public I3FrameObject {
private://definitions
  typedef std::vector<Response> ResponseSeries;
  typedef I3Map<OMKey, ResponseSeries> ResponseSeriesMap;
  typedef boost::shared_ptr<ResponseSeriesMap> ResponseSeriesMapPtr;
  typedef boost::shared_ptr<const ResponseSeriesMap> ResponseSeriesMapConstPtr;
//   typedef boost::shared_ptr<ResponseSeriesMapMask<Response> > ResponseSeriesMapMaskPtr;
//   typedef boost::shared_ptr<const ResponseSeriesMapMask<Response> > ResponseSeriesMapMaskConstPtr;
  
public:
	/* 
	 * Construct a union for the map stored at "key." All bits are set.
	 */
	I3MapOMKeyUnion(const I3Frame&, const std::vector<std::string> &keys);
	I3MapOMKeyUnion();
	
	ResponseSeriesMapConstPtr Apply(const I3Frame&) const;
	std::vector<std::string> GetSources() const { return keys_; }
private:
	std::vector<std::string> keys_;
	mutable ResponseSeriesMapPtr unified_;
	
	friend class boost::serialization::access;
	template <class Archive> void serialize(Archive& ar, unsigned version);
	
	SET_LOGGER("I3MapOMKeyUnion");
};

#include "dataclasses/physics/I3RecoPulse.h"
typedef I3MapOMKeyUnion<I3RecoPulse> I3RecoPulseSeriesMapUnion;
BOOST_CLASS_VERSION(I3RecoPulseSeriesMapUnion, i3mapomkeyunion_version_);
I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMapUnion);

#include "dataclasses/physics/I3MCHit.h"
typedef I3MapOMKeyUnion<I3MCHit> I3MCHitSeriesMapUnion;
BOOST_CLASS_VERSION(I3MCHitSeriesMapUnion, i3mapomkeyunion_version_);
I3_POINTER_TYPEDEFS(I3MCHitSeriesMapUnion);



// ================= IMPLEMENTATIONS ===================

#include "boost/make_shared.hpp"
#include "boost/foreach.hpp"

template <class Response>
I3MapOMKeyUnion<Response>::I3MapOMKeyUnion() : keys_(), unified_() {}

template <class Response>
I3MapOMKeyUnion<Response>::I3MapOMKeyUnion(const I3Frame &frame,
    const std::vector<std::string> &keys) : keys_(keys), unified_() {}

template <class Response>
static bool PulseCompare(const Response &p1, const Response &p2)
{
  return p1.GetTime() < p2.GetTime();
}

template <class Response>
typename I3MapOMKeyUnion<Response>::ResponseSeriesMapConstPtr
I3MapOMKeyUnion<Response>::Apply(const I3Frame &frame) const
{
  typedef ResponseSeriesMap Map;
  typedef boost::shared_ptr<const Map> MapConstPtr;
  typedef typename Map::value_type Pair;
  typedef typename Pair::second_type Series;
  typedef typename Series::value_type Element;
  
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
        PulseCompare<Response>);
  
  return unified_;
}

template <class Response> template <class Archive>
void
I3MapOMKeyUnion<Response>::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("Keys", keys_);
}





#endif
