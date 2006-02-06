/**
 * Definition of I3MCRawDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id: I3MCRawDOMStatus.h 6917 2005-04-26 02:56:37Z dima $
 * @file I3MCRawDOMStatus.h
 * @date $Date: 2005-04-25 22:56:37 -0400 (Mon, 25 Apr 2005) $
 */

#ifndef I3MCRAWDOMSTATUS_H_INCLUDED
#define I3MCRAWDOMSTATUS_H_INCLUDED

#include "dataclasses/status/I3RawDOMStatus.h"

class I3MCRawDOMStatus : public I3RawDOMStatus
{
public:
    I3MCRawDOMStatus()
	{};
    
    virtual ~I3MCRawDOMStatus();
    
    TrigMode GetTrigMode() const
	{
	    return trigMode_;
	};

    virtual void SetTrigMode(const TrigMode trigMode)
	{
	    trigMode_ = trigMode;
	};
    
    LCMode GetLCMode() const
	{
	    return lcMode_;
	};

    virtual void SetLCMode(const LCMode lcMode)
	{
	    lcMode_ = lcMode;
	};
    
    double GetLCWindowPre() const
	{
	    return lcWindowPre_;
	};
    
    virtual void SetLCWindowPre(const double lcWindow)
	{
	    lcWindowPre_ = lcWindow;
	};

    double GetLCWindowPost() const
	{
	    return lcWindowPost_;
	};

    virtual void SetLCWindowPost(const double lcWindow)
	{
	  lcWindowPost_ = lcWindow;
	};
    
    OnOff GetStatusATWD_A() const
	{
	    return statusATWDa_;
	};

    virtual void SetStatusATWD_A(const OnOff status)
      {
	  statusATWDa_ = status;
      };
    
    OnOff GetStatusATWD_B() const
	{
	    return statusATWDb_;
	};
    
    virtual void SetStatusATWD_B(const OnOff status)
	{
	    statusATWDb_ = status;
	};

    OnOff GetStatusFADC() const
	{
	    return statusFADC_;
	};
    
    virtual void SetStatusFADC(const OnOff status)
	{
	    statusFADC_ = status;
	};

    double GetPMTHV() const
	{
	    return pmtHV_;
	};
      
    virtual void SetPMTHV(const double hv)
	{
	    pmtHV_ = hv;
	};

    double GetSingleSPEThreshold() const
	{
	    return speThreshold_;
	};

    virtual void SetSingleSPEThreshold(const double threshold)
      {
	  speThreshold_ = threshold;
      };
    
    double GetFEPedestal() const
	{
	    return fePedestal_;
	};

    virtual void SetFEPedestal(const double pedestal)
	{
	    fePedestal_ = pedestal;
	};

    virtual void SetDACTriggerBias(int bias, int chip)
	{
	    if ( chip == 0 )
		dacTriggerBias0_ = static_cast<double>(bias);
	    else if ( chip == 1 )
		dacTriggerBias1_ = static_cast<double>(bias);
	    else 
		log_fatal("Bad chip ID in I3MCRawDOMStatus::SetDACTriggerBias");
	};

    double GetDACTriggerBias(int chip) const
	{
	    if ( chip == 0 )
		return dacTriggerBias0_;
	    else if ( chip == 1 )
		return dacTriggerBias1_;
	    else 
		log_fatal("Bad chip ID in I3MCRawDOMStatus::GetDACTriggerBias");
		return 0.0;
	};
    
    virtual void SetNBinsATWD(unsigned int channel, unsigned int samples)
	{
	    if ( channel == 0 )
		nBinsATWD0_ = samples;
	    else if ( channel == 1 )
		nBinsATWD1_ = samples;
	    else if ( channel == 2 )
		nBinsATWD2_ = samples;
	    else if ( channel == 3 )
		nBinsATWD3_ = samples;
	    else
		log_fatal("Bad ATWD channel in I3MCRawDOMStatus::SetNBinsATWD");
	};
    
    unsigned int GetNBinsATWD(unsigned int channel) const
	{
	    if ( channel == 0 )
		return nBinsATWD0_;
	    else if ( channel == 1 )
		return nBinsATWD1_;
	    else if ( channel == 2 )
		return nBinsATWD2_;
	    else if ( channel == 3 )
		return nBinsATWD3_;
	    else
		log_fatal("Bad ATWD channel in I3MCRawDOMStatus::GetNBinsATWD");
	};
    
    virtual void SetNBinsFADC(unsigned int samples)
	{
	    nBinsFADC_ = samples;
	};

    unsigned int GetNBinsFADC() const
	{
	    return nBinsFADC_;
	};
    
 private:
    TrigMode trigMode_;
    
    LCMode lcMode_;
    
    double lcWindowPre_;
    double lcWindowPost_;
    
    OnOff statusATWDa_;
    OnOff statusATWDb_;
    OnOff statusFADC_;
    
    double pmtHV_;
    double speThreshold_;
    double fePedestal_;
    
    double dacTriggerBias0_;
    double dacTriggerBias1_;

    unsigned int nBinsATWD0_;
    unsigned int nBinsATWD1_;
    unsigned int nBinsATWD2_;
    unsigned int nBinsATWD3_;

    unsigned int nBinsFADC_;
    
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3MCRawDOMStatus);

#endif //I3MCRAWDOMSTATUS_H_INCLUDED

