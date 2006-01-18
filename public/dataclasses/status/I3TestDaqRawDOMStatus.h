/**
 * Definition of I3TestDaqDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id: I3TestDaqRawDOMStatus.h 6917 2005-04-26 02:56:37Z dima $
 * @file I3TestDaqRawDOMStatus.h
 * @date $Date: 2005-04-25 22:56:37 -0400 (Mon, 25 Apr 2005) $
 */

#ifndef I3TESTDAQRAWDOMSTATUS_H_INCLUDED
#define I3TESTDAQRAWDOMSTATUS_H_INCLUDED

#include "dataclasses/status/I3RawDOMStatus.h"
#include <map>

using namespace std;

class I3TestDaqRawDOMStatus : public I3RawDOMStatus
{
public:
    I3TestDaqRawDOMStatus()
	{};

    virtual ~I3TestDaqRawDOMStatus();
    
    const map<string,unsigned int>& GetRawStatus() const;
    map<string,unsigned int>& GetRawStatus();
    
    TrigMode GetTrigMode() const;
    
    LCMode GetLCMode() const;

    /**
     * Get LCWindowPre...for now, to fufill virtual interface. 
     *   return the up, they are pretty much always the same
     */
    double GetLCWindowPre() const { return GetLCWindowUpPre(); }

    /**
     * Get LCWindowPost...for now, to fufill virtual interface. 
     *   return the up, they are pretty much always the same
     */
    double GetLCWindowPost() const { return GetLCWindowUpPost(); }
    
    double GetLCWindowUpPre() const;
    double GetLCWindowDownPre() const;
    double GetLCWindowUpPost() const;
    double GetLCWindowDownPost() const;

    double GetDACTriggerBias(int) const;
    
    OnOff GetStatusATWD_A() const;
    OnOff GetStatusATWD_B() const;
    OnOff GetStatusFADC() const;
    
    double GetPMTHV() const;
    double GetSingleSPEThreshold() const;
    double GetFEPedestal() const;

    unsigned int GetNBinsATWD(unsigned int) const;
    unsigned int GetNBinsFADC() const;

 private:
    mutable map<string,unsigned int> rawStatus_;

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

};

typedef shared_ptr<I3TestDaqRawDOMStatus> I3TestDaqRawDOMStatusPtr;

#endif //I3TESTDAQRAWDOMSTATUS_H_INCLUDED
