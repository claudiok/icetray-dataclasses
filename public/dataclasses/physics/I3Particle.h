/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id$
    @file I3Particle.h
    @date $Date$
*/

#ifndef I3PARTICLE_H_INCLUDED
#define I3PARTICLE_H_INCLUDED

#include "dataclasses/I3Position.h"
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Units.h"
#include <TObject.h>
#include <map>
#include <string>

/**
 * @brief 
 */
class I3Particle : public TObject
{
    
 public:

  enum ParticleID { null, e, mu };
  enum ParticleType { Null, Primary, TopShower, Cascade, InfiniteTrack, 
		      StartingTrack, StoppingTrack, ContainedTrack };

  I3Particle() : 
    number_(-1),
    parentID_(-1),
    primID_(-1),
    id_(null),
    type_(Null),
    pos_(),
    dir_(),
    time_(NAN),
    energy_(NAN),
    length_(NAN),
    speed_(I3Constants::c)
    {};
  
  virtual ~I3Particle();

  const int GetParticleNumber() const { return number_; }
  void SetParticleNumber(int number) { number_ = number; }

  const int GetParentID() const { return parentID_; }
  void SetParentID(int id) { parentID_ = id; }

  const int GetPrimaryID() const { return primID_; }
  void SetPrimaryID(int id) { primID_ = id; }

  const ParticleID GetParticleID() const { return id_; }
  void SetParticleID(ParticleID id) { id_ = id; }

  const ParticleType GetParticleType() const { return type_; }
  void SetType(ParticleType type) { type_ = type; }

  const I3Position& GetPos() const { return pos_; }
  void SetPos(const I3Position& p) { pos_.SetPosition(p); }
  void SetPos(double p1, double p2, double p3, 
	      I3Position::RefFrame frame=I3Position::car)
    { pos_.SetPosition(p1,p2,p3,frame); }

  const I3Direction& GetDir() const { return dir_; }
  void SetDir(const I3Direction& d) { dir_.SetDirection(d); }
  void SetDir(double zen, double azi) { dir_.SetDirection(zen,azi); }
  void SetDir(double x, double y, double z) 
    { dir_.SetDirection(x,y,z); }

  void SetThetaPhi(double theta, double phi) { dir_.SetThetaPhi(theta,phi); }

  double GetZenith() const { return dir_.GetZenith(); }
  double GetAzimuth() const { return dir_.GetAzimuth(); }
  double GetX() const { return pos_.GetX(); }
  double GetY() const { return pos_.GetY(); }
  double GetZ() const { return pos_.GetZ(); }

  double GetT() const { return time_; }
  void SetT(double t) { time_ = t; }

  double GetLength() const { return length_; }
  void SetLength(double length) { length_ = length; }

  double GetEnergy() const { return energy_; }
  void SetEnergy(double energy) { energy_ = energy; }

  double GetSpeed() const { return speed_; }
  void SetSpeed(double s) { speed_ = s; }

  const map<string,double>& GetParameters() const { return user_; }
  map<string,double>& GetParameters() { return user_; }

  const vector<I3Particle>& GetComposite() const { return composite_; }
  vector<I3Particle>& GetComposite() { return composite_; }

  I3Position GetStartPos() const { 
    if (type_==StartingTrack || type_==ContainedTrack) return pos_;
    else {
      I3Position nullpos;
      return nullpos;
    }
  }
  double GetStartT() const {
    if (type_==StartingTrack || type_==ContainedTrack) return time_;
    else return NAN;
  }

  I3Position GetStopPos() const {
    if (type_==StoppingTrack) return pos_;
    else if (type_==ContainedTrack) {
      double x = GetX() - length_ * sin(GetZenith()) * cos(GetAzimuth());
      double y = GetY() - length_ * sin(GetZenith()) * sin(GetAzimuth());
      double z = GetZ() - length_ * cos(GetZenith());
      I3Position stoppos(x,y,z,I3Position::car);
      return stoppos;
    }
    else {
      I3Position nullpos;
      return nullpos;
    }
  }
  double GetStopT() const { 
    if (type_==StoppingTrack) return time_;
    else if (type_==ContainedTrack) { return time_ + length_/speed_; }
    else return NAN;
  }

  void ToStream(ostream& o) const;

 private:

  int number_;
  int parentID_;
  int primID_;
  ParticleID id_;
  ParticleType type_;
  I3Position pos_;
  I3Direction dir_;
  double time_;
  double energy_;
  double length_;
  double speed_;
  map<string,double> user_; //!
  vector<I3Particle> composite_; //!

  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);

  ClassDef(I3Particle,1);
};

I3_POINTER_TYPEDEFS(I3Particle);

#endif 

