/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: HasntNAN.cxx,v 1.1 2005/04/07 13:16:23 olivas Exp $

    @version $Revision: 1.1 $
    @date $Date: 2005/04/07 13:16:23 $
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
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
