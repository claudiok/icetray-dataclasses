/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatusIcecube.h,v 1.4 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3OMStatusIcecube.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/06/30 17:20:26 $
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
 *
 * @todo the file needs the full 'doxygen' comments
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

  void SetTrigSource(OMTrigSource source){fTrigSource = source;}
  OMTrigSource GetTrigSource(){ return fTrigSource;}

/*  Control the Local Coincidences */
/*  The separate variables for Up/Down, and distance follow the
    documentation */

/*  This controls how far the local coincidence signal is sent */

  typedef Int_t LCMode;
  static const LCMode kLCOff;
  static const LCMode kNearestNeighbor;
  static const LCMode kSecondNeighbor;  /* Includes nearest neighbor*/

  void SetLocalCoincidence(LCMode mode){fLCMode = mode;}
  LCMode GetLocalCoincidence(){ return fLCMode;}

/*  There is also provision to turn on or off the local coincidence sending and
    receiving */

  typedef Int_t OnOff;
  static const OnOff kOn;
  static const OnOff kOff;

/*  These control whether the local coincidences recievers are enabled
    They should normally both be on.  */

  void SetLCReceiveUp(OnOff onoff){fLCRecieveUp = onoff;}
  void SetLCReceiveDown(OnOff onoff){fLCRecieveDown = onoff;}
  Bool_t GetLCReceiveUp(){return fLCRecieveUp;}
  Bool_t GetLCReceiveDown(){return fLCRecieveDown;}

/*  These control whether the local coincidences sending is enabled
    They should normally both be on.  */

  void SetLCSendUp(OnOff onoff){fLCSendUp = onoff;}
  void SetLCSendDown(OnOff onoff){fLCSendDown = onoff;}
  Bool_t GetLCSendUp() {return fLCSendUp;}
  Bool_t GetLCSendDown() {return fLCSendDown;}

/*  This control the length of the local coincidence window before
    and after the discriminator.  Setting is in 100 nsec ticks */

  void SetLCPreWindow(Int_t window){ fLCPreWindow = window;}
  void SetLCPostWindow(Int_t window) { fLCPostWindow = window;}
  Int_t GetLCPreWindow() { return fLCPreWindow;}
  Int_t GetLCPostWindow() {return fLCPostWindow;}

/*  This controls the 'cable length correction' (widening the discriminator
    to account for the 54 meter cable length instead of 18 m.  */

  void SetLCLongCableUp(OnOff onoff) {fLCLongCableUp = onoff;}
  void SetLCLongCableDown(OnOff onoff) {fLCLongCableDown = onoff;}
  Bool_t GetLCLongCableUp() {return fLCLongCableUp;}
  Bool_t GetLCLongCableDown() { return fLCLongCableDown;}


/*  Control and Monitor different parts of the OM */

  void SetStausATWD_A(OnOff onoff) {fStatusATWD_A = onoff;}
  void SetStatusATWD_B(OnOff onoff) {fStatusATWD_B = onoff;}
  void SetStatusFADC(OnOff onoff) {fStatusFADC = onoff;}
  Bool_t GetStatusATWD_A(){return fStatusATWD_A;}
  Bool_t GetStatusATWD_B(){return fStatusATWD_B;}
  Bool_t GetStatusFADC(){return fStatusFADC;}


/* This controls the ATWD frequency.  Implementation, units remain TBD */

  void SetATWDFrequency(float freq) {fATWDFrequency = freq;}
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

  ClassDef(I3OMStatusIcecube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMStatusIcecube>::ThePolicy I3OMStatusIcecubePtr;

#endif


