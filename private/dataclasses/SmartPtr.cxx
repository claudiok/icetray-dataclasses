/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: SmartPtr.cxx,v 1.1 2004/02/23 22:10:56 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/23 22:10:56 $
    @author Troy Straszheim

    @todo

*/
/// Boost shared_ptr class would be preferred but rootcint wont swallow it

#include "dataclasses/SmartPtr.h"
#include <vector>
#include <iostream>

//templateClassImp(SmartPtr);

using namespace std;

//
// Instantiations must go in same file as definition of template class for some reason.
//
template<class T>
void SmartPtr<T>::init()
{
  if (counter->isShareable() == false) {
    T *oldValue = counter->pointee;
    counter = new CountHolder;
    counter->pointee = oldValue ? new T(*oldValue) : 0;
  } 
  counter->addReference();
}

template<class T>
SmartPtr<T>::SmartPtr(T* realPtr)
: counter(new CountHolder)
{ 
  counter->pointee = realPtr;
  init();
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr& rhs)
: counter(rhs.counter)
{ 
  init(); 
}

template<class T>
SmartPtr<T>::~SmartPtr()
{ 
  counter->removeReference(); 
}

template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr& rhs)
{
  if (counter != rhs.counter) {         
    counter->removeReference();     
    counter = rhs.counter;
    init();
  }
  return *this;
}

template<class T>
T* SmartPtr<T>::operator->() const
{ return counter->pointee; }

template<class T>
T& SmartPtr<T>::operator*() const
{ return *(counter->pointee); }



