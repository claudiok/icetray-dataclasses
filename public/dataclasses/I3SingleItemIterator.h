#ifndef I3SINGLEITEMITERATOR_H
#define I3SINGLEITEMITERATOR_H

/**
 * Class: I3SingleItemIterator
 *
 * Version: $Id: I3SingleItemIterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 *
 * Date: 13 Jan 2004
 * 
 * (c) 2004 IceCube Collaboration
 */

#include "dataclasses/I3DataExecution.h"

class TCollection;
class TObject;
class TIter;

/**
 * I3SingleItemIterator
 * is an iterator which just has a single item in it's 'collection'
 * @version $Id: I3SingleItemIterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 * @author pretz
 */
template <class Type>
class I3SingleItemIterator : public I3Iterator<Type>{
 public:
  /**
   * constructor.  specifies the data that this is an iterator for
   */
  I3SingleItemIterator(Type* data);

  /**
   * destructor
   */
  virtual ~I3SingleItemIterator();

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
  // default, assignment and copy declared private
  I3SingleItemIterator();
  I3SingleItemIterator(const I3SingleItemIterator<Type>&);
  I3SingleItemIterator<Type>& operator=(const I3SingleItemIterator<Type>&);

  // instance data
  Bool_t fDataCurrent;
  Type* fData;

  // ROOT Macro
  ClassDefT(I3SingleItemIterator,0);
};

ClassDefT2(I3SingleItemIterator,Type);

template <class Type>
I3SingleItemIterator<Type>::I3SingleItemIterator(Type* data):
  fDataCurrent(kTRUE),
  fData(data)
{
}

template <class Type>
I3SingleItemIterator<Type>::~I3SingleItemIterator(){
}

template <class Type>
void I3SingleItemIterator<Type>::First(){
  // sloppy
  fDataCurrent = kTRUE;
}

template <class Type>
void I3SingleItemIterator<Type>::Next(){
  fDataCurrent = kFALSE;
}


template <class Type>
Bool_t I3SingleItemIterator<Type>::IsDone(){
  return !fDataCurrent;
}

template <class Type>
Type& I3SingleItemIterator<Type>::CurrentItem(){
  if(fDataCurrent)
    return *fData;
  I3DataExecution::Instance().Fatal("I3SingleItemIterator::CurrentItem() requested an item out of bounds");
  return *(Type*)0;
}


#endif
