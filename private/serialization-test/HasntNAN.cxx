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

struct HasntNAN {
  float f;
  double d;

  HasntNAN() {
    f = 0;
    d = 0;
  }

  template <class Archive>
  void serialize(Archive &ar, unsigned version)
  {
    ar & make_nvp("f", f);
    ar & make_nvp("d", d);
  }
};

TEST_GROUP(HasntNAN);

I3_SERIALIZATION_TEST(HasntNAN);
