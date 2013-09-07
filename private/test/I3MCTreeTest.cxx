/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision$
    @date $Date$
    @author tschmidt
*/
#include <vector>
#include <I3Test.h>
#include <dataclasses/physics/I3MCTree.h>
#include <dataclasses/physics/I3MCTreeUtils.h>
#include <icetray/I3Frame.h>

using namespace std;

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3MCTreeTest);

TEST(add_and_get_primaries)
{

  I3Particle p1;
  I3Particle p2;

  I3MCTree t;
  I3MCTreeUtils::AddPrimary(t,p1);
  I3MCTreeUtils::AddPrimary(t,p2);
  
  std::vector<I3Particle> p_list = I3MCTreeUtils::GetPrimaries(t);
  std::vector<I3Particle>::iterator i;

  bool found1 = false;
  bool found2 = false;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetMinorID() == p1.GetMinorID()) found1 = true;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetMinorID() == p2.GetMinorID()) found2 = true;

  ENSURE(found1 && found2);
}

TEST(add_children_to_primaries)
{
  I3Particle p1; 
  I3Particle p2; 

  int p1_id = p1.GetMinorID();
  int p2_id = p2.GetMinorID();

  I3MCTree t;
  I3MCTreeUtils::AddPrimary(t,p1);
  I3MCTreeUtils::AddPrimary(t,p2);
  
  std::vector<I3Particle> p_list = I3MCTreeUtils::GetPrimaries(t);
  std::vector<I3Particle>::iterator i;

  bool found1 = false;
  bool found2 = false;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetMinorID() == p1.GetMinorID()) found1 = true;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetMinorID() == p2.GetMinorID()) found2 = true;

  ENSURE(found1 && found2);

  I3Particle c1; 
  I3Particle c2; 
  I3Particle c3; 
  I3Particle c4; 

  int c1_id = c1.GetMinorID();
  int c2_id = c2.GetMinorID();
  int c3_id = c3.GetMinorID();
  int c4_id = c4.GetMinorID();

  I3MCTreeUtils::AppendChild(t,p1,c1);
  I3MCTreeUtils::AppendChild(t,p1,c2);
  I3MCTreeUtils::AppendChild(t,p2,c3);
  I3MCTreeUtils::AppendChild(t,p2,c4);

  I3Tree<I3Particle>::sibling_iterator si(t.begin());

  ENSURE(si->GetMinorID() == p1_id);

  I3Tree<I3Particle>::sibling_iterator ci(t.begin(si));
  ENSURE(ci->GetMinorID() == c1_id);
  ci++;
  ENSURE(ci->GetMinorID() == c2_id);

  si++;
  ENSURE(si->GetMinorID() == p2_id);
  ci = t.begin(si);
  ENSURE(ci->GetMinorID() == c3_id);
  ci++;
  ENSURE(ci->GetMinorID() == c4_id);

  std::vector<I3Particle>::iterator d_iter;
  std::vector<I3Particle> d_list;

  d_list = I3MCTreeUtils::GetDaughters(t,p1);
  d_iter = d_list.begin();
  ENSURE(d_iter->GetMinorID() == c1.GetMinorID());
  d_iter++;
  ENSURE(d_iter->GetMinorID() == c2.GetMinorID());

  ENSURE(I3MCTreeUtils::HasParent(t,c1));
  const I3Particle& p1_1 = I3MCTreeUtils::GetParent(t,c1);
  ENSURE(I3MCTreeUtils::HasParent(t,c2));
  const I3Particle& p1_2 = I3MCTreeUtils::GetParent(t,c2);
  ENSURE(p1_1.GetMinorID() == p1.GetMinorID());
  ENSURE(p1_2.GetMinorID() == p1.GetMinorID());

  d_list = I3MCTreeUtils::GetDaughters(t,p2);
  d_iter = d_list.begin();
  ENSURE(d_iter->GetMinorID() == c3.GetMinorID());
  d_iter++;
  ENSURE(d_iter->GetMinorID() == c4.GetMinorID());

  ENSURE(I3MCTreeUtils::HasParent(t,c3));
  const I3Particle& p2_3 = I3MCTreeUtils::GetParent(t,c3);
  ENSURE(I3MCTreeUtils::HasParent(t,c4));
  const I3Particle& p2_4 = I3MCTreeUtils::GetParent(t,c4);
  ENSURE(p2_3.GetMinorID() == p2.GetMinorID());
  ENSURE(p2_4.GetMinorID() == p2.GetMinorID());

}

