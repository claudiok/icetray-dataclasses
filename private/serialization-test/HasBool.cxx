/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.2 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3Hit.h"

struct HasBool {
  bool b;
  template <class Archive>
  void serialize(Archive &ar, unsigned version)
  {
    ar & make_nvp("b", b);
  }
};

TEST_GROUP(HasBool);

I3_SERIALIZATION_TEST(HasBool);

TEST(verified_bool_test)
{
  HasBool b;
  std::ofstream ofs("/tmp/verified_bool_test.xml");
  {
    xml_oarchive oa(ofs);
    b.b = true;
    oa << make_nvp("HasTrueBool", b);
  }
  {
    xml_oarchive oa(ofs);
    b.b = false;
    oa << make_nvp("HasFalseBool", b);
  }
  ofs.close();
  std::ifstream ifs("/tmp/verified_bool_test.xml");
  
  {
    b.b = false;
    xml_iarchive ia(ifs);
    ia >> make_nvp("HasTrueBool", b);
    ENSURE(b.b == true);
  }
  {
    xml_iarchive ia(ifs);
    ia >> make_nvp("HasFalseBool", b);
    ENSURE(b.b == false);
  }
  ifs.close();
}

