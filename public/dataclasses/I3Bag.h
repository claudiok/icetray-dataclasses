/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Bag.h,v 1.20.4.3 2005/02/04 21:49:04 troy Exp $
 *
 * @file I3Bag.h
 * @version $Revision: 1.20.4.3 $
 * @date $Date: 2005/02/04 21:49:04 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3BAG_H
#define I3BAG_H

#include "StoragePolicy.h"

#include <sstream>
#include <iostream>

/**
 * pointer typedeffed away to insulate users from memory management
 */ 
typedef PtrPolicy<TObject>::ThePolicy TObjectPtr;


/**
 * @brief I3Bag is a generic keyed TObject container, akin to the
 * Sieglinde bag. 
 *
 * Each Event (and geometry etc) gets one so that it can hold 
 * stuff that  doesn't really fit into the Data structure.  Just for 
 * 'temporary' or 'personal' use.
 */
class I3Bag : public TObject, public MapPolicy<string,TObjectPtr>::ThePolicy
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

  void ToStream(ostream& o) const
    {
      o<<"[ I3Bag! Wheee!]\n";
    }

  string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  // ROOT macro
};
/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3Bag& bag)
{
  bag.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Bag>::ThePolicy I3BagPtr;

#endif //I3BAG_H
