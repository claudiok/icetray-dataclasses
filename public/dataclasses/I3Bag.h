#ifndef I3BAG_H
#define I3BAG_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Bag.h,v 1.9 2004/02/25 16:27:46 pretz Exp $
 *
 * I3Bag is a generic keyed TObject container, akin to the
 * Sieglinde bag. Each Event (and geometry etc) gets one so that it can hold 
 * stuff that  doesn't really fit into the Data structure.  Just for 
 * 'temporary' or 'personal' use.
 *
 * @version $Revision: 1.9 $
 * @date $Date: 2004/02/25 16:27:46 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */

#include "TObject.h"
#include "StoragePolicy.h"

typedef TObject* TObjectPtr;

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

 private:
  // copy and assignment are private
  I3Bag(const I3Bag& rhs);
  const I3Bag& operator=(const I3Bag& rhs);

  // ROOT macro
  ClassDef(I3Bag,1);
};

typedef I3Bag* I3BagPtr;

#endif //I3BAG_H
