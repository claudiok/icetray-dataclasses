/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleDict.h,v 1.2 2004/07/03 18:40:57 troy Exp $
 *
 * @file I3MCParticleDict.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/03 18:40:57 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3MCPARTICLEDATA_H
#define I3MCPARTICLEDATA_H

#include "dataclasses/I3MCParticleEvent.h"
#include "TObject.h"

/**
 * @brief This is a map of I3MCParticleEvents.  
 *
 * It is supposed to contain all the
 * MC information for the tracks in the Event.  
 *
 */
class I3MCParticleDict : public TObject, public MapPolicy<I3MCParticleEventPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCParticleDict(){}

  /**
   * destructor
   */
  virtual ~I3MCParticleDict() {};

 private:
  // copy and assignment private
  I3MCParticleDict(const I3MCParticleDict& rhs);
  const I3MCParticleDict& operator=(const I3MCParticleDict& rhs);

  // ROOT macro
  ClassDef(I3MCParticleDict,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleDict>::ThePolicy I3MCParticleDictPtr;

#endif
