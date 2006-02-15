/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id$
    @date $Date$
*/

#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "TObject.h"
#include <stdint.h> //int64_t, etc
#include "dataclasses/copy_if.h"

namespace boost 
{
  namespace serialization 
  {
    // normal forward declarations:
    class access;
    template <class T> struct nvp;
    template <class T> const nvp<T> make_nvp(const char* name, T& t);

    // special dummy no-ops that check to see if boost headers have
    // already been included.
#ifndef BOOST_SERIALIZATION_BASE_OBJECT_HPP
    template <class Retval, class Derived>
      Retval base_object(Derived);
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
#ifndef BOOST_SERIALIZATION_SPLIT_MEMBER_HPP
#define BOOST_SERIALIZATION_SPLIT_MEMBER()
#endif
  }
}

using boost::serialization::make_nvp;
using boost::serialization::base_object;

#include "icetray/services/I3Logging.h"

// for generating pointer typedefs in dataclass structures.
// pointer to const object and pointer to object
#define I3_POINTER_TYPEDEFS(class) \
typedef shared_ptr<class> class##Ptr; \
typedef shared_ptr<const class> class##ConstPtr;


#endif 

