/*
 * class: None - just template declarations
 *
 * Version $Id: I3Iter-TObject.cxx,v 1.1 2004/01/28 22:32:12 pretz Exp $
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
#include "TObject.h"

ClassImpT(I3Iterator,Type);
ClassImpT(I3SingleItemIterator,Type);
ClassImpT(I3ZeroItemIterator,Type);
ClassImpT(I3TCollectionIterator,Type);
ClassImpT(I3Iter,Type);

template I3Iterator<TObject>;
template I3SingleItemIterator<TObject>;
template I3ZeroItemIterator<TObject>;
template I3TCollectionIterator<TObject>;
template I3Iter<TObject>;

