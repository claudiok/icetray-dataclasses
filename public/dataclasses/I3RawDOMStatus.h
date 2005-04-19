#ifndef I3RAWDOMSTATUS_PROPOSAL_H
#define I3RAWDOMSTATUS_PROPOSAL_H

#include <map>
#include <string>

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
 * @todo the file needs the full 'doxygen' comments
 */
class I3RawDOMStatus
{
 public:
  /**
   * constructor
   */
  I3RawDOMStatus(){}

  /**
   * destructor
   */
  virtual ~I3RawDOMStatus(){}

  /**
   * The status variables are stored as string-keyed unsigned
   * ints, the raw values that the DOMs take.
   */
  const map<string,unsigned int>& GetRawStatus() const;

  /**
   * The status variables are stored as string-keyed unsigned
   * ints, the raw values that the DOMs take.
   */
  map<string,unsigned int>& GetRawStatus();

  /**
   * The different kinds of triggers that can be used for the dom
   * The standard data-taking operation is SPE
   */
  enum TrigMode { TestPattern = 0 , CPU = 1, SPE = 2 };

  /**  
   * This controls how far the local coincidence signal is sent 
   */
  enum LCMode {LCOff = 0, UpOrDown = 1, Up = 2, Down = 3, UpAndDown = 4};

  /**
   * There is also provision to turn on or off various settings in the 
   * DOM
   */
  enum OnOff {Off = 0, On = 1};

  /**
   * Gets the current trigger source setting
   * @return the current trigger source setting
   */
  TrigMode GetTrigMode() const;

  /**
   * gets how far local coincidence signals are sent
   * @return how far local coincidence signals are sent
   */
  LCMode GetLCMode() const;

  /**
   * @return the local coincidence window before the descriminator 
   * in standard dataclasses units (ns) for the upward coming signal
   */
  double GetLCWindowUpPre() const;

  /**
   * @return the local coincidence window before the descriminator 
   * in standard dataclasses units (ns) for the downward coming signal
   */
  double GetLCWindowDownPre() const;

  /**
   * @return the local coincidence window after the descriminator 
   * in standard dataclasses units (ns) for the upward coming signal
   */

  double GetLCWindowUpPost() const;

  /**
   * @return the local coincidence window after the descriminator 
   * in standard dataclasses units (ns) for the downward coming signal
   */
  double GetLCWindowDownPost() const;

  /*  Control and Monitor different parts of the OM */
  
  /**
   * @return the status of ATWD A
   */
  OnOff GetStatusATWD_A() const;

  /**
   * @return the status of ATWD B
   */
  OnOff GetStatusATWD_B() const;

  /**
   * @return the status of the FADC
   */
  OnOff GetStatusFADC() const;

  /**
   * @return the high voltage on the PMT in standard dataclasses units
   */
  double GetPMTHV() const;
  
  /**
   * @return the voltage that is the threshold for a dom single SPE trigger
   */
  double GetSingleSPEThreshold() const;

  /**
   * @gives the FE pedestal applied to the atwd chip
   */
  double GetFEPedestal() const;

 private:
  mutable map<string,unsigned int> rawStatus_;
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RawDOMStatus>  I3RawDOMStatusPtr;

#endif


