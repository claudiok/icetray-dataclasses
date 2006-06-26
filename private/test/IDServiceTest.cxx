#include <I3Test.h>

#include "dataclasses/physics/I3Particle.h"
// This is a test that checks that each of the frames that comes
// through is a.) created on the right stream and b.) has the 
// right classes in it.
TEST_GROUP(IDServiceTest);

TEST(test)
{

  I3Particle p1;
  I3Particle p2;

  cout<<"id1:"<<p1.GetID()<<endl;
  cout<<"id2:"<<p2.GetID()<<endl;

  ENSURE(p1.GetID() == 0,"This ID should be 0");
  ENSURE(p2.GetID() == 1,"This ID should be 1");
}

TEST(copy_test)
{

  I3Particle p1;
  I3Particle p2;

  cout<<"id1:"<<p1.GetID()<<endl;
  cout<<"id2:"<<p2.GetID()<<endl;

  I3Particle p1_prime(p1);
  I3Particle p2_prime(p2);

  ENSURE(p1.GetID() == p1_prime.GetID(),"This ID should be 0");
  ENSURE(p2.GetID() == p2_prime.GetID(),"This ID should be 1");
}

