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
    I3MCRawDOMStatus();
    
    ~I3MCRawDOMStatus()
	{};
    
    const map<string,unsigned int>& GetRawStatus() const
	{
	    return rawStatus_;
	};
    
    map<string,unsigned int>& GetRawStatus()
	{
	    return rawStatus_;
	};
    
    TrigMode GetTrigMode() const
	{
	    return trigMode_;
	};
    
    LCMode GetLCMode() const
	{
	    return lcMode_;
	};
    
    double GetLCWindowUpPre() const
	{
	    return lcWindowUpPre_;
	};
    
    double GetLCWindowDownPre() const
	{
	    return lcWindowDownPre_;
	};
    
    double GetLCWindowUpPost() const
	{
	    return lcWindowUpPost_;
	};
    
    double GetLCWindowDownPost() const
	{
	    return lcWindowDownPost_;
	};
    
    OnOff GetStatusATWD_A() const
	{
	    return statusATWDa_;
	};
    
    OnOff GetStatusATWD_B() const
	{
	    return statusATWDb_;
	};
    
    OnOff GetStatusFADC() const
	{
	    return statusFADC_;
	};
    
    double GetPMTHV() const
	{
	    return pmtHV_;
	};
    
    double GetSingleSPEThreshold() const
	{
	    return speThreshold_;
	};
    
    double GetFEPedestal() const
	{
	    return fePedestal_;
	};
};

#endif
