#ifndef I3NONIDENTIFIABLE_H
#define I3NONIDENTIFIABLE_H

#include "Rtypes.h"
#include "I3Particle.h"

class I3NonIdentifiable{
 public:
  virtual bool IsIdentifiable() const {return false;}

  virtual I3Particle::ParticleType Type() {return I3Particle::Unknown;}

  ClassDef(I3NonIdentifiable,1);
};

#endif
