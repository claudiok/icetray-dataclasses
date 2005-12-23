#include "dataclasses/physics/I3TrackImpl.h"
#include "dataclasses/physics/I3Infinite.h"
#include "dataclasses/physics/I3Contained.h"
#include "dataclasses/physics/I3NonEnergetic.h"
#include "dataclasses/physics/I3Energetic.h"
#include "dataclasses/physics/I3NonComposite.h"
#include "dataclasses/physics/I3Composite.h"
#include "dataclasses/physics/I3Starting.h"

template <typename ContainedT, typename EnergyT, typename CompositeT>
I3TrackImpl<ContainedT, EnergyT, CompositeT>::~I3TrackImpl() {}
template class I3TrackImpl<I3Infinite, I3NonEnergetic, I3NonComposite>;
template class I3TrackImpl<I3Contained, I3Energetic, I3Composite>;
template class I3TrackImpl<I3Contained, I3NonEnergetic, I3NonComposite>;
template class I3TrackImpl<I3Infinite, I3Energetic, I3Composite>;
template class I3TrackImpl<I3Starting, I3NonEnergetic, I3Composite>;

