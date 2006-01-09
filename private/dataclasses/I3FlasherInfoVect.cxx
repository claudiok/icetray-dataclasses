/**
 * copyright (C) 2005
 * The IceCube collaboration
 * @Id:
 *
 * @file I3FlasherInfoVect.cxx
 * @version
 * @date
 * @author Doug Rutledge
 */
#include "dataclasses/BoostHeaders.h"
#include "dataclasses/I3FlasherInfoVect.h"

template<class Archive> void I3FlasherInfoVect :: 
  serialize(Archive& archive, unsigned version)
{
  archive & make_nvp("I3Trigger", base_object<I3Trigger> (*this));
  archive & make_nvp("Flashers",flashers_);
}

I3_SERIALIZABLE(I3FlasherInfoVect);
