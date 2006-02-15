#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Map.h>
#include <dataclasses/OMKey.h>
#include <dataclasses/physics/I3DOMLaunch.h>
#include <dataclasses/physics/I3RecoHit.h>
#include <dataclasses/physics/I3RecoPulse.h>

typedef I3Map<OMKey, I3DOMLaunchSeries> RawData;
I3_SERIALIZABLE(RawData);

typedef I3Map<OMKey, I3RecoHitSeries> RecoHits;
I3_SERIALIZABLE(RecoHits);

typedef I3Map<OMKey, I3RecoPulseSeries> RecoPulses;
I3_SERIALIZABLE(RecoPulses);
