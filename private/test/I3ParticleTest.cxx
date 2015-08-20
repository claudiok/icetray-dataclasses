/**
    copyright  (C) 2004
    the icecube collaboration

    @version $Revision$
    @date $Date$
    @author blaufuss

    @todo
*/

#include <I3Test.h>
#include <cmath>
#include <iostream>
#include <string>
#include <boost/preprocessor.hpp>

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/I3Constants.h"
#include "icetray/I3Units.h"

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
                  "Copied position (X) do not match");
  ENSURE_DISTANCE(p1->GetY(),p2->GetY(),0.01,
                  "Copied position (Y) do not match");
  ENSURE_DISTANCE(p1->GetZ(),p2->GetZ(),0.01,
                  "Copied position (Z) do not match");
  ENSURE_DISTANCE(p1->GetZenith(),p2->GetZenith(),0.01,
                  "Copied direction (Zenith) does not match");
  ENSURE_DISTANCE(p1->GetAzimuth(),p2->GetAzimuth(),0.01,
                  "Copied direction (Azimuth) does not match");
  ENSURE_DISTANCE(p1->GetEnergy(),p2->GetEnergy(),0.01,
                  "Copied energy does not match");
  ENSURE_DISTANCE(p1->GetSpeed(),p2->GetSpeed(),0.01,
                  "Copied speed does not match");
  ENSURE( p1->GetType() == p2->GetType(),
                  "Copied type do not match");
  ENSURE( p1->GetShape() == p2->GetShape(),
                  "Copied shape do not match");

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
                  "Copied position (X) do not match");
  ENSURE_DISTANCE(p1.GetY(),p2.GetY(),0.01,
                  "Copied position (Y) do not match");
  ENSURE_DISTANCE(p1.GetZ(),p2.GetZ(),0.01,
                  "Copied position (Z) do not match");
  ENSURE_DISTANCE(p1.GetZenith(),p2.GetZenith(),0.01,
                  "Copied direction (Zenith) does not match");
  ENSURE_DISTANCE(p1.GetAzimuth(),p2.GetAzimuth(),0.01,
                  "Copied direction (Azimuth) does not match");
  ENSURE_DISTANCE(p1.GetEnergy(),p2.GetEnergy(),0.01,
                  "Copied energy does not match");
  ENSURE_DISTANCE(p1.GetSpeed(),p2.GetSpeed(),0.01,
                  "Copied speed does not match");
  ENSURE( p1.GetType() == p2.GetType(),
                  "Copied type do not match");
  ENSURE( p1.GetShape() == p2.GetShape(),
                  "Copied shape do not match");
  ENSURE( p1.GetID() == p2.GetID(),
                  "Particle IDs do not match");

}

TEST(istrack){

  I3Particle itrack; 
  I3Particle start_track;
  I3Particle stop_track;
  I3Particle cont_track;
  I3Particle muplus;
  I3Particle muminus;
  I3Particle tauplus;
  I3Particle tauminus;
  I3Particle mp;

  itrack.SetShape(I3Particle::InfiniteTrack);
  start_track.SetShape(I3Particle::StartingTrack);
  stop_track.SetShape(I3Particle::StoppingTrack);
  cont_track.SetShape(I3Particle::ContainedTrack);
  muplus.SetType(I3Particle::MuPlus);
  muminus.SetType(I3Particle::MuMinus);
  tauplus.SetType(I3Particle::TauPlus);
  tauminus.SetType(I3Particle::MuMinus);
  mp.SetType(I3Particle::Monopole);

  ENSURE(itrack.IsTrack()); 
  ENSURE(start_track.IsTrack());
  ENSURE(stop_track.IsTrack());
  ENSURE(cont_track.IsTrack());
  ENSURE(muplus.IsTrack());
  ENSURE(muminus.IsTrack());
  ENSURE(tauplus.IsTrack());
  ENSURE(tauminus.IsTrack());
  ENSURE(mp.IsTrack());
  

}

TEST(iscascade){

  I3Particle cascade; 
  I3Particle eplus; 
  I3Particle eminus; 
  I3Particle brem; 
  I3Particle delta; 
  I3Particle pair; 
  I3Particle nucl; 
  I3Particle gamma; 
  I3Particle hadron; 
  I3Particle piplus; 
  I3Particle piminus; 

  cascade.SetShape(I3Particle::Cascade);
  eplus.SetType(I3Particle::EPlus); 
  eminus.SetType(I3Particle::EMinus); 
  brem.SetType(I3Particle::Brems); 
  delta.SetType(I3Particle::DeltaE); 
  pair.SetType(I3Particle::PairProd); 
  nucl.SetType(I3Particle::NuclInt); 
  gamma.SetType(I3Particle::Gamma); 
  hadron.SetType(I3Particle::Hadrons); 
  piplus.SetType(I3Particle::PiPlus); 
  piminus.SetType(I3Particle::PiMinus); 

  ENSURE(cascade.IsCascade()); 
  ENSURE(eplus.IsCascade()); 
  ENSURE(eminus.IsCascade()); 
  ENSURE(brem.IsCascade()); 
  ENSURE(delta.IsCascade()); 
  ENSURE(pair.IsCascade()); 
  ENSURE(nucl.IsCascade()); 
  ENSURE(gamma.IsCascade()); 
  ENSURE(hadron.IsCascade()); 
  ENSURE(piplus.IsCascade()); 
  ENSURE(piminus.IsCascade()); 
}

TEST(shifting_tracks) {
  I3Particle p(I3Position(0.,0.,0.), I3Direction(1.,1.,1.), 0., I3Particle::ContainedTrack, 20.);
  //p.SetSpeed(I3Constants::c); //implicit
  ENSURE(p.ShiftAlongTrack(0)== I3Position(0.,0.,0.) );
  // 1/sqrt(3)*10 == 5.7735
  ENSURE( (p.ShiftAlongTrack(10)-I3Position(5.7735,5.7735,5.7735)).Magnitude() <0.001 ); //precision better than a mm
  ENSURE(p.ShiftTimeTrack(0)== I3Position(0.,0.,0.) );
  // 1/sqrt(3)*10*I3Constants::c == 1.73085
  ENSURE( (p.ShiftTimeTrack(10)-I3Position(1.73085,1.73085,1.73085)).Magnitude() <0.001 ); //precision better than a mm
}

TEST(stop_time) {
  I3Particle particle;
  ENSURE(isnan(particle.GetStopTime()));

  particle.SetShape(I3Particle::StoppingTrack);
  double time = 10.*I3Units::ns;
  particle.SetTime(10.*I3Units::ns);
  ENSURE(fabs(particle.GetStopTime() - time) < 0.001*I3Units::ns);

  particle.SetShape(I3Particle::ContainedTrack);
  double length = 500.*I3Units::m;
  particle.SetLength(length);
  double stop_time = time + length/I3Constants::c;
  ENSURE(fabs(particle.GetStopTime() - stop_time) < 0.001*I3Units::ns);

  particle.SetShape(I3Particle::MCTrack);
  ENSURE(fabs(particle.GetStopTime() - stop_time) < 0.001*I3Units::ns);
}

