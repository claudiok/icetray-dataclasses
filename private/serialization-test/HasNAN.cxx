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
