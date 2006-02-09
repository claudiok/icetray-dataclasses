/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerStatus.h 13154 2005-12-01 21:45:55Z  $
 *
 * @file I3TriggerStatus.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 * @author blaufuss
 */
#ifndef I3_TRIGGER_STATUS_H_INCLUDED
#define I3_TRIGGER_STATUS_H_INCLUDED


#include <string>
#include <iostream>
#include <sstream>
#include <TObject.h>

#include "dataclasses/I3Map.h"
#include "icetray/services/I3Logging.h"


/**
 * @brief A trigger configuration object.
 *
 * A class to describe a basic trigger configuration.
 * Will make available the basics of a trigger:
 * - name
 * - a map of trigger settings:  string, integer values
 *   (contents vary by trigger type)
 */
class I3TriggerStatus : public TObject
{
private:
  std::string name_;
  I3Map<std::string, int> settings_;

public:

  /**
   * Default constructor.
   */
  I3TriggerStatus() {}
  
  /**
   * Constructor.
   * 
   * @param name Name of the trigger.
   * @param settings Trigger settings: string, integer values.
   */
  I3TriggerStatus(const std::string& name,
                  const I3Map<std::string, int>& settings)
    : name_(name), settings_(settings) {}
  
  /**
   * Destructor.
   */
  virtual ~I3TriggerStatus();
  
  /**
   * Get trigger name.
   * 
   * @return Name of trigger.
   */
  virtual const std::string& GetTriggerName() const { return name_; }
  virtual std::string& GetTriggerName() { return name_; }
  
  /**
   * Get trigger settings.
   * 
   * @return Trigger settings: string, integer values
   * (contents vary by trigger type).
   */
  virtual const I3Map<std::string, int>& GetTriggerSettings() const { return settings_; }
  virtual I3Map<std::string, int>& GetTriggerSettings() { return settings_; }  

  virtual void ToStream(std::ostream& o) const
  {
    o << "[I3TriggerStatus: \n"
      << " Name: " << name_;
    
    if(!settings_.empty())
    {
      o << "\n Settings:";
      for(I3Map<std::string, int>::const_iterator iter = settings_.begin();
          iter != settings_.end();
          ++iter)
        o << "\n  " << iter->first << ": " << iter->second;
    }
      
    o << "]";
  };
  
  virtual std::string ToString() const
    {
      std::ostringstream out;
      ToStream(out);
      return out.str();
    };

private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);


  // logging
  SET_LOGGER("I3TriggerStatus");
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
I3_POINTER_TYPEDEFS(I3TriggerStatus);

/**
 * Streams a trigger statusto an arbitrary ostream.
 * 
 * @param o An arbitrary ostream.
 * @param status A trigger status.
 * @return The ostream.
 */
inline std::ostream&
operator<<(std::ostream& o, const I3TriggerStatus& status)
{
  status.ToStream(o);
  
  return o;
}

#endif

