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
