#include "dataclasses/I3TrackImpl.h"
#include "dataclasses/I3Infinite.h"
#include "dataclasses/I3Contained.h"
#include "dataclasses/I3NonEnergetic.h"
#include "dataclasses/I3Energetic.h"
#include "dataclasses/I3NonComposite.h"
#include "dataclasses/I3Composite.h"

template <typename ContainedT, typename EnergyT, typename CompositeT>
I3TrackImpl<ContainedT, EnergyT, CompositeT>::~I3TrackImpl() {}
template class I3TrackImpl<I3Infinite, I3NonEnergetic, I3NonComposite>;
template class I3TrackImpl<I3Contained, I3Energetic, I3Composite>;
template class I3TrackImpl<I3Contained, I3NonEnergetic, I3NonComposite>;
template class I3TrackImpl<I3Infinite, I3Energetic, I3Composite>;

