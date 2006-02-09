/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3TWRLaunch.h,v 1.2 2005/02/21 06:47:54 ehrlich Exp $
 * @file I3TWRLaunch.h
 * @date $Date: 2005/02/21 06:47:54 $
 */
#ifndef I3TWRFRAG_H_INCLUDED
#define I3TWRFRAG_H_INCLUDED

#include <TObject.h>
#include <vector>
#include "dataclasses/Utility.h"

using namespace std;

class I3TWRFrag : public TObject
{
  Int_t            id;
  Int_t            parent_id;
  Float_t          frag_start_time;
  Int_t            frag_start_bin;
  vector<Double_t> waveform;

  public:
  I3TWRFrag() {id=0; frag_start_time=NAN; frag_start_bin=0;}
  virtual ~I3TWRFrag();

  Int_t          GetId() {return id;}
  void           SetId(Int_t id_) {id=id_;}
  Int_t          GetParentId() {return id;}
  void           SetParentId(Int_t parent_id_) {parent_id=parent_id_;}
  Float_t        GetStartTime() {return frag_start_time;}
  void           SetStartTime(Float_t frag_start_time_) {frag_start_time=frag_start_time_;}
  Int_t          GetStartBin() {return frag_start_bin;}
  void           SetStartBin(Int_t frag_start_bin_) {frag_start_bin=frag_start_bin_;}
  
  vector<Double_t>& GetWaveform() {return waveform;}

  private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);

  //ClassDef(I3TWRFrag,1);
};

I3_POINTER_TYPEDEFS(I3TWRFrag);

#endif //I3TWRFRAG_H_INCLUDED

