/*
 * class: None - just template declarations
 *
 * Version $Id: I3Iter-constI3DataReadout.cxx,v 1.1 2004/02/10 00:15:00 ehrlich Exp $
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
#include "dataclasses/I3DataReadout.h"

ClassImpT(I3Iterator,Type);
ClassImpT(I3SingleItemIterator,Type);
ClassImpT(I3ZeroItemIterator,Type);
ClassImpT(I3TCollectionIterator,Type);
ClassImpT(I3Iter,Type);

template I3Iterator<const I3DataReadout>;
template I3SingleItemIterator<const I3DataReadout>;
template I3ZeroItemIterator<const I3DataReadout>;
template I3TCollectionIterator<const I3DataReadout>;
template I3Iter<const I3DataReadout>;

