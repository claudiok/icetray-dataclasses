/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.h,v 1.7 2004/02/17 15:48:13 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/17 15:48:13 $
    @author

    @todo

*/
#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>
#include <TRefArray.h>

class I3Track : public TObject
{
  public:
  enum Type {
    Null = 0, 
    Unknown = -100,
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
    Elph = 9999};

 private:
  unsigned short fTrackNumber;
  Type           fParticleId;
  float          fStartTime;
  float          fStartX;
  float          fStartY;
  float          fStartZ;
  float          fStopTime;
  float          fStopX;
  float          fStopY;
  float          fStopZ;
  float          fLength;
  float          fZenith;
  float          fAzimuth;
  float          fEnergy;
  TRef           parenttrack;
  TRefArray      *childrentrack;

 public:
  I3Track();
  virtual ~I3Track();
    
  unsigned short TrackNumber() const { return fTrackNumber; }
  Type ParticleID() const { return fParticleId; }
  float StartTime() const { return fStartTime; }
  float StartX() const { return fStartX; }
  float StartY() const { return fStartY; }
  float StartZ() const { return fStartZ; }
  float StopTime() const { return fStopTime; }
  float StopX() const { return fStopX; }
  float StopY() const { return fStopY; }
  float StopZ() const { return fStopZ; }
  float Length() const { return fLength; }
  float Zenith() const { return fZenith; }
  float Azimuth() const { return fAzimuth; }
  float Energy() const { return fEnergy; }

  void TrackNumber(unsigned short arg) { fTrackNumber = arg; }
  void ParticleID(Type arg) { fParticleId = arg; }
  void StartTime(float arg) { fStartTime = arg; }
  void StartX(float arg) { fStartX = arg; }
  void StartY(float arg) { fStartY = arg; }
  void StartZ(float arg) { fStartZ = arg; }
  void StopTime(float arg) { fStopTime = arg; }
  void StopX(float arg) { fStopX = arg; }
  void StopY(float arg) { fStopY = arg; }
  void StopZ(float arg) { fStopZ = arg; }
  void Length(float arg) { fLength = arg; }
  void Zenith(float arg) { fZenith = arg; }
  void Azimuth(float arg) { fAzimuth = arg; }
  void Energy(float arg) { fEnergy = arg; }

  bool           HasParentTrack() const;
  const I3Track& GetParentTrack() const;
  void           SetParentTrack(I3Track& parenttrack_);

  unsigned short GetNumberChildrenTracks() const;
  const I3Track& GetChildrenTrack(unsigned short number) const;
  void           AddChildrenTrack(I3Track& childrentrack_);

  ClassDef(I3Track, 1);
};
#endif
