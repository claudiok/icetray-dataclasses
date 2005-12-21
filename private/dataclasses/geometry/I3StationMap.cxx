/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3StationMap
 * @version $Revision: 1.6 $
 * @date $Date$
 * @author niessen Thu Sep  2 16:38:31 EDT 2004 
 */
#include <dataclasses/BoostHeaders.h>
#include "dataclasses/I3StationMap.h"
#include "dataclasses/I3SurfModuleGeo.h"

I3StationMap::~I3StationMap() {}

template <class Archive>
  void I3StationMap::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3StationMap",
      base_object< map<StationKey, I3StationGeoPtr> >(*this));
  }


void I3StationMap::GoFirstTank () {

#if 0
  fCurrentStation = this->begin ();
  fCurrentSurfModule = fCurrentStation->second->begin ();
#endif

}
I3_SERIALIZABLE(I3StationMap);
