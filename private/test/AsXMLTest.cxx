/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: ToStringTest.cxx 9329 2005-06-20 22:36:05Z dule $
*/

#include <I3Test.h>

#include "dataclasses/Utility.h"
#include "dataclasses/physics/I3Particle.h"

using namespace std;

TEST_GROUP(AsXMLTest);

TEST(I3Position)
{
  I3Position pos;
  cout << AsXML(pos);
  I3PositionPtr pptr(new I3Position);
  cout << AsXML(pptr);
}

TEST(I3Direction)
{
  I3Direction dir;
  cout << AsXML(dir);
  I3DirectionPtr dirptr(new I3Direction);
  cout << AsXML(dirptr);
  I3DirectionConstPtr dircnstptr(new I3Direction);
  cout << AsXML(dircnstptr);
}

TEST(I3Particle)
{
  I3Particle muon;
  cout << AsXML(muon);
}
