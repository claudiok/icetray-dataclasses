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
  I3Particle p1; p1.SetID(1);
  I3Particle p2; p1.SetID(2);

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

  I3Particle c1; c1.SetID(3);
  I3Particle c2; c2.SetID(4);
  I3Particle c3; c3.SetID(5);
  I3Particle c4; c4.SetID(6);

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

TEST(convert_composite){
  I3MCTree t;

  I3Particle p1; p1.SetID(1);//primary

  I3Particle c1; c1.SetID(2);//child
  I3Particle c2; c2.SetID(3);//child

  p1.GetComposite().push_back(c1);
  p1.GetComposite().push_back(c2);

  I3Particle dummy(p1);
  dummy.GetComposite().clear();

  I3Tree<I3Particle>::iterator si;
  si = t.end(t.begin());
  I3Tree<I3Particle>::iterator p_iter = t.insert(si,dummy);

  I3MCTreeUtils::ConvertComposite(t,p_iter,p1.GetComposite());

  ENSURE(static_cast<int>(t.size())==3);

}

TEST(list_to_tree){

  I3MCListPtr l(new I3MCList);

  I3Particle p1; p1.SetID(1);//primary
  I3Particle p2; p2.SetID(2);//primary
  I3Particle p3; p3.SetID(3);//primary

  I3Particle c1; c1.SetID(4);//child
  I3Particle c2; c2.SetID(5);//child

  I3Particle gc1; gc1.SetID(6);//grandchild
  I3Particle gc2; gc2.SetID(7);//grandchild
  I3Particle gc3; gc2.SetID(8);//grandchild

  c2.GetComposite().push_back(gc1);
  c2.GetComposite().push_back(gc2);
  c2.GetComposite().push_back(gc3);

  p2.GetComposite().push_back(c1);
  p2.GetComposite().push_back(c2);

  l->push_back(p1);
  l->push_back(p2);
  l->push_back(p3);

  I3MCTreePtr tree = I3MCTreeUtils::ListToTree(*l);

  ENSURE(tree);
  ENSURE(static_cast<int>(tree->size())==8);

  vector<I3Particle> pl = I3MCTreeUtils::GetPrimaries(tree);
  ENSURE(static_cast<int>(pl.size()) == 3);
  ENSURE(((pl[0].GetID() == p1.GetID())&&(pl[1].GetID() == p2.GetID())&&(pl[2].GetID() == p3.GetID())) ||
	 ((pl[1].GetID() == p1.GetID())&&(pl[0].GetID() == p2.GetID())&&(pl[2].GetID() == p3.GetID())) ||
	 ((pl[1].GetID() == p1.GetID())&&(pl[2].GetID() == p2.GetID())&&(pl[0].GetID() == p3.GetID())) ||
	 ((pl[2].GetID() == p1.GetID())&&(pl[1].GetID() == p2.GetID())&&(pl[0].GetID() == p3.GetID())) ||
	 ((pl[2].GetID() == p1.GetID())&&(pl[0].GetID() == p2.GetID())&&(pl[1].GetID() == p3.GetID())) ||
	 ((pl[0].GetID() == p1.GetID())&&(pl[2].GetID() == p2.GetID())&&(pl[1].GetID() == p3.GetID())));

  vector<I3Particle> dl = I3MCTreeUtils::GetDaughters(tree,p2);

  ENSURE(static_cast<int>(dl.size())==2);
  ENSURE(((dl[0].GetID() == c1.GetID())&&(dl[1].GetID() == c2.GetID())) ||
	 ((dl[1].GetID() == c1.GetID())&&(dl[0].GetID() == c2.GetID())));

  vector<I3Particle> gdl = I3MCTreeUtils::GetDaughters(tree,c2);
  ENSURE(static_cast<int>(gdl.size())==3);
  vector<I3Particle>::iterator gdi = gdl.begin();
  ENSURE(((gdl[0].GetID() == gc1.GetID())&&(gdl[1].GetID() == gc2.GetID())&&(gdl[2].GetID() == gc3.GetID())) ||
	 ((gdl[1].GetID() == gc1.GetID())&&(gdl[0].GetID() == gc2.GetID())&&(gdl[2].GetID() == gc3.GetID())) ||
	 ((gdl[1].GetID() == gc1.GetID())&&(gdl[2].GetID() == gc2.GetID())&&(gdl[0].GetID() == gc3.GetID())) ||
	 ((gdl[2].GetID() == gc1.GetID())&&(gdl[1].GetID() == gc2.GetID())&&(gdl[0].GetID() == gc3.GetID())) ||
	 ((gdl[2].GetID() == gc1.GetID())&&(gdl[0].GetID() == gc2.GetID())&&(gdl[1].GetID() == gc3.GetID())) ||
	 ((gdl[0].GetID() == gc1.GetID())&&(gdl[2].GetID() == gc2.GetID())&&(gdl[1].GetID() == gc3.GetID())));

}
