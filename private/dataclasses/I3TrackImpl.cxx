#include "dataclasses/I3TrackImpl.h"
#include "dataclasses/I3Infinite.h"
#include "dataclasses/I3Contained.h"
#include "dataclasses/I3NonEnergetic.h"
#include "dataclasses/I3Energetic.h"
#include "dataclasses/I3NonComposite.h"
#include "dataclasses/I3Composite.h"

I3TrackImpl<I3Infinite, I3NonEnergetic, I3NonComposite>::~I3TrackImpl() {}
I3TrackImpl<I3Contained, I3Energetic, I3Composite>::~I3TrackImpl() {}
