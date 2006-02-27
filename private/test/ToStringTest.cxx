/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: ToStringTest.cxx 9329 2005-06-20 22:36:05Z dule $
*/

#include <I3Test.h>

#include "dataclasses/Utility.h"
#include "dataclasses/physics/I3Particle.h"

using namespace std;

TEST_GROUP(ToString);

TEST(I3Position)
{
  I3PositionPtr posp(new I3Position());
  ENSURE(ToString(posp).substr(399,3)=="<Y>");

  I3Position pos;
  ENSURE(ToString(pos).substr(346,3)=="<Y>");
}

TEST(I3Direction)
{
  I3DirectionPtr dirp(new I3Direction());
  ENSURE(ToString(dirp).substr(405,5)=="<Azi>");

  I3Direction dir;
  ENSURE(ToString(dir).substr(352,5)=="<Azi>");
}

TEST(I3Particle)
{
  I3ParticlePtr muonp(new I3Particle());
  ENSURE(ToString(muonp).substr(820,8)=="<energy>");

  I3Particle muon;
  ENSURE(ToString(muon).substr(751,8)=="<energy>");
}
