/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleEvent.h,v 1.1 2004/05/04 23:40:06 pretz Exp $
 *
 * @file I3MCParticleEvent.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/05/04 23:40:06 $
 * @author pretz
 *
 */

#ifndef I3MCPARTICLEEVENT_H
#define I3MCPARTICLEEVENT_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3ObsParticleList.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A set of causely-related MC Tracks. 
 *
 * The stuff at the surface, and the stuff in the ice
 * @todo work out how the copy and assignment can be private.
 */
class I3MCParticleEvent : public TObject 
{

  I3MCPrimary fPrimary;
  I3ObsParticleList fInIceTracks;
  I3ObsParticleList fIceTopTracks;

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
  const I3ObsParticleList& InIceTracks() const {return fInIceTracks;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3ObsParticleList& InIceTracks() {return fInIceTracks;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3ObsParticleList& IceTopTracks() const {return fIceTopTracks;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3ObsParticleList& IceTopTracks() {return fIceTopTracks;};

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
