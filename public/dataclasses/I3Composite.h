/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Composite.h,v 1.3 2004/04/22 16:55:52 pretz Exp $
 *
 * @file I3Composite.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/22 16:55:52 $
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3COMPOSITE_H
#define I3COMPOSITE_H

#include <vector>
#include "I3Particle.h"

/**
 * This class satisfies the "Composite" part of an I3Track Implementation, 
 * representing a track that is made up of several constituents.
 * @todo implement fatal call if out of bounds
 * @todo implement I3ParticlePtr stuff
 * @todo WARNING!!!!!! What to do about potential memory leak in 'CopyTo'
 */
class I3Composite
{
 private:
  vector<I3Particle*> fConstituents;
 public:
  /**
   * constructor
   */
  I3Composite(){}

  /**
   * destructor
   */
  virtual ~I3Composite(){}

  /**
   *
   */
  Bool_t IsComposite() const {return true;}

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

