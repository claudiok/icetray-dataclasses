/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file TWRAOMStatus.cxx
 * @version $Revision$
 * @date $Date$
 */
#include <icetray/serialization.h>
#include <dataclasses/status/TWRAOMStatus.h>


TWRAOMStatus::~TWRAOMStatus() {}


template <class Archive>
void
TWRAOMStatus::serialize(Archive& ar, unsigned version)  
{
  if (version>twraomstatus_version_)
    log_fatal("Attempting to read version %u from file but running version %u of TWRAOMStatus class.",version,twraomstatus_version_);
 
  ar & make_nvp("BinSize", binSize_);
  ar & make_nvp("StopDelay", stopDelay_);
  ar & make_nvp("Baseline", baseline_);
  ar & make_nvp("Threshold", threshold_);
  ar & make_nvp("CableType", cableType_);
}
  

I3_SERIALIZABLE(TWRAOMStatus);
