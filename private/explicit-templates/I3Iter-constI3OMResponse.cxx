/*
 * class: None - just template declarations
 *
 * Version $Id: I3Iter-constI3OMResponse.cxx,v 1.1 2004/02/02 15:37:28 pretz Exp $
 *
 * Date: 29 Sept 2003
 *
 * (c) IceCube Collaboration
 */

// Header files
#include "dataclasses/I3Iterator.h"
#include "dataclasses/I3SingleItemIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3Iter.h"
#include "dataclasses/I3OMResponse.h"

ClassImpT(I3Iterator,Type);
ClassImpT(I3SingleItemIterator,Type);
ClassImpT(I3ZeroItemIterator,Type);
ClassImpT(I3TCollectionIterator,Type);
ClassImpT(I3Iter,Type);

template I3Iterator<const I3OMResponse>;
template I3SingleItemIterator<const I3OMResponse>;
template I3ZeroItemIterator<const I3OMResponse>;
template I3TCollectionIterator<const I3OMResponse>;
template I3Iter<const I3OMResponse>;

