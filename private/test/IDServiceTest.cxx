#include <I3Test.h>

#include "dataclasses/I3IDService.h"
#include "dataclasses/physics/I3Particle.h"
// This is a test that checks that each of the frames that comes
// through is a.) created on the right stream and b.) has the 
// right classes in it.
TEST_GROUP(IDServiceTest);

TEST(test)
{
  shared_ptr<I3IDService> id_service(new I3IDService);

  I3Particle p1;
  I3Particle p2;

  p1.SetID(id_service);
  p2.SetID(id_service);
  //should have unique IDs now

  ENSURE(p1.GetID() == 0,"This ID should be 0");
  ENSURE(p2.GetID() == 1,"This ID should be 1");
}

