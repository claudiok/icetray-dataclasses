/**
    copyright  (C) 2004
    the icecube collaboration

    @version $Revision$
    @date $Date$
    @author blaufuss

    @todo
*/

#include <I3Test.h>
#include <iostream>
#include <string>
#include <boost/preprocessor.hpp>

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/I3Constants.h"

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

TEST(ParticleTypesDoStillWork)
{
    // ParticleTypes get converted to PDG encodings
    // internally. Are they still consistent?
    // (do not test I3Particle::UnknownWithPdgEncoding,
    // which is not supposed to be used with SetType)

#define THE_TEST(r, data, type)                         \
    if (I3Particle::type != I3Particle::UnknownWithPdgEncoding) {   \
        I3Particle test;                                \
        test.SetType(I3Particle::type);                             \
        ENSURE(test.GetType()==I3Particle::type);                   \
    }

    BOOST_PP_SEQ_FOR_EACH(THE_TEST, ~, I3PARTICLE_H_I3Particle_ParticleType)
}
