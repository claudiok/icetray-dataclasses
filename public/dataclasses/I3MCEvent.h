/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCEvent.h,v 1.2 2004/07/01 21:37:43 pretz Exp $
 *
 * @file I3MCEvent.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/01 21:37:43 $
 * @author Spencer Klein
 */
#ifndef I3MCEVENT_H
#define I3MCEVENT_H

#include "dataclasses/I3Event.h"

/**
 * @brief This holds the global event Monte Carlo information
 * For now, this is the frame start and stop times
 */

class I3MCEvent : public I3Event
{
  Float_t fMCFrameStart;
  Float_t fMCFrameStop;
  I3MCParticleDict    fMCParticleDict; //||

 public:
  /**
   * default constructor
   */
  I3MCEvent();
  
  /**
   * default destructor
   */
  virtual ~I3MCEvent();

  /**
   * @get and set the frame start time
   */
  const Float_t GetMCFrameStart() const {return fMCFrameStart; }
  void SetMCFrameStart(Float_t MCFrameStart){fMCFrameStart=MCFrameStart;}

  /**
   * @get and set the frame stop time
   */

  const Float_t GetMCFrameStop() const {return fMCFrameStop;}
  void SetMCFrameStop(Float_t MCFrameStop){fMCFrameStop=MCFrameStop;}

  /**
   * @return the MCParticleDict as a constant object.
   */
  const I3MCParticleDict& GetMCParticleDict() const { return fMCParticleDict;}

  /**
   * @return the MCParticleDict as a non-const object.
   */
  I3MCParticleDict& GetMCParticleDict(){ return fMCParticleDict;}

 private:
  // copy and assignment private
  I3MCEvent(const I3MCEvent& rhs);
  const I3MCEvent& operator=(const I3MCEvent& rhs);

  //ROOT macro
  ClassDef(I3MCEvent, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCEvent>::ThePolicy I3MCEventPtr;

#endif
