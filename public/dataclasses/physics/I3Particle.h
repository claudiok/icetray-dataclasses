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
#include "icetray/I3Units.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/physics/I3ParticleID.h"
#include <map>
#include <string>

#ifndef __CINT__
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <boost/bimap/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#endif

static const unsigned i3particle_version_ = 5;

// let other code know that I3Particle stores PDG encodings internally
#define I3PARTICLE_SUPPORTS_PDG_ENCODINGS

/**
 * List the names of enumeration members defined in this file
 * here. These can be used for e.g. pybindings, which require
 * the names of the enumeration members to be known. This list
 * should be updated whenver members or new enums are added to
 * the class.
 */
#define I3PARTICLE_H_RDMCParticleTypes_ParticleType                               \
    (unknown)(Gamma)(EPlus)(EMinus)(Nu)(MuPlus)(MuMinus)(Pi0)(PiPlus)(PiMinus)    \
    (KPlus)(KMinus)(PPlus)(PMinus)(TauPlus)(TauMinus)(Monopole)(NuE)(NuMu)        \
    (NuTau)(NuEBar)(NuMuBar)(NuTauBar)(Brems)(DeltaE)(PairProd)(NuclInt)(MuPair)  \
    (Hadrons)(FiberLaser)(N2Laser)(YAGLaser)(ZPrimary)(APrimary)(CRProton)        \
    (CRHelium)(CROxygen)(CRSilicon)(CRIron)(Elph)

#define I3PARTICLE_H_I3Particle_ParticleType                                      \
    (UnknownWithPdgEncoding)(unknown)(Gamma)(EPlus)(EMinus)(MuPlus)(MuMinus)(Pi0) \
    (PiPlus)(PiMinus)(K0_Long)(KPlus)(KMinus)(Neutron)(PPlus)(PMinus)(K0_Short)   \
    (Eta)(Lambda)(SigmaPlus)(Sigma0)(SigmaMinus)(Xi0)(XiMinus)(OmegaMinus)        \
    (NeutronBar)(LambdaBar)(SigmaMinusBar)(Sigma0Bar)(SigmaPlusBar)(Xi0Bar)       \
    (XiPlusBar)(OmegaPlusBar)(DPlus)(DMinus)(D0)(D0Bar)(DsPlus)(DsMinusBar)       \
    (LambdacPlus)(WPlus)(WMinus)(Z0)(NuE)(NuEBar)                                 \
    (NuMu)(NuMuBar)(TauPlus)(TauMinus)(NuTau)(NuTauBar)                           \
    (He3Nucleus)(He4Nucleus)(Li6Nucleus)(Li7Nucleus)(Be9Nucleus)(B10Nucleus)      \
    (B11Nucleus)(C12Nucleus)(C13Nucleus)(N14Nucleus)(N15Nucleus)(O16Nucleus)      \
    (O17Nucleus)(O18Nucleus)(F19Nucleus)(Ne20Nucleus)(Ne21Nucleus)(Ne22Nucleus)   \
    (Na23Nucleus)(Mg24Nucleus)(Mg25Nucleus)(Mg26Nucleus)(Al26Nucleus)(Al27Nucleus)\
    (Si28Nucleus)(Si29Nucleus)(Si30Nucleus)(Si31Nucleus)(Si32Nucleus)(P31Nucleus) \
    (P32Nucleus)(P33Nucleus)(S32Nucleus)(S33Nucleus)(S34Nucleus)(S35Nucleus)      \
    (S36Nucleus)(Cl35Nucleus)(Cl36Nucleus)(Cl37Nucleus)(Ar36Nucleus)(Ar37Nucleus) \
    (Ar38Nucleus)(Ar39Nucleus)(Ar40Nucleus)(Ar41Nucleus)(Ar42Nucleus)(K39Nucleus) \
    (K40Nucleus)(K41Nucleus)(Ca40Nucleus)(Ca41Nucleus)(Ca42Nucleus)(Ca43Nucleus)  \
    (Ca44Nucleus)(Ca45Nucleus)(Ca46Nucleus)(Ca47Nucleus)(Ca48Nucleus)(Sc44Nucleus)\
    (Sc45Nucleus)(Sc46Nucleus)(Sc47Nucleus)(Sc48Nucleus)(Ti44Nucleus)(Ti45Nucleus)\
    (Ti46Nucleus)(Ti47Nucleus)(Ti48Nucleus)(Ti49Nucleus)(Ti50Nucleus)(V48Nucleus) \
    (V49Nucleus)(V50Nucleus)(V51Nucleus)(Cr50Nucleus)(Cr51Nucleus)(Cr52Nucleus)   \
    (Cr53Nucleus)(Cr54Nucleus)(Mn52Nucleus)(Mn53Nucleus)(Mn54Nucleus)(Mn55Nucleus)\
    (Fe54Nucleus)(Fe55Nucleus)(Fe56Nucleus)(Fe57Nucleus)(Fe58Nucleus)             \
    (CherenkovPhoton)(Nu)(Monopole)(Brems)(DeltaE)(PairProd)(NuclInt)(MuPair)     \
    (Hadrons)(ContinuousEnergyLoss)(FiberLaser)(N2Laser)(YAGLaser)                \
    (STauPlus)(STauMinus)

