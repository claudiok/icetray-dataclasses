/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: HasBool.cxx,v 1.1 2005/04/02 17:44:32 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2005/04/02 17:44:32 $
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
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
