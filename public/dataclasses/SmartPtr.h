/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: SmartPtr.h,v 1.2 2004/02/24 02:48:43 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/24 02:48:43 $
    @author Troy D. Straszheim

    @todo

*/
#ifndef SMARTPTR_H_INCLUDED
#define SMARTPTR_H_INCLUDED

#include "RCObject.h"

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


