#ifndef I3NONCOMPOSITE_H
#define I3NONCOMPOSITE_H

#include <vector>
#include "I3Particle.h"
#include "NanPolicy.h"

/**
 * @todo implement fatal call if out of bounds
 * @todo implement I3ParticlePtr stuff
 */
class I3NonComposite
{
 public:
  I3NonComposite(){}
  virtual ~I3NonComposite(){}


  Bool_t IsComposite() const {return false;}

  int NumConstituents() const 
    {
      NanPolicy::Fatal();
      return 0;
    }
  const I3Particle& Constituent(int i) const 
    {
      NanPolicy::Fatal();
      return *(I3Particle*)0;
    }
  void CopyTo(I3Particle& destination) const {}

  ClassDef(I3NonComposite,1);
};

#endif

