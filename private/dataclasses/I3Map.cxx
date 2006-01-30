#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Map.h>
#include <dataclasses/OMKey.h>
#include <dataclasses/physics/I3DOMLaunchSeries.h>
#include <dataclasses/physics/I3RecoHitSeries.h>

typedef I3Map<OMKey, I3DOMLaunchSeries> RawData;
I3_SERIALIZABLE(RawData);

typedef I3Map<OMKey, I3RecoHitSeries> RecoHits;
I3_SERIALIZABLE(RecoHits);