#define I3PARTICLE_H_I3Particle_ParticleShape                                     \
    (Null)(Primary)(TopShower)(Cascade)(InfiniteTrack)(StartingTrack)             \
    (StoppingTrack)(ContainedTrack)(MCTrack)(Dark)
    
#define I3PARTICLE_H_I3Particle_FitStatus                                         \
    (NotSet)(OK)(GeneralFailure)(InsufficientHits)(FailedToConverge)              \
    (MissingSeed)(InsufficientQuality)

#define I3PARTICLE_H_I3Particle_LocationType                                      \
    (Anywhere)(IceTop)(InIce)(InActiveVolume)

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
 public:

  enum ParticleType {
    UnknownWithPdgEncoding = -1,  
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
    Eta = 17,
    Lambda = 18,
    SigmaPlus = 19,
    Sigma0 = 20,
    SigmaMinus = 21,
    Xi0 = 22,
    XiMinus = 23,
    OmegaMinus = 24,
    NeutronBar = 25, // as found in "topsimulator"
    LambdaBar = 26,
    SigmaMinusBar = 27,
    Sigma0Bar = 28,
    SigmaPlusBar = 29,
    Xi0Bar = 30,
    XiPlusBar = 31,
    OmegaPlusBar = 32,
    DPlus = 35,
    DMinus = 36,
    D0 = 37,
    D0Bar = 38,
    DsPlus = 39,
    DsMinusBar = 40,
    LambdacPlus = 41,
    WPlus = 42,
    WMinus = 43,
    Z0 = 44,
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
     * (not all of those are actually stable,
     * they are included here for compatibility
     * with software that might have generated
     * them by casting ParticleType to int)
     */
    He3Nucleus = 302,
    He4Nucleus = 402,
    Li6Nucleus = 603,
    Li7Nucleus = 703,
    Be9Nucleus = 904,
    B10Nucleus = 1005,
    B11Nucleus = 1105,
    C12Nucleus = 1206,
    C13Nucleus = 1306,
    N14Nucleus = 1407,
    N15Nucleus = 1507,
    O16Nucleus = 1608,
    O17Nucleus = 1708,
    O18Nucleus = 1808,
    F19Nucleus = 1909,
    Ne20Nucleus = 2010,
    Ne21Nucleus = 2110,
    Ne22Nucleus = 2210,
    Na23Nucleus = 2311,
    Mg24Nucleus = 2412,
    Mg25Nucleus = 2512,
    Mg26Nucleus = 2612,
    Al26Nucleus = 2613,
    Al27Nucleus = 2713,
    Si28Nucleus = 2814,
    Si29Nucleus = 2914,
    Si30Nucleus = 3014,
    Si31Nucleus = 3114,
    Si32Nucleus = 3214,
    P31Nucleus = 3115,
    P32Nucleus = 3215,
    P33Nucleus = 3315,
    S32Nucleus = 3216,
    S33Nucleus = 3316,
    S34Nucleus = 3416,
    S35Nucleus = 3516,
    S36Nucleus = 3616,
    Cl35Nucleus = 3517,
    Cl36Nucleus = 3617,
    Cl37Nucleus = 3717,
    Ar36Nucleus = 3618,
    Ar37Nucleus = 3718,
    Ar38Nucleus = 3818,
    Ar39Nucleus = 3918,
    Ar40Nucleus = 4018,
    Ar41Nucleus = 4118,
    Ar42Nucleus = 4218,
    K39Nucleus = 3919,
    K40Nucleus = 4019,
    K41Nucleus = 4119,
    Ca40Nucleus = 4020,
    Ca41Nucleus = 4120,
    Ca42Nucleus = 4220,
    Ca43Nucleus = 4320,
    Ca44Nucleus = 4420,
    Ca45Nucleus = 4520,
    Ca46Nucleus = 4620,
    Ca47Nucleus = 4720,
    Ca48Nucleus = 4820,
    Sc44Nucleus = 4421,
    Sc45Nucleus = 4521,
    Sc46Nucleus = 4621,
    Sc47Nucleus = 4721,
    Sc48Nucleus = 4821,
    Ti44Nucleus = 4422,
    Ti45Nucleus = 4522,
    Ti46Nucleus = 4622,
    Ti47Nucleus = 4722,
    Ti48Nucleus = 4822,
    Ti49Nucleus = 4922,
    Ti50Nucleus = 5022,
    V48Nucleus = 4823,
    V49Nucleus = 4923,
    V50Nucleus = 5023,
    V51Nucleus = 5123,
    Cr50Nucleus = 5024,
    Cr51Nucleus = 5124,
    Cr52Nucleus = 5224,
    Cr53Nucleus = 5324,
    Cr54Nucleus = 5424,
    Mn52Nucleus = 5225,
    Mn53Nucleus = 5325,
    Mn54Nucleus = 5425,
    Mn55Nucleus = 5525,
    Fe54Nucleus = 5426,
    Fe55Nucleus = 5526,
    Fe56Nucleus = 5626,
    Fe57Nucleus = 5726,
    Fe58Nucleus = 5826,
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
    ContinuousEnergyLoss = -1111, // special type used by MMC with the -recc option
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
    InIce = 20,
    InActiveVolume = 30
  };

 private:

  I3ParticleID ID_;
  int32_t pdgEncoding_; // this replaces ParticleType
  ParticleShape shape_;
  FitStatus status_;
  I3Position pos_;
  I3Direction dir_;
  double time_;
  double energy_;
  double length_;
  double speed_;
  LocationType locationType_;

 public:
  /** @brief Constructor for a simple particle with generated ID
   * useful in applications where the exact nature of an particle are in focus
   * @param shape Shape of the track
   * @param type Particle type
  */
  I3Particle(ParticleShape shape = Null, ParticleType type = unknown);
  /** @brief Constructor for particle as a unique identifier by majorID and minorID
   * useful in iteration processes (in I3MCTree) where unique tagging is required
   * @param major MajorID of that particle
   * @param minor MinorID of that particle
   */
