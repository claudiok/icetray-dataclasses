/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MonoTrack.h,v 1.2 2004/04/22 15:55:44 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/04/22 15:55:44 $
    @author

    @todo

*/

#ifndef I3TRACK_H
#define I3TRACK_H

#include "dataclasses/I3BasicTrack.h"

class I3MonoTrack : public I3BasicTrack
{

  Double_t fSpeed;

 public:

  I3MonoTrack() {
    fSpeed=NAN;
  };

  virtual ~I3MonoTrack() {};
    
  virtual Double_t Speed() const { return fSpeed; }
  virtual void Speed(Double_t arg) { fSpeed = arg; }

  ClassDef(I3MonoTrack, 1);
};

#endif
