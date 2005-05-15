/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.2 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include <services/I3Logging.h>
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

TEST(verified_bool_test_xml)
{
  HasBool btrue, bfalse;
  std::ofstream ofs("/tmp/verified_bool_test.xml");
  {
    xml_oarchive oa(ofs);
    btrue.b = true;
    oa << make_nvp("HasTrueBool", btrue);
    bfalse.b = false;
    oa << make_nvp("HasFalseBool", bfalse);
  }
  ofs.close();
  std::ifstream ifs("/tmp/verified_bool_test.xml");
  {
    btrue.b = false;
    xml_iarchive ia(ifs);
    ia >> make_nvp("HasTrueBool", btrue);
    ENSURE(btrue.b == true);
    bfalse.b = true;
    ia >> make_nvp("HasFalseBool", bfalse);
    ENSURE(bfalse.b == false);
  }
  ifs.close();
}

TEST(verified_bool_test_text)
{
  HasBool btrue, bfalse;
  std::ofstream ofs("/tmp/verified_bool_test.txt");
  {
    text_oarchive oa(ofs);
    btrue.b = true;
    oa << make_nvp("HasTrueBool", btrue);
    bfalse.b = false;
    oa << make_nvp("HasFalseBool", bfalse);
  }
  ofs.close();

  std::ifstream ifs("/tmp/verified_bool_test.txt");
  {
    btrue.b = false;
    text_iarchive ia(ifs);
    ia >> make_nvp("HasTrueBool", btrue);
    ENSURE(btrue.b == true);
    bfalse.b = true;
    ia >> make_nvp("HasFalseBool", bfalse);
    ENSURE(bfalse.b == false);
  }
  ifs.close();
}

