/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeo.h,v 1.11 2004/03/04 16:45:56 troy Exp $
 *
 * The basic Optical Module Geometry class.  This is the static 
 * frozen-in-the-ice properties of an optical module
 *
 * @version $Revision: 1.11 $
 * @date $Date: 2004/03/04 16:45:56 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>
#include <string>

class I3OMGeo : public TObject
{
 protected:
  UShort_t fOMNumber;
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  Bool_t fOrientation;
  UChar_t fVersion;

  public:
  /**
   * constructor
   */
  I3OMGeo() { Init(); TRef r=this;}

  /**
   * copy constructor just uses assignment
   */
  I3OMGeo(const I3OMGeo& rhs){*this = rhs;}

  /**
   * destructor
   */
  virtual ~I3OMGeo(){}

  /**
   * assignment is member-wise assignment
   */
  const I3OMGeo& operator=(const I3OMGeo& rhs){
    if (this == &rhs) return *this; // check for assignment to self
    TObject::operator=(rhs); // call base class assignment operator
    fOMNumber = rhs.fOMNumber;
    fX = rhs.fX;
    fY = rhs.fY;
    fZ = rhs.fZ;
    fOrientation = rhs.fOrientation;
    fVersion = rhs.fVersion;
    return *this;
  }

  /**
   * resets the data to 0's.
   */
  void Init();

  /**
   * @return the number of this optical module
   */
  UShort_t OMNumber() const {return fOMNumber;}

  /**
   * @param omnumber the new number for this optical module
   */
  void   OMNumber(UShort_t omnumber) { fOMNumber = omnumber; }

  /**
   * @return the x position of the OM
   */
  Double_t X() const { return fX; }

  /**
   * @param x the new x position of the OM
   */
  void   X(Double_t x) { fX = x; }

  /**
   * @return the y position of the OM
   */
  Double_t Y() const { return fY; }

  /**
   * @param y the new y position of the OM
   */
  void   Y(Double_t y) { fY = y; }

  /**
   * @return the z position of the OM
   */
  Double_t Z() const { return fZ; }

  /**
   * @param z the new z position of the OM
   */
  void     Z(Double_t z) { fZ = z; }

  /**
   * @return kTRUE if the om is pointed down
   */
  Bool_t  Orientation() const { return fOrientation; }

  /**
   * @param orientation the new orientation for the tube
   */
  void    Orientation(Bool_t orientation) { fOrientation = orientation; }

  /**
   * @return the version of the OM
   */
  UChar_t Version() const { return fVersion; }

  /**
   * @param version the new version of the OM
   */
  void    Version(UChar_t version) { fVersion = version; }

  // for testing
  virtual std::string iam() { return "I3OMGeo"; }

 private:
  //ROOT macro
  ClassDef(I3OMGeo,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeo>::ThePolicy I3OMGeoPtr;

#endif

