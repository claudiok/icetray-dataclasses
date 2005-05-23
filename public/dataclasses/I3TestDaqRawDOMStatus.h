/**
 * Definition of I3TestDaqDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3TestDaqRawDOMStatus.h 6917 2005-04-26 02:56:37Z dima $
 *
 * @file I3TestDaqRawDOMStatus.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005-04-25 22:56:37 -0400 (Mon, 25 Apr 2005) $
 * @author pretz
 * @author tmccauley
 */

#ifndef I3TESTDAQRAWDOMSTATUS_H
#define I3TESTDAQRAWDOMSTATUS_H

#include "dataclasses/I3RawDOMStatus.h"

class I3TestDaqRawDOMStatus : public I3RawDOMStatus
{
public:
    I3TestDaqRawDOMStatus()
	{};

    ~I3TestDaqRawDOMStatus()
	{};
    
    const map<string,unsigned int>& GetRawStatus() const;
    map<string,unsigned int>& GetRawStatus();
    
    TrigMode GetTrigMode() const;
    
    LCMode GetLCMode() const;
    
    double GetLCWindowUpPre() const;
    double GetLCWindowDownPre() const;
    double GetLCWindowUpPost() const;
    double GetLCWindowDownPost() const;
    
    OnOff GetStatusATWD_A() const;
    OnOff GetStatusATWD_B() const;
    OnOff GetStatusFADC() const;
    
    double GetPMTHV() const;
    double GetSingleSPEThreshold() const;
    double GetFEPedestal() const;
};

#endif
