/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCEvent.h,v 1.1 2004/07/01 21:20:47 spencer Exp $
 *
 * @file I3MCEvent.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/01 21:20:47 $
 * @author Spencer Klein
 */
#ifndef I3MCEVENT_H
#define I3MCEVENT_H

/**
 * @brief This holds the global event Monte Carlo information
 * For now, this is the frame start and stop times
 */

class I3MCEvent : public I3Event
{
  Float_t fMCFrameStart;
  Float_t fMCFrameStop;
  
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
