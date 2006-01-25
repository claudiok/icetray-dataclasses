#include "dataclasses/I3CascadeImpl.h"
#include "dataclasses/I3NonEnergetic.h"
#include "dataclasses/I3Energetic.h"
#include "dataclasses/I3NonComposite.h"
#include "dataclasses/I3Composite.h"
#include "dataclasses/I3Directional.h"
#include "dataclasses/I3NonDirectional.h"
#include "dataclasses/I3Localized.h"


template <typename DirectionT, typename LocalT, typename EnergyT, typename CompositeT>
I3CascadeImpl<DirectionT, LocalT, EnergyT, CompositeT>::~I3CascadeImpl() {}

template class I3CascadeImpl<I3NonDirectional, I3Localized, I3NonEnergetic, I3NonComposite>;
template class I3CascadeImpl<I3Directional, I3Localized, I3Energetic, I3Composite>;
template class I3CascadeImpl<I3Directional, I3Localized, I3NonEnergetic, I3NonComposite>;
template class I3CascadeImpl<I3Directional, I3Localized, I3Energetic, I3NonComposite>;


