/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TreeTest.cxx 10872 2005-08-31 16:19:29Z tschmidt $

    @version $Revision: 1.8 $
    @date $Date: 2005-08-31 12:19:29 -0400 (Wed, 31 Aug 2005) $
    @author tschmidt
*/
#include <vector>
#include <I3Test.h>
#include <dataclasses/physics/I3MCTree.h>
#include <dataclasses/physics/I3MCTreeUtils.h>

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
    if(i->GetID() == p1.GetID()) found1 = true;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetID() == p2.GetID()) found2 = true;

  ENSURE(found1 && found2);
}

TEST(add_children_to_primaries)
{
  I3Particle p1;
  I3Particle p2;

  int p1_id = p1.GetID();
  int p2_id = p2.GetID();

  I3MCTree t;
  I3MCTreeUtils::AddPrimary(t,p1);
  I3MCTreeUtils::AddPrimary(t,p2);
  
  std::vector<I3Particle> p_list = I3MCTreeUtils::GetPrimaries(t);
  std::vector<I3Particle>::iterator i;

  bool found1 = false;
  bool found2 = false;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetID() == p1.GetID()) found1 = true;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->GetID() == p2.GetID()) found2 = true;

  ENSURE(found1 && found2);

  I3Particle c1;
  I3Particle c2;
  I3Particle c3;
  I3Particle c4;

  int c1_id = c1.GetID();
  int c2_id = c2.GetID();
  int c3_id = c3.GetID();
  int c4_id = c4.GetID();

  I3MCTreeUtils::AppendChild(t,p1,c1);
  I3MCTreeUtils::AppendChild(t,p1,c2);
  I3MCTreeUtils::AppendChild(t,p2,c3);
  I3MCTreeUtils::AppendChild(t,p2,c4);

  I3Tree<I3Particle>::sibling_iterator si(t.begin());

  ENSURE(si->GetID() == p1_id);

  I3Tree<I3Particle>::sibling_iterator ci(t.begin(si));
  ENSURE(ci->GetID() == c1_id);
  ci++;
  ENSURE(ci->GetID() == c2_id);

  si++;
  ENSURE(si->GetID() == p2_id);
  ci = t.begin(si);
  ENSURE(ci->GetID() == c3_id);
  ci++;
  ENSURE(ci->GetID() == c4_id);

  std::vector<I3Particle>::iterator d_iter;
  std::vector<I3Particle> d_list;

  d_list = I3MCTreeUtils::GetDaughters(t,p1);
  d_iter = d_list.begin();
  ENSURE(d_iter->GetID() == c1.GetID());
  d_iter++;
  ENSURE(d_iter->GetID() == c2.GetID());

  ENSURE(I3MCTreeUtils::HasParent(t,c1));
  const I3Particle& p1_1 = I3MCTreeUtils::GetParent(t,c1);
  ENSURE(I3MCTreeUtils::HasParent(t,c2));
  const I3Particle& p1_2 = I3MCTreeUtils::GetParent(t,c2);
  ENSURE(p1_1.GetID() == p1.GetID());
  ENSURE(p1_2.GetID() == p1.GetID());

  d_list = I3MCTreeUtils::GetDaughters(t,p2);
  d_iter = d_list.begin();
  ENSURE(d_iter->GetID() == c3.GetID());
  d_iter++;
  ENSURE(d_iter->GetID() == c4.GetID());

  ENSURE(I3MCTreeUtils::HasParent(t,c3));
  const I3Particle& p2_3 = I3MCTreeUtils::GetParent(t,c3);
  ENSURE(I3MCTreeUtils::HasParent(t,c4));
  const I3Particle& p2_4 = I3MCTreeUtils::GetParent(t,c4);
  ENSURE(p2_3.GetID() == p2.GetID());
  ENSURE(p2_4.GetID() == p2.GetID());

}

TEST(get_most_energetic)
{
  I3MCTree tree;
  I3MCTreePtr tree_ptr(new I3MCTree(tree));
  I3Particle p1, p2, p3, p4, p5, p6;
  p1.SetEnergy(10); p1.SetLocationType(I3Particle::Anywhere);
  p2.SetEnergy(100); p2.SetLocationType(I3Particle::InIce);
  p3.SetEnergy(20); p3.SetLocationType(I3Particle::InIce);
  p4.SetEnergy(56); p4.SetLocationType(I3Particle::InIce);
  I3MCTreeUtils::AddPrimary(tree_ptr, p1);
  I3MCTreeUtils::AppendChild(tree_ptr, p1, p2);
  I3MCTreeUtils::AppendChild(tree_ptr, p2, p3);
  I3MCTreeUtils::AppendChild(tree_ptr, p2, p3);
  I3MCTreeUtils::AppendChild(tree_ptr, p2, p4);
  ENSURE_DISTANCE(I3MCTreeUtils::GetMostEnergeticInIce(tree_ptr).GetEnergy(),100,0.001);
}
