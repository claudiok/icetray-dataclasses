#ifndef I3NONCOMPOSITE_H
#define I3NONCOMPOSITE_H

#include <vector>
#include "I3Particle.h"

/**
 * @todo implement fatal call if out of bounds
 * @todo implement I3ParticlePtr stuff
 */
class I3NonComposite
{
 public:
  I3NonComposite(){}
  virtual ~I3NonComposite(){}


  bool IsComposite() const {return false;}

  int NumConstituents() const {return 0;}
  const I3Particle& Constituent(int i) const 
    {
      return *(I3Particle*)0;
    }
  void CopyTo(I3Particle& destination) const {}

  ClassDef(I3NonComposite,1);
};

#endif

