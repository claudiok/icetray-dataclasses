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
  vector<int> aTWD0_;

  /** These contain the 4 ATWD waveforms - same time bins, but different 
   * gains.  All are 128 samples 
   */
  vector<int> aTWD1_;

  /** 
   * These contain the 4 ATWD waveforms - same time bins, but different 
   * gains.  All are 128 samples 
   */
  vector<int> aTWD2_;

  /** 
   * These contain the 4 ATWD waveforms - same time bins, but different 
   * gains.  All are 128 samples 
   */
  vector<int> aTWD3_;

  /** 
   * This holds the 40 MHz FADC data 
   */
  vector<int> fADC_;

  /**
   * This holds the combined ATWD waveform (over the 3 channels).
   * The combination utilizes the calibration information.
   */
  vector<double> combinedATWD_;
    
  /** 
   * This holds the local coincidence bit
   */
  bool localCoincidence_;

 public:
  /**
   * constructor
   */
  I3DOMLaunch() {startTime_=0.;}

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
   * return ATWD 0 waveform as a read-only object
   */
  const vector<int>& GetATWD0() const {return aTWD0_;}
  
  /**
   * return ATWD 1 waveform as a read-only object
   */
  const vector<int>& GetATWD1() const {return aTWD1_;}

  /**
   * return ATWD 2 waveform as a read-only object
   */
  const vector<int>& GetATWD2() const {return aTWD2_;}

  /**
   * return ATWD 3 waveform as a read-only object
   */
  const vector<int>& GetATWD3() const {return aTWD3_;}

  /**
   * return ATWD by channel number
   */
    const vector<int>& GetATWD(int channel) const
	{
	    if ( channel == 0 )
	    {
		return aTWD0_;
	    }
	    
	    else if ( channel == 1 )
	    {
		return aTWD1_;
	    }
	    
	    else if ( channel == 2 )
	    {
		return aTWD2_;
	    }
	    
	    else if ( channel == 3 )
	    {
		return aTWD3_;
	    }
	    
	    else
	    {
		log_fatal("Bad ATWD channel in I3DOMLaunch::GetATWD(channel)");
                return *(vector<int>*)0;
	    }
	}
    
    
  /**
   * return FADC waveform as a read-only object
   */
  const vector<int>& GetFADC() const {return fADC_;}
  
  /** 
   * return combined ATWD waveform
   */
  const vector<double>& GetCombinedATWD() const
	{
	    return combinedATWD_;
	}
    
  /**
   * sets the ATWD0 waveform
   */
 void SetATWD0(const vector<int>& ATWD0data) {aTWD0_=ATWD0data;}

 /**
  * sets the ATWD1 waveform
  */
 void SetATWD1(const vector<int>& ATWD1data) {aTWD1_=ATWD1data;}

 /**
  * sets the ATWD2 waveform
  */
 void SetATWD2(const vector<int>& ATWD2data) {aTWD2_=ATWD2data;}

 /**
  * sets the ATWD2 waveform
  */
 void SetATWD3(const vector<int>& ATWD3data) {aTWD3_=ATWD3data;}

  /** 
   * set ATWD by channel number
   */
    void SetATWD(int channel, const vector<int>& ATWDdata)
	{
	    if ( channel == 0 )
	    {
		aTWD0_ = ATWDdata;
		return;
	    }
	    
	    else if ( channel == 1 )
	    {
		aTWD1_ = ATWDdata;
		return;
	    }
	    
	    else if ( channel == 2 )
	    {
		aTWD2_ = ATWDdata;
		return;
	    }
	    
	    else if ( channel == 3 )
	    {
		aTWD3_ = ATWDdata;
		return;
	    }
	    
	    else 
	    {
		log_fatal("Bad ATWD channel in I3DOMLaunch::GetATWD(channel)");
		throw std::exception();
	    }
	}    

 /**
  * sets the FADC waveform
  */
 void SetFADC(const vector<int>& FADCdata) {fADC_=FADCdata;}

  /**
   * sets the combined ATWD waveform
   */
  void SetCombinedATWD(const vector<double>& CombinedATWD) 
	{
	    combinedATWD_ = CombinedATWD;
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
     o<<"StartTime: "<<startTime_;
   }

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DigitalLaunch", base_object<I3DigitalLaunch>(*this) );
    ar & make_nvp("StartTime", startTime_);
    ar & make_nvp("ATWDBinSize", aTWDBinSize_);
    ar & make_nvp("Trigger", trigger_);
    ar & make_nvp("WhichATWD", whichATWD_);
    ar & make_nvp("ATWD0", aTWD0_);
    ar & make_nvp("ATWD1", aTWD1_);
    ar & make_nvp("ATWD2", aTWD2_);
    ar & make_nvp("ATWD3", aTWD3_);
    ar & make_nvp("FADC", fADC_);
    ar & make_nvp("CombinedATWD", combinedATWD_);
    ar & make_nvp("LocalCoincidence", localCoincidence_);
  }

  // ROOT macro
  ClassDef(I3DOMLaunch,1);
};

BOOST_SHARED_POINTER_EXPORT(I3DOMLaunch);

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DOMLaunch>  I3DOMLaunchPtr;

#endif

