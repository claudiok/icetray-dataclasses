/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3ParticleMultiMap.h,v 1.1 2004/08/14 16:41:16 pretz Exp $
 *
 * @file I3ParticleMultiMap.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/08/14 16:41:16 $
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
class I3ParticleMultiMap : public TObject, public MultiMapPolicy<string, I3ParticlePtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3ParticleMultiMap(){};

  /**
   * destructor
   */
  virtual ~I3ParticleMultiMap(){};

 private:
  // copy and assignment private
/*   I3ParticleMultiMap(const I3ParticleMultiMap&);  */
/*   const I3ParticleMultiMap& operator=(const I3ParticleMultiMap&); */

  // ROOT macro
  ClassDef(I3ParticleMultiMap,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3ParticleMultiMap>::ThePolicy I3ParticleMultiMapPtr;

#endif
