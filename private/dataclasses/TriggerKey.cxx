#include <dataclasses/TriggerKey.h>
TriggerKey::~TriggerKey() { }

string TriggerKey::GenerateName(const TriggerKey& mykey)
{
  //Take our triggerKey, turn it into a unique string
  const string prefix = "Trig_";
  string sourceID,triggerType,configID,mystring;

  std::ostringstream strm_sourceID;
  strm_sourceID << mykey.GetSourceID();
  sourceID = strm_sourceID.str();
 
  std::ostringstream strm_triggerType;
  strm_triggerType << mykey.GetTriggerType();
  triggerType = strm_triggerType.str();
 
  std::ostringstream strm_configID;
  strm_configID << mykey.GetTriggerConfigID();
  configID = strm_configID.str();

  mystring = prefix+sourceID+"_"+triggerType+"_"+configID;
  log_trace("GenerateName: Created name: %s",mystring.c_str());
  return mystring;

}
