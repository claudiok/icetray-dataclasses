#ifndef I3ITERATOR_H
#define I3ITERATOR_H

/**
 * Class: I3Iterator
 *
 * Version: $Id: I3Iterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 *
 * Date: 12 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

#include "Rtypes.h"

/**
 * I3Iterator is a standard iterator implementation.  Just the interface.
 * People shouldn't use this directly because they'll have to delete it.
 * Instead they should create an I3Iter on the stack and it'll insure all
 * the memory gets cleaned up.
 * @version $Id: I3Iterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 * @author pretz
 */
template <class Type>
class I3Iterator {
 public:
  /**
   * constructor
   */
  I3Iterator();

  /**
   * destructor
   */
  virtual ~I3Iterator();

  /**
   * Puts the iterator to the first item in the collection
   */
  virtual void First() = 0;

  /**
   * Moves the iterator to the next item in the collection
   */
  virtual void Next() = 0;

  /**
   * Indicates whether or not there is more in the collection
   * @return kTRUE if the iterator is past the end of the list
   */
  virtual Bool_t IsDone() = 0;

  /**
   * retrieves the current item if the iterator is not at the end of the list
   */
  virtual Type& CurrentItem() = 0;

  // ROOT Macro
  ClassDefT(I3Iterator,0);
};

ClassDefT2(I3Iterator,Type);

template <class Type>
I3Iterator<Type>::I3Iterator(){

}

template <class Type>
I3Iterator<Type>::~I3Iterator(){

}


#endif
