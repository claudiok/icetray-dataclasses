/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeo.h,v 1.17 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3OMGeo.h
 * @version $Revision: 1.17 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include <TObjArray.h>
#include <string>

/**
 * @brief The basic Optical Module Geometry class.  
 * 
 * This is the static frozen-in-the-ice properties of an optical module
 *
 * @todo we need to implement the I3Position stuff here -J.Pretz
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
  Double_t fArea;

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
    fRelativeQE = rhs.fRelativeQE;
    fArea = rhs.fArea;    
    return *this;
  }

  /**
   * @return the number of this optical module
   */
  UShort_t GetOMNumber() const {return fOMNumber;}

  /**
   * @param omnumber the new number for this optical module
   */
  void   SetOMNumber(UShort_t omnumber) { fOMNumber = omnumber; }

  /**
   * @return the x position of the OM
   */
  Double_t GetX() const { return fX; }

  /**
   * @param x the new x position of the OM
   */
  void   SetX(Double_t x) { fX = x; }

  /**
   * @return the y position of the OM
   */
  Double_t GetY() const { return fY; }

  /**
   * @param y the new y position of the OM
   */
  void   SetY(Double_t y) { fY = y; }

  /**
   * @return the z position of the OM
   */
  Double_t GetZ() const { return fZ; }

  /**
   * @param z the new z position of the OM
   */
  void     SetZ(Double_t z) { fZ = z; }

  /**
   * @return kTRUE if the om is pointed down
   */
  EOrientation  GetOrientation() const { return fOrientation; }

  /**
   * @param orientation the new orientation for the tube
   */
  void SetOrientation(EOrientation orientation) { fOrientation = orientation; }

  /**
   * @return the string that this is an OM for
   */
  Int_t GetString() const {return fString;}

  /**
   * @param string the new string number for this OM
   */
  void SetString(Int_t string) {fString = string;}

  /**
   * This is the relative quantum efficiency of this OM.  Relative
   * to some standard.  This is the 'relative sensitivity' of the 
   * AMANDA experiment
   * @return the relative quantum efficiency of this OM
   */
  Double_t GetRelativeQE() const {return fRelativeQE;}

  /**
   * This is the relative quantum efficiency of this OM.  Relative
   * to some standard.  This is the 'relative sensitivity' of the 
   * AMANDA experiment
   * @param qe the new Relative Quantum Efficiency for this OM
   */
  void SetRelativeQE(Double_t qe) { fRelativeQE = qe;}

  /**
   * retrieves the area of the photo cathode for this tube
   * @return the area of the photocathode
   */
  Double_t GetArea() const { return fArea;}


  /**
   * sets the photocathode area for this tube
   * @param area the new area for the photocathode
   */
  void Area(Double_t area){fArea = area;}

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

