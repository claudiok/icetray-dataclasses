#ifndef STLMAPPOINTAINERPOLICY_H
#define STLMAPPOINTAINERPOLICY_H

#include "STLMapStoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: STLMapPointainerPolicy.h,v 1.1 2004/03/01 20:19:49 pretz Exp $
 *
 * A STLMapPolicy which contains the added functionality that
 * it deletes all the members when it goes out of scope.
 *
 * @version $$
 * @date $Id: STLMapPointainerPolicy.h,v 1.1 2004/03/01 20:19:49 pretz Exp $
 * @author pretz
 *
 * @todo 
 */

template <class ElementType>
class STLMapPointainerPolicy : public STLMapStoragePolicy<ElementType>{
  /**
   * destructor.  Deletes all the pointed to objects.
   */
 public:
  typedef typename STLMapStoragePolicy<ElementType>::iterator iterator;
  virtual ~STLMapPointainerPolicy(){
    iterator iter;
    for(iter = begin() ; iter!=end() ; iter++){
      delete *iter;
      *iter = 0;
    }
  }

};

#endif
