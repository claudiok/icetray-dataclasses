/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.16.4.1 2005/01/25 23:33:44 troy Exp $

    @file StoragePolicy.h
    @version $Revision: 1.16.4.1 $
    @date $Date: 2005/01/25 23:33:44 $
    @author Troy D. Straszheim
*/

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "dataclasses/copy_if.h"

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"
#include "STLMultiMapStoragePolicy.h"



/**
 * @brief The pointer policy.  Should use typedefs of this rather than
 * raw pointers.
 *
 * The existence of this PtrPolicy allows for typdefs of
 * PtrPolicy<Foo>::ThePolicy FooPtr.  Then users use FooPtr rather than
 * Foo*.  What this does is allow the true implemntation of FooPtr to change
 * in this one place, and the rest of the code is unaffected
 */

#ifndef __CINT__
#include <boost/serialization/serialization.hpp>
#include <boost/shared_ptr.hpp>

template <class Pointed>
struct PtrPolicy
{
  /**
   * roost smart pointers.  FIXME: need docs
   */
  typedef boost::shared_ptr<Pointed> ThePolicy;
  //  typedef Pointed* ThePolicy;
};

using boost::dynamic_pointer_cast;
#else
#include <roost/shared_ptr.hpp>

template <class Pointed>
struct PtrPolicy
{
  /**
   * roost smart pointers.  FIXME: need docs
   */
  typedef roost::shared_ptr<Pointed> ThePolicy;
  //  typedef Pointed* ThePolicy;
};

using roost::dynamic_pointer_cast;

namespace boost {
  namespace serialization {
    class access;
  }
}
#endif

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
template <class Key, class Stored>
struct MapPolicy {
  /**
   *  ThePolicy is just a typedeffed STLMapStoragePolicy
   */
  typedef STLMapStoragePolicy<Key,Stored> ThePolicy;

};

/**
 * @brief The storage policy for multimaps of objects
 *
 * The existence of this MultiMapPolicy class allows classes to inherit
 * from MultiMapPolicy<>::ThePolicy.  That policy's implementation can change -
 * provided the new implementation supplies the same interface - just by
 * changing this MultiMapPolicy class.  That's what it is here for.
 */
template <class Key, class Stored>
struct MultiMapPolicy {
  /**
   *  ThePolicy is just a typedeffed STLMapStoragePolicy
   */
  typedef STLMultiMapStoragePolicy<Key,Stored> ThePolicy;

};

#endif //STORAGEPOLICY_H_INCLUDED