TEST(mclist_to_mctree){

  I3Particle p;
  I3Particle gc5;

  I3MCListPtr l(new I3MCList);
  l->push_back(p);
  l->push_back(gc5);

  I3FramePtr frame(new I3Frame(I3Frame::Physics));
  frame->Put("TestI3MCList",l);

  I3MCTreeConstPtr t = I3MCTreeUtils::Get(frame,"TestI3MCList","BLAH");
  ENSURE(t->size() == 2); 

  I3Particle primary = I3MCTreeUtils::GetPrimaries(*t)[0];
  ENSURE(primary.GetMinorID() == p.GetMinorID());
}

TEST(most_energetic)
{
  I3Particle p1, p2;
  I3Particle m1, m2, m3;
  I3Particle c1, c2, c3; 

  p1.SetEnergy(500);
  p2.SetEnergy(700);

  m1.SetLocationType(I3Particle::InIce);
  m1.SetType(I3Particle::MuPlus);
  m1.SetEnergy(100);
  m2.SetLocationType(I3Particle::InIce);
  m2.SetType(I3Particle::MuMinus);
  m2.SetEnergy(300);
  m3.SetLocationType(I3Particle::InIce);
  m3.SetType(I3Particle::TauPlus);
  m3.SetEnergy(200);

  c1.SetLocationType(I3Particle::InIce);
  c1.SetType(I3Particle::EPlus);
  c1.SetEnergy(400);
  c2.SetLocationType(I3Particle::InIce);
  c2.SetType(I3Particle::Brems);
  c2.SetEnergy(600);
  c3.SetLocationType(I3Particle::InIce);
  c3.SetType(I3Particle::DeltaE);
  c3.SetEnergy(500);

  I3MCTree t;
  I3MCTreeUtils::AddPrimary(t,p1);
  I3MCTreeUtils::AddPrimary(t,p2);
  I3MCTreeUtils::AppendChild(t,p2,m1);
  I3MCTreeUtils::AppendChild(t,p2,m2);
  I3MCTreeUtils::AppendChild(t,p2,m3);
  I3MCTreeUtils::AppendChild(t,m2,c1);
  I3MCTreeUtils::AppendChild(t,m2,c2);
  I3MCTreeUtils::AppendChild(t,m2,c3);

  I3MCTree::iterator p = I3MCTreeUtils::GetMostEnergeticPrimary(t);
  ENSURE(p->GetEnergy()==700);
  ENSURE(p->GetMinorID()==p2.GetMinorID());

  p = I3MCTreeUtils::GetMostEnergeticInIce(t);
  ENSURE(p->GetEnergy()==600);
  ENSURE(p->GetMinorID()==c2.GetMinorID());

  p = I3MCTreeUtils::GetMostEnergeticTrack(t);
  ENSURE(p->GetEnergy()==300);
  ENSURE(p->GetMinorID()==m2.GetMinorID());

  p = I3MCTreeUtils::GetMostEnergeticCascade(t);
  ENSURE(p->GetEnergy()==600);
  ENSURE(p->GetMinorID()==c2.GetMinorID());

  p = I3MCTreeUtils::GetMostEnergetic(t,I3Particle::MuPlus);
  ENSURE(p->GetEnergy()==100);
  ENSURE(p->GetMinorID()==m1.GetMinorID());

  I3Particle px;
  px.SetType(I3Particle::MuPlus);
  px.SetEnergy(1000);
  I3MCTreeUtils::AppendChild(t,p1,px);
  p = I3MCTreeUtils::GetMostEnergeticInIce(t);
  ENSURE(p->GetEnergy()==600);
  ENSURE(p->GetMinorID()==c2.GetMinorID());

  I3MCTree t2;
  p = I3MCTreeUtils::GetMostEnergeticPrimary(t2);
  ENSURE(p==t2.end());
  p = I3MCTreeUtils::GetMostEnergeticInIce(t2);
  ENSURE(p==t2.end());
  p = I3MCTreeUtils::GetMostEnergeticTrack(t2);
  ENSURE(p==t2.end());
  p = I3MCTreeUtils::GetMostEnergeticCascade(t2);
  ENSURE(p==t2.end());
  p = I3MCTreeUtils::GetMostEnergetic(t2,I3Particle::MuPlus);
  ENSURE(p==t2.end());
}

TEST(add_subtree_to_empty_tree)
{
  I3Particle p;

  I3MCTreePtr st( new I3MCTree ); //subtree
  I3MCTreeUtils::AddPrimary(st,p);
  
  I3MCTreePtr cst( new I3MCTree(*st)); // making a copy
  I3MCTreePtr t( new I3MCTree ); //adding a subtree to an empty tree

  // this should silently fail
  // http://code.icecube.wisc.edu/projects/icecube/ticket/352
  // ...but I can't seem to reproduce it
  I3MCTreeUtils::AddPrimary(*dynamic_pointer_cast<I3MCTree>(t),*cst);
  ENSURE(t->size() == 1);
}
