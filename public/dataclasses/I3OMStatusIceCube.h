/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatusIceCube.h,v 1.4 2004/08/16 16:22:13 pretz Exp $
 *
 * @file I3OMStatusIceCube.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/08/16 16:22:13 $
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
  I3OMStatusIceCube(){}

  /**
   * destructor
   */
  virtual ~I3OMStatusIceCube(){}


  /** 
   * The OM Trigger to the Single or Multiple PE Discriminator, or off 
   */
  typedef Int_t OMTrigSource;

  /**
   * A single PE trigger
   */
  static const OMTrigSource kSPE;

  /**
   * a multi pe trigger
   */
  static const OMTrigSource kMPE;

  /**
   * no trigger
   */
  static const OMTrigSource kTrigSourceOff;

  /**
   * Sets the OM Trigger to the Single or Multiple PE Discriminator, or off 
   * @param source the new trigger source
   */
  void SetTrigSource(OMTrigSource source){fTrigSource = source;}

  /**
   * Gets the current trigger source setting
   * @return the current trigger source setting
   */
  OMTrigSource GetTrigSource(){ return fTrigSource;}

  /*  Control the Local Coincidences */
  /*  The separate variables for Up/Down, and distance follow the
      documentation */
  
  /**  
   * This controls how far the local coincidence signal is sent 
   */
  typedef Int_t LCMode;
  
  /**
   * Indicates that the local coincidence signal is not sent
   */
  static const LCMode kLCOff;

  /**
   * Indicates that the local concidence signal is sent just to nearest 
   * neighbors
   */
  static const LCMode kNearestNeighbor;

  /**
   * Indicates that the local concidence signal is sent to nearest and 
   * next-to-nearest neighbors.
   */
  static const LCMode kSecondNeighbor;  /* Includes nearest neighbor*/

  /**
   * sets how far local coincidence signals are sent
   * @param mode how far the signal is sent
   */
  void SetLocalCoincidence(LCMode mode){fLCMode = mode;}

  /**
   * gets how far local coincidence signals are sent
   * @return how far local coincidence signals are sent
   */
  LCMode GetLocalCoincidence(){ return fLCMode;}

  /**
   * There is also provision to turn on or off various settings in the 
   * DOM
   */
  typedef Int_t OnOff;

  /**
   * On
   */
  static const OnOff kOn;

  /**
   * Off
   */
  static const OnOff kOff;

  /** 
   * These control whether the local coincidences recievers are enabled
   * They should normally both be on.
   * @param onoff the new setting for the local coincidence upward reciever
   */
  void SetLCReceiveUp(OnOff onoff){fLCRecieveUp = onoff;}

  /**
   * Same as SetLCReceiveUp but for the downward receiver
   * @param onoff the new setting for the local concidence downward receiver
   */
  void SetLCReceiveDown(OnOff onoff){fLCRecieveDown = onoff;}

  /**
   * @return the local coincidence receiver status for the upward receiver
   */
  Bool_t GetLCReceiveUp(){return fLCRecieveUp;}

  /**
   * @return the local coincidenc receiver status for the downward receiver
   */
  Bool_t GetLCReceiveDown(){return fLCRecieveDown;}

  /**
   * These control whether the local coincidences sending is enabled
   * They should normally both be on.  
   * @param onoff the new setting for the local coincidence upward sender
   */
  void SetLCSendUp(OnOff onoff){fLCSendUp = onoff;}

  /**
   * The same as SetLCSendUp but for the downward sender
   */
  void SetLCSendDown(OnOff onoff){fLCSendDown = onoff;}

  /**
   * @return the local coincidence sender status for the upward sender
   */
  Bool_t GetLCSendUp() {return fLCSendUp;}

  /**
   * @return the local coincidence sender status for the downward sender
   */
  Bool_t GetLCSendDown() {return fLCSendDown;}

  /**
   * This controls the length of the local coincidence window before
   * the discriminator.  Setting is in 100 nsec ticks.
   * @param window the new local coincidence window before the descriminator in
   * 100 ns ticks
   */
  void SetLCPreWindow(Int_t window){ fLCPreWindow = window;}

  /**
   * This controls the length of the local concidence window after the
   * descriminator.  Setting is in 100 ns ticks.
   * @param window the new local coincidence window after the descriminator in
   * 100 ns ticks.
   */
  void SetLCPostWindow(Int_t window) { fLCPostWindow = window;}

  /**
   * @return the local coincidence window before the descriminator in
   * 100 ns ticks
   */
  Int_t GetLCPreWindow() { return fLCPreWindow;}

  /**
   * @return the local concidence window after the descriminator in 
   * 100 ns ticks
   */
  Int_t GetLCPostWindow() {return fLCPostWindow;}

/*  This controls the 'cable length correction' (widening the discriminator
    to account for the 54 meter cable length instead of 18 m.  */

  void SetLCLongCableUp(OnOff onoff) {fLCLongCableUp = onoff;}
  void SetLCLongCableDown(OnOff onoff) {fLCLongCableDown = onoff;}
  Bool_t GetLCLongCableUp() {return fLCLongCableUp;}
  Bool_t GetLCLongCableDown() { return fLCLongCableDown;}


  /*  Control and Monitor different parts of the OM */
  
  /**
   * Sets the status of ATWD A
   * @param onoff the new status for ATWD A
   */
  void SetStausATWD_A(OnOff onoff) {fStatusATWD_A = onoff;}

  /**
   * Sets the status of ATWD B
   * @param onoff the new status for ATWD B 
   */
  void SetStatusATWD_B(OnOff onoff) {fStatusATWD_B = onoff;}

  /**
   * Sets the status of the FADC
   * @param onoff the new status of the FADC
   */
  void SetStatusFADC(OnOff onoff) {fStatusFADC = onoff;}

  /**
   * @return the status of ATWD A
   */
  Bool_t GetStatusATWD_A(){return fStatusATWD_A;}

  /**
   * @return the status of ATWD B
   */
  Bool_t GetStatusATWD_B(){return fStatusATWD_B;}

  /**
   * @return the status of the FADC
   */
  Bool_t GetStatusFADC(){return fStatusFADC;}


  /**
   * Sets the ATWD frequency.  Implementation, units remain TBD 
   */
  void SetATWDFrequency(float freq) {fATWDFrequency = freq;}

  /**
   * Gets the ATWD frequency.  Implementation, units remain TBD
   * @return the ATWD frequency
   */
  float GetATWDFrequency() {return fATWDFrequency;}

 private:
  OMTrigSource fTrigSource;
  LCMode fLCMode;
  OnOff fLCRecieveUp;
  OnOff fLCRecieveDown;
  OnOff fLCSendUp;
  OnOff fLCSendDown;
  Int_t fLCPreWindow;
  Int_t fLCPostWindow;
  OnOff fLCLongCableUp;
  OnOff fLCLongCableDown;
  OnOff fStatusATWD_A;
  OnOff fStatusATWD_B;
  OnOff fStatusFADC;
  Float_t fATWDFrequency;

  ClassDef(I3OMStatusIceCube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMStatusIceCube>::ThePolicy I3OMStatusIceCubePtr;

#endif


