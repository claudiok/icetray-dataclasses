/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatusIcecube.h,v 1.3 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3OMStatusIcecube.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 *
 * @todo  this header needs commented yet.
 */
#ifndef I3OMSTATUSICECUBE_H
#define I3OMSTATUSICECUBE_H

#include <TObject.h>
#include <TObjArray.h>
#include "I3OMStatus.h"

/**
 * @brief I3OMStatusIcecube has status information on the IceCube
 * OM parameters that can be controlled or adjusted, such as
 * the trigger, local coincidence and ATWD settings.
 *
 * It may be extended to include FPGA/ARM7 code
 * parameters, like data compression algorithms 
 *
 * This is based on "IceCube DOMAPP CPU FPGA Interface, Version 0.6
 * bu Thorsten Stetzelberger, Jan. 24, 2004 
 */
class I3OMStatusIcecube : public I3OMStatus
{
 public:
  I3OMStatusIcecube(){}
  virtual ~I3OMStatusIcecube(){}


/*  Sets the OM Trigger to the Single or Multiple PE Discriminator, or off */

  typedef Int_t OMTrigSource;
  static const OMTrigSource kSPE;
  static const OMTrigSource kMPE;
  static const OMTrigSource kTrigSourceOff;

  void TrigSource(OMTrigSource source){fTrigSource = source;}
  Int_t TrigSource(){ return fTrigSource;}

/*  Control the Local Coincidences */
/*  The separate variables for Up/Down, and distance follow the
    documentation */

/*  This controls how far the local coincidence signal is sent */

  typedef Int_t LCMode;
  static const LCMode kLCOff;
  static const LCMode kNearestNeighbor;
  static const LCMode kSecondNeighbor;  /* Includes nearest neighbor*/

  void LocalCoincidence(LCMode mode){fLCMode = mode;}
  LCMode LocalCoincidence(){ return fLCMode;}

/*  There is also provision to turn on or off the local coincidence sending and
    receiving */

  typedef Int_t OnOff;
  static const OnOff kOn;
  static const OnOff kOff;

/*  These control whether the local coincidences recievers are enabled
    They should normally both be on.  */

  void LCReceiveUp(OnOff onoff){fLCRecieveUp = onoff;}
  void LCReceiveDown(OnOff onoff){fLCRecieveDown = onoff;}
  Bool_t LCReceiveUp(){return fLCRecieveUp;}
  Bool_t LCReceiveDown(){return fLCRecieveDown;}

/*  These control whether the local coincidences sending is enabled
    They should normally both be on.  */

  void LCSendUp(OnOff onoff){fLCSendUp = onoff;}
  void LCSendDown(OnOff onoff){fLCSendDown = onoff;}
  Bool_t LCSendUp() {return fLCSendUp;}
  Bool_t LCSendDown() {return fLCSendDown;}

/*  This control the length of the local coincidence window before
    and after the discriminator.  Setting is in 100 nsec ticks */

  void LCPreWindow(Int_t window){ fLCPreWindow = window;}
  void LCPostWindow(Int_t window) { fLCPostWindow = window;}
  Int_t LCPreWindow() { return fLCPreWindow;}
  Int_t LCPostWindow() {return fLCPostWindow;}

/*  This controls the 'cable length correction' (widening the discriminator
    to account for the 54 meter cable length instead of 18 m.  */

  void LCLongCableUp(OnOff onoff) {fLCLongCableUp = onoff;}
  void LCLongCableDown(OnOff onoff) {fLCLongCableDown = onoff;}
  Bool_t LCLongCableUp() {return fLCLongCableUp;}
  Bool_t LCLongCableDown() { return fLCLongCableDown;}


/*  Control and Monitor different parts of the OM */

  void StausATWD_A(OnOff onoff) {fStatusATWD_A = onoff;}
  void StatusATWD_B(OnOff onoff) {fStatusATWD_B = onoff;}
  void StatusFADC(OnOff onoff) {fStatusFADC = onoff;}
  Bool_t StatusATWD_A(){return fStatusATWD_A;}
  Bool_t StatusATWD_B(){return fStatusATWD_B;}
  Bool_t StatusFADC(){return fStatusFADC;}


/* This controls the ATWD frequency.  Implementation, units remain TBD */

  void ATWDFrequency(float freq) {fATWDFrequency = freq;}
  float ATWDFrequency() {return fATWDFrequency;}

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

  ClassDef(I3OMStatusIcecube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMStatusIcecube>::ThePolicy I3OMStatusIcecubePtr;

#endif


