/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalReadout.h,v 1.4 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3DigitalReadout.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 *
 */
#ifndef I3DIGITALREADOUT_H
#define I3DIGITALREADOUT_H

#include "StoragePolicy.h"
#include "I3DataReadout.h"

#include <vector>

using namespace std; 
/**
 * @brief A collection of digital signals.
 *
 */
class I3DigitalReadout : public I3DataReadout, public vector<Double_t>
{
  Double_t fStartTime;
  Double_t fBinSize;
 public:
  /**
   * constructor
   */
  I3DigitalReadout() 
    : fStartTime(0),
    fBinSize(0)
    {}

  /**
   * destructor
   */
  virtual ~I3DigitalReadout(){;}
  
  /** 
   * @return the start time of the series
   */
  Double_t StartTime() const { return fStartTime; }

  /**
   * @param starttime the new start time for the series
   */
  void StartTime(Double_t starttime) { fStartTime = starttime; }

  /**
   * @return the size of the time bins in this waveform
   */
  Double_t BinSize() const {return fBinSize;}

  /**
   * @param binsize is the new binsize for this waveform
   */
  void BinSize(Double_t binsize) {fBinSize = binsize;}

  /**
   * Gives the value of the waveform in absolute time, rather than 
   * 'by-bin.'  Give '0.0' if you ask outside bht bounds of the the array
   * @param absolutetime the time that you want the value of
   * @return the value of the waveform at the indicated absolutetime
   * after scaling by the binsize and adjusting by the start time.
   * @todo is 'truncation' right here?? I think so, but somebody should 
   * confirm it.
   */
  Double_t Value(Double_t absolutetime) const
    {
      unsigned int binlookup = (unsigned int)
	((absolutetime - fStartTime)/fBinSize);
      if(binlookup < 0 || binlookup >= size())
	return 0.0;
      return (*this)[binlookup];
    }
 private:
  // copy and assignment private
  I3DigitalReadout(const I3DigitalReadout&);
  const I3DigitalReadout& operator=(const I3DigitalReadout&);

  // ROOT macro
  ClassDef(I3DigitalReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalReadout>::ThePolicy I3DigitalReadoutPtr;

#endif

