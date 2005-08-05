/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Flasherinfo srklein$
 *
 * @file I3FlasherInfo.h
 * @version $Revision: 1.0 $
 * @date $Date: 2005-06-16 14:39:52 -0700 (Thu, 16 Jun 2005) $
 * @author klein
 *
 */
#ifndef I3FLASHERINFO_H
#define I3FLASHERINFO_H

#include "dataclasses/OMKey.h"

using namespace std; 
/**
 * @brief This contains the data on which DOM flashed during flasher runs
 *
 * It holds the flashing DOMs OMKey, brightness level, mask (which LEDs fired)
 * firing time, and ATWD trace of the LED current pulse 
 *
 */
class I3FlasherInfo
{

protected:

    /**  
     * This is the OM that flashed
     */

    OMKey flasherOM_; 
    /**
     *  Time (in nsec) in 25 nsec units, of the LED
     */

    double flashTime_;  

    /** 
     * These is the ATWD waveform of the LED current pulse, and the
     * ATWD time bin size, in nsec 
     */

    vector<int> rawATWD3_;
    double aTWDBinSize_;
    bool pedestalSubtractedATWD3_;

    /*  This holds the mask which showed which of the 12 LED(s) fired*/

    unsigned int mask_;

    /* This is the brightness level (1 to 127) */

     int LEDBrightness_;

    
public:
    /**
     * constructor
     */
     I3FlasherInfo():flashTime_(0.0),LEDBrightness_(0)
	{
	}

    /**
     * destructor
     */
    virtual ~I3FlasherInfo(){;}


    /* return and set OMKey */

    OMKey GetFlashingOM() const { return flasherOM_; }
    void SetFlashingOM(OMKey flashOM) { flasherOM_ = flashOM; }
  
    /**
     * return and set flash  time
     */
    double GetFlashTime() const { return flashTime_; }
    void SetFlashTime(double flashtime) { flashTime_ = flashtime; }

    /**
     * return and set ATWD time bin size
     */
    double GetATWDBinSize() const {return aTWDBinSize_;}
    void SetATWDBinSize(double ATWDbinsize) {aTWDBinSize_ = ATWDbinsize;}

    /* return and set LEDbrightness */

    int GetLEDBrightness() const { return LEDBrightness_; }
    void SetLEDBrightness(int LEDint) { LEDBrightness_ = LEDint; }


    /* return and set mask - which LEDs are on */

    unsigned int GetMask() const { return mask_; }
    void SetMask(int LEDmask) { mask_ = LEDmask; }



    /**
     * return raw ATWD3 waveform as a read-only object
     * ATWD3 holds the digitized LED current pulse; the others channels are empty
     */
    const vector<int>& GetRawATWD3() const {return rawATWD3_;}
  

    void SetPedestalIsSubtractedATWD3(bool subtracted) { pedestalSubtractedATWD3_ = subtracted; }

    
    /* is ATWD3 pedestal subtracted? */
    bool PedestalSubtractedATWD3() { return pedestalSubtractedATWD3_; }

    /* sets the ATWD3 waveform */
    void SetRawATWD3(const vector<int>& ATWD3data) {rawATWD3_=ATWD3data;}


    /* Dumps the file to the given ostream */

    virtual void ToStream(ostream& o) const
	{
	  o<<"LED Firing Time: "<< flashTime_ << " Intensity "<<LEDBrightness_;
	}

private:

    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, unsigned version)
	{
	    ar & make_nvp("FlasherOM", flasherOM_);
	    ar & make_nvp("FlashTime", flashTime_);
	    ar & make_nvp("ATWDBinSize", aTWDBinSize_);
	    //ar & make_nvp("Trigger", trigger_);
	    //trigger_ isn't defined anywhere
	    ar & make_nvp("RawATWD3", rawATWD3_);
	    ar & make_nvp("PedestalSubtractedATWD3", pedestalSubtractedATWD3_);
	    ar & make_nvp("mask", mask_);
	    ar & make_nvp("LEDBrightness", LEDBrightness_);
	}

};

/**
 * There is only one I3FlasherInfo, so should be no need for pointers
 */
typedef shared_ptr<I3FlasherInfo>  I3FlasherInfoPtr;


#endif

