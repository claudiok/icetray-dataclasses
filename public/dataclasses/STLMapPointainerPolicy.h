#ifndef STLMAPPOINTAINERPOLICY_H
#define STLMAPPOINTAINERPOLICY_H

#include "STLMapStoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: STLMapPointainerPolicy.h,v 1.2 2004/03/10 18:39:56 pretz Exp $
 *
 * A STLMapPolicy which contains the added functionality that
 * it deletes all the members when it goes out of scope.
 *
 * @version $$
 * @date $Id: STLMapPointainerPolicy.h,v 1.2 2004/03/10 18:39:56 pretz Exp $
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
      delete (iter->second);
      iter->second = 0;
    }
  }

};

#endif
