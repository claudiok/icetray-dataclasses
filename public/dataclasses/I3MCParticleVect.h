/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleVect.h,v 1.2 2004/07/03 18:40:57 troy Exp $
 *
 * @file I3MCParticleVect.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/03 18:40:57 $
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
class I3MCParticleVect : public TObject, public VectorPolicy<I3ObservableParticlePtr>::ThePolicy
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
