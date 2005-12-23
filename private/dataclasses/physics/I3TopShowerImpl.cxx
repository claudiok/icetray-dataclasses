#include "dataclasses/physics/I3TopShowerImpl.h"
#include "dataclasses/physics/I3Directional.h"
#include "dataclasses/physics/I3CoreLocalized.h"
#include "dataclasses/physics/I3NonLocalized.h"
#include "dataclasses/physics/I3NonDirectional.h"
#include "dataclasses/physics/I3Localized.h"
#include "dataclasses/physics/I3Energetic.h"
#include "dataclasses/physics/I3NonEnergetic.h"


template <typename DirectionT, typename CoreT, typename EnergyT>
I3TopShowerImpl<DirectionT, CoreT, EnergyT>::~I3TopShowerImpl() {}

template class I3TopShowerImpl<I3Directional, I3CoreLocalized, I3Energetic>;
template class I3TopShowerImpl<I3Directional, I3NonLocalized, I3NonEnergetic>;
template class I3TopShowerImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>;

