/**
 * Definition of I3DaqRawDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3DaqRawDOMStatus.h 6917 2005-04-26 02:56:37Z dima $
 *
 * @file I3DaqRawDOMStatus.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005-04-25 22:56:37 -0400 (Mon, 25 Apr 2005) $
 * @author blaufuss
 */

#ifndef I3DAQRAWDOMSTATUS_H
#define I3DAQRAWDOMSTATUS_H

#include "dataclasses/I3RawDOMStatus.h"

class I3DaqRawDOMStatus : public I3RawDOMStatus
    {
public:
    I3DaqRawDOMStatus()
	{};
    
    virtual ~I3DaqRawDOMStatus();
    
    /**
     * Gets the current DOM trigger source setting
     * @return the current trigger source setting
     */
    TrigMode GetTrigMode() const
	{
	return trigMode_;
	};

    /**
     * Sets the current DOM trigger source setting
     * @return the current trigger source setting
     */
    void SetTrigMode(const TrigMode trigMode)
	{
	trigMode_ = trigMode;
	};
    
    /**
     * get DOM local coincidence setting mode (off, up or down, up, down)
     * @return LCMode value
     */
    LCMode GetLCMode() const
	{
	return lcMode_;
	};
    /**
     * get DOM local coincidence setting mode (off, up or down, up, down)
     * @return LCMode value
     */
    void SetLCMode(const LCMode lcMode)
	{
	lcMode_ = lcMode;
	};
    /**
     * Get the local coincidence window before the descriminator 
     * in standard dataclasses units (ns) for any signal
     */    
    double GetLCWindowPre() const
	{
	return lcWindowPre_;
	};
    
    /**
     * set the local coincidence window before the descriminator 
     * in standard dataclasses units (ns) for any signal
     */    
    void SetLCWindowPre(const double lcWindow)
	{
	    lcWindowPre_ = lcWindow;
	};

    /**
     * Get the local coincidence window after the descriminator 
     * in standard dataclasses units (ns) for the any signal
     */
    double GetLCWindowPost() const
	{
	return lcWindowPost_;
	};
    
    /**
     * set the local coincidence window after the descriminator 
     * in standard dataclasses units (ns) for the any signal
     */
    void SetLCWindowPost(const double lcWindow)
	{
	lcWindowPost_ = lcWindow;
	};

    /**
     * Get the status of the FADC (on/off)
     */
    OnOff GetStatusFADC() const
	{
	return statusFADC_;
	};
    
    /**
     * set the status of the FADC (on/off)
     */
    void SetStatusFADC(const OnOff status)
	{
	statusFADC_ = status;
	};
    
    /**
     * Get the high voltage on the PMT in standard dataclasses units
     *  (I3Units::V)
     */
    double GetPMTHV() const
	{
	return pmtHV_;
	};
    
    /**
     * set the high voltage on the PMT in standard dataclasses units
     *  Any conversion to I3Units::V should be done before storing value
     */
    void SetPMTHV(const double hv)
	{
	pmtHV_ = hv;
	};
       
    /**
     * Get the voltage that is the threshold for a dom single SPE trigger
     *    return value should be in I3Units::V
     */
    double GetSingleSPEThreshold() const
	{
	return speThreshold_;
	};

    /**
     * Set the voltage that is the threshold for a dom single SPE trigger
     *     value should be in I3Units::V
     *     See physics-docs project for full details of conversion
     */
    void SetSingleSPEThreshold(const double threshold)
	{
	speThreshold_ = threshold;
	};
    
    /**
     * Get the FE pedestal (offset) applied to the atwd chip in I3Units::V 
     */
    double GetFEPedestal() const
	{
	return fePedestal_;
	};
    
    /**
     * Set the FE pedestal (offset) applied to the atwd chip in I3Units::V 
     *     See physics-docs project for full details of conversion
     */
    void SetFEPedestal(const double pedestal)
	{
	fePedestal_ = pedestal;
	};
    
    /**
     * Set trigger_bias DAC setting used for sampling rate calibration
     *  This is the raw DAC setting, stored as a double.  Used in 
     *  ATWD sampling rate calcuation from DOMCAL
     */    
    void SetDACTriggerBias(int bias, int chip)
	{
	if ( chip == 0 )
	    dacTriggerBias0_ = static_cast<double>(bias);
	else if ( chip == 1 )
	    dacTriggerBias1_ = static_cast<double>(bias);
	else 
	    log_fatal("Bad chip ID in I3DaqRawDOMStatus::SetDACTriggerBias");
	};
    
    /**
     * Get trigger_bias DAC setting used for sampling rate calibration
     *  This is the raw DAC setting, stored as a double.  Used in 
     *  ATWD sampling rate calcuation from DOMCAL
     */    
    double GetDACTriggerBias(int chip) const
	{
	if ( chip == 0 )
	    return dacTriggerBias0_;
	else if ( chip == 1 )
	    return dacTriggerBias1_;
	else 
	    log_fatal("Bad chip ID in I3DaqRawDOMStatus::GetDACTriggerBias");
	return 0.0;
	};

private:
    TrigMode trigMode_;
    
    LCMode lcMode_;
    
    double lcWindowPre_;
    double lcWindowPost_;
    
    OnOff statusFADC_;
    
    double pmtHV_;
    double speThreshold_;
    double fePedestal_;
    
    double dacTriggerBias0_;
    double dacTriggerBias1_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3DaqRawDOMStatus> I3DaqRawDOMStatusPtr;

#endif

