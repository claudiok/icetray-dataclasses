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
#include <dataclasses/I3IDService.h>

using namespace std;

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3MCTreeTest);

TEST(add_and_get_primaries)
{
  shared_ptr<I3IDService> id_service(new I3IDService);

  I3Particle p1;
  I3Particle p2;

  p1.SetID(id_service);
  p2.SetID(id_service);
  //should have unique IDs now

  I3MCTree t;
  I3MCTreeUtils::add_primary(t,p1);
  I3MCTreeUtils::add_primary(t,p2);
  
  std::vector<I3Particle> p_list = I3MCTreeUtils::get_primaries(t);
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
  shared_ptr<I3IDService> id_service(new I3IDService);

  I3Particle p1;
  I3Particle p2;

  p1.SetID(id_service);//0
  p2.SetID(id_service);//1
  //should have unique IDs now

  I3MCTree t;
  I3MCTreeUtils::add_primary(t,p1);
  I3MCTreeUtils::add_primary(t,p2);
  
  std::vector<I3Particle> p_list = I3MCTreeUtils::get_primaries(t);
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

  c1.SetID(id_service);//2
  c2.SetID(id_service);//3
  c3.SetID(id_service);//4
  c4.SetID(id_service);//5

  I3MCTreeUtils::append_child(t,p1,c1);
  I3MCTreeUtils::append_child(t,p1,c2);
  I3MCTreeUtils::append_child(t,p2,c3);
  I3MCTreeUtils::append_child(t,p2,c4);

  I3Tree<I3Particle>::sibling_iterator si(t.begin());

  ENSURE(si->GetID() == 0);

  I3Tree<I3Particle>::sibling_iterator ci(t.begin(si));
  ENSURE(ci->GetID() == 2);
  ci++;
  ENSURE(ci->GetID() == 3);

  si++;
  ENSURE(si->GetID() == 1);
  ci = t.begin(si);
  ENSURE(ci->GetID() == 4);
  ci++;
  ENSURE(ci->GetID() == 5);

}
