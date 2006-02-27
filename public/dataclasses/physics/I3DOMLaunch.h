/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3DOMLaunch.h
 * @date $Date$
 */

#ifndef I3DOMLAUNCH_H_INCLUDED
#define I3DOMLAUNCH_H_INCLUDED

#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"


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
class I3DOMLaunch 
{

public:  
    enum ATWDselect {ATWDa,ATWDb};

private:
    /**  
     * This is the time (in nsec) in 25 nsec units, of the DOM clock 
     * which launches the ATWD (launch is synchronized to the first clock 
     * transition AFTER the discriminator fires 
     */
    double startTime_;  

    /**  
     * This holds the trigger information -somewhat of a placeholder for now 
     * Q: Will this be used at all? -tpm
     */
    int trigger_;

    /**  
     * This tells which ATWD in the DOM was used
     */
    ATWDselect whichATWD_;

    /** 
     * Raw ATWD channel 0 to 3
     */
    I3Vector<I3Vector<int> > rawATWD_;

    /** 
     * This holds the 40 MHz FADC data 
     */
    I3Vector<int> rawFADC_;

    /** 
     * This holds the local coincidence bit
     */
    bool localCoincidence_;

    /**
     * Raw course charge stamp
     */
    I3Vector<int> rawChargeStamp_;

    /**
     * The raw course charge stamp is 9-bit, so
     * this tells us whether we're using the
     * upper or lower 10-bit range 
     */
    bool chargeStampRange_;

public:

    /**
     * Default constructor.
     */
    I3DOMLaunch();

    /**
     * Destructor.
     */
    virtual ~I3DOMLaunch();
  
    /**
     * Return ATWD/FADC launch time.
     */
    double GetStartTime() const { return startTime_; }

    /**
     * Set ATWD/FADC launch time.
     */
    void SetStartTime(double starttime) { startTime_ = starttime; }

    /**
     * Return which ATWD.
     */
    ATWDselect GetWhichATWD() const { return whichATWD_; }

    /**
     * Set which ATWD.
     */
    void SetWhichATWD(ATWDselect WhichATWD) { whichATWD_ = WhichATWD; }

    /**
     * Return raw ATWD by channel number
     */
    const I3Vector<int>& GetRawATWD(unsigned int channel) const
    {
      if(channel >= rawATWD_.size())
        log_fatal("Bad ATWD channel in I3DOMLaunch::GetRawATWD(channel)");
      return rawATWD_[channel];
    }

    I3Vector<int>& GetRawATWD(unsigned int channel)
    {
      if(channel >= rawATWD_.size())
        log_fatal("Bad ATWD channel in I3DOMLaunch::GetRawATWD(channel)");
      return rawATWD_[channel];
    }
        
    /**
     * Return raw FADC waveform.
     */
    const I3Vector<int>& GetRawFADC() const { return rawFADC_; }
    I3Vector<int>& GetRawFADC() { return rawFADC_; }

    /**
     * Return local coincidence bit.
     */
    bool GetLCBit() const { return localCoincidence_; }
  
    /**
     * Set the local coincidence bit.
     */
    void SetLCBit(bool LCBit) {localCoincidence_=LCBit;}

    /** 
     * Return the raw charge stamp.
     */
    const I3Vector<int>& GetRawChargeStamp() const { return rawChargeStamp_; }
    I3Vector<int>& GetRawChargeStamp() { return rawChargeStamp_; }

    /**
     * Return the range for the raw charge stamp.
     */
    const bool GetChargeStampRange() const { return chargeStampRange_; }

    /** 
     * Set the range for the raw charge stamp.
     */
    void SetChargeStampRange(bool range)
    {
      chargeStampRange_ = range;
    };

private:
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3DOMLaunch);

typedef I3Vector<I3DOMLaunch> I3DOMLaunchSeries;
typedef I3Map<OMKey, I3DOMLaunchSeries> I3DOMLaunchSeriesMap;

#endif //I3DOMLAUNCH_H_INCLUDED


