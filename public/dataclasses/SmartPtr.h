/******************************************************************************
*                  Template Class SmartPtr (from pp. 209-210)                   *
*                                                                             *
* The code for SmartPtr has changed over the years in response to errors        *
* both in the original source code as well as in the subsequent fixes.  You   *
* can find a complete list of changes at the More Effective C++ errata page.  *
* The code here is accurate as of the 13th printing of the book.              *
******************************************************************************/
#ifndef RCIPTR_H_INCLUDED
#define RCIPTR_H_INCLUDED

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


