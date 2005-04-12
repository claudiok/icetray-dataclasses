/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatusIceCube.h,v 1.8 2005/04/12 20:12:56 pretz Exp $
 *
 * @file I3OMStatusIceCube.h
 * @version $Revision: 1.8 $
 * @date $Date: 2005/04/12 20:12:56 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 *
 * @todo  this header needs commented yet.
 */
#ifndef I3OMSTATUSICECUBE_H
#define I3OMSTATUSICECUBE_H

#include <TObject.h>
#include <TClass.h>
#include "I3OMStatus.h"

/**
 * @brief I3OMStatusIceCube has status information on the IceCube
 * OM parameters that can be controlled or adjusted, such as
 * the trigger, local coincidence and ATWD settings.
 *
 * It may be extended to include FPGA/ARM7 code
 * parameters, like data compression algorithms 
 *
 * This is based on "IceCube DOMAPP CPU FPGA Interface, Version 0.6
 * bu Thorsten Stetzelberger, Jan. 24, 2004 
 *
 * @todo the file needs the full 'doxygen' comments
 */
class I3OMStatusIceCube : public I3OMStatus
{
 public:
  /**
   * constructor
   */
  I3OMStatusIceCube() { }

  /**
   * destructor
   */
  virtual ~I3OMStatusIceCube() { }


  /** 
   * The OM Trigger to the Single or Multiple PE Discriminator, or off 
   */
  typedef int OMTrigSource;

  /**
   * A single PE trigger
   */
  static const OMTrigSource SPE;

  /**
   * a multi pe trigger
   */
  static const OMTrigSource MPE;

  /**
   * no trigger
   */
  static const OMTrigSource trigSourceOff;

  /**
   * Sets the OM Trigger to the Single or Multiple PE Discriminator, or off 
   * @param source the new trigger source
   */
  void SetTrigSource(OMTrigSource source) { trigSource_ = source; }

  /**
   * Gets the current trigger source setting
   * @return the current trigger source setting
   */
  OMTrigSource GetTrigSource() { return trigSource_; }

  /*  Control the Local Coincidences */
  /*  The separate variables for Up/Down, and distance follow the
      documentation */
  
  /**  
   * This controls how far the local coincidence signal is sent 
   */
  typedef int LCMode;
  
  /**
   * Indicates that the local coincidence signal is not sent
   */
  static const LCMode LCOff;

  /**
   * Indicates that the local concidence signal is sent just to nearest 
   * neighbors
   */
  static const LCMode nearestNeighbor;

  /**
   * Indicates that the local concidence signal is sent to nearest and 
   * next-to-nearest neighbors.
   */
  static const LCMode secondNeighbor;  /* Includes nearest neighbor*/

  /**
   * sets how far local coincidence signals are sent
   * @param mode how far the signal is sent
   */
  void SetLocalCoincidence(LCMode mode) { LCMode_ = mode; }

  /**
   * gets how far local coincidence signals are sent
   * @return how far local coincidence signals are sent
   */
  LCMode GetLocalCoincidence() { return LCMode_; }

  /**
   * There is also provision to turn on or off various settings in the 
   * DOM
   */
  typedef int OnOff;

  /**
   * On
   */
  static const OnOff on;

  /**
   * Off
   */
  static const OnOff off;

  /** 
   * These control whether the local coincidences recievers are enabled
   * They should normally both be on.
   * @param onoff the new setting for the local coincidence upward reciever
   */
  void SetLCReceiveUp(OnOff onoff) { LCRecieveUp_ = onoff; }

  /**
   * Same as SetLCReceiveUp but for the downward receiver
   * @param onoff the new setting for the local concidence downward receiver
   */
  void SetLCReceiveDown(OnOff onoff) { LCRecieveDown_ = onoff; }

  /**
   * @return the local coincidence receiver status for the upward receiver
   */
  bool GetLCReceiveUp() { return LCRecieveUp_; }

  /**
   * @return the local coincidenc receiver status for the downward receiver
   */
  bool GetLCReceiveDown() { return LCRecieveDown_; }

