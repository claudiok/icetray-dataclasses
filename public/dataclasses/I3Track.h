#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include <TObjArray.h>
#include <vector>

using namespace std;
/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.h,v 1.10 2004/03/14 15:07:12 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/03/14 15:07:12 $
    @author

    @todo

*/
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
  UShort_t fTrackNumber;
  Type           fParticleId;
  Double_t       fStartTime;
  Double_t       fStartX;
  Double_t       fStartY;
  Double_t       fStartZ;
  Double_t       fStopTime;
  Double_t       fStopX;
  Double_t       fStopY;
  Double_t       fStopZ;
  Double_t       fLength;
  Double_t       fZenith;
  Double_t       fAzimuth;
  Double_t       fEnergy;
  Int_t          fParent;
  vector<Int_t> fChildren;

 public:
  I3Track();
  virtual ~I3Track();
    
  UShort_t TrackNumber() const { return fTrackNumber; }
  Type ParticleID() const { return fParticleId; }
  Double_t StartTime() const { return fStartTime; }
  Double_t StartX() const { return fStartX; }
  Double_t StartY() const { return fStartY; }
  Double_t StartZ() const { return fStartZ; }
  Double_t StopTime() const { return fStopTime; }
  Double_t StopX() const { return fStopX; }
  Double_t StopY() const { return fStopY; }
  Double_t StopZ() const { return fStopZ; }
  Double_t Length() const { return fLength; }
  Double_t Zenith() const { return fZenith; }
  Double_t Azimuth() const { return fAzimuth; }
  Double_t Energy() const { return fEnergy; }

  void TrackNumber(UShort_t arg) { fTrackNumber = arg; }
  void ParticleID(Type arg) { fParticleId = arg; }
  void StartTime(Double_t arg) { fStartTime = arg; }
  void StartX(Double_t arg) { fStartX = arg; }
  void StartY(Double_t arg) { fStartY = arg; }
  void StartZ(Double_t arg) { fStartZ = arg; }
  void StopTime(Double_t arg) { fStopTime = arg; }
  void StopX(Double_t arg) { fStopX = arg; }
  void StopY(Double_t arg) { fStopY = arg; }
  void StopZ(Double_t arg) { fStopZ = arg; }
  void Length(Double_t arg) { fLength = arg; }
  void Zenith(Double_t arg) { fZenith = arg; }
  void Azimuth(Double_t arg) { fAzimuth = arg; }
  void Energy(Double_t arg) { fEnergy = arg; }

  Int_t Parent() const {return fParent;}
  void  Parent(Int_t parent) { fParent = parent;}

  const vector<Int_t>& Children() const {return fChildren;}
  vector<Int_t>& Children() {return fChildren;}

  ClassDef(I3Track, 1);
};
#endif
