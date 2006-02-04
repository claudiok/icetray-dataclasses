/**
 * Definition of I3RawDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id$
 * @file I3RawDOMStatus.h
 * @date $Date$
 */

#ifndef I3RAWDOMSTATUS_H_INCLUDED
#define I3RAWDOMSTATUS_H_INCLUDED

#include <string>
#include "dataclasses/StoragePolicy.h"

using namespace std;

/**
 * @brief I3RawDOMStatus has status information on the IceCube
 * OM parameters that can be controlled or adjusted, such as
 * the trigger, local coincidence and ATWD settings.
 *
 * It may be extended to include FPGA/ARM7 code
 * parameters, like data compression algorithms 
 *
 * This is based on "IceCube DOMAPP CPU FPGA Interface, Version 0.6
 * bu Thorsten Stetzelberger, Jan. 24, 2004 
 *
 * Updated Nov 05- Real DAQ updates.
 */

class I3RawDOMStatus
{
public:
    /**
     * The different kinds of triggers that can be used for the dom
     * The standard data-taking operation is SPE
     */
    enum TrigMode { TestPattern = 0 , CPU = 1, SPE = 2, Flasher=3 };

    /**  
     * This controls how far the local coincidence signal is sent 
     */
    enum LCMode {LCOff = 0, UpOrDown = 1, Up = 2, Down = 3 };

    /**
     * There is also provision to turn on or off various settings in the 
     * DOM
     */
    enum OnOff {Off = 0, On = 1};

    virtual ~I3RawDOMStatus();

    /**
     * Gets the current trigger source setting
     * @return the current trigger source setting
     */
    virtual TrigMode GetTrigMode() const
    {  
      log_fatal("pure virtual method called"); return TestPattern;
    }
    /**
     * gets how far local coincidence signals are sent
     * @return how far local coincidence signals are sent
     */
    virtual LCMode GetLCMode() const
    {  
      log_fatal("pure virtual method called"); return LCOff;
    }


    /**
     * @return the local coincidence window before the descriminator 
     * in standard dataclasses units (ns) for any signal
     */
    virtual double GetLCWindowPre() const
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

    /**
     * @return the local coincidence window after the descriminator 
     * in standard dataclasses units (ns) for the any signal
     */
    virtual double GetLCWindowPost() const
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

    /**
     * @return  trigger_bias DAC setting used for sampling rate calibration
     */
    virtual double GetDACTriggerBias(int chip) const
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

    /*  Control and Monitor different parts of the OM */
  
    /**
     * @return the status of the FADC
     */
    virtual OnOff GetStatusFADC() const
    {  
      log_fatal("pure virtual method called"); return Off;
    }
    
    /**
     * @return the high voltage on the PMT in standard dataclasses units
     */
    virtual double GetPMTHV() const
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

    /**
     * @return the voltage that is the threshold for a dom single SPE trigger
     */
    virtual double GetSingleSPEThreshold() const
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

    /**
     * @gives the FE pedestal applied to the atwd chip
     */
    virtual double GetFEPedestal() const 
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, unsigned version)
     {
         //This method intentionally left blank
     }

};	

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RawDOMStatus>  I3RawDOMStatusPtr;

#endif //I3RAWDOMSTATUS_H_INCLUDED


