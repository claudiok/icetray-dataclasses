/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.8 2004/04/27 13:35:23 pretz Exp $

    @file StoragePolicy.h
    @version $Revision: 1.8 $
    @date $Date: 2004/04/27 13:35:23 $
    @author troy
*/

// inlcude one and only one

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"
#include "STLVecPointainerPolicy.h"
#include "STLMapPointainerPolicy.h"

//#include "TClonesPolicy.h"
#include "SmartPtr.h"

// something like this would be nice but root wont allow it
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
   * Right now, ThePolicy is an STLVectorStoragePolicy
   */
  typedef STLVectorStoragePolicy<Stored> ThePolicy;

  // half-implemented
  // typedef TClonesArrayStoragePolicy<Stored> ThePolicy;
};

/**
 * @brief The storage policy for vectors of pointers to objects 
 *
 * The existence of this VecPointainerPolicy class allows classes to inherit
 * from VecPointainerPolicy<>::ThePolicy.  That policy's implementation can 
 * change -
 * provided the new implementation supplies the same interface - just by
 * changing this VecPointainerPolicy class.  Classes that are Vectors of 
 * Pointers
 * should inherit from this class rather than VectorPolicy<>::ThePolicy so
 * that the memory management can be out of the hands of the users.
 */
template <class Stored>
struct VecPointainerPolicy{
  /**
   * Right now, ThePolicy is just a typedefed STLVecPointainerPolicy
   */
  typedef STLVecPointainerPolicy<Stored> ThePolicy;
};

/**
 * @brief The storage policy for maps of objects
 *
 * The existence of this MapPolicy class allows classes to inherit
 * from MapPolicy<>::ThePolicy.  That policy's implementation can change -
 * provided the new implementation supplies the same interface - just by
 * changing this Mapolicy class.  That's what it is here for.
 */
template <class Stored>
struct MapPolicy {
  /**
   * Right now, ThePolicy is just a typedeffed STLMapStoragePolicy
   */
  typedef STLMapStoragePolicy<Stored> ThePolicy;

  // not yet implemented
  // typedef TMapStoragePolicy<Stored> ThePolicy;
};

/**
 * @brief The storage policy for maps of pointers to objects
 *
 * The existence of this MapPointainerPolicy class allows classes to inherit
 * from MapPointainerPolicy<>::ThePolicy.  That policy's implementation can 
 * change -
 * provided the new implementation supplies the same interface - just by
 * changing this MapPointainerPolicy class.  Classes that are Maps of Pointers
 * should inherit from this class rather than MapPolicy<>::ThePolicy so
 * that the memory management can be out of the hands of the users.
 */
template <class Stored>
struct MapPointainerPolicy{
  /**
   * Right now, ThePolicy is just a typedeffed STLMapPointainerPolicy
   */
  typedef STLMapPointainerPolicy<Stored> ThePolicy;
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
struct PtrPolicy {
  //  typedef SmartPtr<Pointed> ThePolicy;

  // to not use smart pointers: currently this results in a bad memory
  // leak.  We will have smart pointers working shortly, they have
  // been tested and work, but not in this build at the moment

  /**
   * Right now the policy is just to use raw pointers, but that can be changed
   * to smart pointers at some later date.
   */
  typedef Pointed* ThePolicy;
};

#endif
