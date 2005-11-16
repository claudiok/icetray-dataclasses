/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3OMGeo.h
 * @version $Revision: 1.32 $
 * @date $Date$
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
  I3Position position_;

  /**
   * the orientation
   */
  EOrientation orientation_;

  /**
   * the quantum efficiency relative to some standard
   */
  double relativeQE_;

  /**
   * the cross-sectional area of the photocathode
   */
  double area_;

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
  virtual ~I3OMGeo();

  /**
   * @return the identity of this OM, either AMANDA or IceCube 
   */
  virtual EOMType GetOMType() const =0;

  /**
   * @return The position of this OM
   */
  const I3Position& GetPos() const { return position_;}

  /**
   * @param pos The new position for this OM
   */
  void SetPos(const I3Position& pos)
    {position_.SetPosition(pos);}
  
  /**
   * Sets the position of the OM
   * @param r1 the first coordinate set
   * @param r2 the second coordinate set
   * @param r3 the third coordinate set
   * @param frame the coordinate system used. Defaults to cartesian.
   */
  void SetPos(double r1, double r2, double r3, 
	      I3Position::RefFrame frame=I3Position::car)
    {position_.SetPosition(r1,r2,r3,frame);}
  
  /**
   * @return the orientation of the tube
   */
  EOrientation  GetOrientation() const { return orientation_; }

  /**
   * @param orientation the new orientation for the tube
   */
  void SetOrientation(EOrientation orientation) { orientation_ = orientation; }

  /**
   * This is the relative quantum efficiency of this OM.  Relative
   * to some standard.  This is the 'relative sensitivity' of the 
   * AMANDA experiment
   * @return the relative quantum efficiency of this OM
   */
  double GetRelativeQE() const {return relativeQE_;}

  /**
   * This is the relative quantum efficiency of this OM.  Relative
   * to some standard.  This is the 'relative sensitivity' of the 
   * AMANDA experiment
   * @param qe the new Relative Quantum Efficiency for this OM
   */
  void SetRelativeQE(double qe) { relativeQE_ = qe;}

  /**
   * retrieves the area of the photo cathode for this tube
   * @return the area of the photocathode
   */
  double GetArea() const { return area_;}


  /**
   * sets the photocathode area for this tube
   * @param area the new area for the photocathode
   */
  void SetArea(double area){area_ = area;}

  /**
   * @todo finish with all the data
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMGeo ]\n"
       <<" X:"
       <<position_.GetX()
       <<" Y:"
       <<position_.GetY()
		 <<" Z:"
       <<position_.GetZ()
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
  void Init() {
	  orientation_ = Unspecified;
	  relativeQE_ = 0;
  }


  //ROOT macro
  //ClassDef(I3OMGeo,1);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("position",position_);
    ar & make_nvp("orientation",orientation_);
    ar & make_nvp("relativeQE",relativeQE_);
    ar & make_nvp("area",area_);
  }

};

BOOST_IS_ABSTRACT(I3OMGeo);

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
typedef shared_ptr<I3OMGeo>  I3OMGeoPtr;

#endif

