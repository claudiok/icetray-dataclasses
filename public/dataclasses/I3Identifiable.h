#ifndef I3IDENTIFIABLE_H
#define I3IDENTIFIABLE_H

#include "I3Particle.h"

class I3Identifiable{
  I3Particle::ParticleType fType;
 public:
  virtual bool IsIdentifiable() const {return true;}

  virtual I3Particle::ParticleType Type() const {return fType;}
  virtual void Type(I3Particle::ParticleType type){fType = type;}

  ClassDef(I3Identifiable,1);
};

#endif
