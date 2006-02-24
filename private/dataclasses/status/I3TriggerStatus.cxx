/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerStatus.cxx 13154 2005-12-01 21:45:55Z  $
 *
 * @file I3TriggerStatus.cxx
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 */
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3TriggerStatus.h>


I3TriggerStatus::~I3TriggerStatus() {}


template <class Archive>
void I3TriggerStatus::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("Name", name_);
  ar & make_nvp("Settings", settings_);
}


I3_SERIALIZABLE(I3TriggerStatus);
