#ifndef I3TRIGGERSTATUS_H
#define I3TRIGGERSTATUS_H

#include "dataclasses/StoragePolicy.h"

using namespace std;


/**
 * @brief A trigger configuration object
 *
 * A class to describe a basic trigger configuration.  Will
 *   make available the basics of a trigger:
 *   -name (from map entry in I3TriggerStatusDict)
 *   -int triggerType (id per detector triggers)
 *   -sourceID (source of trigger, redundant with map type (in ice or icetop)
 *   -a MAP of trigger settings:  string, integer values,
 *     contents vary by trigger type.
 *
 */


class I3TriggerStatus 
{
 public:
  
  /**
   * Get TriggerType  - the unique ID PER Subdetector SourceID
   */
  unsigned int GetTriggerType() const { return triggerType_; }
  
  /**
   * Set TriggerType  - the unique ID PER Subdetector SourceID
   */
  void SetTriggerType(unsigned int triggerType) {triggerType_ = triggerType; }
  
  /**
   * Get SourceID  - the unique Subdetector ID
   */
  unsigned int GetSourceID() const { return trigSourceID_; }
  
  /**
   * Set SourceID  - the unique Subdetector ID
   */
  void SetSourceID(unsigned int sourceID) {trigSourceID_ = sourceID; }
  
  /**
   * Get Map of settings, pairs of setting name : int
   */
  const map<string, int>& GetTriggerSettings() const { return triggerSettings_; }
  
  /**
   * Set Map of settings, pairs of setting name : int
   */
  void SetTriggerSettings(const map<string,int>& settings) 
    { triggerSettings_= settings; }
  

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3TriggerStatus]\n"
       <<"TriggerType: "<<triggerType_
       <<"TriggerSourceID: "<<trigSourceID_;
    };
  
  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    };

 private:
  unsigned int triggerType_;
  unsigned int trigSourceID_;
  map<string, int> triggerSettings_;
  
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

#endif

