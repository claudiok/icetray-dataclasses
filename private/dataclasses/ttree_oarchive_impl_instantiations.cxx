/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// text_oarchive.cpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#ifndef I3_NO_TTREE_OARCHIVE

#define BOOST_ARCHIVE
#include <boost/archive/binary_oarchive.hpp>

#include <dataclasses/ttree_oarchive.h>

#include <sstream>

//#include <boost/archive/impl/basic_binary_oarchive.ipp>
//#include <boost/archive/impl/basic_binary_oprimitive.ipp> // contains init(), etc
#include <boost/archive/impl/archive_pointer_oserializer.ipp>
#include <boost/archive/basic_binary_oprimitive.hpp>
#include <boost/archive/detail/basic_pointer_oserializer.hpp>
#include <boost/archive/detail/oserializer.hpp>


namespace boost {
namespace archive {

  //  template class boost::archive::detail::common_oarchive<ttree_oarchive> ;
  //  template class basic_binary_oprimitive<root_oarchive, std::ostream> ;
  //  template class binary_oarchive_impl<root_oarchive> ;
  template class detail::archive_pointer_oserializer<ttree_oarchive_impl> ;

} // namespace archive
} // namespace boost

#endif
