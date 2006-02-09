/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Trigger.h 12685 2005-11-17 15:04:25Z blaufuss $
 *
 * @file I3Trigger.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005-11-17 16:04:25 +0100 (Thu, 17 Nov 2005) $
 * @author blaufuss
 * @author deyoung
 * @author ehrlich
 */

#ifndef I3_TRIGGER_H_INCLUDED
#define I3_TRIGGER_H_INCLUDED

#include <string>
#include <iostream>
#include <sstream>
#include <TObject.h>

#include "dataclasses/TriggerKey.h"
#include "icetray/services/I3Logging.h"


/**
 * @brief The basic Trigger class.  
 * 
 * This is the base class for trigger records that will live in the I3TriggerDict.
 */
class I3Trigger : public TObject
{
private:
  double     time_;             // Time at which the trigger was issued
  double     length_;           // Duration of triggered readout window
  bool       fired_;            // True, if trigger fired (used for simulations)
  TriggerKey key_;              // Trigger key that identifies source, type and config

public:
  /**
   * Default constructor.
   */
  I3Trigger()
    : time_(0.0), length_(0.0), fired_(false) {}

  /**
   * Destructor.
   */
  virtual ~I3Trigger();

  /**
   * Retrieves time at which the trigger was issued.
   * 
   * @return Trigger time.
   */
  double GetTriggerTime() const {return time_;}
  /**
   * Sets time at which the trigger was issued.
   * 
   * @param time Trigger time.
   */
  void SetTriggerTime(double time) {time_ = time;}

  /**
   * Retrieves duration of triggered readout window.
   * 
   * @return Trigger duration.
   */
  double GetTriggerLength() const {return length_;}
  /**
   * Sets duration of triggered readout window.
   * 
   * @param length Trigger duration.
   */
  void SetTriggerLength(double length) {length_ = length;}

  /**
   * Indicates, if the trigger was fired (used for simulations).
   * 
   * @return true, if the trigger was fired.
   */
  bool GetTriggerFired() const {return fired_;}
  /**
   * Sets, if the trigger was fired (used for simulations).
   * 
   * @param fired Indicates, if the trigger was fired.
   */
  void SetTriggerFired(bool fired) {fired_ = fired;}

  /**
   * Gets trigger key.
   * 
   * @return Key.
   */
  const TriggerKey& GetTriggerKey() const {return key_;}
  TriggerKey& GetTriggerKey() {return key_;}

  virtual const std::string ToString() const
  {
    std::ostringstream out;
    ToStream(out);
    return out.str();
  }

  virtual void ToStream(std::ostream& o) const
  {
    o << "[I3Trigger: \n"
      << " Time:" << time_ << "\n"
      << " Length:" << length_ << "\n"
      << " Key:" << key_ << "\n"
      << " Fired:" << fired_ << "]";
  }

private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);


  // logging
  SET_LOGGER("I3Trigger");
};

/**
 * pointer type to insulate users from memory management
 */
I3_POINTER_TYPEDEFS(I3Trigger);

/**
 * Streams a trigger to an arbitrary ostream.
 * 
 * @param o An arbitrary ostream.
 * @param trigger A trigger.
 * @return The ostream.
 */
inline std::ostream&
operator<<(std::ostream& o, const I3Trigger& trigger)
{
  trigger.ToStream(o);
  
  return o;
}

#endif


