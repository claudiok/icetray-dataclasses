#ifndef I3ZEROITEMITERATOR_H
#define I3ZEROITEMITERATOR_H
/**
 * Class: I3ZeroItemIterator
 *
 * Version: $Id: I3ZeroItemIterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 *
 * Date: 13 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

// included files
#include "dataclasses/I3Iter.h"
#include "dataclasses/I3DataExecution.h"

// forward declarations
class TCollection;
class TObject;
class TIter;

/**
 * I3ZeroItemIterator
 * is an iterator over no items.  So it's always 'Done'
 * @version $Id: I3ZeroItemIterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 * @author pretz
 */
template <class Type>
class I3ZeroItemIterator : public I3Iterator<Type>{
 public:
  /**
   * constructor
   */
  I3ZeroItemIterator();

  /**
   * destructor
   */
  virtual ~I3ZeroItemIterator();

  /**
   * Puts the iterator to the first item in the collection
   */
  virtual void First();

  /**
   * Moves the iterator to the next item in the collection
   */
  virtual void Next();

  /**
   * Indicates whether or not there is more in the collection
   * @return kTRUE if the iterator is past the end of the list
   */
  virtual Bool_t IsDone();

  /**
   * retrieves the current item if the iterator is not at the end of the list
   */
  virtual Type& CurrentItem();
 private:
  // copy and assignment declared private
  I3ZeroItemIterator(const I3ZeroItemIterator<Type>&);
  I3ZeroItemIterator<Type>& operator=(const I3ZeroItemIterator<Type>&);

  // ROOT macros
  ClassDefT(I3ZeroItemIterator,0);
};

ClassDefT2(I3ZeroItemIterator,Type);

template <class Type>
I3ZeroItemIterator<Type>::I3ZeroItemIterator()
{
}

template <class Type>
I3ZeroItemIterator<Type>::~I3ZeroItemIterator(){
}

template <class Type>
void I3ZeroItemIterator<Type>::First(){
}

template <class Type>
void I3ZeroItemIterator<Type>::Next(){
}

template <class Type>
Bool_t I3ZeroItemIterator<Type>::IsDone(){
  return kTRUE;
}

template <class Type>
Type& I3ZeroItemIterator<Type>::CurrentItem(){
  I3DataExecution::Instance().Fatal("I3ZeroItemIterator::CurrentItem() requested an item out of bounds");
  return *(Type*)0;
}

#endif
