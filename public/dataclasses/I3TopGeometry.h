/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometry.h,v 1.2 2004/02/19 23:03:08 niessen Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/19 23:03:08 $
    @author Peter Niessen Thu Feb 19 12:48:42 EST 2004

    @brief This is an collection of tanks.

    @todo 

*/

#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include "dataclasses/StoragePolicy.h"
#include "dataclasses/GarnishedVector.h"

#include "dataclasses/I3TankGeo.h"

class I3TopGeometryHeader {

 public:

  UChar_t ID () const { return fID; }
  void ID (UChar_t id) { fID = id; }

  Double_t Time () const { return fTime; }
  void Time (Double_t time) { fTime = time; }

  Long_t Date () const { return fDate; }
  void Date (Long_t date) { fDate = date; }

 private:

  UChar_t fID; // some id
  Double_t fTime; // time
  Long_t fDate; // and date
  
};

typedef StoragePolicy<I3TankGeo> I3TopGeometryStoragePolicy;
typedef GarnishedVector<I3TopGeometryHeader, I3TankGeo, I3TopGeometryStoragePolicy> I3TopGeometry;

#endif
