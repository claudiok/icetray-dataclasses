#ifndef I3COMPOSITE_H
#define I3COMPOSITE_H

#include <vector>
#include "I3Particle.h"

/**
 * @todo implement fatal call if out of bounds
 * @todo implement I3ParticlePtr stuff
 */
class I3Composite
{
 private:
  vector<I3Particle*> fConstituents;
 public:
  I3Composite(){}
  virtual ~I3Composite(){}


  virtual bool IsComposite() const {return true;}

  virtual int NumConstituents() const {return fConstituents.size();}
  virtual const I3Particle& Constituent(int i) const 
    {
      return *(fConstituents[i]);
    }
  virtual vector<I3Particle*>& Constituents(){return fConstituents;}
  ClassDef(I3Composite,1);
};

#endif

