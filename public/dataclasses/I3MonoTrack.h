/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MonoTrack.h,v 1.1.2.1 2004/04/07 16:59:31 troy Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/07 16:59:31 $
    @author

    @todo

*/

#ifndef I3TRACK_H
#define I3TRACK_H

#include "dataclasses/I3BasicTrack.h"

class I3MonoTrack : public I3BasicTrack
{

  Double_t fSpeed;

  I3MonoTrack() {
    fSpeed=NAN;
  };

  virtual ~I3BasicTrack() {};
    
  virtual Double_t Speed() const { return fSpeed; }
  virtual void Speed(Double_t arg) { fSpeed = arg; }

  ClassDef(I3MonoTrack, 1);
};

#endif
