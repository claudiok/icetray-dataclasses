/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleVect.h,v 1.1 2004/07/01 01:31:06 pretz Exp $
 *
 * @file I3MCParticleVect.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/01 01:31:06 $
 * @author pretz
 */

#ifndef I3OBSPARTICLELIST_H
#define I3OBSPARTICLELIST_H

#include "I3ObservableParticle.h"
#include "StoragePolicy.h"

/**
 * @brief A list of observable particles
 *
 * @todo figure out how to make copy and assignment private
 */
class I3MCParticleVect : public TObject, public VecPointainerPolicy<I3ObservableParticlePtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCParticleVect(){};

  /**
   * destructor
   */
  virtual ~I3MCParticleVect(){};

 private:
  // copy and assignment private
/*   I3MCParticleVect(const I3MCParticleVect&);  */
/*   const I3MCParticleVect& operator=(const I3MCParticleVect&); */ 

  // ROOT macro
  ClassDef(I3MCParticleVect,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleVect>::ThePolicy I3MCParticleVectPtr;


#endif
