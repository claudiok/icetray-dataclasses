#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3DOMStatus.h>

//hack to make a failing test
//for serialization
namespace temp_hack{
  const unsigned DOMSTATUS_VERSION = 1;
}

I3DOMStatus::~I3DOMStatus() {}

BOOST_CLASS_VERSION(I3DOMStatus, temp_hack::DOMSTATUS_VERSION);

template <class Archive>
void I3DOMStatus::serialize (Archive& ar, unsigned version)
{

  if(version != temp_hack::DOMSTATUS_VERSION) 
    log_fatal("I3DOMStatus: class versioning does not appear to work.");

  ar & make_nvp("TrigMode",trigMode);
  ar & make_nvp("LCMode",lcMode);
  ar & make_nvp("LCWindowPre",lcWindowPre);
  ar & make_nvp("LCWindowPost",lcWindowPost);
  ar & make_nvp("LCSpan",lcSpan);
  ar & make_nvp("statusATWDa",statusATWDa);
  ar & make_nvp("statusATWDb",statusATWDb);
  ar & make_nvp("statusFADC",statusFADC);
  ar & make_nvp("PMTHV",pmtHV);
  ar & make_nvp("speThreshold",speThreshold);
  ar & make_nvp("fePedestal",fePedestal);
  ar & make_nvp("dacTriggerBias0",dacTriggerBias0);
  ar & make_nvp("dacTriggerBias1",dacTriggerBias1);
  ar & make_nvp("dacFADCRef",dacFADCRef);
  ar & make_nvp("nBinsATWD0",nBinsATWD0);
  ar & make_nvp("nBinsATWD1",nBinsATWD1);
  ar & make_nvp("nBinsATWD2",nBinsATWD2);
  ar & make_nvp("nBinsATWD3",nBinsATWD3);
  ar & make_nvp("nBinsFADC",nBinsFADC);
  ar & make_nvp("fbState",fbState);
  ar & make_nvp("fbBrightness",fbBrightness);
  ar & make_nvp("fbLength",fbLength);
  ar & make_nvp("fbDelay",fbDelay);
  ar & make_nvp("fbMask",fbMask);
  ar & make_nvp("fbRate",fbRate);

  if(version > 0)
  {
      ar & make_nvp("domGainType",domGainType);
  }
  else
  {
      domGainType = I3DOMStatus::UnknownGainType;
  }	

  if ( version > 0 )
  {
      ar & make_nvp("cableType", cableType);
  }
  else 
  {
      cableType = I3DOMStatus::UnknownCableType;
  }
}

I3_SERIALIZABLE(I3DOMStatus);
