/**
 *
 * copyright (C) 2004
 * IceCube collaboration
 * $Id:$
 *
 * @file I3StationGeo.cxx
 * @version $Revision:$
 * @date $Date:$
 * @author niessen Fri May  6 16:04:10 EDT 2005
 */

#include "dataclasses/I3StationGeo.h"

// loop over all surface modules in the station and return a pointer
// to the omgeo specified by the om key
I3OMGeoPtr I3StationGeo::GetOMGeoPtr (OMKey &om_key) {

  for (STLVectorStoragePolicy<I3SurfModuleGeoPtr>::iterator i_surf_module
	 = this->begin ();
       i_surf_module != this->end ();
       ++i_surf_module) {
    if (0 != (**i_surf_module)[om_key])
      return (**i_surf_module)[om_key];
  }

  return I3OMGeoPtr ();

}
