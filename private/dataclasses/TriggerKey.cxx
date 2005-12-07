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

TriggerKey TriggerKey::ParseName(const string& myname)
{
  //Take our nicely generated string and deconvolve into a TriggerKey
  TriggerKey myKey;

  int sourceID, triggerType, configID;
  size_t  strpos = myname.find("_", 0);
  //Let's cut off of the trig_
  string temp = myname.substr(strpos+1, myname.size());

  const char* mycharstring = temp.c_str();
  sscanf(mycharstring,"%i_%i_%i",&sourceID,&triggerType,&configID);
  log_trace("ParseName found SourceID: %i triggerType: %i ConfigID: %i",sourceID,triggerType,configID);

  myKey.SetSourceID(sourceID);
  myKey.SetTriggerType(triggerType);
  myKey.SetTriggerConfigID(configID);

  return myKey;

}
