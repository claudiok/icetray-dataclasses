#ifndef I3BAG_H
#define I3BAG_H

/**
 * Class: I3Bag
 *
 * Version: $Id: I3Bag.h,v 1.7 2004/02/24 18:02:08 troy Exp $
 *
 * Date: 30 Jan 2004
 *
 * (c) 2004 IceCube collaboration
 *
 */

#include "TObject.h"
#include "StoragePolicy.h"

typedef TObject* TObjectPtr;

/**
 * I3Bag is a generic keyed TObject container, akin to the
 * Sieglinde bag. Each Event (and geometry etc) gets one so that it can hold 
 * stuff that  doesn't really fit into the Data structure.  Just for 
 * 'temporary' or 'personal' use.
 */
class I3Bag : public MapPolicy<TObjectPtr>::ThePolicy
{
 public:
  I3Bag();
  virtual ~I3Bag();

  ClassDef(I3Bag,1);
};

#endif //I3BAG_H
