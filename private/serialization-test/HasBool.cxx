/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: HasBool.cxx,v 1.2 2005/04/06 21:28:59 olivas Exp $

    @version $Revision: 1.2 $
    @date $Date: 2005/04/06 21:28:59 $
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
#include "dataclasses/I3Hit.h"

struct HasBool {
  bool b;
  template <class Archive>
  void serialize(Archive &ar, unsigned version)
  {
    ar & make_nvp("b", (int)b);
  }
};

TEST_GROUP(HasBool);

I3_SERIALIZATION_TEST(HasBool);
