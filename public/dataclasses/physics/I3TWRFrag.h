/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3TWRLaunch.h,v 1.2 2005/02/21 06:47:54 ehrlich Exp $
 * @file I3TWRLaunch.h
 * @date $Date: 2005/02/21 06:47:54 $
 */
#ifndef I3TWRFRAG_H_INCLUDED
#define I3TWRFRAG_H_INCLUDED

#include <vector>
#include "dataclasses/Utility.h"

using namespace std;

class I3TWRFrag 
{
  int            id;
  int            parent_id;
  float          frag_start_time;
  int            frag_start_bin;
  vector<double> waveform;

  public:
  I3TWRFrag() {id=0; frag_start_time=NAN; frag_start_bin=0;}
  virtual ~I3TWRFrag();

  int          GetId() {return id;}
  void           SetId(int id_) {id=id_;}
  int          GetParentId() {return id;}
  void           SetParentId(int parent_id_) {parent_id=parent_id_;}
  float        GetStartTime() {return frag_start_time;}
  void           SetStartTime(float frag_start_time_) {frag_start_time=frag_start_time_;}
  int          GetStartBin() {return frag_start_bin;}
  void           SetStartBin(int frag_start_bin_) {frag_start_bin=frag_start_bin_;}
  
  vector<double>& GetWaveform() {return waveform;}

  private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);

};

I3_POINTER_TYPEDEFS(I3TWRFrag);

#endif //I3TWRFRAG_H_INCLUDED


