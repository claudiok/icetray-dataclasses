#ifndef I3ITER_H
#define I3ITER_H

/**
 * Class: I3Iter
 *
 * Version: $Id: I3Iter.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 *
 * Date: 12 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

#include "Rtypes.h"

#include "dataclasses/I3Iterator.h"
#include "dataclasses/I3DataExecution.h"

/**
 * I3Iter
 * An iterator class which can be used to iterate over a container.  Should
 * be created with an I3Iterator which is created by the container on the 
 * stack and it'll clean up its own memory.
 * @version $Id: I3Iter.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 * @author pretz
 */
template <class Type>
class I3Iter {
 public:
  /**
   *constructor
   */
  I3Iter(I3Iterator<Type>* iterator);

  /**
   * destructor
   */
  virtual ~I3Iter();

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
  // assignment and copy declared private
  I3Iter<Type>::I3Iter(const I3Iter<Type>&);
  I3Iter<Type>& operator=(const I3Iter<Type>&);

  // member data
  I3Iterator<Type>* fIter;

  // ROOT macro
  ClassDefT(I3Iter,0);
};

ClassDefT2(I3Iter,Type);

template <class Type>
I3Iter<Type>::I3Iter(I3Iterator<Type>* iterator)
{
  if(iterator == 0)
    I3DataExecution::Instance().Fatal("I3Iter::I3Iter() was built with a null I3Iterator");
  
  fIter = iterator;
}

template <class Type>
I3Iter<Type>::~I3Iter()
{
  delete fIter;
}

template <class Type>
void I3Iter<Type>::First(){
  fIter->First();
}

template <class Type>
void I3Iter<Type>::Next(){
  fIter->Next();
}

template <class Type>
Bool_t I3Iter<Type>::IsDone(){
  return fIter->IsDone();
}

template <class Type>
Type& I3Iter<Type>::CurrentItem(){
  return fIter->CurrentItem();
}

#endif
