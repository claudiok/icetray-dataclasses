#ifndef I3COMPOSITE_H
#define I3COMPOSITE_H

#include <vector>
#include "I3Particle.h"

/**
 * @todo implement fatal call if out of bounds
 * @todo implement I3ParticlePtr stuff
 * @todo WARNING!!!!!! What to do about potential memory leak in 'CopyTo'
 */
class I3Composite
{
 private:
  vector<I3Particle*> fConstituents;
 public:
  I3Composite(){}
  virtual ~I3Composite(){}


  bool IsComposite() const {return true;}

  int NumConstituents() const {return fConstituents.size();}
  const I3Particle& Constituent(int i) const 
    {
      return *(fConstituents[i]);
    }
  vector<I3Particle*>& Constituents(){return fConstituents;}

  void CopyTo(I3Particle& destination) const
    {
      I3Composite* composite = dynamic_cast<I3Composite*>(&destination);
      if(composite)
	{
	  composite->fConstituents = fConstituents;
	}
    }
  ClassDef(I3Composite,1);
};

#endif

