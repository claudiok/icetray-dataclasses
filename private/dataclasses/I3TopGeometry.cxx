/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h 1430 2005-04-12 18:59:51Z dule $
 *
 * @file I3TopGeometry.cxx
 * @version $Revision: 1.19 $
 * @date $Date: 2005-04-12 14:59:51 -0400 (Tue, 12 Apr 2005) $
 * @author niessen Fri May  6 16:39:38 EDT 2005
 */

#include "dataclasses/I3TopGeometry.h"

I3OMGeoPtr I3TopGeometry::GetOMGeoPtr (OMKey &om_key) {

  for (I3StationMap::iterator i_station = stationMap_.begin ();
       i_station != stationMap_.end ();
       ++i_station) {
    if (0 != i_station->second->GetOMGeoPtr (om_key))
      return i_station->second->GetOMGeoPtr (om_key);
  }

  return I3OMGeoPtr ();
}
