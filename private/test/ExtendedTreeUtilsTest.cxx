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
#include <dataclasses/physics/I3MCExtendedTree.h>
#include <dataclasses/physics/I3MCTreeUtils.h>
#include <dataclasses/I3IDService.h>

using namespace std;

class I3Pinkness{
public:
  double GetPinkness(){ return pinkness_; };
  void SetPinkness(double p){ pinkness_ = p; };
private:
  double pinkness_;
  template <class Archive> void serialize(Archive & ar, unsigned version){
    ar & make_nvp("Pinkness", pinkness_ );}
};

typedef I3MCParticle<I3Pinkness> I3PinkParticle;


// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3MCExtendedTreeTest);

TEST(add_and_get_primaries)
{
  shared_ptr<I3IDService> id_service(new I3IDService);

  I3PinkParticle p1;
  I3PinkParticle p2;

  p1.particle.SetID(id_service);
  p2.particle.SetID(id_service);
  //should have unique IDs now

  //I3MCExtendedTree<I3Pinkness> t;
  I3Tree<I3MCParticle<I3Pinkness> > t;
  I3MCTreeUtils::add_primary<I3Pinkness>(t,p1);
  I3MCTreeUtils::add_primary<I3Pinkness>(t,p2);
  
  std::vector<I3PinkParticle> p_list;
  p_list = I3MCTreeUtils::get_primaries<I3Pinkness>(t);
  std::vector<I3PinkParticle>::iterator i;

  bool found1 = false;
  bool found2 = false;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->particle.GetID() == p1.particle.GetID()) found1 = true;

  for(i = p_list.begin(); i!= p_list.end(); ++i)
    if(i->particle.GetID() == p2.particle.GetID()) found2 = true;

  ENSURE(found1 && found2);
}

TEST(add_children_to_primaries)
{
  shared_ptr<I3IDService> id_service(new I3IDService);

  I3PinkParticle p1;
  I3PinkParticle p2;

  p1.particle.SetID(id_service);
  p2.particle.SetID(id_service);
  //should have unique IDs now

  //I3MCExtendedTree<I3Pinkness> t;
  I3Tree<I3MCParticle<I3Pinkness> > t;
  I3MCTreeUtils::add_primary<I3Pinkness>(t,p1);
  I3MCTreeUtils::add_primary<I3Pinkness>(t,p2);

  I3PinkParticle c1;
  I3PinkParticle c2;
  I3PinkParticle c3;
  I3PinkParticle c4;

  c1.particle.SetID(id_service);//2
  c2.particle.SetID(id_service);//3
  c3.particle.SetID(id_service);//4
  c4.particle.SetID(id_service);//5

  I3MCTreeUtils::append_child<I3Pinkness>(t,p1,c1);
  I3MCTreeUtils::append_child<I3Pinkness>(t,p1,c2);
  I3MCTreeUtils::append_child<I3Pinkness>(t,p2,c3);
  I3MCTreeUtils::append_child<I3Pinkness>(t,p2,c4);

  I3Tree<I3PinkParticle>::sibling_iterator si(t.begin());

  ENSURE(si->particle.GetID() == 0);

  I3Tree<I3PinkParticle>::sibling_iterator ci(t.begin(si));
  ENSURE(ci->particle.GetID() == 2);
  ci++;
  ENSURE(ci->particle.GetID() == 3);

  si++;
  ENSURE(si->particle.GetID() == 1);
  ci = t.begin(si);
  ENSURE(ci->particle.GetID() == 4);
  ci++;
  ENSURE(ci->particle.GetID() == 5);

}
