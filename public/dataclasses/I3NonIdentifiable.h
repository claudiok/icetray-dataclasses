#ifndef I3NONIDENTIFIABLE_H
#define I3NONIDENTIFIABLE_H

#include "Rtypes.h"
#include "I3Particle.h"

class I3NonIdentifiable{
 public:
  Bool_t IsIdentifiable() const {return false;}

  I3Particle::ParticleType Type() {return I3Particle::Unknown;}

  void CopyTo(I3Particle& destination) const {}

  ClassDef(I3NonIdentifiable,1);
};

#endif
