/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.h,v 1.10.2.1 2004/04/07 16:59:31 troy Exp $

    @version $Revision: 1.10.2.1 $
    @date $Date: 2004/04/07 16:59:31 $
    @author

    @todo

*/

#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include <vector>
#include <cmath>
class I3Track : public TObject
{
 public:

  enum TrackType {
    Unknown = -100,
    Null = 0, 
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
    Elph = 9999
  };

 private:

  TrackType           fType;
  Double_t       fX;
  Double_t       fY;
  Double_t       fZ;

 public:
  I3Track() {
    fType=Null;
    fX=NAN;
    fY=NAN;
    fZ=NAN;
  };

  virtual ~I3Track() {};
    
  Double_t X() const { return fX; }
  void X(Double_t arg) { fX = arg; }

  Double_t Y() const { return fY; }
  void Y(Double_t arg) { fY = arg; }

  Double_t Z() const { return fZ; }
  void Z(Double_t arg) { fZ = arg; }
  
  virtual TrackType Type() const { return fType; }
  virtual void Type(TrackType arg) { fType = arg; }
  
  virtual Double_t Zenith() const { return NAN; }
  virtual void Zenith(Double_t arg) { return; }

  virtual Double_t Azimuth() const { return NAN; }
  virtual void Azimuth(Double_t arg) { return; }

  virtual Double_t Length() const { return NAN; }
  virtual void Length(Double_t arg) { return; }

  virtual Double_t Speed() const { return 1; }
  virtual void Speed(Double_t arg) { return; }

  virtual Double_t Energy() const { return NAN; }
  virtual void Energy(Double_t arg) { return; }

  virtual bool IsStarting() = 0;
  virtual bool IsStopping() = 0;
  virtual bool IsBounded() = 0;
  virtual bool IsUnbounded() = 0;
  
  ClassDef(I3Track, 1);
};

#endif
