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
static const unsigned i3particle_version_ = 4;

namespace RDMCParticleTypes{
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
    KPlus = 11,
    KMinus = 12,
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
};

/**
 * @brief 
 */
class I3Particle : public I3FrameObject
{

  static int global_minor_id_;
  static uint64_t global_major_id_;
    
 public:

  enum ParticleType {
    unknown = 0,
    Gamma = 1,
    EPlus = 2,
    EMinus = 3,
    MuPlus = 5,
    MuMinus = 6,
    Pi0 = 7,
    PiPlus = 8,
    PiMinus = 9,
    K0_Long = 10,
    KPlus = 11,
    KMinus = 12,
    Neutron = 13,
    PPlus = 14,
    PMinus = 15,
    K0_Short = 16,
    NuE = 66,
    NuEBar = 67,
    NuMu = 68,
    NuMuBar = 69,
    TauPlus = 131,
    TauMinus = 132,
    NuTau = 133,
    NuTauBar = 134,
    /**
     * In CORSIKA nuclei numbers
     * are A x 100 + Z 
     */
    He4Nucleus = 402,
    Li7Nucleus = 703,
    Be9Nucleus = 904,
    B11Nucleus = 1105,
    C12Nucleus = 1206,
    N14Nucleus = 1407,
    O16Nucleus = 1608,
    F19Nucleus = 1909,
    Ne20Nucleus = 2010,
    Na23Nucleus = 2311,
    Mg24Nucleus = 2412,
    Al27Nucleus = 2713,
    Si28Nucleus = 2814,
    P31Nucleus = 3115,
    S32Nucleus = 3216,
    Cl35Nucleus = 3517,
    Ar40Nucleus = 4018,
    K39Nucleus = 3919,
    Ca40Nucleus = 4020,
    Sc45Nucleus = 4521,
    Ti48Nucleus = 4822,
    V51Nucleus = 5123,
    Cr52Nucleus = 5224,
    Mn55Nucleus = 5525,
    Fe56Nucleus = 5626,
    CherenkovPhoton = 9900,
    /**
     *Particle types not in CORSIKA
     */
    Nu = -4,
    Monopole = -41,
    Brems = -1001,
    DeltaE = -1002,
    PairProd = -1003,
    NuclInt = -1004,
    MuPair = -1005,
    Hadrons = -1006,
    FiberLaser = -2100,
    N2Laser = -2101,
    YAGLaser = -2201,
    /**
     * Make SUSY partners -(9000 + SM_number)
     */
    STauPlus = -9131,
    STauMinus = -9132
  };

  enum ParticleShape { 
    Null = 0, 
    Primary = 10, 
    TopShower = 20, 
    Cascade = 30, 
    InfiniteTrack = 40, 
    StartingTrack = 50, 
    StoppingTrack = 60, 
    ContainedTrack = 70,
    MCTrack = 80,
    Dark = 90
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
  uint64_t major_ID_;
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
  double weight_;
  vector<I3Particle> composite_; //!
  LocationType locationType_;

 public:

  I3Particle(ParticleShape shape = Null, ParticleType type = unknown);
  
  virtual ~I3Particle();

  bool IsTrack() const;
  bool IsCascade() const;
  bool IsPrimary() const;
  bool IsTopShower() const;
  bool IsNeutrino() const;

  bool HasPosition() const;
  bool HasDirection() const;
  bool HasEnergy() const;

  int GetID() const { 
    log_warn("I3Particle::GetID is deprecated.  Please use I3Particle::GetMinorID.");
    return ID_; 
  }
  int GetMinorID() const { return ID_; }
  uint64_t GetMajorID() const { return major_ID_; }

  int GetParentID() const { return parentID_; }
  int GetPrimaryID() const { return primaryID_; }

  ParticleType GetType() const { return type_; }
  void SetType(ParticleType type) { type_ = type; }
  void SetRDMCType(int type) { type_ = convert_rdmc(type); }
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

  double GetWeight() const { return weight_; }
  void SetWeight(double w) { weight_ = w; }

  const vector<I3Particle>& GetComposite() const { return composite_; }
  vector<I3Particle>& GetComposite() { return composite_; }

  I3Position ShiftAlongTrack(double dist) const;

  I3Position GetStartPos() const;

  double GetStartTime() const;

  I3Position GetStopPos() const;

  double GetStopTime() const;


 private:

  friend class boost::serialization::access;
  template <class Archive> void save(Archive & ar, unsigned version) const;
  template <class Archive> void load(Archive & ar, unsigned version);
  BOOST_SERIALIZATION_SPLIT_MEMBER();

  ParticleType convert_rdmc(int) const ;

};

bool operator==(const I3Particle& lhs, const I3Particle& rhs);

I3_POINTER_TYPEDEFS(I3Particle);
BOOST_CLASS_VERSION(I3Particle,i3particle_version_);

typedef I3Vector<I3Particle> I3ParticleVect;
I3_POINTER_TYPEDEFS(I3ParticleVect);

#endif 


