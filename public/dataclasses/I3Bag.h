/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Bag.h,v 1.15 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3Bag.h
 * @version $Revision: 1.15 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3BAG_H
#define I3BAG_H

#include "TObject.h"
#include "StoragePolicy.h"

typedef TObject* TObjectPtr;

/**
 * @brief I3Bag is a generic keyed TObject container, akin to the
 * Sieglinde bag. 
 *
 * Each Event (and geometry etc) gets one so that it can hold 
 * stuff that  doesn't really fit into the Data structure.  Just for 
 * 'temporary' or 'personal' use.
 */
class I3Bag : public TObject, public MapPointainerPolicy<TObjectPtr>::ThePolicy
{
 public:
  /**
   * Constructor
   */
  I3Bag() {};

  /**
   * destructor
   */
  ~I3Bag() {};

 private:
  // copy and assignment are private
  I3Bag(const I3Bag& rhs);
  const I3Bag& operator=(const I3Bag& rhs);

  // ROOT macro
  ClassDef(I3Bag,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Bag>::ThePolicy I3BagPtr;

#endif //I3BAG_H
