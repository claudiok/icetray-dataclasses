/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeo.h,v 1.21 2004/07/05 18:25:56 pretz Exp $
 *
 * @file I3OMGeo.h
 * @version $Revision: 1.21 $
 * @date $Date: 2004/07/05 18:25:56 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include "dataclasses/I3Position.h"
#include <string>

/**
 * @brief The basic Optical Module Geometry class.  
 * 
 * This is the static frozen-in-the-ice properties of an optical module
 */
class I3OMGeo : public TObject
{
 public:
  /**
   * An enumerated type for the OM Orientation
   */
  enum EOrientation {Unspecified,Up,Down};

  /**
   * An enumerated type for the possible kinds of OMs
   */
  enum EOMType {AMANDA,IceCube};

 protected:
  UShort_t fOMNumber;
  I3Position fPosition;
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
    fPosition = rhs.fPosition;
    fOrientation = rhs.fOrientation;
    fRelativeQE = rhs.fRelativeQE;
    fArea = rhs.fArea;    
    return *this;
  }

  /**
   * @return the identity of this OM, either AMANDA or IceCube 
   */
  virtual EOMType GetOMType() const =0;

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
  Double_t GetX() const { return fPosition.GetX(); }

  /**
   * @param x the new x position of the OM
   */
  void   SetX(Double_t x) { fPosition.SetX(x); }

  /**
   * @return the y position of the OM
   */
  Double_t GetY() const { return fPosition.GetY(); }

  /**
   * @param y the new y position of the OM
   */
  void   SetY(Double_t y) { fPosition.SetY(y); }

  /**
   * @return the z position of the OM
   */
  Double_t GetZ() const { return fPosition.GetZ(); }

  /**
   * @param z the new z position of the OM
   */
  void     SetZ(Double_t z) { fPosition.SetZ(z);; }

  /**
   * @return The position of this OM
   */
  const I3Position& GetPosition() const { return fPosition;}

  /**
   * @param position The new position for this OM
   */
  void SetPosition(I3Position& position)
    {
      fPosition = position;
    }
  
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

