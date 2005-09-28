/**
 * Definition of I3MCRawDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3MCRawDOMStatus.h 6917 2005-04-26 02:56:37Z dima $
 *
 * @file I3MCRawDOMStatus.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005-04-25 22:56:37 -0400 (Mon, 25 Apr 2005) $
 * @author tmccauley
 */

#ifndef I3MCRAWDOMSTATUS_H
#define I3MCRAWDOMSTATUS_H

#include "dataclasses/I3RawDOMStatus.h"

class I3MCRawDOMStatus : public I3RawDOMStatus
{
public:
    I3MCRawDOMStatus()
	{};
    
    ~I3MCRawDOMStatus()
	{};
    
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
    
    double GetLCWindowUpPre() const
	{
	    return lcWindowUpPre_;
	};
    
    virtual void SetLCWindowUpPre(const double lcWindow)
	{
	    lcWindowUpPre_ = lcWindow;
	};

    double GetLCWindowDownPre() const
	{
	    return lcWindowDownPre_;
	};

    virtual void SetLCWindowDownPre(const double lcWindow)
	{
	    lcWindowDownPre_ = lcWindow;
	};

    double GetLCWindowUpPost() const
	{
	    return lcWindowUpPost_;
	};

    virtual void SetLCWindowUpPost(const double lcWindow)
	{
	  lcWindowUpPost_ = lcWindow;
	};
    
    double GetLCWindowDownPost() const
	{
	    return lcWindowDownPost_;
	};

    virtual void SetLCWindowDownPost(const double lcWindow)
	{
	    lcWindowDownPost_ = lcWindow;
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
	    {
		dacTriggerBias0_ = bias;
	    }
	    
	    else if ( chip == 1 )
	    {
		dacTriggerBias1_ = bias;
	    }
	    
	    else 
	    {
		log_fatal("Bad chip ID in I3MCRawDOMStatus::SetDACTriggerBias");
	    }
			  
	};

    double GetDACTriggerBias(int chip) const
	{
	    if ( chip == 0 )
	    {
		return dacTriggerBias0_;
	    }
	    
	    else if ( chip == 1 )
	    {
		return dacTriggerBias1_;
	    }

	    else 
	    {
		log_fatal("Bad chip ID in I3MCRawDOMStatus::GetDACTriggerBias");
		return 0.0;
	    }
	};
    
    

 private:
    TrigMode trigMode_;
    
    LCMode lcMode_;
    
    double lcWindowUpPre_;
    double lcWindowDownPre_;
    double lcWindowUpPost_;
    double lcWindowDownPost_;
    
    OnOff statusATWDa_;
    OnOff statusATWDb_;
    OnOff statusFADC_;
    
    double pmtHV_;
    double speThreshold_;
    double fePedestal_;
    
    double dacTriggerBias0_;
    double dacTriggerBias1_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3MCRawDOMStatus> I3MCRawDOMStatusPtr;

#endif

