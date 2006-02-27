/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3Flasherinfo srklein$
 * @file I3FlasherInfo.h
 * @date $Date: 2005-06-16 14:39:52 -0700 (Thu, 16 Jun 2005) $
 */

#ifndef I3FLASHERINFO_H_INCLUDED
#define I3FLASHERINFO_H_INCLUDED

#include <TObject.h>
#include "dataclasses/OMKey.h"

using namespace std; 

enum EventFlasherStatusType{single_flasher = 0, muon_event = 1, 
  multi_flasher = 2,flasher_not_set = -1};

/**
 * @brief This contains the data on which DOM flashed during flasher runs
 *
 * It holds the flashing DOMs OMKey, brightness level, mask (which LEDs fired)
 * firing time, and ATWD trace of the LED current pulse 
 * 
 * This will be changed into a I3Trigger derrived class eventually, once there
 * is sufficient funcionality to get Flasher settings somewhere.
 * Included here for use by flasher analysis people.  It can be "I3Bagged".
 *
 */
class I3FlasherInfo : public TObject
{

protected:

    /**  
     * This is the OM that flashed
     */

    OMKey flasherOM_; 
    /**
     *  Time (in nsec) in 25 nsec units, of the LED flash time.
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

     EventFlasherStatusType eventFlasherStatus_;

    
public:
 
    I3FlasherInfo():flashTime_(0.0),LEDBrightness_(0)
	{
	  eventFlasherStatus_= flasher_not_set;
	}

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


    /* return and set whether a particular event is a muon or not
     * for use by muon-filter
     */
    
     EventFlasherStatusType GetEventFlasherStatus() const 
     {return eventFlasherStatus_;}
     void SetEventFlasherStatus(EventFlasherStatusType eventFlasherStatus) 
     {eventFlasherStatus_=eventFlasherStatus;}


    /**
     * return raw ATWD3 waveform as a read-only object
     * ATWD3 holds the digitized LED current pulse; the others channels are empty
     */
    const vector<int>& GetRawATWD3() const {return rawATWD3_;}
  

 //   void SetPedestalIsSubtractedATWD3(bool subtracted) { pedestalSubtractedATWD3_ = subtracted; }

    
    /* is ATWD3 pedestal subtracted? */
   // bool PedestalSubtractedATWD3() { return pedestalSubtractedATWD3_; }

    /* sets the ATWD3 waveform */
    void SetRawATWD3(const vector<int>& ATWD3data) {rawATWD3_=ATWD3data;}


private:

    friend class boost::serialization::access;

    template <class Archive> void serialize(Archive & ar, unsigned version);

//ClassDef(I3FlasherInfo,1);
};

I3_POINTER_TYPEDEFS(I3FlasherInfo);

#endif //I3FLASHERINFO_H_INCLUDED


