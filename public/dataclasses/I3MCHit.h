/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCHit.h,v 1.2 2004/02/15 02:21:35 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/15 02:21:35 $
    @author

*/
#ifndef I3MCHIT_H
#define I3MCHIT_H

#include <TObject.h>
#include "I3Hit.h"

class I3MCHit : public I3Hit
{
  Float_t          fWeight;
  UShort_t fTrackNum;

  public:
  I3MCHit() { fWeight = 0; fTrackNum=0;}

  Float_t Weight() const { return fWeight; }
  void Weight(Float_t weight_) { fWeight = weight_; }

  short TrackNumber() const { return fTrackNum; }
  void TrackNumber(UShort_t tracknum_) { fTrackNum = tracknum_; }


  ClassDef(I3MCHit, 1);
};
#endif

