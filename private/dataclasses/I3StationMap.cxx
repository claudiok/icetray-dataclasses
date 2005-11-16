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

#include "dataclasses/I3StationMap.h"
#include "dataclasses/I3SurfModuleGeo.h"

using namespace boost;

void I3StationMap::GoFirstTank () {

#if 0
  fCurrentStation = this->begin ();
  fCurrentSurfModule = fCurrentStation->second->begin ();
#endif

}

#if 0
// something to loop over tanks
I3TankGeo &I3StationMap::GetNextTank () {

  static I3StationGeo::iterator fCurrentStation (this->begin ());
  static I3SurfModuleGeo::iterator fCurrentSurfModule (fCurrentStation->second->begin ());

  for (I3StationMap::iterator i_station = fCurrentStation;
       i_station != this->end ();
       ++i_station) {
    i_station->second->Hello ();
    log_info ("Station # %d", i_station->first);
    for (I3StationGeo::iterator i_module = fCurrentSurfModule;
	 i_module != i_station->second->end ();
	 ++i_module) {
      I3SurfModuleGeoPtr surf_module = *i_module;
      log_info ("%f\t%f",
		surf_module->GetPos ().GetX (),
		surf_module->GetPos ().GetY ());
      fCurrentStation = &(*i_station);
      fCurrentSurfModule = &(*i_module);
      return *surf_module;
    }
  }

}
#endif
