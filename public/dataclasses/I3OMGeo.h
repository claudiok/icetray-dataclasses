/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeo.h,v 1.24 2004/07/30 18:08:00 dule Exp $
 *
 * @file I3OMGeo.h
 * @version $Revision: 1.24 $
 * @date $Date: 2004/07/30 18:08:00 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include "dataclasses/I3Position.h"
#include <TClass.h>
#include <string>
#include <iostream>
#include "dataclasses/OMKey.h"

using namespace std;

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
  I3Position fPosition;
  EOrientation fOrientation;
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
   * @return The position of this OM
   */
  const I3Position& GetPos() const { return fPosition;}

  /**
   * @param position The new position for this OM
   */
  void SetPos(I3Position& pos)
    {fPosition.SetPosition(pos);}
  
  /**
   * @param position The new position for this OM
   */
  void SetPos(Double_t r1, Double_t r2, Double_t r3, 
	      I3Position::RefFrame frame=I3Position::car)
    {fPosition.SetPosition(r1,r2,r3,frame);}
  
  /**
   * @return kTRUE if the om is pointed down
   */
  EOrientation  GetOrientation() const { return fOrientation; }

  /**
   * @param orientation the new orientation for the tube
   */
  void SetOrientation(EOrientation orientation) { fOrientation = orientation; }

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

  /**
   * @todo finish with all the data
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "
       <<IsA()->GetName()
       <<" X:"
       <<fPosition.GetX()
       <<" Y:"
       <<fPosition.GetY()
	<<" Z:"
       <<fPosition.GetZ()
       <<" ]\n";
    }

 private:
  /**
   * resets the data to 0's.
   */
  void Init();

  //ROOT macro
  ClassDef(I3OMGeo,1);
};

inline ostream& operator<<(ostream& o,const I3OMGeo& g)
{
  g.ToStream(o); 
  return o;
}

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeo>::ThePolicy I3OMGeoPtr;

#endif

