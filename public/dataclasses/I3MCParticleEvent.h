/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleEvent.h,v 1.4 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3MCParticleEvent.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/06/30 17:20:26 $
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
  const I3MCPrimary& GetPrimary() const {return fPrimary;}

  /**
   * @return the primary track as non-const
   */
  I3MCPrimary& GetPrimary() {return fPrimary;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3MCParticleList& GetInIceParticles() const {return fInIceParticles;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3MCParticleList& GetInIceParticles() {return fInIceParticles;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3MCParticleList& GetIceTopParticles() const {return fIceTopParticles;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3MCParticleList& GetIceTopParticles() {return fIceTopParticles;};

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
