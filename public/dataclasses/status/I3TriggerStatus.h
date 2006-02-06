#ifndef I3TRIGGERSTATUS_H_INCLUDED
#define I3TRIGGERSTATUS_H_INCLUDED

#include "dataclasses/Utility.h"

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


class I3TriggerStatus : public TObject
{
 public:

  virtual ~I3TriggerStatus();
  
  /**
   * Get TriggerName  - name of trigger
   */
  string GetTriggerName() const { return triggerName_; }
  
  /**
   * Set TriggerName  - name of trigger
   */
  void SetTriggerName(string triggerName) {triggerName_ = triggerName; }
  
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
       <<"TriggerName: "<<triggerName_;

    };
  
  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    };

 private:
  string triggerName_;
  map<string, int> triggerSettings_;
  
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3TriggerStatus);

#endif //I3TRIGGERSTATUS_H_INCLUDED

