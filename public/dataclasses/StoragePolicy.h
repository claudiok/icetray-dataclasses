/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$
    @version $Revision: 1.24 $
    @date $Date$

    @author troy d. straszheim
*/

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "TObject.h"

#include "dataclasses/copy_if.h"

namespace boost 
{
  namespace serialization 
  {
    // normal forward declarations:
    class access;
    template <class T> struct nvp;
    template <class T> nvp<T> make_nvp(const char* name, T& t);

    // special dummy no-ops that check to see if boost headers have
    // already been included.
#ifndef BOOST_SERIALIZATION_BASE_OBJECT_HPP
    template <class Base, class Derived, class Retval>
      Retval base_object(Derived &d);
#endif
#ifndef BOOST_SERIALIZATION_IS_ABSTRACT_CLASS_HPP
#define BOOST_IS_ABSTRACT(X)
#endif
#ifndef BOOST_SERIALIZATION_EXPORT_HPP
#define BOOST_CLASS_EXPORT(X) 
#endif
#ifndef BOOST_SERIALIZATION_SHARED_PTR_HPP
#define BOOST_SHARED_POINTER_EXPORT(X) 
#endif

  }
}

using boost::serialization::make_nvp;
using boost::serialization::base_object;

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"
#include "STLMultiMapStoragePolicy.h"

#include "services/I3Logging.h"


#endif

