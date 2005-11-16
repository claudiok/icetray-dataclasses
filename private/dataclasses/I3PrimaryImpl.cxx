#include "dataclasses/I3PrimaryImpl.h"
#include "dataclasses/I3Directional.h"
#include "dataclasses/I3Localized.h"
#include "dataclasses/I3CoreLocalized.h"
#include "dataclasses/I3Energetic.h"

template <typename DirT, typename LocalT, typename EnergT>
I3PrimaryImpl<DirT, LocalT, EnergT>::~I3PrimaryImpl() { }
template class I3PrimaryImpl<I3Directional,I3Localized,I3Energetic>;
template class I3PrimaryImpl<I3Directional, I3CoreLocalized, I3Energetic>;