  /**
   * These control whether the local coincidences sending is enabled
   * They should normally both be on.  
   * @param onoff the new setting for the local coincidence upward sender
   */
  void SetLCSendUp(OnOff onoff) { LCSendUp_ = onoff; }

  /**
   * The same as SetLCSendUp but for the downward sender
   */
  void SetLCSendDown(OnOff onoff) { LCSendDown_ = onoff; }

  /**
   * @return the local coincidence sender status for the upward sender
   */
  bool GetLCSendUp() { return LCSendUp_; }

  /**
   * @return the local coincidence sender status for the downward sender
   */
  bool GetLCSendDown() { return LCSendDown_; }

  /**
   * This controls the length of the local coincidence window before
   * the discriminator.  Setting is in 100 nsec ticks.
   * @param window the new local coincidence window before the descriminator in
   * 100 ns ticks
   */
  void SetLCPreWindow(int window){ LCPreWindow_ = window; }

  /**
   * This controls the length of the local concidence window after the
   * descriminator.  Setting is in 100 ns ticks.
   * @param window the new local coincidence window after the descriminator in
   * 100 ns ticks.
   */
  void SetLCPostWindow(int window) { LCPostWindow_ = window; }

  /**
   * @return the local coincidence window before the descriminator in
   * 100 ns ticks
   */
  int GetLCPreWindow() { return LCPreWindow_; }

  /**
   * @return the local concidence window after the descriminator in 
   * 100 ns ticks
   */
  int GetLCPostWindow() {return LCPostWindow_; }

/*  This controls the 'cable length correction' (widening the discriminator
    to account for the 54 meter cable length instead of 18 m.  */

  void SetLCLongCableUp(OnOff onoff) { LCLongCableUp_ = onoff; }
  void SetLCLongCableDown(OnOff onoff) { LCLongCableDown_ = onoff; }
  bool GetLCLongCableUp() { return LCLongCableUp_; }
  bool GetLCLongCableDown() { return LCLongCableDown_; }


  /*  Control and Monitor different parts of the OM */
  
  /**
   * Sets the status of ATWD A
   * @param onoff the new status for ATWD A
   */
  void SetStausATWD_A(OnOff onoff) { statusATWD_A_ = onoff; }

  /**
   * Sets the status of ATWD B
   * @param onoff the new status for ATWD B 
   */
  void SetStatusATWD_B(OnOff onoff) { statusATWD_B_ = onoff; }

  /**
   * Sets the status of the FADC
   * @param onoff the new status of the FADC
   */
  void SetStatusFADC(OnOff onoff) { statusFADC_ = onoff; }

  /**
   * @return the status of ATWD A
   */
  bool GetStatusATWD_A() { return statusATWD_A_; }

  /**
   * @return the status of ATWD B
   */
  bool GetStatusATWD_B() { return statusATWD_B_; }

  /**
   * @return the status of the FADC
   */
  bool GetStatusFADC() { return statusFADC_; }


  /**
   * Sets the ATWD frequency.  Implementation, units remain TBD 
   */
  void SetATWDFrequency(float freq) { ATWDFrequency_ = freq; }

  /**
   * Gets the ATWD frequency.  Implementation, units remain TBD
   * @return the ATWD frequency
   */
  float GetATWDFrequency() { return ATWDFrequency_; }

 private:
  OMTrigSource trigSource_;
  LCMode LCMode_;
  OnOff LCRecieveUp_;
  OnOff LCRecieveDown_;
  OnOff LCSendUp_;
  OnOff LCSendDown_;
  int LCPreWindow_;
  int LCPostWindow_;
  OnOff LCLongCableUp_;
  OnOff LCLongCableDown_;
  OnOff statusATWD_A_;
  OnOff statusATWD_B_;
  OnOff statusFADC_;
  float ATWDFrequency_;

  ClassDef(I3OMStatusIceCube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3OMStatusIceCube>  I3OMStatusIceCubePtr;

#endif


