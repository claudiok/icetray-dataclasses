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

#include <dataclasses/BoostHeaders.h>
#include "dataclasses/geometry/I3StationGeo.h"

I3StationGeo::~I3StationGeo() {}
I3StationGeo::I3StationGeo() {}

template <class Archive>
void 
I3StationGeo::serialize(Archive& ar, unsigned version)
{	
  ar & make_nvp("I3StationGeo",
		base_object< I3Vector<I3SurfModuleGeoPtr> >(*this));  
}
	

I3OMGeoPtr I3StationGeo::GetOMGeoPtr (OMKey &om_key) {

  for (vector<I3SurfModuleGeoPtr>::iterator i_surf_module
	 = this->begin ();
       i_surf_module != this->end ();
       ++i_surf_module) {
    if (0 != (**i_surf_module)[om_key])
      return (**i_surf_module)[om_key];
  }

  return I3OMGeoPtr ();

}

I3_SERIALIZABLE(I3StationGeo);
