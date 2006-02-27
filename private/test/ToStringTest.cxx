/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: ToStringTest.cxx 9329 2005-06-20 22:36:05Z dule $
*/

#include <I3Test.h>

#include "dataclasses/Utility.h"
#include "dataclasses/physics/I3Particle.h"

using namespace std;

#warning AsXML tests out for now

#if 0
TEST_GROUP(AsXML);

TEST(I3Position)
{
  I3PositionPtr posp(new I3Position());
  ENSURE(AsXML(posp).substr(399,3)=="<Y>");

  I3Position pos;
  ENSURE(AsXML(pos).substr(346,3)=="<Y>");
}

TEST(I3Direction)
{
  I3DirectionPtr dirp(new I3Direction());
  ENSURE(AsXML(dirp).substr(405,5)=="<Azi>");

  I3Direction dir;
  ENSURE(AsXML(dir).substr(352,5)=="<Azi>");
}

TEST(I3Particle)
{
  I3ParticlePtr muonp(new I3Particle());
  ENSURE(AsXML(muonp).substr(820,8)=="<energy>");

  I3Particle muon;
  ENSURE(AsXML(muon).substr(751,8)=="<energy>");
}
#endif
