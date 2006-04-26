#ifndef DISABLE_TTREE_OARCHIVE

#include <icetray/serialization.h>

#include <boost/random/lagged_fibonacci.hpp>
#include <boost/random/mersenne_twister.hpp>

#include <dataclasses/physics/I3Particle.h>

static boost::lagged_fibonacci607 random_double;
static boost::mt19937             random_int;

static void reseed()
{
  random_double.seed();
  random_int.seed();
}

#include <I3Test.h>
#include <fstream>

using boost::serialization::make_nvp;
using boost::serialization::base_object;

#include <TFile.h>
#include <TTree.h>
#include <boost/preprocessor.hpp>

TEST_GROUP(ttree_oarchive);

const string fname = "I3Particle_via_I3FrameObject.root";
const unsigned nentries = 50000;

static void randomize(I3Particle& particle)
{
  particle.SetPos(random_double(), random_double(), random_double());
  particle.SetEnergy(random_double());
  particle.SetLength(random_double());
}

TEST(particle_shared_ptr_0)
{
  reseed();
  unlink (fname.c_str());
  TFile tfile(I3Test::tempfile("particle_shared_ptr_0.root").c_str(), "RECREATE");
  TTree ttree("particle", "", 0);
  boost::archive::ttree_oarchive oa(ttree);
  
  I3ParticlePtr particles[10];
  for (unsigned i=0; i<10; i++)
    particles[i] = I3ParticlePtr(new I3Particle);

  for (unsigned i=0; i<nentries; i++)
    {
      randomize(*(particles[i%10]));
      I3ParticlePtr particle(particles[i%10]);
      oa << make_nvp("particle", particle);
    }
  ttree.Write();
  tfile.Close();
}

TEST(particle_shared_ptr_1)
{
  reseed();
  TFile tfile(I3Test::tempfile("particle_shared_ptr_0.root").c_str());
  TTree* tree = (TTree*)tfile.Get("particle");
  ENSURE(tree);

  double x, y, z, e, len;

  tree->SetBranchAddress("X", &x);
  tree->SetBranchAddress("Y", &y);
  tree->SetBranchAddress("Z", &z);
  tree->SetBranchAddress("energy", &e);
  tree->SetBranchAddress("length", &len);

  ENSURE_EQUAL(tree->GetEntries(), nentries);

  for (unsigned j=0; j<nentries; j++)
    {
      I3Particle db;
      randomize(db);
      tree->GetEntry(j);
      ENSURE_DISTANCE(e, db.GetEnergy(), 0.00001);
      ENSURE_DISTANCE(len, db.GetLength(), 0.00001);
      ENSURE_DISTANCE(x, db.GetPos().GetX(), 0.00001);
      ENSURE_DISTANCE(y, db.GetPos().GetY(), 0.00001);
      ENSURE_DISTANCE(z, db.GetPos().GetZ(), 0.00001);
    }
}

TEST(particle_bald_ptr_0)
{
  reseed();
  unlink (fname.c_str());
  TFile tfile(I3Test::tempfile("particle_bald_ptr.root").c_str(), "RECREATE");
  TTree ttree("particle", "", 0);
  boost::archive::ttree_oarchive oa(ttree);
  
  I3Particle* particles[10];
  for (unsigned i=0; i<10; i++)
    particles[i] = new I3Particle;

  for (unsigned i=0; i<nentries; i++)
    {
      randomize(*(particles[i%10]));
      I3Particle* particle = particles[i%10];
      oa << make_nvp("particle", particle);
    }
  ttree.Write();
  tfile.Close();
}

TEST(particle_bald_ptr_1)
{
  reseed();
  TFile tfile(I3Test::tempfile("particle_bald_ptr.root").c_str());
  TTree* tree = (TTree*)tfile.Get("particle");
  ENSURE(tree);

  double x, y, z, e, len;

  tree->SetBranchAddress("X", &x);
  tree->SetBranchAddress("Y", &y);
  tree->SetBranchAddress("Z", &z);
  tree->SetBranchAddress("energy", &e);
  tree->SetBranchAddress("length", &len);

  ENSURE_EQUAL(tree->GetEntries(), nentries);

  for (unsigned j=0; j<nentries; j++)
    {
      I3Particle db;
      randomize(db);
      tree->GetEntry(j);
      ENSURE_DISTANCE(e, db.GetEnergy(), 0.00001);
      ENSURE_DISTANCE(len, db.GetLength(), 0.00001);
      ENSURE_DISTANCE(x, db.GetPos().GetX(), 0.00001);
      ENSURE_DISTANCE(y, db.GetPos().GetY(), 0.00001);
      ENSURE_DISTANCE(z, db.GetPos().GetZ(), 0.00001);
    }
}


