#ifndef SMARTPTR_H_INCLUDED
#define SMARTPTR_H_INCLUDED

#include "RCObject.h"
/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: SmartPtr.h,v 1.3 2004/03/14 15:07:12 pretz Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/03/14 15:07:12 $
    @author Troy D. Straszheim

    @todo

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


