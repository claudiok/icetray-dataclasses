/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometry.h,v 1.4 2004/02/21 17:38:10 pretz Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/02/21 17:38:10 $
    @author Peter Niessen Thu Feb 19 12:48:42 EST 2004

    @brief This is an collection of tanks.

    @todo 

*/

#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include "dataclasses/StoragePolicy.h"
#include "dataclasses/AugVec.h"

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
class I3TopGeometry : public AugVec<I3TopGeometryHeader, I3TankGeo, I3TopGeometryStoragePolicy> 
{
  ClassDef(I3TopGeometry,1);
};

#endif
