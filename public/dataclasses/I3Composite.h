/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Composite.h,v 1.6 2004/07/06 15:35:52 pretz Exp $
 *
 * @file I3Composite.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/07/06 15:35:52 $
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
 * @todo What do do in copy.  Deep copy?  Needs to be implemented.
 */
class I3Composite
{
 private:
  vector<I3ParticlePtr> fConstituents;
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

  /**
   * retrieves the constituents that make up this track as const
   */
  const vector<I3ParticlePtr>& GetConstituents() const {return fConstituents;}

  /**
   * retrieves the constituents that make up this track as non-const
   */
  vector<I3ParticlePtr>& GetConstituents() {return fConstituents;}

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

