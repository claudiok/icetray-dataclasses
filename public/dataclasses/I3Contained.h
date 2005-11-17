/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Contained.h
 * @version $Revision: 1.23 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include "I3Position.h"
#include "dataclasses/I3Particle.h"
#include "I3Direction.h"
#include "I3Constants.h"
#include <cmath>
/**
 * @brief This class services the 'geometrical' part of an I3Track interface.
 *
 * Has a starting postion, a length, and a direction.  So the full interface
 * is implemented.  Assumes the particle is relativistic.
 */
class I3Contained
{
 private:
  I3Position startPos_;
  mutable I3Position stopPos_;
  mutable bool calculateStopPos_;
  I3Direction dir_;
  double startT_;
  double length_;

 public:

  /**
   * default constructor.
   */
  I3Contained() : calculateStopPos_(true) {}

  /**
   * destructor.
   */
  virtual ~I3Contained();

  /**
   * indicates that the track is starting
   */
  bool IsStarting() const {return true;}

  /**
   * indicates that the track is stopping
   */
  bool IsStopping() const {return true;}

  /**
   * indicates that the track has a direction
   */
  bool HasDirection() const {return true;}

  /**
   * gets the starting time
   */
  double GetStartT() const {return startT_;}

  /**
   * sets the starting time
   */
  void SetStartT(double startt) {startT_ = startt;}

  /**
   * gets the starting position
   */
  const I3Position& GetStartPos() const {return startPos_;}

  /**
   * sets the starting position
   */
  void SetStartPos(const I3Position& p)
  {
    startPos_ = p;
    calculateStopPos_ = true;
  }

  /**
   * sets the starting position in any reference frame
   */
  void SetStartPos(double startp1, double startp2, double startp3,
  I3Position::RefFrame frame=I3Position::car)
  {
    startPos_.SetPosition(startp1,startp2,startp3,frame);
    calculateStopPos_ = true;
  }

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  double GetT() const {return startT_;}

  /**
   * gives the starting positition as a position on the track
   */
  const I3Position& GetPos() const {return startPos_;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(const I3Position& p)
  {
    startPos_ = p;
    calculateStopPos_ = true;
  }

  /**
   * sets the starting position as a position along the track
   * in any reference frame
   */
  void SetPos(double startp1, double startp2, double startp3, 
  I3Position::RefFrame frame=I3Position::car)
  {
    startPos_.SetPosition(startp1,startp2,startp3,frame);
    calculateStopPos_ = true;
  }

  /**
   * gets the direction of the track
   */
  const I3Direction& GetDir() const {return dir_;}

  /**
   * sets the direction of the track
   */
  void SetDir(const I3Direction& d)
  {
    dir_.SetDirection(d);
    calculateStopPos_ = true;
  }

  /**
   * sets the direction of the track
   */
  void SetDir(double zen, double azi)
  {
    dir_.SetDirection(zen,azi);
    calculateStopPos_ = true;
  }

  /**
   * sets the direction of the track
   */
  void SetDir(double x, double y, double z)
  {
    dir_.SetDirection(x,y,z);
    calculateStopPos_ = true;
  }

  /**
   * gives the zenith of the track
   */
  double GetZenith() const {return dir_.GetZenith();}

  /**
   * gives the azimuth of the track
   */
  double GetAzimuth() const {return dir_.GetAzimuth();}

  /**
   * sets the zenith of the track
   */
  void SetZenith(double zen)
  {
    dir_.SetDirection(zen,dir_.GetAzimuth());
    calculateStopPos_ = true;
  }

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(double azi)
  {
    dir_.SetDirection(dir_.GetZenith(),azi);
    calculateStopPos_ = true;
  }

  /**
   * gives the length of the track
   */
  double GetLength() const {return length_;}

  /**
   * sets the length of the track
   */
  void SetLength(double length)
  {
    length_ = length;
    calculateStopPos_ = true;
  }

  /**
   * computes the stopping t of the track
   */
  double GetStopT() const 
    {
      return startT_ + length_ / GetSpeed();
    }
  
  /**
   * computes the stopping position of the track
   */
  const I3Position& GetStopPos() const
  {
    if(calculateStopPos_)
    {
      double x=startPos_.GetX()-length_*sin(dir_.GetZenith())*cos(dir_.GetAzimuth());
      double y=startPos_.GetY()-length_*sin(dir_.GetZenith())*sin(dir_.GetAzimuth());
      double z=startPos_.GetZ()-length_*cos(dir_.GetZenith());
      // According to IceCube angle definitions, zenith and azimuth are
      // defined for the minus track direction, i.e. where the track came from
      // This means that there is a minus sign in the calculations.
      stopPos_.SetPosition(x,y,z,I3Position::car);
      // use I3Distance::ShiftAlongTrack(this, length_) ???
      calculateStopPos_ = false;
    }
    return stopPos_;
  }

  /**
   * returns the speed of light
   */
  double GetSpeed() const {return I3Constants::c;}

  /**
   * copies all the interal data into destination if a dynamic cast
   * to I3Contained succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Contained* contained = dynamic_cast<I3Contained*>(&destination);
      if(contained){
	contained->startPos_ = startPos_;
	contained->dir_ = dir_;
	contained->startT_ = startT_;
	contained->length_ = length_;
  contained->calculateStopPos_ = true;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Contained\n"
       <<"StartPosition:\n"<<GetStopPos()
       <<"StopPosition:\n"<<stopPos_
       <<"Direction:\n"<<dir_
       <<"StartTime: "<<startT_<<"\n"
       <<"StopTime: "<<GetStopT()<<"\n";
    }

  private:
  friend class boost::serialization::access;

  template <class Archive>
  void save(Archive& ar, unsigned version) const
  {
    ar & make_nvp("StartPos", startPos_ );
    ar & make_nvp("Dir", dir_ );
    ar & make_nvp("StartT", startT_ );
    ar & make_nvp("Length", length_ );
  }

  template <class Archive>
  void load(Archive& ar, unsigned version)
  {
    ar & make_nvp("StartPos", startPos_ );
    ar & make_nvp("Dir", dir_ );
    ar & make_nvp("StartT", startT_ );
    ar & make_nvp("Length", length_ );
    
    calculateStopPos_ = true;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
  
  //ROOT macro
  //ClassDef(I3Contained,2)
};

#endif //I3CONTAINED_H
