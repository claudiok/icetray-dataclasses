/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: TriggerKey.cxx 13154 2005-12-01 21:45:55Z tschmidt $
 *
 * @file TriggerKey.cxx
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 */
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/TriggerKey.h>


using namespace std;


const char*
TriggerKey::GetSourceString(SourceID source)
{
  switch (source)
  {
    case IN_ICE:
      return("IN_ICE");
    case ICE_TOP:
      return("ICE_TOP");
    case AMANDA:
      return("AMANDA");
    case EXTERNAL:
      return("EXTERNAL");
    case GLOBAL:
      return("GLOBAL");
    case AMANDA_MUON_DAQ:
      return("AMANDA_MUON_DAQ");
    case AMANDA_TWR_DAQ:
      return("AMANDA_TWR_DAQ");
    case SPASE:
      return("SPASE");
    case UNKNOWN_SOURCE:
      return("UNKNOWN_SOURCE");
  }
  log_warn("undefined source ID");
  
  return NULL;
}

const char *
TriggerKey::GetTypeString (TypeID type)
{
  switch(type)
  {
    case SIMPLE_MULTIPLICITY:
      return("SIMPLE_MULTIPLICITY");
    case CALIBRATION:
      return("CALIBRATION");
    case MIN_BIAS:
      return("MIN_BIAS");
    case THROUGHPUT:
      return("THROUGHPUT");
    case TWO_COINCIDENCE:
      return("TWO_COINCIDENCE");
    case THREE_COINCIDENCE:
      return("THREE_COINCIDENCE");
    case AMANDA_MULTIPLICITY:
      return("AMANDA_MULTIPLICITY");
    case MERGED:
      return("MERGED");
    case MAIN:
      return("MAIN");
    case AMANDA_A:
      return("AMANDA_A");
    case MULTIPLICITY:
      return("MULTIPLICITY");
    case FRAGEMENT_MULTIPLICITY:
      return("FRAGMENT_MULTIPLICITY");
    case AMANDA_A_MULTIPLICITY_COINCIDENCES:
      return("AMANDA_A_MULTIPLICITY_COINCIDENCES");
    case STRING:
      return("STRING");
    case VOLUME:
      return("VOLUME");
    case SPHERE:
      return("SPHERE");
    case DOWNSCALED_MULTIPLICITY:
      return("DOWNSCALED_MULTIPLICITY");
    case TDC_CALIBRATION:
      return("TDC_CALIBRATION");
    case GENERAL_SPASE:
      return("GENERAL_SPASE");
    case SPASE_1:
      return("SPASE_1");
    case SPASE_2:
      return("SPASE_2");
    case UNKNOWN_TYPE:
      return("UNKNOWN_TYPE");
  }
  log_warn("undefined type ID");

  return NULL;
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
