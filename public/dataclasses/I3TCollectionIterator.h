#ifndef I3TCOLLECTIONITER_H
#define I3TCOLLECTIONITER_H
/**
 * Class: I3TCollectionIterator
 *
 * Version: $Id: I3TCollectionIterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 *
 * Date 13 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

// inclucded files
#include "dataclasses/I3Iter.h"
#include "dataclasses/I3DataExecution.h"
#include "TCollection.h"

/**
 * I3TCollectionIterator is a wrapper for TIter, and is used in much
 * the same way.  It is created with a TCollection and then iterates
 * over it.  The behavior is a little more friendly than TIter, I think.
 * @version $Id: I3TCollectionIterator.h,v 1.1 2004/01/28 22:32:52 pretz Exp $
 * @author pretz
 */
template <class Type>
class I3TCollectionIterator : public I3Iterator<Type>{
 public:
  /**
   * constructor
   * @param collection the collection we're iterating over.
   */
  I3TCollectionIterator(TCollection* collection);

  /**
   * destructor
   */
  virtual ~I3TCollectionIterator();

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
  // default, copy and assignment are private
  I3TCollectionIterator();
  I3TCollectionIterator(const I3TCollectionIterator<Type>&);
  I3TCollectionIterator<Type>& operator=(const I3TCollectionIterator<Type>&);

  // instance data
  TIter* fIter;
  Type* fData;

  // ROOT Macros
  ClassDefT(I3TCollectionIterator,0);
};

ClassDefT2(I3TCollectionIterator,Type);

template <class Type>
I3TCollectionIterator<Type>::I3TCollectionIterator(TCollection* collection):
  fIter(new TIter(collection))
{
  fData = (Type*)fIter->Next();
}

template <class Type>
I3TCollectionIterator<Type>::~I3TCollectionIterator(){
  delete fIter;
}

template <class Type>
void I3TCollectionIterator<Type>::First(){
  // sloppy
  TIter *iter = new TIter(fIter->GetCollection());
  delete fIter;
  fIter = iter;
  fData = (Type*)fIter->Next();
}

template <class Type>
void I3TCollectionIterator<Type>::Next(){
  fData = (Type*)fIter->Next();
}

template <class Type>
Bool_t I3TCollectionIterator<Type>::IsDone(){
  if(fData)
    return kFALSE;
  return kTRUE;
}

template <class Type>
Type& I3TCollectionIterator<Type>::CurrentItem(){
  if(fData)
    return *fData;
  I3DataExecution::Instance().Fatal("I3TCollectionIterator::CurrentItem() is out of the bounds of the collection");
  return *(Type*)0;
}

#endif
