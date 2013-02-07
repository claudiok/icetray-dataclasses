/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file TWRAOMStatus.h
 * @version $Revision$
 * @date $Date$
 * @author tschmidt
 */
#ifndef TWRAOMSTATUS_H_INCLUDED
#define TWRAOMSTATUS_H_INCLUDED

// forward declarations


// header files

#include <icetray/I3Logging.h>
#include <dataclasses/Utility.h>

// definitions


/** This class provides information about some DAQ parameters of an analog OM connected
 *  to the TWR DAQ.
 */

static const unsigned twraomstatus_version_ = 0;

class TWRAOMStatus
{
  public:
  enum CableType
  {
    ELECTRICAL = 0,
    OPTICAL = 10
  };
  
  private:
  double binSize_;
  unsigned int stopDelay_;
  unsigned int baseline_;
  unsigned int threshold_;
  CableType cableType_;
  
  public:
  /** Default constructor.
   */
  TWRAOMStatus() {}
  /** Destructor
   */
  virtual ~TWRAOMStatus();
  /** Get/Set for the TWR bin size.
   */
  double GetBinSize() const { return(binSize_); }
  void SetBinSize(double binSize) { binSize_ = binSize; }
  /** Get/Set for the TWR external stop delay.
   */
  unsigned int GetStopDelay() const { return(stopDelay_); }
  void SetStopDelay(unsigned int stopDelay) { stopDelay_ = stopDelay; }
  /** Get/Set for the TWR channel baseline.
   * 
   * The baseline is determined at run start using minimum bias triggers.
   */
  unsigned int GetBaseline() const { return(baseline_); }
  void SetBaseline(unsigned int baseline) { baseline_ = baseline; }
  /** Get/Set for the TWR channel threshold.
   */
  unsigned int GetThreshold() const { return(threshold_); }
  void SetThreshold(unsigned int threshold) { threshold_ = threshold; }
  /** Get/Set for the OM's signal transmission media.
   */
  CableType GetCableType() const { return(cableType_); }
  void SetCableType(CableType cableType) { cableType_ = cableType; }
  
  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize (Archive& ar, unsigned version);


  // logging
  SET_LOGGER("TWRAOMStatus");
};
/**
 * pointer type to insulate users from memory management
 */
I3_POINTER_TYPEDEFS(TWRAOMStatus);
BOOST_CLASS_VERSION(TWRAOMStatus, twraomstatus_version_);

#endif /*TWRAOMSTATUS_H_INCLUDED*/
