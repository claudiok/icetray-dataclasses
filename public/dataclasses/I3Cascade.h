#ifndef I3CASCADE_H
#define I3CASCADE_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Cascade.h,v 1.1.2.4 2004/04/20 16:51:16 pretz Exp $
 *
 * @version $Revision: 1.1.2.4 $
 * @date $Date: 2004/04/20 16:51:16 $
 * @author pretz
 *
 * @todo implement fatal calls
 *
 */
class I3Cascade : public I3Particle{
 public:
  virtual Bool_t IsLocalized() const =0;

  virtual Double_t X() const =0;

  virtual Double_t Y() const =0;

  virtual Double_t Z() const =0;

  virtual Double_t T() const =0;

  virtual I3Position Pos() { return I3Position(X(),Y(),Z(),T());}

  virtual void CopyTo(I3Particle& destination) const
    {
      I3Particle::CopyTo(destination);
    }

  ClassDef(I3Cascade,1);
};


#endif
