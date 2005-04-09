/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCEvent.h,v 1.13 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3MCEvent.h
 * @version $Revision: 1.13 $
 * @date $Date: 2005/04/09 03:02:10 $
 * @author Spencer Klein
 */
#ifndef I3MCEVENT_H
#define I3MCEVENT_H

#include "dataclasses/I3Event.h"
#include "dataclasses/I3MCParticleData.h"

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
  float           fMCFrameStart;
  float           fMCFrameStop;
  I3MCParticleData  fMCParticleData; //||

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
   * The time that the simulation starts.  This is as opposed to the
   * the event time, which is when the hardware thinks the event starts.
   * This is the earliest time simulated
   * @return the start time for the simulation
   */
  const float GetMCFrameStart() const {return fMCFrameStart; }

  /**
   * sets the start time for the simulation
   */
  void SetMCFrameStart(float MCFrameStart){fMCFrameStart=MCFrameStart;}

  /**
   * The time that the simulation stops.  See GetMCFrameStart for more.
   * This is the latest time simulated
   * @return the stop time for the simulation
   */
  const float GetMCFrameStop() const {return fMCFrameStop;}

  /**
   * sets the stop time for the simulation
   */
  void SetMCFrameStop(float MCFrameStop){fMCFrameStop=MCFrameStop;}

  /**
   * @return the MCParticleDict as a constant object.
   */
  const I3MCParticleData& GetMCParticleData() const { return fMCParticleData;}

  /**
   * @return the MCParticleDict as a non-const object.
   */
  I3MCParticleData& GetMCParticleData(){ return fMCParticleData;}

  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3MCEvent ] \n";
      I3Event::ToStream(o);
      o<<"Frame Start: "<<fMCFrameStart<<"\n"
       <<"Frame Stop: "<<fMCFrameStop<<"\n"
       <<fMCParticleData<<"\n";
    }
  
 private:

  //ROOT macro
  ClassDef(I3MCEvent, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCEvent>  I3MCEventPtr;

#endif
