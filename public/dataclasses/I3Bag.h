#ifndef I3BAG_H
#define I3BAG_H

/**
 * Class: I3Bag
 *
 * Version: $Id: I3Bag.h,v 1.8 2004/02/25 00:20:59 pretz Exp $
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
 * @author ehrlich
 * @author troy
 * @author pretz
 */
class I3Bag : public MapPolicy<TObjectPtr>::ThePolicy
{
 public:
  /**
   * Constructor
   */
  I3Bag();

  /**
   * destructor
   */
  virtual ~I3Bag();

  // ROOT macro
  ClassDef(I3Bag,1);
};

#endif //I3BAG_H
