/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeo.h,v 1.29.4.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3OMGeo.h
 * @version $Revision: 1.29.4.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3OMGEO_H
#define I3OMGEO_H

#include "dataclasses/I3Position.h"
#include <string>
#include <iostream>
#include <sstream>
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
  enum EOMType {AMANDA,IceCube,IceTop};

 protected:
  /**
   * the position
   */
  I3Position fPosition;

  /**
   * the orientation
   */
  EOrientation fOrientation;

  /**
   * the quantum efficiency relative to some standard
   */
  Double_t fRelativeQE;

  /**
   * the cross-sectional area of the photocathode
   */
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
   * @return the identity of this OM, either AMANDA or IceCube 
   */
  virtual EOMType GetOMType() const =0;

  /**
   * @return The position of this OM
   */
  const I3Position& GetPos() const { return fPosition;}

  /**
   * @param pos The new position for this OM
   */
  void SetPos(I3Position& pos)
    {fPosition.SetPosition(pos);}
  
  /**
   * Sets the position of the OM
   * @param r1 the first coordinate set
   * @param r2 the second coordinate set
   * @param r3 the third coordinate set
   * @param frame the coordinate system used. Defaults to cartesian.
   */
  void SetPos(Double_t r1, Double_t r2, Double_t r3, 
	      I3Position::RefFrame frame=I3Position::car)
    {fPosition.SetPosition(r1,r2,r3,frame);}
  
  /**
   * @return the orientation of the tube
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
  void SetArea(Double_t area){fArea = area;}

  /**
   * @todo finish with all the data
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMGeo X:"
       <<fPosition.GetX()
       <<" Y:"
       <<fPosition.GetY()
	<<" Z:"
       <<fPosition.GetZ()
       <<" ]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
  /**
   * resets the data to 0's.
   */
  void Init();

};

/**
 * streams an I3OMGeo to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3OMGeo& g)
{
  g.ToStream(o); 
  return o;
}

#include "dataclasses/StoragePolicy.h"
/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef PtrPolicy<I3OMGeo>::ThePolicy I3OMGeoPtr;

#endif

