/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleEvent.h,v 1.3 2004/05/05 19:34:54 pretz Exp $
 *
 * @file I3MCParticleEvent.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/05/05 19:34:54 $
 * @author pretz
 *
 */

#ifndef I3MCPARTICLEEVENT_H
#define I3MCPARTICLEEVENT_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3MCParticleList.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A set of causely-related MC particles.
 *
 * The stuff at the surface, and the stuff in the ice
 * @todo work out how the copy and assignment can be private.
 */
class I3MCParticleEvent : public TObject 
{

  I3MCPrimary fPrimary;
  I3MCParticleList fInIceParticles;
  I3MCParticleList fIceTopParticles;

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
  const I3MCPrimary& Primary() const {return fPrimary;}

  /**
   * @return the primary track as non-const
   */
  I3MCPrimary& Primary() {return fPrimary;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3MCParticleList& InIceParticles() const {return fInIceParticles;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3MCParticleList& InIceParticles() {return fInIceParticles;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3MCParticleList& IceTopParticles() const {return fIceTopParticles;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3MCParticleList& IceTopParticles() {return fIceTopParticles;};

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
