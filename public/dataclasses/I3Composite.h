/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Composite.h,v 1.5 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3Composite.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 */
#ifndef I3COMPOSITE_H
#define I3COMPOSITE_H

#include <vector>
#include "I3Particle.h"

/**
 * @brief This class satisfies the "Composite" part of an I3Track 
 * Implementation, 
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

  int GetNumConstituents() const {return fConstituents.size();}

  const I3Particle& GetConstituent(int i) const 
    {
      return *(fConstituents[i]);
    }

  vector<I3Particle*>& GetConstituents(){return fConstituents;}

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

