#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>
#include <TRefArray.h>

class I3Track : public TObject
{
 public:
  /**
   * A typedef so that we can have a custom Track type.
   */
  typedef Int_t Type;

  /**
   * null particle
   */
  static const Type Null;

  /**
   * unknown particle
   */
  static const Type Unknown;

  /**
   * gamma
   */
  static const Type Gamma;

  /**
   * e+ particle
   */
  static const Type EPlus;

  /**
   * e- particle
   */
  static const Type EMinus;

  /**
   * nu particle
   */
  static const Type Nu;

  /**
   * mu+ particle
   */
  static const Type MuPlus;

  /**
   * mu- particle 
   */
  static const Type MuMinus;

  /**
   * pi0 particle
   */
  static const Type Pi0; 

  /**
   * pi+ particle
   */
  static const Type PiPlus;

  /**
   * pi- particle
   */
  static const Type PiMinus;

  /**
   * proton particle
   */
  static const Type PPlus;

  /**
   * antiproton particle
   */
  static const Type PMinus;

  /**
   * tau+ particle
   */
  static const Type TauPlus;

  /**
   * tau- particle
   */
  static const Type TauMinus;

  /**
   * e neutrino particle
   */
  static const Type NuE;

  /**
   * mu neutrino particle
   */
  static const Type NuMu;

  /**
   * tau neutrino particle
   */
  static const Type NuTau;

  /**
   * e bar neutrino particle
   */
  static const Type NuEBar;

  /**
   * mu bar neutrino particle
   */
  static const Type NuMuBar;

  /**
   * tau bar neutrino particle
   */
  static const Type NuTauBar;

  /**
   * Brems particle
   */
  static const Type Brems;

  /**
   * Delta electron particle
   */
  static const Type DeltaE;

  /**
   * Pair Production particle
   */
  static const Type PairProd;

  /**
   * Nuclear interaction
   */
  static const Type NuclInt;

  /**
   * muon pair particle
   */
  static const Type MuPair;

  /**
   * Hadrons particle
   */
  static const Type Hadrons;

  /**
   * fiber laser (AMANDA calibration laser)
   */
  static const Type FiberLaser;

  /**
   * N2 laser 
   */
  static const Type N2Laser;

  /**
   * YAG laser
   */
  static const Type YAGLaser;

  /**
   * CRPrimary starting value in Z
   */
  static const Type ZPrimary;

  /**
   * CR Primary starting value in A
   */
  static const Type APrimary;

  /**
   * Elphantino particle
   */
  static const Type Elph;


  unsigned short tracknumber;
  Type           particleid;
  float          starttime;
  float          startx;
  float          starty;
  float          startz;
  float          stoptime;
  float          stopx;
  float          stopy;
  float          stopz;
  float          length;
  float          zenith;
  float          azimuth;
  float          energy;
  TRef           parenttrack;
  TRefArray      *childrentrack;

  public:
           I3Track();
  virtual ~I3Track();
    
  unsigned short GetTrackNumber() const;
  Type           GetParticleID() const;
  float          GetStartTime() const;
  float          GetStartX() const;
  float          GetStartY() const;
  float          GetStartZ() const;
  float          GetStopTime() const;
  float          GetStopX() const;
  float          GetStopY() const;
  float          GetStopZ() const;
  float          GetLength() const;
  float          GetZenith() const;
  float          GetAzimuth() const;
  float          GetEnergy() const;

  void SetTrackNumber(unsigned short tracknumber_);
  void SetParticleID(Type particleid_);
  void SetStartTime(float time);
  void SetStartX(float x);
  void SetStartY(float y);
  void SetStartZ(float z);
  void SetStopTime(float time);
  void SetStopX(float x);
  void SetStopY(float y);
  void SetStopZ(float z);
  void SetLength(float length_);
  void SetZenith(float zenith_);
  void SetAzimuth(float azimuth_);
  void SetEnergy(float energy_);
  
  bool           HasParentTrack() const;
  const I3Track& GetParentTrack() const;
  void           SetParentTrack(I3Track& parenttrack_);

  unsigned short GetNumberChildrenTracks() const;
  const I3Track& GetChildrenTrack(unsigned short number) const;
  void           AddChildrenTrack(I3Track& childrentrack_);

  ClassDef(I3Track, 1);
};
#endif
