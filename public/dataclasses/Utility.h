/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id$
    @date $Date$
*/

#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdint.h> //int64_t, etc
#include "dataclasses/copy_if.h"
#include <icetray/IcetrayFwd.h>
#include "icetray/I3FrameObject.h"

namespace boost 
{
  namespace serialization 
  {
    // normal forward declarations:
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

#include <icetray/I3Logging.h>

using namespace std;

// forward declarations.  Instantiations come via I3_SERIALIZABLE().
// icetray/serialization.h
template <typename T>
std::string 
AsXML(const T& ob);

// hide Get from ROOT since Rene doesn't like templates
#ifndef __CINT__
namespace I3
{

  /**
   * @brief function to get data out of a map-like object.  
   */
  template <class MapType>
    typename MapType::value_type::second_type& 
    Get(const typename MapType::key_type& key,
	MapType& themap)
    {
      typename MapType::iterator found = themap.find(key);
      if(found == themap.end())
	{
	  ostringstream error;
	  error<<"Couldn't find key "<<key<<" in this map";
	  log_fatal(error.str().c_str());
	}
      return found->second;
    }
  
  /**
   * @brief function to get data out of a map-like object.  
   */
  template <class MapType>
    const typename MapType::value_type::second_type& 
    Get(const typename MapType::key_type& key,
	const MapType& themap)
    {
      typename MapType::const_iterator found = themap.find(key);
      if(found == themap.end())
      if(found == themap.end())
	{
	  ostringstream error;
	  error<<"Couldn't find key "<<key<<" in this map";
	  log_fatal(error.str().c_str());
	}
      return found->second;
    }
};
#endif

#endif 
