/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DOMLaunch.h
 * @version $Revision: 1.16 $
 * @date $Date$
 * @author klein
 * @author blaufuss
 * @author tmccauley
 *
 */
#ifndef I3DOMLAUNCH_H
#define I3DOMLAUNCH_H

#include "dataclasses/physics/I3DigitalLaunch.h"

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

public:  
    enum ATWDselect {ATWDa,ATWDb};

protected:
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
     * This is the ATWD time bin size, in nsec 
     */
    double aTWDBinSize_;

    /**  
     * This tells which ATWD in the DOM was used
     */
    ATWDselect whichATWD_;

    /** 
     * Raw ATWD channel 0 waveform
     */
    vector<int> rawATWD0_;

    /** 
     * Raw ATWD channel 1 waveform
     */
    vector<int> rawATWD1_;

    /** 
     * Raw ATWD channel 2 waveform 
     */
    vector<int> rawATWD2_;

    /** 
     * Raw ATWD channel 3 waveform
     */
    vector<int> rawATWD3_;

    /**
     * This holds the pedestal-subtracted and gain-corrected ATWD waveform.
     * Depending on the specific calibration, this is either a combination
     * of the ATWD channels or the lowest gain channel that doesn't have saturation.
     */
    vector<double> calibratedATWD_;

    /** 
     * This holds the 40 MHz FADC data 
     */
    vector<int> rawFADC_;

    /**
     * This holds the pedestal-subtracted and gain-corrected FADC data
     */
    vector<double> calibratedFADC_;

    /** 
     * This holds the local coincidence bit
     */
    bool localCoincidence_;

    /**
     * Raw course charge stamp
     */
    vector<int> rawChargeStamp_;

    /**
     * The raw course charge stamp is 9-bit, so
     * this tells us whether we're using the
     * upper or lower 10-bit range 
     */
    bool chargeStampRange_;
    
    /**
     * Calibrated course charge stamp
     */
    vector<double> calibratedChargeStamp_;

