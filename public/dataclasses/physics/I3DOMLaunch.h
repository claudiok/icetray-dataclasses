
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 *
 * @file I3DOMLaunch.h
 * @version $Revision: 1.11 $
 * @date $Date$
 */

#ifndef I3DOMLAUNCH_H_INCLUDED
#define I3DOMLAUNCH_H_INCLUDED

#include <vector>

#include <dataclasses/I3Vector.h>
#include <dataclasses/I3Map.h>
#include <dataclasses/OMKey.h>

/**
 * @brief The direct (digital) readout of an IceCube DOM
 * 
 * The full digital readout of an IceCube DOM consists of 1-4
 * short but fine-grained ATWD readouts, and a long but coarse fADC
 * readout, all beginning at the same time. The fADC is fixed at 40
 * MHz, while the sampling rate of the ATWDs is adjustable and is
 * determined by the DOM calibrator. There is also a 'coarse charge stamp'
 * containing the 3 largest samples out of the first 16 fADC samples
 */
static const unsigned i3domlaunch_version_ = 3;

class I3DOMLaunch 
{
public:  
    enum ATWDselect
    {
      ATWDa = 1,
      ATWDb = 2
    };
    
    enum TriggerType
    {
      TEST_PATTERN = 0,
      CPU_REQUESTED = 1,
      SPE_DISCRIMINATOR_TRIGGER = 2,
      FLASHER_BOARD_TRIGGER = 3,
      MPE_DISCRIMINATOR_TRIGGER = 4,
      ONBOARD_LED = 5
    };
    
    enum TriggerMode
    {
      UNDEFINED = 0,
      /** Set if signals from both upper and lower DOMs are required
       *  to satisfy local coincidence */
      REQUIRE_BOTH = 1L << 0,
      /** Set if flasher board run is in the progress */
      FR_RUN = 1L << 1,
      /** Set if local coincidence requirement is met, and
       *  LC has been configured to be received by the lower DOM */
      LC_LOWER = 1L << 2,
      /** Set if local coincidence requirement is met, and
       *  LC has been configured to be received by the upper DOM */
      LC_UPPER = 1L << 3,
      /** in case of an invalid trigger setting, the UNKNOWN_MODE is set and
       *  the test pattern trigger is used */
      UNKNOWN_MODE = 1L << 4,
      // first five bits come originally from the engineering format
      // keep three additional bits reserved
      // and use the upper eight bits for artificial modes like SLC
      /** Set if the DOM triggered with SLC condition met */
      SLC_READOUT = 1L << 8,
      /** limit this enum on a 16 bit value range */
      LAST_TRIGGER_SITUATION = 1 << 16
    };

private:
    /**  
     * This is the time (in nsec) in 25 nsec units, of the DOM clock 
     * which launches the ATWD (launch is synchronized to the first clock 
     * transition AFTER the discriminator fires 
     */
    double startTime_;  

    /**  
     * This represents the trigger type
     */
    TriggerType trigger_;
    
    /**
     * This signals special trigger circumstances
     */
    TriggerMode mode_;

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
     * These values are already unpacked to full 10-bit numbers
     */
    I3Vector<int> rawChargeStamp_;

    /**
     *  chargeStampHighestSample runs from 1-16, and points to the highest fADC
     *  sample in the first 16 samples; this is from the charge stamp
     */
    unsigned int chargeStampHighestSample_;

    /*  chargeStampRange_ has been deleted - on the rare occassions anyone cares, 
     *  they can see if any of the samples are above 512  */
    /**
     * pedestal_ is a bool that tells you if the pedestal_ has or has not
     * been subtracted from the waveforms. This is only for delta-compressed
     * waveforms. True means pedestal has been subtracted. Flase means it
     * has not been subtracted.
     */
    bool pedestal_;
  

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
     * Return the trigger type/why this launch was recorded
     * (SPE_DISCRIMINATOR_TRIGGER is the standard 'physics data').
     */
    TriggerType GetTriggerType() const { return trigger_; }
    
    /**
     * Specify the trigger type/why this launch was recorded.
     */
    void SetTriggerType(TriggerType trigger) { trigger_ = trigger; }

