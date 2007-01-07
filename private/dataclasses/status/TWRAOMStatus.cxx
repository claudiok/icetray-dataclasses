/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: TWRAOMStatus.cxx 12685 2005-11-17 15:04:25Z blaufuss $
 *
 * @file TWRAOMStatus.cxx
 * @version $Revision: 1.5 $
 * @date $Date: 2005-11-17 16:04:25 +0100 (Thu, 17 Nov 2005) $
 */
#include <icetray/serialization.h>
#include <dataclasses/status/TWRAOMStatus.h>


TWRAOMStatus::~TWRAOMStatus() {}


template <class Archive>
void
TWRAOMStatus::serialize(Archive& ar, unsigned version)  
{ 
  ar & make_nvp("BinSize", binSize_);
  ar & make_nvp("StopDelay", stopDelay_);
  ar & make_nvp("Baseline", baseline_);
  ar & make_nvp("Threshold", threshold_);
  ar & make_nvp("CableType", cableType_);
}
  

I3_SERIALIZABLE(TWRAOMStatus);
