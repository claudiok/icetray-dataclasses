/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DOMReadout.h,v 1.2 2004/07/15 20:29:25 deyoung Exp $
 *
 * @file I3DOMReadout.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/15 20:29:25 $
 * @author klein
 *
 */
#ifndef I3DOMREADOUT_H
#define I3DOMREADOUT_H

//#include "StoragePolicy.h"
#include "I3DataReadout.h"

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
class I3DOMReadout : public I3DataReadout
{

/*  This is the time (in nsec) in 25 nsec units, of the DOM clock which
launches the ATWD (launch is synchronized to the first clock transition
AFTER the discriinator fires */

  Double_t fStartTime;  

/*  This is the ATWD time bin size, in nsec */

  Double_t fATWDBinSize;

  /*  This holds the trigger information -somewhat of a placeholder for now */

  Int_t fTrigger;

/* These contain the 3 ATWD waveforms - same time bins, but different gains*
   All are 128 samples */

  vector<Int_t> fATWD0;
  vector<Int_t> fATWD1;
  vector<Int_t> fATWD2;

  /* This holds the 40 MHz FADC data */

  vector<Int_t> fFADC;

 public:
  /**
   * constructor
   */
  I3DOMReadout() {fStartTime=0.;}

  /**
   * destructor
   */
  virtual ~I3DOMReadout(){;}
  
  // set ATWD/FADC launch time

  Double_t StartTime() const { return fStartTime; }

  // return ATWD/FADC launch time

  void StartTime(Double_t starttime) { fStartTime = starttime; }

  // return ATWD time bin size

  Double_t ATWDBinSize() const {return fATWDBinSize;}

  // set ATWD time bin size 

  void ATWDBinSize(Double_t ATWDbinsize) {fATWDBinSize = ATWDbinsize;}

// return ATWD and FADC waveforms

const vector<Int_t>& ATWD0() const {return fATWD0;}
const vector<Int_t>& ATWD1() const {return fATWD1;}
const vector<Int_t>& ATWD2() const {return fATWD2;}
const vector<Int_t>& FADC()  const {return fFADC;}

// set ATWD and FADC waveforms

 void ATWD0(vector<Int_t> ATWD0data) {fATWD0=ATWD0data;}
 void ATWD1(vector<Int_t> ATWD1data) {fATWD1=ATWD1data;}
 void ATWD2(vector<Int_t> ATWD2data) {fATWD2=ATWD2data;}
 void FADC(vector<Int_t> FADCdata) {fFADC=FADCdata;}

 private:
  // copy and assignment private
  I3DOMReadout(const I3DOMReadout&);
  const I3DOMReadout& operator=(const I3DOMReadout&);

  // ROOT macro
  ClassDef(I3DOMReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DOMReadout>::ThePolicy I3DOMReadoutPtr;

#endif

