/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Trigger.cxx 12685 2005-11-17 15:04:25Z blaufuss $
 *
 * @file I3Trigger.cxx
 * @version $Revision: 1.5 $
 * @date $Date: 2005-11-17 16:04:25 +0100 (Thu, 17 Nov 2005) $
 */
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Trigger.h>


I3Trigger::~I3Trigger() {}


template <class Archive> void I3Trigger::serialize(Archive& ar, unsigned version)  
{ 
  ar & make_nvp("TriggerTime", time_);
  ar & make_nvp("TriggerLength", length_);
  ar & make_nvp("Fired", fired_);
  ar & make_nvp("TriggerKey", key_);
}
  

I3_SERIALIZABLE(I3Trigger);
