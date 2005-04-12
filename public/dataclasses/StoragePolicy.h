/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.23 2005/04/12 17:24:13 troy Exp $
    @version $Revision: 1.23 $
    @date $Date: 2005/04/12 17:24:13 $

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
    class access;
    template <class T> struct nvp;
    template <class T> nvp<T> make_nvp(const char* name, T& t);
#ifndef BOOST_SERIALIZATION_BASE_OBJECT_HPP
    template <class Base, class Derived, class Retval>
      Retval base_object(Derived &d);
#endif
#ifndef BOOST_SERIALIZATION_IS_ABSTRACT_CLASS_HPP
#define BOOST_IS_ABSTRACT(X)
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

