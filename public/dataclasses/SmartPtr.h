/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: SmartPtr.h,v 1.4 2004/04/27 13:35:23 pretz Exp $

    @file SmartPtr.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/27 13:35:23 $
    @author Troy D. Straszheim
*/
#ifndef SMARTPTR_H_INCLUDED
#define SMARTPTR_H_INCLUDED

#include "RCObject.h"

/**
 * @brief A smart pointer class.  Deletes the pointee when all references
 * to it go out of scope.
 */
template<class T>
class SmartPtr {
public:
  SmartPtr(T* realPtr = 0);
  SmartPtr(const SmartPtr& rhs);
  virtual ~SmartPtr();
  SmartPtr& operator=(const SmartPtr& rhs);

  T* operator->() const;
  T& operator*() const;

  // this is recommended against
  operator bool() { return (counter->pointee != NULL); }
  bool operator! () const {
    return counter->pointee == 0;
  }

  unsigned use_count() const {
    return counter->use_count();
  }

  template <class newType>
    operator SmartPtr<newType>() {
    return SmartPtr<newType>(*this);
  }


  class CountHolder: public RCObject {
  public:
    ~CountHolder() { 
      // C++ standard says that "delete NULL" has no effect
      delete pointee; 
    }
    T *pointee; //->
  };

private:
  CountHolder *counter; //->
  void init();
};

#endif


