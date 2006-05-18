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

string TriggerKey::GetSourceString() const
{
  string str;
  switch (source_) {
  case  0: str = "IN_ICE"; break;
  case 10: str = "ICE_TOP"; break;
  case 20: str = "AMANDA"; break;
  case 30: str = "EXTERNAL"; break;
  case 40: str = "GLOBAL"; break;
  case 50: str = "AMANDA_MUON_DAQ"; break;
  case 60: str = "AMANDA_TWR_DAQ"; break;
  case 70: str = "SPASE"; break;
  case 80: str = "UNKNOWN_SOURCE"; break;
  }
  return str;
}

string TriggerKey::GetTypeString() const
{
  string str;
  switch (type_) {
  case   0: str = "SIMPLE_MULTIPLICITY"; break;
  case  10: str = "CALIBRATION"; break;
  case  20: str = "MIN_BIAS"; break;
  case  30: str = "THROUGHPUT"; break;
  case  40: str = "TWO_COINCIDENCE"; break;
  case  50: str = "THREE_COINCIDENCE"; break;
  case  60: str = "AMANDA_MULTIPLICITY"; break;
  case  70: str = "MERGED"; break;
  case  80: str = "MAIN"; break;
  case  90: str = "AMANDA_A"; break;
  case 100: str = "MULTIPLICITY"; break;
  case 110: str = "AMANDA_A_MULTIPLICITY_COINCIDENCES"; break;
  case 120: str = "STRING"; break;
  case 130: str = "DOWNSCALED_MULTIPLICITY"; break;
  case 140: str = "TDC_CALIBRATION"; break;
  case 150: str = "GENERAL_SPASE"; break;
  case 160: str = "SPASE_1"; break;
  case 170: str = "SPASE_2"; break;
  case 180: str = "UNKNOWN_TYPE"; break;
  }
  return str;
}


TriggerKey::~TriggerKey() {}


template <class Archive>
void TriggerKey::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("SourceID", source_);
  ar & make_nvp("TypeID", type_);
  ar & make_nvp("ConfigIDSet", configIDSet_);
  if (configIDSet_)
    ar & make_nvp("ConfigID", configID_);
}

  
I3_SERIALIZABLE(TriggerKey);
