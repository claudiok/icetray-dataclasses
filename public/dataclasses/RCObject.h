/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: RCObject.h,v 1.2 2004/04/27 13:35:23 pretz Exp $
 *
 * @file RCObject.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author troy
 */
#ifndef RCOBJECT_H_INCLUDED
#define RCOBJECT_H_INCLUDED

#include <iostream>      // The iostream facilities are not used in the classes
                         // in this file, but they are used in the code that 
                         // tests the classes.

#include <cstring>       // This includes the C string functions, e.g.,
                         // strlen, strcpy, etc.  They are used in the
                         // implementation of class String::StringValue.

/**
 * @brief This class is used by the SmartPtr class.
 */
class RCObject {                       // base class for reference-
public:                                // counted objects
  void addReference();
  void removeReference();
  void markUnshareable();
  bool isShareable() const;
  bool isShared() const;
  int use_count() const { return refCount; }

protected:
  RCObject();
  RCObject(const RCObject& rhs);
  RCObject& operator=(const RCObject& rhs);
  virtual ~RCObject(); //TDS: should be pure virtual

private:
  int refCount;
  bool shareable;
  //  ClassDef(RCObject,1);
};


#endif
