#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include <TObjArray.h>
#include <string>
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeo.h,v 1.14 2004/03/13 19:51:20 pretz Exp $
 *
 * The basic Optical Module Geometry class.  This is the static 
 * frozen-in-the-ice properties of an optical module
 *
 * @version $Revision: 1.14 $
 * @date $Date: 2004/03/13 19:51:20 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
class I3OMGeo : public TObject
{
 public:
  enum EOrientation {Unspecified,Up,Down};

 protected:
  UShort_t fOMNumber;
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  EOrientation fOrientation;
  Int_t fString;
  Double_t fRelativeQE;

  public:
  /**
   * constructor
   */
  I3OMGeo() { Init();}

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
    return *this;
  }

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
  EOrientation  Orientation() const { return fOrientation; }

  /**
   * @param orientation the new orientation for the tube
   */
  void    Orientation(EOrientation orientation) { fOrientation = orientation; }

  /**
   * @return the string that this is an OM for
   */
  Int_t String() const {return fString;}

  /**
   * @param string the new string number for this OM
   */
  void String(Int_t string) {fString = string;}

  /**
   * This is the relative quantum efficiency of this OM.  Relative
   * to some standard.  This is the 'relative sensitivity' of the 
   * AMANDA experiment
   * @return the relative quantum efficiency of this OM
   */
  Double_t RelativeQE(){return fRelativeQE;}

  /**
   * This is the relative quantum efficiency of this OM.  Relative
   * to some standard.  This is the 'relative sensitivity' of the 
   * AMANDA experiment
   * @param qe the new Relative Quantum Efficiency for this OM
   */
  void RelativeQE(Double_t qe) { fRelativeQE = qe;}

  // for testing
  virtual std::string iam() { return "I3OMGeo"; }

 private:
  /**
   * resets the data to 0's.
   */
  void Init();

  //ROOT macro
  ClassDef(I3OMGeo,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeo>::ThePolicy I3OMGeoPtr;

#endif

