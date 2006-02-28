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
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"

using namespace std;

class I3TWRLaunch : public I3Vector<I3TWRFrag>
{
  int   id;
  float bin_size;
  float baseline;
  int   stop_delay;
  int   threshold;
  bool  optical;

  public:
  I3TWRLaunch() {id=0; bin_size=0; baseline=0; stop_delay=0; threshold=0; optical=false;}
  virtual ~I3TWRLaunch();
  int   GetId() {return id;}
  void    SetId(int id_) {id=id_;}
  float GetBinSize() {return bin_size;}
  void    SetBinSize(float bin_size_) {bin_size=bin_size_;}
  float GetBaseline() {return baseline;}
  void    SetBaseline(float baseline_) {baseline=baseline_;}
  int   GetStopDelay() {return stop_delay;}
  void    SetStopDelay(int stop_delay_) {stop_delay=stop_delay_;}
  int   GetThreshold() {return threshold;}
  void    SetThreshold(int threshold_) {threshold=threshold_;}
  bool  GetOptical() {return optical;}
  void    SetOptical(bool optical_) {optical=optical_;}

  private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);

};

typedef I3Map<OMKey, I3TWRLaunch> I3TWRLaunchMap;

I3_POINTER_TYPEDEFS(I3TWRLaunch);
I3_POINTER_TYPEDEFS(I3TWRLaunchMap);

#endif //I3TWRLAUNCH_H_INCLUDED


