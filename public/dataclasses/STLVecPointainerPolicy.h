#ifndef STLVECPOINTAINERPOLICY_H
#define STLVECPOINTAINERPOLICY_H

#include "STLVectorStoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: STLVecPointainerPolicy.h,v 1.1 2004/03/01 20:19:49 pretz Exp $
 *
 * A STLVectorPolicy which contains the added functionality that
 * it deletes all the members when it goes out of scope.
 *
 * @version $$
 * @date $Id: STLVecPointainerPolicy.h,v 1.1 2004/03/01 20:19:49 pretz Exp $
 * @author pretz
 *
 * @todo 
 */

template <class ElementType>
class STLVecPointainerPolicy : public STLVectorStoragePolicy<ElementType>{
  /**
   * destructor.  Deletes all the pointed to objects.
   */
 public:
  typedef typename STLVectorStoragePolicy<ElementType>::iterator iterator;
  virtual ~STLVecPointainerPolicy(){
    iterator iter;
    for(iter = begin() ; iter!=end() ; iter++){
      delete *iter;
      *iter = 0;
    }
  }
};



#endif