TEST(particle_via_bareframeobjptr_0)
{
  reseed();
  unlink (fname.c_str());
  TFile tfile(I3Test::tempfile("particle_via_bareframeobjptr.root").c_str(), "RECREATE");
  TTree ttree("particle", "", 0);
  boost::archive::ttree_oarchive oa(ttree);
  
  I3ParticlePtr particles[10];
  for (unsigned i=0; i<10; i++)
    particles[i] = I3ParticlePtr(new I3Particle);

  for (unsigned i=0; i<nentries; i++)
    {
      randomize(*(particles[i%10]));
      I3FrameObject* object = particles[i%10].get();
      oa << make_nvp("particle", object);
    }
  ttree.Write();
  tfile.Close();
}

TEST(particle_via_bareframeobjptr_1)
{
  reseed();
  TFile tfile(I3Test::tempfile("particle_via_bareframeobjptr.root").c_str());
  TTree* tree = (TTree*)tfile.Get("particle");
  ENSURE(tree);

  double x, y, z, e, len;

  tree->SetBranchAddress("X", &x);
  tree->SetBranchAddress("Y", &y);
  tree->SetBranchAddress("Z", &z);
  tree->SetBranchAddress("energy", &e);
  tree->SetBranchAddress("length", &len);

  ENSURE_EQUAL(tree->GetEntries(), nentries);

  for (unsigned j=0; j<nentries; j++)
    {
      I3Particle db;
      randomize(db);
      tree->GetEntry(j);
      ENSURE_DISTANCE(e, db.GetEnergy(), 0.00001);
      ENSURE_DISTANCE(len, db.GetLength(), 0.00001);
      ENSURE_DISTANCE(x, db.GetPos().GetX(), 0.00001);
      ENSURE_DISTANCE(y, db.GetPos().GetY(), 0.00001);
      ENSURE_DISTANCE(z, db.GetPos().GetZ(), 0.00001);
    }
}

TEST(particle_via_sharedframeobjptr_0)
{
  reseed();
  unlink (fname.c_str());
  TFile tfile(I3Test::tempfile("particle_via_sharedframeobjptr.root").c_str(), "RECREATE");
  TTree ttree("particle", "", 0);
  boost::archive::ttree_oarchive oa(ttree);
  
  I3ParticlePtr particles[10];
  for (unsigned i=0; i<10; i++)
    particles[i] = I3ParticlePtr(new I3Particle);

  for (unsigned i=0; i<nentries; i++)
    {
      randomize(*(particles[i%10]));
      I3FrameObjectConstPtr object(particles[i%10]);
      oa << make_nvp("particle", object);
    }
  ttree.Write();
  tfile.Close();
}

TEST(particle_via_sharedframeobjptr_1)
{
  reseed();
  TFile tfile(I3Test::tempfile("particle_via_sharedframeobjptr.root").c_str());
  TTree* tree = (TTree*)tfile.Get("particle");
  ENSURE(tree);

  double x, y, z, e, len;

  tree->SetBranchAddress("X", &x);
  tree->SetBranchAddress("Y", &y);
  tree->SetBranchAddress("Z", &z);
  tree->SetBranchAddress("energy", &e);
  tree->SetBranchAddress("length", &len);

  ENSURE_EQUAL(tree->GetEntries(), nentries);

  for (unsigned j=0; j<nentries; j++)
    {
      I3Particle db;
      randomize(db);
      tree->GetEntry(j);
      ENSURE_DISTANCE(e, db.GetEnergy(), 0.00001);
      ENSURE_DISTANCE(len, db.GetLength(), 0.00001);
      ENSURE_DISTANCE(x, db.GetPos().GetX(), 0.00001);
      ENSURE_DISTANCE(y, db.GetPos().GetY(), 0.00001);
      ENSURE_DISTANCE(z, db.GetPos().GetZ(), 0.00001);
    }
}
#endif
