/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.h,v 1.10.2.7 2004/04/15 11:26:56 troy Exp $

    @version $Revision: 1.10.2.7 $
    @date $Date: 2004/04/15 11:26:56 $
    @author

    @todo

*/

#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include <vector>
#include <cmath>
#include <cassert>

#include <iostream>

#include "dataclasses/I3DataExecution.h"
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

  TrackType      fType;
  Double_t       fX;
  Double_t       fY;
  Double_t       fZ;

  Double_t checknan(Double_t it) const { 
    if (isnan(it)) {
      // The following does not work.  I will look at this logging stuff at some point..
      // I3DataExecution::Instance().Fatal("Illegal access of initialized or invalid track parameter.") 
      cerr << "Illegal access of initialized or invalid track parameter." << endl;
      assert(0);
      return NAN;
    } else {
      return it;
    }
  }
  
 public:
  I3Track() {
    fType=Null;
    fX=NAN;
    fY=NAN;
    fZ=NAN;
  };

  virtual ~I3Track() {};
    
  TrackType Type() const { return fType; }
  void Type(TrackType arg) { fType = arg; }
  
  Double_t X() const { return checknan(fX); }
  void X(Double_t arg) { fX = arg; }

  Double_t Y() const { return checknan(fY); }
  void Y(Double_t arg) { fY = arg; }

  Double_t Z() const { return checknan(fZ); }
  void Z(Double_t arg) { fZ = arg; }
  
  virtual Double_t Speed() const { return 1; }
  virtual void Speed(Double_t arg) { return; }

  virtual Double_t Time() const { return checknan(NAN); }
  virtual void Time(Double_t arg) { return; }

  virtual Double_t Zenith() const { return checknan(NAN); }
  virtual void Zenith(Double_t arg) { return; }

  virtual Double_t Azimuth() const { return checknan(NAN); }
  virtual void Azimuth(Double_t arg) { return; }

  virtual Double_t Length() const { return checknan(NAN); }
  virtual void Length(Double_t arg) { return; }

  virtual Double_t Energy() const { return checknan(NAN); }
  virtual void Energy(Double_t arg) { return; }

  virtual Double_t Weight() const { return checknan(NAN); }
  virtual void Weight(Double_t arg) { return; }

  virtual bool IsStarting() = 0;
  virtual bool IsStopping() = 0;
  virtual bool IsBounded() = 0;
  virtual bool IsUnbounded() = 0;
  
  //FIXME:  need fns like distancefromtrack, isontrack, etc.

  I3Track& operator=(const I3Track&);
  virtual void ToStream (std::ostream &s) const;

  ClassDef(I3Track, 1);
};

inline 
std::ostream& 
operator<< (std::ostream& s, const I3Track& t) 
{
  // this is done through a reference, virtual call dispatch occurs.
  // need only this function to cover all subtypes of I3Track that define
  // the function  "void ToStream(std::ostream &) const"
  t.ToStream(s);
  return s;
}
  
// inside here the member variables are compared one-by-one.  Each one
// involves a virtual call dispatch.
bool 
operator== (const I3Track& lhs, const I3Track& rhs);

// FIXME (rather, caution.) The "(NAN==NAN)==true" thing bothers me.
inline 
bool 
operator!= (const I3Track& lhs, const I3Track& rhs) 
{
  return !(lhs==rhs);
}

#endif
