/**
    copyright  (C) 2004
    the icecube collaboration

    @version $Revision: 1.3 $
    @date $Date: 2005-06-19 19:06:10 +0200 (Sun, 19 Jun 2005) $
    @author blaufuss

    @todo
*/

#include <I3Test.h>
#include <iostream>
#include <string>
#include "dataclasses/physics/I3Particle.h"

using namespace std;

TEST_GROUP(I3Particle);

TEST(CopyPtrConstructor)
{

  I3ParticlePtr p1(new I3Particle());
  p1->SetPos(1.0, 2.0, 3.0);
  p1->SetDir(2.5,3.5);
  p1->SetType(I3Particle::PMinus);
  p1->SetShape(I3Particle::Cascade);
  p1->SetEnergy(100*I3Units::GeV);
  p1->SetSpeed(I3Constants::c);
  cout<<AsXML(p1);

  I3ParticlePtr p2(p1);
  cout<<AsXML(p2);

  ENSURE_DISTANCE(p1->GetX(),p2->GetX(),0.01,
                  "Copied positions do not match");
  ENSURE_DISTANCE(p1->GetY(),p2->GetY(),0.01,
                  "Copied positions do not match");
  ENSURE_DISTANCE(p1->GetZ(),p2->GetZ(),0.01,
                  "Copied positions do not match");
  ENSURE_DISTANCE(p1->GetZenith(),p2->GetZenith(),0.01,
                  "Copied directions do not match");
  ENSURE_DISTANCE(p1->GetAzimuth(),p2->GetAzimuth(),0.01,
                  "Copied directions do not match");

}

TEST(CopyObjConstructor)
{

  I3Particle p1;
  p1.SetPos(1.0, 2.0, 3.0);
  p1.SetDir(2.5,3.5);
  p1.SetType(I3Particle::PMinus);
  p1.SetShape(I3Particle::Cascade);
  p1.SetEnergy(100*I3Units::GeV);
  p1.SetSpeed(I3Constants::c);
  cout<<AsXML(p1);

  I3Particle p2(p1);
  cout<<AsXML(p2);

  ENSURE_DISTANCE(p1.GetX(),p2.GetX(),0.01,
                  "Copied positions do not match");
  ENSURE_DISTANCE(p1.GetY(),p2.GetY(),0.01,
                  "Copied positions do not match");
  ENSURE_DISTANCE(p1.GetZ(),p2.GetZ(),0.01,
                  "Copied positions do not match");
  ENSURE_DISTANCE(p1.GetZenith(),p2.GetZenith(),0.01,
                  "Copied directions do not match");
  ENSURE_DISTANCE(p1.GetAzimuth(),p2.GetAzimuth(),0.01,
                  "Copied directions do not match");
}


