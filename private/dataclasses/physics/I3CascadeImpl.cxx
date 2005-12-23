#include "dataclasses/physics/I3CascadeImpl.h"
#include "dataclasses/physics/I3NonEnergetic.h"
#include "dataclasses/physics/I3Energetic.h"
#include "dataclasses/physics/I3NonComposite.h"
#include "dataclasses/physics/I3Composite.h"
#include "dataclasses/physics/I3Directional.h"
#include "dataclasses/physics/I3NonDirectional.h"
#include "dataclasses/physics/I3Localized.h"


template <typename DirectionT, typename LocalT, typename EnergyT, typename CompositeT>
I3CascadeImpl<DirectionT, LocalT, EnergyT, CompositeT>::~I3CascadeImpl() {}

template class I3CascadeImpl<I3NonDirectional, I3Localized, I3NonEnergetic, I3NonComposite>;
template class I3CascadeImpl<I3Directional, I3Localized, I3Energetic, I3Composite>;
template class I3CascadeImpl<I3Directional, I3Localized, I3NonEnergetic, I3NonComposite>;


