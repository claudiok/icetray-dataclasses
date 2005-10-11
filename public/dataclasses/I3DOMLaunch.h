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
 *
 */
#ifndef I3DOMLAUNCH_H
#define I3DOMLAUNCH_H

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

public:  

    enum ATWDselect {ATWDa,ATWDb};

protected:

    /**  
     * This is the time (in nsec) in 25 nsec units, of the DOM clock 
     * which launches the ATWD (launch is synchronized to the first clock 
     * transition AFTER the discriinator fires 
     */
    double startTime_;  

    /** 
     * This is the ATWD time bin size, in nsec 
     */
    double aTWDBinSize_;

    /**  
     * This holds the trigger information -somewhat of a placeholder for now 
     */
    int trigger_;
  
    /**  
     * This tells which ATWD in the DOM was used
     */
    ATWDselect whichATWD_;

    /** 
     * These contain the 4 ATWD waveforms - same time bins, but different 
     * gains.  All are 128 samples 
     */
    vector<int> rawATWD0_;

    /** These contain the 4 ATWD waveforms - same time bins, but different 
     *  gains. All are 128 samples 
     */
    vector<int> rawATWD1_;

    /** 
     * These contain the 4 ATWD waveforms - same time bins, but different 
     * gains.  All are 128 samples 
     */
    vector<int> rawATWD2_;

    /** 
     * These contain the 4 ATWD waveforms - same time bins, but different 
     * gains.  All are 128 samples 
     */
    vector<int> rawATWD3_;

    /** 
     * This holds the 40 MHz FADC data 
     */
    vector<int> rawFADC_;

    /**
     * This holds the pedestal subtracted and gain-corrected FADC data
     */
    vector<double> calibratedFADC_;

    /**
     * This holds the combined (pedestal subtracted and gain-corrected)
     * ATWD waveform (over the 3 channels).
     * The combination utilizes the calibration information.
     */
    vector<double> calibratedATWD_;
    
    /** 
     * This holds the local coincidence bit
     */
    bool localCoincidence_;

    /** 
     * Has the pedestal been subtracted from the waveforms?
     */ 

    /*
      NOTE: no longer needed - tpm
    bool pedestalSubtractedATWD0_;
    bool pedestalSubtractedATWD1_;
    bool pedestalSubtractedATWD2_;
    bool pedestalSubtractedATWD3_;
    
    bool pedestalSubtractedFADC_;
    */

public:
    /**
     * constructor
     */
    I3DOMLaunch() 
	{
	    startTime_ = 0.0;
	   
	    /*	
	      NOTE: no longer needed - tpm
	    pedestalSubtractedATWD0_ = false;
	    pedestalSubtractedATWD1_ = false;
	    pedestalSubtractedATWD2_ = false;
	    pedestalSubtractedATWD3_ = false;

	    pedestalSubtractedFADC_ = false;
	    */
	}

    /**
     * destructor
     */
    virtual ~I3DOMLaunch(){;}
  
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
     * set if pedestal is subtracted for ATWDs and FADC
     */
    /*
      NOTE: no longer needed - tpm
    void SetPedestalIsSubtractedATWD0(bool subtracted) { pedestalSubtractedATWD0_ = subtracted; }
    void SetPedestalIsSubtractedATWD1(bool subtracted) { pedestalSubtractedATWD1_ = subtracted; }
    void SetPedestalIsSubtractedATWD2(bool subtracted) { pedestalSubtractedATWD2_ = subtracted; }
    void SetPedestalIsSubtractedATWD3(bool subtracted) { pedestalSubtractedATWD3_ = subtracted; }

    void SetPedestalIsSubtractedFADC(bool subtracted) { pedestalSubtractedFADC_ = subtracted; }
    */
    
    /**
     * is pedestal subtracted for ATWDs and FADC?
     **/
    /*
      NOTE: no longer needed - tpm
    bool PedestalSubtractedATWD0() { return pedestalSubtractedATWD0_; }
    bool PedestalSubtractedATWD1() { return pedestalSubtractedATWD1_; }
    bool PedestalSubtractedATWD2() { return pedestalSubtractedATWD2_; }
    bool PedestalSubtractedATWD3() { return pedestalSubtractedATWD3_; }

    bool PedestalSubtractedFADC() { return pedestalSubtractedFADC_; }

    bool PedestalSubtractedATWD(int channel)
	{
	    if ( channel == 0 )
	    {
		return pedestalSubtractedATWD0_;
	    }
	    
	    else if ( channel == 1 )
	    {
		return pedestalSubtractedATWD1_;
	    }
	    
	    else if ( channel == 2 )
	    {
		return pedestalSubtractedATWD2_;
	    }
	    
	    else if ( channel == 3 )
	    {
		return pedestalSubtractedATWD3_;
	    }
	    
	    else 
	    {
		log_fatal("Bad ATWD channel in I3DOMLaunch::PedestalSubtractedATWD(channel)");
		throw std::exception();
	    }
	}
    */

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
     * return local coincidence bit as a read-only object
     */
    bool GetLCBit() const {return localCoincidence_;}
  
    /**
     * sets the local coincidence bit
     */
    void SetLCBit(const bool & LCBit) {localCoincidence_=LCBit;}

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
    ClassDef(I3DOMLaunch,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DOMLaunch>  I3DOMLaunchPtr;

#endif


