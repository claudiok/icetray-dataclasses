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
#include "dataclasses/I3Vector.h"
#include <map>
#include <string>

using namespace std;

/**
 * @brief 
 */
class I3Particle : public I3FrameObject
{

  static int global_id_;
    
 public:

  enum ParticleType {
    unknown = -100,
    Gamma = 1,
    EPlus = 2,
    EMinus = 3,
    Nu = 4,
    MuPlus = 5,
    MuMinus = 6,
    Pi0 = 7,
    PiPlus = 8,
    PiMinus = 9,
    PPlus = 14,
    PMinus = 15,
    TauPlus = 33,
    TauMinus = 34,
    Monopole = 41,
    NuE = 201,
    NuMu = 202,
    NuTau = 203,
    NuEBar = 204,
    NuMuBar = 205,
    NuTauBar = 206,
    Brems = 1001,
    DeltaE = 1002,
    PairProd = 1003,
    NuclInt = 1004,
    MuPair = 1005,
    Hadrons = 1006,
    FiberLaser = 2100,
    N2Laser = 2101,
    YAGLaser = 2201,
    ZPrimary = 3000,
    APrimary = 3500,
    CRProton = 4001,
    CRHelium = 4004,
    CROxygen = 4016,
    CRSilicon = 4028,
    CRIron = 4056,
    Elph = 9999
  };
  enum ParticleShape { 
    Null = 0, 
    Primary = 10, 
    TopShower = 20, 
    Cascade = 30, 
    InfiniteTrack = 40, 
    StartingTrack = 50, 
    StoppingTrack = 60, 
    ContainedTrack = 70
  };

  enum FitStatus {
    NotSet = -1,
    OK = 0,
    GeneralFailure = 10,
    InsufficientHits = 20,
    FailedToConverge = 30,
    MissingSeed = 40,
    InsufficientQuality = 50
  };

  enum LocationType {
    Anywhere = 0,
    IceTop = 10,
    InIce = 20
  };

 private:

  int ID_;
  int parentID_;
  int primaryID_;
  ParticleType type_;
  ParticleShape shape_;
  FitStatus status_;
  I3Position pos_;
  I3Direction dir_;
  double time_;
  double energy_;
  double length_;
  double speed_;
  vector<I3Particle> composite_; //!
  LocationType locationType_;

 public:

  I3Particle(ParticleShape shape = Null, ParticleType type = unknown) : 
    ID_(-1),
    parentID_(-1),
    primaryID_(-1),
    type_(type),
    shape_(shape),
    status_(NotSet),
    pos_(),
    dir_(),
    time_(NAN),
    energy_(NAN),
    length_(NAN),
    speed_(I3Constants::c),
    locationType_(Anywhere)
    {ID_ = global_id_++;};
  
  virtual ~I3Particle();

  bool IsTrack() const;
  bool IsCascade() const;
  bool IsPrimary() const;
  bool IsTopShower() const;

  int GetID() const { return ID_; }
  int GetParentID() const { return parentID_; }
  int GetPrimaryID() const { return primaryID_; }

  ParticleType GetType() const { return type_; }
  void SetType(ParticleType type) { type_ = type; }
  string GetTypeString() const;

  ParticleShape GetShape() const { return shape_; }
  void SetShape(ParticleShape shape) { shape_ = shape; }
  string GetShapeString() const;

  FitStatus GetFitStatus() const { return status_; }
  void SetFitStatus(FitStatus status) { status_ = status; }
  string GetFitStatusString() const;

  LocationType GetLocationType() const { return locationType_; }
  void SetLocationType(LocationType type) { locationType_ = type; }
  string GetLocationTypeString() const;

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

  double GetTime() const { return time_; }
  void SetTime(double t) { time_ = t; }

  double GetLength() const { return length_; }
  void SetLength(double length) { length_ = length; }

  double GetEnergy() const { return energy_; }
  void SetEnergy(double energy) { energy_ = energy; }

  double GetSpeed() const { return speed_; }
  void SetSpeed(double s) { speed_ = s; }

  const vector<I3Particle>& GetComposite() const { return composite_; }
  void ClearComposite() { composite_.clear(); }

  I3Position ShiftAlongTrack(double dist) const;

  I3Position GetStartPos() const;

  double GetStartTime() const;

  I3Position GetStopPos() const;

  double GetStopTime() const;


 private:

  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);

};

I3_POINTER_TYPEDEFS(I3Particle);
BOOST_CLASS_VERSION(I3Particle,1);

typedef I3Vector<I3Particle> I3ParticleVect;
I3_POINTER_TYPEDEFS(I3ParticleVect);

#endif 


