/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrack.h,v 1.1.2.2 2004/04/10 16:38:59 troy Exp $

    @version $Revision: 1.1.2.2 $
    @date $Date: 2004/04/10 16:38:59 $
    @author

    @todo

*/

#ifndef I3BASICTRACK_H
#define I3BASICTRACK_H

#include "dataclasses/I3Track.h"

class I3BasicTrack : public I3Track
{

  Double_t fTime, fLength, fZenith, fAzimuth;

 public:
  I3BasicTrack() {
    fZenith=NAN;
    fAzimuth=NAN;
    fLength=NAN;
  };

  virtual ~I3BasicTrack() {};
    
  virtual Double_t Time() const { return fTime; }
  virtual void Time(Double_t arg) { fTime = arg; }

  virtual Double_t Zenith() const { return fZenith; }
  virtual void Zenith(Double_t arg) { fZenith = arg; }

  virtual Double_t Azimuth() const { return fAzimuth; }
  virtual void Azimuth(Double_t arg) { fAzimuth = arg; }

  virtual Double_t Length() const { return fLength; }
  virtual void Length(Double_t arg) { fLength = arg; }

  virtual bool IsStarting() { return isinf(Length()) && Length() > 0; }
  virtual bool IsStopping() { return isinf(Length()) && Length() < 0; }
  virtual bool IsBounded() { return !isinf(Length()) && !isnan(Length()) && Length() != 0; }
  virtual bool IsUnbounded() { return Length() == 0; }

  ClassDef(I3BasicTrack, 1);
};

#endif
