/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3Hit.h"
#include <sstream>

struct HasNan {
  float f;
  double d;

  HasNan() {
    f = NAN;
    d = NAN;
  }

  template <class Archive>
  void serialize(Archive &ar, unsigned version)
  {
    ar & make_nvp("f", f);
    ar & make_nvp("d", d);
  }
};

TEST_GROUP(HasNan);

I3_SERIALIZATION_TEST(HasNan);

// this test shows if streaming in a float as "nan" from text actually
// works or bails out.  The behavior is in libstdc++, not in our stuff.
#if 0
TEST(stdio_nan)
{
  ostringstream oss;
  float f = NAN;
  oss << f;
  istringstream iss(oss.str());
  cout << "oss.str == " << oss.str() << endl;
  cout << "iss.str == " << iss.str() << endl;
  //  ENSURE(iss.str() == "nan");
  f = 2;
  ENSURE(!iss.fail());
  iss >> f;
  ENSURE(!iss.fail());
  cout << "f=" << f << endl;
  ENSURE(isnan(f));
}
#endif


TEST(a_nan)
{
  double d = NAN;
  std::ofstream ofs("/tmp/one_nan.xml");
  xml_oarchive oa(ofs);
  oa << make_nvp("a_nan", d);
  ofs.close();
  std::ifstream ifs("/tmp/one_nan.xml");
  xml_iarchive ia(ifs);
  ia >> make_nvp("a_nan", d);
  ENSURE(isnan(d));
  ifs.close();
}

TEST(verified_nan_test)
{
  HasNan n;
  std::ofstream ofs("/tmp/verified_nan_test.xml");
  {
    xml_oarchive oa(ofs);
    oa << make_nvp("HasNans", n);
  }
  {
    xml_oarchive oa(ofs);
    n.f = 1.0;
    n.d = 1.0;
    oa << make_nvp("HasntNans", n);
  }

  ofs.close();
  std::ifstream ifs("/tmp/verified_nan_test.xml");
  
  {
    xml_iarchive ia(ifs);
    ia >> make_nvp("HasNans", n);
    ENSURE(isnan(n.d));
    ENSURE(isnan(n.f));
  }
  {
    xml_iarchive ia(ifs);
    ia >> make_nvp("HasntNans", n);
    ENSURE(n.d== 1.0);
    ENSURE(n.f== 1.0);
  }
  ifs.close();
}
