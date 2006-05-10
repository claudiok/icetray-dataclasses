
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 *
 * @file I3DOMLaunch.h
 * @version $Revision: 1.10 $
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
 * The full digital readout of an IceCube DOM consists of one to four
 * short but fine-grained ATWD readouts, and a long but coarse fADC
 * readout, all beginning at the same time. The fADC is fixed at 40
 * MHz, while the sampling rate of the ATWDs is adjustable and will be
 * determined by the DOM calibrator.
 */
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
      FLASHER_BOARD_TRIGGER = 3
    };
    
    enum TriggerMode
    {
      UNDEFINED = 0,
      /** Set if signals from both upper and lower DOMs are required
       *  to satisfy local coincidence */
      REQUIRE_BOTH = 1,
      /** Set if flasher board run is in the progress */
      FR_RUN = 2,
      /** Set if local coincidence requirement is met, and
       *  LC has been configured to be received by the lower DOM */
      LC_LOWER = 4,
      /** Set if local coincidence requirement is met, and
       *  LC has been configured to be received by the upper DOM */
      LC_UPPER = 8,
      /** in case of an invalid trigger setting, the UNKNOWN_MODE is set and
       *  the test pattern trigger is used */
      UNKNOWN_MODE = 16,
      LAST_TRIGGER_SITUATION = 1 << 5
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
     * no information available that would indicate which neighbouring DOM
     * caused the LC requirement to be met. Rather, modes LC_UPPER and LC_LOWER
     * are a reflection of how the DOM was configured at the time this launch
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

typedef std::vector<I3DOMLaunch> I3DOMLaunchSeries;
typedef I3Map<OMKey, I3DOMLaunchSeries> I3DOMLaunchSeriesMap;

I3_POINTER_TYPEDEFS(I3DOMLaunchSeries);
I3_POINTER_TYPEDEFS(I3DOMLaunchSeriesMap);


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
