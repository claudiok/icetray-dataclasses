/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopStationGeo.h,v 1.2 2004/07/13 16:24:52 niessen Exp $
 *
 * @file I3TopStationGeo.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/13 16:24:52 $
 * @author PN/RU Tue Jun 22 10:30:16 EDT 2004
 */
#ifndef __I3TankStationGEO_H_
#define __I3TankStationGEO_H_

#include <iostream>

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3TopGeometry.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3TankGeo.h"

using namespace std;
/**
 * @brief Class which describes a icetop station
 * @todo needs the i3tankgeo a z coordinate
 */
class I3TopStationGeo : public TObject, public VectorPolicy<I3TankGeoPtr>::ThePolicy
{
  UShort_t fStationID;

 public:
  I3TopStationGeo (UShort_t station_id = 0) {fStationID = station_id;}
  virtual ~I3TopStationGeo() {;}  
  UShort_t StationID () const {return fStationID;}
  void StationID (UShort_t station_id) {fStationID = station_id;}
  ClassDef(I3TopStationGeo,1);
};

typedef PtrPolicy<I3TopStationGeo>::ThePolicy I3TopStationGeoPtr;

class I3TopStationGeoMatchesStationID {
  
 public:

  /**
   * Constructor.
   */
  I3TopStationGeoMatchesStationID (UShort_t station_id) : id (station_id) {
  cerr << "Get station_id  " << station_id << endl;}

  /**
   * Comparison operator.
   */
  bool operator () (I3TopStationGeoPtr sg) const {
    //    cerr << "Trying to equal station id" << endl;
    return id == sg->StationID ();
  }
 private:
  UShort_t id;
  
};

#endif

