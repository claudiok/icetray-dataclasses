/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3TWRLaunch.h
 * @date $Date$
 */

#ifndef I3TWRLAUNCH_H_INCLUDED
#define I3TWRLAUNCH_H_INCLUDED

#include "dataclasses/I3Vector.h"
#include "dataclasses/physics/I3TWRFrag.h"

using namespace std;

class I3TWRLaunch : public I3Vector<I3TWRFrag>
{
  Int_t   id;
  Float_t bin_size;
  Float_t baseline;
  Int_t   stop_delay;
  Int_t   threshold;
  Bool_t  optical;

  public:
  I3TWRLaunch() {id=0; bin_size=0; baseline=0; stop_delay=0; threshold=0; optical=false;}
  virtual ~I3TWRLaunch();
  Int_t   GetId() {return id;}
  void    SetId(Int_t id_) {id=id_;}
  Float_t GetBinSize() {return bin_size;}
  void    SetBinSize(Float_t bin_size_) {bin_size=bin_size_;}
  Float_t GetBaseline() {return baseline;}
  void    SetBaseline(Float_t baseline_) {baseline=baseline_;}
  Int_t   GetStopDelay() {return stop_delay;}
  void    SetStopDelay(Int_t stop_delay_) {stop_delay=stop_delay_;}
  Int_t   GetThreshold() {return threshold;}
  void    SetThreshold(Int_t threshold_) {threshold=threshold_;}
  Bool_t  GetOptical() {return optical;}
  void    SetOptical(Bool_t optical_) {optical=optical_;}

  private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);


  //ClassDef(I3TWRLaunch,1);
};

typedef shared_ptr<I3TWRLaunch> I3TWRLaunchPtr;
#endif //I3TWRLAUNCH_H_INCLUDED


