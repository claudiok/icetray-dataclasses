/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DOMLaunch.h,v 1.3 2004/10/19 01:17:10 spencer Exp $
 *
 * @file I3DOMLaunch.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/10/19 01:17:10 $
 * @author klein
 * @author blaufuss
 *
 */
#ifndef I3DOMLAUNCH_H
#define I3DOMLAUNCH_H

//#include "StoragePolicy.h"
#include "dataclasses/I3DigitalLaunch.h"

using namespace std; 
/**
 * @brief The direct (digital) readout of an IceCube DOM
 * 
 * The full digital readout of an IceCube DOM consists of one to three
 * short but fine-grained ATWD readouts, and a long but coarse fADC
 * readout, all beginning at the same time.  The fADC is fixed at 40
 * MHz, while the sampling rate of the ATWDs is adjustable and is
 * stored in the ATWDBinSize variable.
 *
 */
class I3DOMLaunch : public I3DigitalLaunch
{

  /**  
   * This is the time (in nsec) in 25 nsec units, of the DOM clock 
   * which launches the ATWD (launch is synchronized to the first clock 
   * transition AFTER the discriinator fires 
   */
  Double_t fStartTime;  

  /** 
   * This is the ATWD time bin size, in nsec 
   */
  Double_t fATWDBinSize;

  /**  
   * This holds the trigger information -somewhat of a placeholder for now 
   */
  Int_t fTrigger;

  /** 
   * These contain the 3 ATWD waveforms - same time bins, but different 
   * gains.  All are 128 samples 
   */
  vector<Int_t> fATWD0;

  /** These contain the 3 ATWD waveforms - same time bins, but different 
   * gains.  All are 128 samples 
   */
  vector<Int_t> fATWD1;

  /** 
   * These contain the 3 ATWD waveforms - same time bins, but different 
   * gains.  All are 128 samples 
   */
  vector<Int_t> fATWD2;

  /** 
   * This holds the 40 MHz FADC data 
   */
  vector<Int_t> fFADC;

  /** 
   * This holds the local coincidence bit
   */
  Bool_t fLocalCoincidence;

 public:
  /**
   * constructor
   */
  I3DOMLaunch() {fStartTime=0.;}

  /**
   * destructor
   */
  virtual ~I3DOMLaunch(){;}
  
  /**
   * return ATWD/FADC launch time
   */
  Double_t GetStartTime() const { return fStartTime; }

  /**
   * set ATWD/FADC launch time
   */
  void SetStartTime(Double_t starttime) { fStartTime = starttime; }

  /**
   * return ATWD time bin size
   */
  Double_t GetATWDBinSize() const {return fATWDBinSize;}

  /**
   * set ATWD time bin size 
   */
  void SetATWDBinSize(Double_t ATWDbinsize) {fATWDBinSize = ATWDbinsize;}
  
  /**
   * return ATWD 0 waveform as a read-only object
   */
  const vector<Int_t>& GetATWD0() const {return fATWD0;}
  
  /**
   * return ATWD 1 waveform as a read-only object
   */
  const vector<Int_t>& GetATWD1() const {return fATWD1;}

  /**
   * return ATWD 2 waveform as a read-only object
   */
  const vector<Int_t>& GetATWD2() const {return fATWD2;}

  /**
   * return FADC waveform as a read-only object
   */
  const vector<Int_t>& GetFADC() const {return fFADC;}
  
  /**
   * sets the ATWD0 waveform
   */
 void SetATWD0(const vector<Int_t>& ATWD0data) {fATWD0=ATWD0data;}

 /**
  * sets the ATWD1 waveform
  */
 void SetATWD1(const vector<Int_t>& ATWD1data) {fATWD1=ATWD1data;}

 /**
  * sets the ATWD2 waveform
  */
 void SetATWD2(const vector<Int_t>& ATWD2data) {fATWD2=ATWD2data;}

 /**
  * sets the FADC waveform
  */
 void SetFADC(const vector<Int_t>& FADCdata) {fFADC=FADCdata;}

  /**
   * return local coincidence bit as a read-only object
   */
 Bool_t GetLCBit() const {return fLocalCoincidence;}
  
 /**
  * sets the local coincidence bit
  */
 void SetLCBit(const Bool_t & LCBit) {fLocalCoincidence=LCBit;}


 /**
  * Dumps the file to the given ostream
  */
 virtual void ToStream(ostream& o) const
   {
     I3DigitalLaunch::ToStream(o);
     o<<"StartTime: "<<fStartTime;
   }

 private:
  // copy and assignment private
  I3DOMLaunch(const I3DOMLaunch&);
  const I3DOMLaunch& operator=(const I3DOMLaunch&);

  // ROOT macro
  ClassDef(I3DOMLaunch,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DOMLaunch>::ThePolicy I3DOMLaunchPtr;

#endif

