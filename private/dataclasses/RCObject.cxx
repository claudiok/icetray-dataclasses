/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: RCObject.cxx,v 1.1 2004/02/23 22:10:56 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/23 22:10:56 $
    @author Troy Straszheim

    @todo

    Reference Counted Object 

*/
#include "dataclasses/RCObject.h"

RCObject::RCObject()
: refCount(0), shareable(true) {}

RCObject::RCObject(const RCObject&)
: refCount(0), shareable(true) {}

RCObject& RCObject::operator=(const RCObject&)
{
  return *this;
}  

RCObject::~RCObject() {}

void RCObject::addReference() 
{
  ++refCount;
}

void RCObject::removeReference()
{
  // delete if refcount goes to zero
  refCount--;
  if (refCount == 0) 
    delete this;
}

void RCObject::markUnshareable()
{
  shareable = false;
}

bool RCObject::isShareable() const
{
  return shareable;
}

bool RCObject::isShared() const
{
  return refCount > 1;
}  

