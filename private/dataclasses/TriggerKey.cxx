/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: TriggerKey.cxx 13154 2005-12-01 21:45:55Z  $
 *
 * @file TriggerKey.cxx
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 */
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/TriggerKey.h>


using namespace std;


string TriggerKey::GenerateName(const TriggerKey& myKey)
{
  // Take our trigger key, turn it into a unique string.
  std::ostringstream myName("Trig_");
  
  myName << myKey.GetSource();
  myName << "_";
  myName << myKey.GetType();
  myName << "_";
  if(myKey.CheckConfigID())
    myName << myKey.GetConfigID();
  else
    myName << "?";

  return myName.str();
}


TriggerKey TriggerKey::ParseName(const string& myName)
{
  const char* format1 = "Trig_%i_%i_%i";
  const char* format2 = "Trig_%i_%i_?";
  
  TriggerKey myKey;
  
  // Take our nicely generated string and deconvolve into a trigger key.
  int src, type, cfg;
  
  if(sscanf(myName.c_str(), format1, &src, &type, &cfg) == 3)
    myKey = TriggerKey(static_cast<SourceID>(src), static_cast<TypeID>(type), cfg);
  else if(sscanf(myName.c_str(), format2, &src, &type) == 2)
    myKey = TriggerKey(static_cast<SourceID>(src), static_cast<TypeID>(type));
  else
    log_fatal("Could not parse string.");

  return myKey;
}


TriggerKey::SourceID TriggerKey::CheckTriggerSource(SourceID source)
{
  SourceID retVal = UNKNOWN_SOURCE;

  if((source >= 0) && (source <= UNKNOWN_SOURCE))
    retVal = source;

  return retVal;
}


TriggerKey::TypeID TriggerKey::CheckTriggerType(TypeID type)
{
  TypeID retVal = UNKNOWN_TYPE;

  if((type >= 0) && (type <= UNKNOWN_TYPE))
    retVal = type;

  return retVal;
}


TriggerKey::~TriggerKey() {}


template <class Archive>
void TriggerKey::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object<TObject>(*this));
  ar & make_nvp("SourceID", source_);
  ar & make_nvp("TypeID", type_);
  ar & make_nvp("ConfigIDSet", configIDSet_);
  ar & make_nvp("ConfigID", configID_);
}

  
I3_SERIALIZABLE(TriggerKey);
