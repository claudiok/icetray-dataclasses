/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometry.h,v 1.5 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/21 18:52:38 $
    @author Peter Niessen Thu Feb 19 12:48:42 EST 2004

    @brief This is an collection of tanks.

    @todo 

*/

#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include "dataclasses/I3TankGeo.h"
#include "dataclasses/StoragePolicy.h"


class I3TopGeometry : public VectorPolicy<I3TankGeo>::ThePolicy
{

  UChar_t fID; // some id
  Double_t fTime; // time
  Long_t fDate; // and date
  
 public:

  UChar_t ID () const { return fID; }
  void ID (UChar_t id) { fID = id; }

  Double_t Time () const { return fTime; }
  void Time (Double_t time) { fTime = time; }

  Long_t Date () const { return fDate; }
  void Date (Long_t date) { fDate = date; }

  virtual ~I3TopGeometry(){};
  ClassDef(I3TopGeometry,1);
};

#endif