    /**
     * Signals the special trigger circumstances. 
     *
     * Note: In testdomapp, the current FPGA implementation in the DOM, there is
     * no information available to indicate which neighbouring DOM
     * caused the LC requirement to be met. Rather, modes LC_UPPER and LC_LOWER
     * reflect how the DOM was configured at the time this launch
     * was recorded. So if signals from both upper and lower DOMs are required
     * to satisfy local coincidence, LC_UPPER and LC_LOWER will be set.
     */
    TriggerMode GetTriggerMode() const { return mode_; }
    
    /**
     * Sets the special trigger circumstances.
     */
    void SetTriggerMode(TriggerMode situation) { mode_ = situation; }

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
    * return Pedestal bool.
    */
   bool GetIsPedestalSub() const { return pedestal_; }
  
    /**
    * Set the pedestal bool
    */
   void SetIsPedestalSub(bool Pedestal) {pedestal_ = Pedestal;}
  
  /** 
     * Return the raw charge stamp.
     */
    const I3Vector<int>& GetRawChargeStamp() const { return rawChargeStamp_; }
    I3Vector<int>& GetRawChargeStamp() { return rawChargeStamp_; }

    /**
     * Return charge stamp highest sample
     */
    unsigned int GetChargeStampHighestSample() const { return chargeStampHighestSample_; }

    /** 
     * Set the charge stamp highest sample
     */
    void SetChargeStampHighestSample(unsigned int highsample)
    {
      chargeStampHighestSample_ = highsample;
    };

private:
    friend class boost::serialization::access;
	
    template <class Archive> void save(Archive & ar, unsigned version) const;
    template <class Archive> void load(Archive & ar, unsigned version);
	BOOST_SERIALIZATION_SPLIT_MEMBER();
};

BOOST_CLASS_VERSION(I3DOMLaunch, i3domlaunch_version_);
I3_POINTER_TYPEDEFS(I3DOMLaunch);

typedef std::vector<I3DOMLaunch> I3DOMLaunchSeries;
typedef I3Map<OMKey, I3DOMLaunchSeries> I3DOMLaunchSeriesMap;

I3_POINTER_TYPEDEFS(I3DOMLaunchSeries);
#ifdef I3_USE_FAST_OMKEY_MAP
BOOST_CLASS_VERSION(I3DOMLaunchSeriesMap, 1);
#endif
I3_POINTER_TYPEDEFS(I3DOMLaunchSeriesMap);

bool operator==(const I3DOMLaunch& lhs, const I3DOMLaunch& rhs);

/**
 * Bit operators to combine different trigger modes.
 * 
 * As an example:
 * One might set I3DOMLaunch::LC_LOWER | I3DOMLaunch::LC_UPPER, if the local
 * coincidence condition for the lower and upper DOM is met at the same time.
 */
inline I3DOMLaunch::TriggerMode
operator|(I3DOMLaunch::TriggerMode a, I3DOMLaunch::TriggerMode b)
{
  return I3DOMLaunch::TriggerMode(static_cast<int>(a) | static_cast<int>(b));
}


inline I3DOMLaunch::TriggerMode
operator&(I3DOMLaunch::TriggerMode a, I3DOMLaunch::TriggerMode b)
{
  return I3DOMLaunch::TriggerMode(static_cast<int>(a) & static_cast<int>(b));
}


inline I3DOMLaunch::TriggerMode
operator^(I3DOMLaunch::TriggerMode a, I3DOMLaunch::TriggerMode b)
{
  return I3DOMLaunch::TriggerMode(static_cast<int>(a) ^ static_cast<int>(b));
}


inline I3DOMLaunch::TriggerMode&
operator|=(I3DOMLaunch::TriggerMode& a, I3DOMLaunch::TriggerMode b)
{
  return a = a | b;
}


inline I3DOMLaunch::TriggerMode&
operator&=(I3DOMLaunch::TriggerMode& a, I3DOMLaunch::TriggerMode b)
{
  return a = a & b;
}


inline I3DOMLaunch::TriggerMode&
operator^=(I3DOMLaunch::TriggerMode& a, I3DOMLaunch::TriggerMode b)
{
  return a = a ^ b;
}


inline I3DOMLaunch::TriggerMode
operator~(I3DOMLaunch::TriggerMode a)
{
  return I3DOMLaunch::TriggerMode(~static_cast<int>(a));
}

#endif // I3DOMLAUNCH_H_INCLUDED
