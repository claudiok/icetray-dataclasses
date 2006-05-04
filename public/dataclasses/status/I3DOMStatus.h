#ifndef I3DOMSTATUS_H_INCLUDED
#define I3DOMSTATUS_H_INCLUDED

#include "dataclasses/Utility.h"


struct I3DOMStatus 
{

  I3DOMStatus():
    trigMode(UnknownTrigMode),
       lcMode(UnknownLCMode),
       lcWindowPre(NAN),
       lcWindowPost(NAN),
       lcSpan(INT_MAX),
       statusATWDa(Unknown),
       statusATWDb(Unknown),
       statusFADC(Unknown),
       pmtHV(NAN),
       speThreshold(NAN),
       dacTriggerBias0(NAN),
       dacTriggerBias1(NAN),
       dacFADCRef(NAN),
       nBinsATWD0(0),
       nBinsATWD1(0),
       nBinsATWD2(0),
       nBinsATWD3(0),
       nBinsFADC(0),
       fbState(Unknown),
       fbBrightness(INT_MAX),
       fbLength(INT_MAX),
       fbDelay(INT_MAX),
       fbMask(INT_MAX),
       fbRate(INT_MAX)
  {};

  virtual ~I3DOMStatus();
  /**
   * The different kinds of triggers that can be used for the dom
   * The standard data-taking operation is SPE
   */
  enum TrigMode { UnknownTrigMode = -1 , TestPattern = 0 , CPU = 1, SPE = 2, Flasher=3 };
  /**  
   * This controls how far the local coincidence signal is sent 
   */
  enum LCMode {UnknownLCMode = -1, LCOff = 0, UpOrDown = 1, Up = 2, Down = 3, UpAndDown =4};
  /**
   * There is also provision to turn on or off various settings in the 
   * DOM
   */
  enum OnOff {Unknown = -1, Off = 0, On = 1};
 
  /**
   * DOM internal trigger mode
   */
  TrigMode trigMode;
  
  /**
   * LC mode:  hard, soft, none
   */
  LCMode lcMode;

  /**
   *  Local coincidence window size, before ATWD launch window
   */
  double lcWindowPre;

  /**
   * Local coincidence window size, after ATWD launch window
   */
  double lcWindowPost;
  
  /**
   * Number of nearest neighbors to consider in LC search.(1,2,3 or 4)
   */
  unsigned int lcSpan;
  
  OnOff statusATWDa;
  OnOff statusATWDb;
  OnOff statusFADC;
  
  /**
   * Real operating PMT HV (Volts)
   */
  double pmtHV;

  /**
   *  Single PE (MPE) discriminator level. 
   */
  double speThreshold;
  /**
   * the Pedestal voltage of the analog front end.
   */
  double fePedestal;
  
  /**
   * Sets ATWD0 sampling speed. Higher DAC setting is faster sample rate.
   */
  double dacTriggerBias0;

  /**
   * Sets ATWD1 sampling speed. Higher DAC setting is faster sample rate.
   */
  double dacTriggerBias1;

  /**
   * FADC_DAC_REF - reference setting for FADC baseline
   */
  double dacFADCRef;
  
  unsigned int nBinsATWD0;
  unsigned int nBinsATWD1;
  unsigned int nBinsATWD2;
  unsigned int nBinsATWD3;
  unsigned int nBinsFADC;
    
  OnOff fbState;
  unsigned int fbBrightness;
  unsigned int fbLength;
  unsigned int fbDelay;
  unsigned int fbMask;
  unsigned int fbRate;


  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3DOMStatus);

#endif //I3DOMSTATUS_H_INCLUDED

