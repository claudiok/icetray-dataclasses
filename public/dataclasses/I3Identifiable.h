#ifndef I3IDENTIFIABLE_H
#define I3IDENTIFIABLE_H

#include "I3Particle.h"

class I3Identifiable{
  I3Particle::ParticleType fType;
 public:
  virtual bool IsIdentifiable() const {return true;}

  I3Particle::ParticleType Type() const {return fType;}
  void Type(I3Particle::ParticleType type){fType = type;}

  void CopyTo(I3Particle& destination) const
    {
      I3Identifiable* idable = dynamic_cast<I3Identifiable*>(&destination);
      if(idable){
	idable->fType = fType;
      }
    }

  ClassDef(I3Identifiable,1);
};

#endif
