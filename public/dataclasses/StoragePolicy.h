/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.12 2004/07/12 16:12:46 pretz Exp $

    @file StoragePolicy.h
    @version $Revision: 1.12 $
    @date $Date: 2004/07/12 16:12:46 $
    @author Troy D. Straszheim
*/

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"

#include "boost/shared_ptr.hpp"


template <class Stored>
/**
 * @brief The storage policy for vectors of objects.
 *
 * The existence of this VectorPolicy class allows classes to inherit
 * from VectorPolicy<>::ThePolicy.  That policy's implementation can change -
 * provided the new implementation supplies the same interface - just by
 * changing this VectorPolicy class.  That's what it is here for.
 */
struct VectorPolicy {
  /**
   *  ThePolicy is an STLVectorStoragePolicy
   */
  typedef STLVectorStoragePolicy<Stored> ThePolicy;

};

/**
 * @brief The storage policy for maps of objects
 *
 * The existence of this MapPolicy class allows classes to inherit
 * from MapPolicy<>::ThePolicy.  That policy's implementation can change -
 * provided the new implementation supplies the same interface - just by
 * changing this Mapolicy class.  That's what it is here for.
 */
template <class Key,class Stored>
struct MapPolicy {
  /**
   *  ThePolicy is just a typedeffed STLMapStoragePolicy
   */
  typedef STLMapStoragePolicy<Key,Stored> ThePolicy;

};

/**
 * @brief The pointer policy.  Should use typedefs of this rather than 
 * raw pointers.
 *
 * The existence of this PtrPolicy allows for typdefs of 
 * PtrPolicy<Foo>::ThePolicy FooPtr.  Then users use FooPtr rather than
 * Foo*.  What this does is allow the true implemntation of FooPtr to change
 * in this one place, and the rest of the code is unaffected
 */
template <class Pointed>
struct PtrPolicy 
{
  /**
   * boost smart pointers.  FIXME: need docs
   */
  typedef boost::shared_ptr<Pointed> ThePolicy;
};

#endif
