/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3ContainedTrack.h 15192 2006-02-02 01:02:05Z dule $
    @file I3ContainedTrack.h
    @date $Date: 2006-02-01 20:02:05 -0500 (Wed, 01 Feb 2006) $
*/

#ifndef I3CONTAINEDTRACK_H_INCLUDED
#define I3CONTAINEDTRACK_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Direction.h"
//#include <TObject.h>
#include <map>
#include <string>

/**
 * @brief Track is for vanilla track (i.e. not cascade)
 * particles.  No starting, stopping points, no energy, etc.
  */
class I3ContainedTrack : public I3Particle
{
 public:

  I3ContainedTrack() : 
    startPos_(),
    dir_(),
    time_(NAN),
    energy_(NAN),
    length_(NAN)
    {};
  
  virtual ~I3ContainedTrack();

  double GetT() const {return time_;}

  void SetT(double t){time_ = t;}

  const I3Position& GetPos() const {return startPos_;}

  void SetStartPos(const I3Position& p) {startPos_.SetPosition(p);}

  void SetStartPos(double p1, double p2, double p3, 
	      I3Position::RefFrame frame=I3Position::car)
    {startPos_.SetPosition(p1,p2,p3,frame);}

  const I3Direction& GetDir() const {return dir_;}

  void SetDir(const I3Direction& d) {dir_.SetDirection(d);}

  void SetDir(double zen, double azi) {dir_.SetDirection(zen,azi);}

  void SetDir(double x, double y, double z) 
    {dir_.SetDirection(x,y,z);}

  void SetThetaPhi(double theta, double phi) {dir_.SetThetaPhi(theta,phi);}

  double GetZenith() const {return dir_.GetZenith();}

  double GetAzimuth() const {return dir_.GetAzimuth();}

  void SetZenith(double zen) {
    dir_.SetDirection(zen,dir_.GetAzimuth());}

  void SetAzimuth(double azi) {
    dir_.SetDirection(dir_.GetZenith(),azi);}

  double GetLength() const {return length_;}

  void SetLength(double length) {length_ = length;}

  double GetEnergy() const {return energy_;}

  void SetEnergy(double energy) { energy_ = energy;}

  const map<string,double>& GetUserParameters() const {return user_;}

  map<string,double>& GetUserParameters(){return user_;}

  void ToStream(ostream& o) const;

 private:

  I3Position startPos_;
  I3Direction dir_;
  double time_;
  double energy_;
  double length_;
  map<string,double> user_; //!
     

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3ContainedTrack);

#endif //I3BASICTRACK_H_INCLUDED


