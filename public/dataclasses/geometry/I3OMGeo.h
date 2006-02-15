/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3OMGeo.h
 * @date $Date$
 */

#ifndef I3OMGEO_H_INCLUDED
#define I3OMGEO_H_INCLUDED

#include <TObject.h>
#include "dataclasses/I3Position.h"
#include <TClass.h>
#include <string>
#include <iostream>
#include <sstream>
#include "dataclasses/OMKey.h"
#include "dataclasses/Utility.h"

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
  enum Orientation {Unspecified,Up,Down};

  /**
   * An enumerated type for the possible kinds of OMs
   */
  enum OMType {AMANDA,IceCube,IceTop};

 protected:
  /**
   * the position
   */
  I3Position position_;

  /**
   * the orientation
   */
  Orientation orientation_;

  /**
   * the type (AMANDA or IceCube)
   */
  OMType type_;

  /**
   * the quantum efficiency relative to some standard
   */
  double relativeQE_;

  /**
   * the cross-sectional area of the photocathode
   */
  double area_;

 public:

  I3OMGeo() { Init();}

   /**
   * copy constructor just uses assignment
   */
  I3OMGeo(const I3OMGeo& rhs){*this = rhs;}

  virtual ~I3OMGeo();

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
  Orientation  GetOrientation() const { return orientation_; }

  /**
   * @param orientation the new orientation for the tube
   */
  void SetOrientation(Orientation orientation) { orientation_ = orientation; }

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

  void SetOMType(OMType type)
    {
      type_ = type;
    }

  OMType GetOMType() const 
    {
      return type_;
    }



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
  void serialize(Archive& ar, unsigned version);

};

/**
 * streams an I3OMGeo to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3OMGeo& g)
{
  g.ToStream(o); 
  return o;
}

I3_POINTER_TYPEDEFS(I3OMGeo);

#endif //I3OMGEO_H_INCLUDED

