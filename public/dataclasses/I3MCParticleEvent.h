/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleEvent.h,v 1.7 2004/07/26 23:39:10 ehrlich Exp $
 *
 * @file I3MCParticleEvent.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/07/26 23:39:10 $
 * @author pretz
 *
 */

#ifndef I3MCPARTICLEEVENT_H
#define I3MCPARTICLEEVENT_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3MCParticleMultiMap.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A set of causely-related MC particles.
 *
 * The stuff at the surface, and the stuff in the ice
 * @todo work out how the copy and assignment can be private.
 */
class I3MCParticleEvent : public TObject 
{

  I3MCParticleMultiMap fPrimary;
  I3MCParticleMultiMap fInIceParticles;
  I3MCParticleMultiMap fIceTopParticles;

 public:
  /**
   * constructor
   */
  I3MCParticleEvent(){}

  /**
   * destructor
   */
  virtual ~I3MCParticleEvent(){}
  
  /**
   * @return the primary track as constant
   */
  const I3MCParticleMultiMap& GetPrimary() const {return fPrimary;}

  /**
   * @return the primary track as non-const
   */
  I3MCParticleMultiMap& GetPrimary() {return fPrimary;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3MCParticleMultiMap& GetInIceParticles() const {return fInIceParticles;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3MCParticleMultiMap& GetInIceParticles() {return fInIceParticles;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3MCParticleMultiMap& GetIceTopParticles() const {return fIceTopParticles;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3MCParticleMultiMap& GetIceTopParticles() {return fIceTopParticles;};

 private:
  // copy and assignment are private
/*   I3MCParticleEvent(const I3MCParticleEvent&){} */
/*   const I3MCParticleEvent& operator=(const I3MCParticleEvent&); */

  ClassDef(I3MCParticleEvent,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleEvent>::ThePolicy I3MCParticleEventPtr;

#endif //I3MCPARTICLEEVENT_H
