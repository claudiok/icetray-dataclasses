/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCEvent.h,v 1.7 2004/07/26 19:00:54 ehrlich Exp $
 *
 * @file I3MCEvent.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/07/26 19:00:54 $
 * @author Spencer Klein
 */
#ifndef I3MCEVENT_H
#define I3MCEVENT_H

#include "dataclasses/I3Event.h"
#include "dataclasses/I3MCParticleEvent.h"

/**
 * @brief Derived I3Event class with Monte Carlo information
 *
 * This is the Monte Carlo version of the regular I3Event, adding the
 * MC-specific information.  For now, this is the frame start and stop
 * times (the boundaries of the simulated time interval) and the MC
 * track information. 
 */

class I3MCEvent : public I3Event
{
  Float_t           fMCFrameStart;
  Float_t           fMCFrameStop;
  I3MCParticleEvent fMCParticleEvent; //||

 public:
  /**
   * default constructor
   */
  I3MCEvent(){}
  
  /**
   * default destructor
   */
  virtual ~I3MCEvent(){}

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
  const I3MCParticleEvent& GetMCParticleEvent() const { return fMCParticleEvent;}

  /**
   * @return the MCParticleDict as a non-const object.
   */
  I3MCParticleEvent& GetMCParticleEvent(){ return fMCParticleEvent;}

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
