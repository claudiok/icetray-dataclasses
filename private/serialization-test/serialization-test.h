#ifndef SERIALIZATION_TEST_H_INCLUDED
#define SERIALIZATION_TEST_H_INCLUDED

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/is_abstract.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <icetray/test/I3Test.h>
#include <fstream>

#include "random_iarchive.hpp"

using boost::archive::xml_oarchive;
using boost::archive::text_oarchive;
using boost::archive::binary_oarchive;
using boost::archive::xml_iarchive;
using boost::archive::text_iarchive;
using boost::archive::binary_iarchive;

using boost::serialization::make_nvp;
using boost::serialization::base_object;

#define I3_SERIALIZATION_TEST_ARCHIVE(TYPE, SUBTYPE, ARCHIVE, RANDOMIZE) \
  TEST(ARCHIVE) {						\
    do_archive<ARCHIVE ##_oarchive, ARCHIVE ##_iarchive, TYPE, SUBTYPE,  \
       RANDOMIZE>                	                        \
    (BOOST_PP_STRINGIZE(SUBTYPE), BOOST_PP_STRINGIZE(ARCHIVE));    \
  }

#define I3_SERIALIZATION_TEST(TYPE)                      		 \
  I3_SERIALIZATION_TEST_ARCHIVE(TYPE, TYPE, text, random_iarchive_randomize);	 \
  I3_SERIALIZATION_TEST_ARCHIVE(TYPE, TYPE, binary, random_iarchive_randomize);	\
  I3_SERIALIZATION_TEST_ARCHIVE(TYPE, TYPE, xml, random_iarchive_randomize);
  
#define I3_VIRTUAL_SERIALIZATION_TEST(BASE, DERIVED) \
  I3_SERIALIZATION_TEST_ARCHIVE(BASE, DERIVED, text, random_iarchive_randomize);	\
  I3_SERIALIZATION_TEST_ARCHIVE(BASE, DERIVED, binary, random_iarchive_randomize);	\
  I3_SERIALIZATION_TEST_ARCHIVE(BASE, DERIVED, xml, random_iarchive_randomize);

struct random_iarchive_randomize {
  template <typename T>
  static void apply (T &t)
  {
    random_iarchive ria;
    ria >> t;
  }
};

struct noop_randomize {
  template <typename T>
  static void apply (T &t) { }
};

template <class OArchive, 
	  class IArchive, 
	  class BaseType, 
	  class DerivedType, 
	  class Randomize>
void do_archive(const string& classname, const string& archive_type)
{
  const unsigned numobjects = 10;
  // make archive
  string tmpfile = "/tmp/" + classname + "." + archive_type;
  std::ofstream ofs(tmpfile.c_str());
  OArchive oa(ofs);
  string ptr_classname = classname + "Ptr";
    
  shared_ptr<DerivedType> t_out;

  for (unsigned i=0; i<numobjects; i++)
    {
      //      t_bald = new DerivedType;
      //      cout << t_bald;
      t_out = shared_ptr<DerivedType>(new DerivedType);
//      Randomize::apply(*t_out);
      //      cout << t_out.get();
      //      t_out = shared_ptr<DerivedType>(new DerivedType);
      //      cout << t_out.get();
      oa << make_nvp(classname.c_str(), *t_out);
    }
  ofs.close();

  //read it back in and compare
  std::ifstream ifs(tmpfile.c_str());
  IArchive ia(ifs);
  shared_ptr<DerivedType> t_in;
  for (unsigned i=0; i<numobjects; i++)
    {
      ia >> make_nvp(classname.c_str(), *t_out);

      // ENSURE(t_in == t_out);
      // boost::shared_ptr<BaseType> baseptr;
      // ia >> make_nvp(ptr_classname.c_str(), baseptr);

    }
  ifs.close();
}

#endif
