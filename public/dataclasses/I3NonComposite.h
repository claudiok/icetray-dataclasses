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


  virtual bool IsComposite() const {return false;}

  virtual int NumConstituents() const {return 0;}
  virtual const I3Particle& Constituent(int i) const 
    {
      return *(I3Particle*)0;
    }
  ClassDef(I3NonComposite,1);
};

#endif

