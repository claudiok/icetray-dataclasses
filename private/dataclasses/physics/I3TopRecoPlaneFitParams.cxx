/**
 * Copyright (C) 2006
 * The IceCube collaboration
 * ID: $Id: I3TopRecoPlaneFitParams.cxx 67045 2010-09-27 12:04:00Z kislat $
 *
 * @file I3TopRecoPlaneFitParams.cxx
 * @version $Rev: 18397 $
 * @date $Date: 2010-09-27 08:04:00 -0400 (Mon, 27 Sep 2010) $
 * @author $Author: klepser $
 */

#include <icetray/serialization.h>
#include <icetray/I3Units.h>
#include <dataclasses/physics/I3TopRecoPlaneFitParams.h>

template <class Archive>
void I3TopRecoPlaneFitParams::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("ET",  ET );
  ar & make_nvp("DeltaT", DeltaT );
  ar & make_nvp("T0", T0 );
  ar & make_nvp("X0", X0 );
  ar & make_nvp("Y0",  Y0 );
  ar & make_nvp("Chi2", Chi2 );
  ar & make_nvp("NPulses", NPulses );

  if (version < 1) DeltaT *= I3Units::s;  // in the old version this was stored in seconds

}

I3_SERIALIZABLE(I3TopRecoPlaneFitParams);
