/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleMultiMap.h,v 1.1 2004/07/26 23:44:09 ehrlich Exp $
 *
 * @file I3MCParticleMultiMap.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/26 23:44:09 $
 * @author ehrlich
 */

#ifndef I3MCPARTICLEMULTIMAP_H
#define I3MCPARTICLEMULTIMAP_H

#include "I3Particle.h"
#include "StoragePolicy.h"

/**
 * @brief A list of MC particles
 *
 * @todo figure out how to make copy and assignment private
 */
class I3MCParticleMultiMap : public TObject, public MultiMapPolicy<string, I3ParticlePtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCParticleMultiMap(){};

  /**
   * destructor
   */
  virtual ~I3MCParticleMultiMap(){};

 private:
  // copy and assignment private
/*   I3MCParticleMultiMap(const I3MCParticleMultiMap&);  */
/*   const I3MCParticleMultiMap& operator=(const I3MCParticleMultiMap&); */

  // ROOT macro
  ClassDef(I3MCParticleMultiMap,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleMultiMap>::ThePolicy I3MCParticleMultiMapPtr;

#endif
