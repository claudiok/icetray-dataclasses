/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: HasNAN.cxx,v 1.1 2005/04/07 13:16:23 olivas Exp $

    @version $Revision: 1.1 $
    @date $Date: 2005/04/07 13:16:23 $
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
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