public:
    /**
     * constructor
     */
    I3DOMLaunch();

    /**
     * destructor
     */
    virtual ~I3DOMLaunch();
  
    /**
     * return and set ATWD/FADC launch time
     */
    double GetStartTime() const { return startTime_; }
    void SetStartTime(double starttime) { startTime_ = starttime; }

    /**
     * return and set ATWD time bin size
     */
    double GetATWDBinSize() const {return aTWDBinSize_;}
    void SetATWDBinSize(double ATWDbinsize) {aTWDBinSize_ = ATWDbinsize;}

    /**
     * return and set WhichATWD
     */
    ATWDselect GetWhichATWD() const {return whichATWD_;}
    void SetWhichATWD(ATWDselect WhichATWD) {whichATWD_ = WhichATWD;}

    /**
     * return raw ATWD 0 waveform as a read-only object
     */
    const vector<int>& GetRawATWD0() const {return rawATWD0_;}
  
    /**
     * return raw ATWD 1 waveform as a read-only object
     */
    const vector<int>& GetRawATWD1() const {return rawATWD1_;}

    /**
     * return raw ATWD 2 waveform as a read-only object
     */
    const vector<int>& GetRawATWD2() const {return rawATWD2_;}

    /**
     * return raw ATWD 3 waveform as a read-only object
     */
    const vector<int>& GetRawATWD3() const {return rawATWD3_;}

    /**
     * return raw ATWD by channel number
     */
    const vector<int>& GetRawATWD(int channel) const
	{
	    if ( channel == 0 )
	    {
		return rawATWD0_;
	    }
	    
	    else if ( channel == 1 )
	    {
		return rawATWD1_;
	    }
	    
	    else if ( channel == 2 )
	    {
		return rawATWD2_;
	    }
	    
	    else if ( channel == 3 )
	    {
		return rawATWD3_;
	    }
	    
	    else
	    {
		log_fatal("Bad ATWD channel in I3DOMLaunch::GetRawATWD(channel)");
                return *(vector<int>*)0;
	    }
	}
        
    /**
     * return raw FADC waveform as a read-only object
     */
    const vector<int>& GetRawFADC() const {return rawFADC_;}

    /**
     * return the pedestal subtracted and gain-corrected (i.e. calibrated) FADC
     */
    const vector<double>& GetCalibratedFADC() const 
	{
	    return calibratedFADC_;
	}
  
    /** 
     * return calibrated ATWD waveform
     */
    const vector<double>& GetCalibratedATWD() const
	{
	    return calibratedATWD_;
	}

    /**
     * return local coincidence bit as a read-only object
     */
    bool GetLCBit() const {return localCoincidence_;}

    /** 
     * Return the raw charge stamp
     */
    const vector<int>& GetRawChargeStamp() const 
	{
	    return rawChargeStamp_;
	};

    /**
     * Return the range for the raw charge stamp
     */
    const bool GetChargeStampRange() const
	{
	    return chargeStampRange_;
	};
    
    /**
     * Return the calibrated charge stamp
     */
    const vector<double>& GetCalibratedChargeStamp() const
	{
	    return calibratedChargeStamp_;
	};
   
    /**
     * sets the raw ATWD0 waveform
     */
    void SetRawATWD0(const vector<int>& ATWD0data) {rawATWD0_=ATWD0data;}

    /**
     * sets the raw ATWD1 waveform
     */
    void SetRawATWD1(const vector<int>& ATWD1data) {rawATWD1_=ATWD1data;}

    /**
     * sets the raw ATWD2 waveform
     */
    void SetRawATWD2(const vector<int>& ATWD2data) {rawATWD2_=ATWD2data;}

    /**
     * sets the ATWD2 waveform
     */
    void SetRawATWD3(const vector<int>& ATWD3data) {rawATWD3_=ATWD3data;}

    /** 
     * set ATWD by channel number
     */
    void SetRawATWD(int channel, const vector<int>& ATWDdata)
	{
	    if ( channel == 0 )
	    {
		rawATWD0_ = ATWDdata;
		return;
	    }
	    
	    else if ( channel == 1 )
	    {
		rawATWD1_ = ATWDdata;
		return;
	    }
	    
	    else if ( channel == 2 )
	    {
		rawATWD2_ = ATWDdata;
		return;
	    }
	    
	    else if ( channel == 3 )
	    {
		rawATWD3_ = ATWDdata;
		return;
	    }
	    
	    else 
	    {
		log_fatal("Bad ATWD channel in I3DOMLaunch::GetRawATWD(channel)");
		throw std::exception();
	    }
	}    

    /**
     * sets the raw FADC waveform
     */
    void SetRawFADC(const vector<int>& FADCdata) {rawFADC_=FADCdata;}

    /**
     * sets the calibrated FADC waveform
     */
    void SetCalibratedFADC (const vector<double> &pgfadc_data) { calibratedFADC_ = pgfadc_data;}

    /**
     * sets the combined ATWD waveform
     */
    void SetCalibratedATWD(const vector<double>& CalibratedATWD) 
	{
	    calibratedATWD_ = CalibratedATWD;
	};
  
    /**
     * sets the local coincidence bit
     */
    void SetLCBit(const bool & LCBit) {localCoincidence_=LCBit;}

    /**
     * Set the coarse charge stamp
     */
    void SetRawChargeStamp(const vector<int>& chargeStamp)
	{
	    rawChargeStamp_ = chargeStamp;
	};

    /** 
     * Set the bit range for the raw charge stamp
     */
    void SetChargeStampRange(const bool range)
	{
	    chargeStampRange_ = range;
	};
    
    /** 
     * Set the calibrated charge stamp
     */
    void SetCalibratedChargeStamp(const vector<double>& chargeStamp)
	{
	    calibratedChargeStamp_ = chargeStamp;
	};
    
    /**
     * Dumps the file to the given ostream
     */
    virtual void ToStream(ostream& o) const
	{
	    I3DigitalLaunch::ToStream(o);
	    o<<"StartTime: "<< startTime_;
	}

private:

    friend class boost::serialization::access;

    template <class Archive> void serialize(Archive & ar, unsigned version);
    
    // ROOT macro
    //ClassDef(I3DOMLaunch,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DOMLaunch>  I3DOMLaunchPtr;

#endif