#ifndef __CINT__
  I3Particle(const I3Position pos, const I3Direction dir, const double vertextime, 
             ParticleShape shape = Null, double length=NAN);
#else
  I3Particle(const I3Position pos, const I3Direction dir, const double vertextime, 
             ParticleShape shape, double length);
#endif

  virtual ~I3Particle();

  bool IsTrack() const;
  bool IsCascade() const;
  bool IsPrimary() const;
  bool IsTopShower() const;
  bool IsNeutrino() const;
  bool IsNucleus() const;

  bool HasPosition() const;
  bool HasDirection() const;
  bool HasEnergy() const;

  operator I3ParticleID() const{ return ID_; }
	
  I3ParticleID GetID() const { return ID_; }
  int32_t GetMinorID() const { return ID_.minorID; }
  uint64_t GetMajorID() const { return ID_.majorID; }

  int32_t GetPdgEncoding() const { return pdgEncoding_; }
  void SetPdgEncoding(int32_t newid) { pdgEncoding_=newid; }
    
  ParticleType GetType() const;
  std::string GetTypeString() const;

  void SetType(ParticleType type);
  void SetRDMCType(int type);
  void SetTypeString(const std::string &str);

  ParticleShape GetShape() const { return shape_; }
  std::string GetShapeString() const;
  void SetShape(ParticleShape shape) { shape_ = shape; }
  void SetShapeString(const std::string &str);

  FitStatus GetFitStatus() const { return status_; }
  std::string GetFitStatusString() const;
  void SetFitStatus(FitStatus status) { status_ = status; }
  void SetFitStatusString(const std::string &str);

  LocationType GetLocationType() const { return locationType_; }
  std::string GetLocationTypeString() const;
  void SetLocationType(LocationType type) { locationType_ = type; }
  void SetLocationTypeString(const std::string &str);

  const I3Position& GetPos() const { return pos_; }
  void SetPos(const I3Position& p) { pos_=p; }
  void SetPos(double p1, double p2, double p3, 
	      I3Position::RefFrame frame)
    { pos_=I3Position(p1,p2,p3,frame); }
  void SetPos(double x, double y, double z)
    { pos_=I3Position(x,y,z); }

  const I3Direction& GetDir() const { return dir_; }
  void SetDir(const I3Direction& d) { dir_=d; }
  void SetDir(double zen, double azi) { dir_=I3Direction(zen,azi); }
  void SetDir(double x, double y, double z) 
    { dir_=I3Direction(x,y,z); }

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

  I3Position ShiftAlongTrack(double dist) const;

  I3Position GetStartPos() const;

  double GetStartTime() const;

  I3Position GetStopPos() const;

  double GetStopTime() const;

 private:

  I3Particle(const uint64_t major, const int32_t minor);
  /** @brief Constructor for a track or ray
   * useful in reconstruction representations, where rather the position and directionality of the particle are in focus
   * @param pos Position of the vertex
   * @param dir Direction of the track
   * @param vertextime time that the vertex is happening
   * @param shape Shape of the track
   * @param type Particle type
   */
  friend class I3Stochastic;
	 
  friend class boost::serialization::access;
  template <class Archive> void save(Archive & ar, unsigned version) const;
  template <class Archive> void load(Archive & ar, unsigned version);
  BOOST_SERIALIZATION_SPLIT_MEMBER();

  ParticleType convert_rdmc(int) const ;

#ifndef __CINT__
  // conversion from ParticleType to pdgEncoding and vice versa
  typedef boost::bimaps::bimap<boost::bimaps::multiset_of<ParticleType>, boost::bimaps::multiset_of<int32_t> > toPdgEncodingConversionTable_t;
  static const toPdgEncodingConversionTable_t toPdgEncodingConversionTable_;
#endif
    
 public:
    
  static ParticleType ConvertFromPdgEncoding(int32_t);
  static int32_t ConvertToPdgEncoding(ParticleType);

};

#ifndef __CINT__
// template specialization for XML i/o
template<> void I3Particle::save(boost::archive::xml_oarchive& ar, unsigned version) const;
template<> void I3Particle::load(boost::archive::xml_iarchive& ar, unsigned version);
#endif

bool operator==(const I3Particle& lhs, const I3Particle& rhs);

std::ostream& operator<<(std::ostream& oss, const I3Particle& d);

I3_POINTER_TYPEDEFS(I3Particle);
BOOST_CLASS_VERSION(I3Particle,i3particle_version_);

typedef I3Vector<I3Particle> I3ParticleVect;
I3_POINTER_TYPEDEFS(I3ParticleVect);

#endif 


