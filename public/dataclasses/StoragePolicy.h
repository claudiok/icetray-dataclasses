/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.19 2005/03/31 17:39:49 troy Exp $
    @version $Revision: 1.19 $
    @date $Date: 2005/03/31 17:39:49 $

    @author troy d. straszheim
*/

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "TObject.h"

#include "dataclasses/copy_if.h"

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"
#include "STLMultiMapStoragePolicy.h"

#include "services/I3Logging.h"

// temporary typedefs to compensate for removal of root shit

/**
 * @brief The pointer policy.  Should use typedefs of this rather than
 * raw pointers.
 *
 * The existence of this PtrPolicy allows for typdefs of
 * PtrPolicy<Foo>::ThePolicy FooPtr.  Then users use FooPtr rather than
 * Foo*.  What this does is allow the true implemntation of FooPtr to change
 * in this one place, and the rest of the code is unaffected
 */

//#ifndef __CINT__
//
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/nvp.hpp>
//#include <boost/serialization/export.hpp>
//#include <boost/serialization/map.hpp>
//#include <boost/serialization/vector.hpp>
//
//
//#else

// forward declarations.  The full headers should only be included
// from modules that actually do the serialization.

namespace boost 
{
  namespace serialization 
  {
    class access;
  }
  template <class T> struct nvp;
  template <class T> nvp<T> make_nvp(const char* name, T& t);
#ifndef BOOST_SERIALIZATION_BASE_OBJECT_HPP
  template <class Base, class Derived, class Retval>
  Retval base_object(Derived &d);
#endif
}
using boost::serialization::make_nvp;
using boost::serialization::base_object;

//#endif

template <class Pointed>
struct PtrPolicy
{
  /**
   * roost smart pointers.  FIXME: need docs
   */
  typedef boost::shared_ptr<Pointed> ThePolicy;
  //  typedef Pointed* ThePolicy;
};

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

#endif

