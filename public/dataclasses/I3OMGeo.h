/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMGeo.h,v 1.7 2004/02/23 22:36:49 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/23 22:36:49 $
    @author

    @todo

*/
#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include <TObjArray.h>

class I3OMGeo : public TObject
{
  protected:
  UShort_t omnumber;
  Double_t x;
  Double_t y;
  Double_t z;
  Bool_t orientation;
  UChar_t version;

  public:
  void Init();

  I3OMGeo() { Init(); }
  I3OMGeo(const I3OMGeo& rhs){*this = rhs;}
  const I3OMGeo& operator=(const I3OMGeo& rhs){
    if (this == &rhs) return *this; // check for assignment to self
    TObject::operator=(rhs); // call base class assignment operator
    omnumber = rhs.omnumber;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    orientation = rhs.orientation;
    version = rhs.version;
    return *this;
  }

  UShort_t OMNumber() const {return omnumber;}
  void   OMNumber(UShort_t omnumber_) { omnumber = omnumber_; }

  Double_t X() const { return x; }
  void   X(Double_t x_) { x = x_; }

  Double_t Y() const { return y; }
  void   Y(Double_t y_) { y = y_; }

  Double_t Z() const { return z; }
  void     Z(Double_t z_) { z = z_; }

  Bool_t  Orientation() const { return orientation; }
  void    Orientation(Bool_t orientation_) { orientation = orientation_; }

  UChar_t Version() const { return version; }
  void    Version(UChar_t version_) { version = version_; }

  ClassDef(I3OMGeo,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeo>::ThePolicy I3OMGeoPtr;

#endif

