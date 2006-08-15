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

TEST(mclist_to_mctree){

  I3Particle p;
  I3Particle c1;
  I3Particle c2;
  I3Particle c3;

  I3Particle gc1;
  I3Particle gc2;
  I3Particle gc3;
  I3Particle gc4;
  I3Particle gc5;

  c1.GetComposite().push_back(gc1);
  c1.GetComposite().push_back(gc2);

  c2.GetComposite().push_back(gc3);
  c2.GetComposite().push_back(gc4);
  c2.GetComposite().push_back(gc5);

  p.GetComposite().push_back(c1);
  p.GetComposite().push_back(c2);
  p.GetComposite().push_back(c3);

  I3MCListPtr l(new I3MCList);
  l->push_back(p);

  I3FramePtr frame(new I3Frame(I3Frame::Physics));
  frame->Put("TestI3MCList",l);

  I3MCTreeConstPtr t = I3MCTreeUtils::Get(frame,"TestI3MCList","BLAH");
  ENSURE(t->size() == 9); 

  I3Particle primary = I3MCTreeUtils::GetPrimaries(*t)[0];
  ENSURE(primary.GetID() == p.GetID());
  ENSURE(primary.GetComposite().size()==0);

  vector<I3Particle> d_list = I3MCTreeUtils::GetDaughters(*t,primary);
  ENSURE(d_list.size() == 3);
  I3Particle d1 = d_list[0];
  I3Particle d2 = d_list[1];
  I3Particle d3 = d_list[2];

  ENSURE(d1.GetComposite().size()==0);
  ENSURE(d2.GetComposite().size()==0);
  ENSURE(d3.GetComposite().size()==0);

  ENSURE(((d1.GetID() == c1.GetID()) && (d2.GetID() == c2.GetID()) && (d3.GetID() == c3.GetID())) ||
	 ((d1.GetID() == c2.GetID()) && (d2.GetID() == c1.GetID()) && (d3.GetID() == c3.GetID())) ||
	 ((d1.GetID() == c2.GetID()) && (d2.GetID() == c3.GetID()) && (d3.GetID() == c1.GetID())) ||
	 ((d1.GetID() == c3.GetID()) && (d2.GetID() == c2.GetID()) && (d3.GetID() == c1.GetID())) ||
	 ((d1.GetID() == c3.GetID()) && (d2.GetID() == c1.GetID()) && (d3.GetID() == c2.GetID())) ||
	 ((d1.GetID() == c1.GetID()) && (d2.GetID() == c3.GetID()) && (d3.GetID() == c2.GetID())));

  vector<I3Particle> gd_1_list = I3MCTreeUtils::GetDaughters(*t,d1);
  vector<I3Particle> gd_2_list = I3MCTreeUtils::GetDaughters(*t,d2);
  vector<I3Particle> gd_3_list = I3MCTreeUtils::GetDaughters(*t,d3);

  ENSURE(((gd_1_list.size() == 0) && (gd_2_list.size() == 2) && (gd_3_list.size() == 3)) ||
	 ((gd_1_list.size() == 2) && (gd_2_list.size() == 0) && (gd_3_list.size() == 3)) ||
	 ((gd_1_list.size() == 2) && (gd_2_list.size() == 3) && (gd_3_list.size() == 0)) ||
	 ((gd_1_list.size() == 3) && (gd_2_list.size() == 2) && (gd_3_list.size() == 0)) ||
	 ((gd_1_list.size() == 3) && (gd_2_list.size() == 0) && (gd_3_list.size() == 2)) ||
	 ((gd_1_list.size() == 0) && (gd_2_list.size() == 3) && (gd_3_list.size() == 2)));

  if(gd_1_list.size()){
    if(gd_1_list.size() == 2){
      ENSURE(((gd_1_list[0].GetID() == gc1.GetID()) && (gd_1_list[1].GetID() == gc2.GetID()))||
	     ((gd_1_list[0].GetID() == gc2.GetID()) && (gd_1_list[1].GetID() == gc1.GetID())));
    }else{
      ENSURE(((gd_1_list[0].GetID() == gc4.GetID()) && (gd_1_list[1].GetID() == gc5.GetID()) && (gd_1_list[2].GetID() == gc3.GetID())) ||
	     ((gd_1_list[0].GetID() == gc4.GetID()) && (gd_1_list[1].GetID() == gc3.GetID()) && (gd_1_list[2].GetID() == gc5.GetID())) ||
	     ((gd_1_list[0].GetID() == gc3.GetID()) && (gd_1_list[1].GetID() == gc4.GetID()) && (gd_1_list[2].GetID() == gc5.GetID())) ||
	     ((gd_1_list[0].GetID() == gc3.GetID()) && (gd_1_list[1].GetID() == gc5.GetID()) && (gd_1_list[2].GetID() == gc4.GetID())) ||
	     ((gd_1_list[0].GetID() == gc5.GetID()) && (gd_1_list[1].GetID() == gc3.GetID()) && (gd_1_list[2].GetID() == gc4.GetID())) ||
	     ((gd_1_list[0].GetID() == gc5.GetID()) && (gd_1_list[1].GetID() == gc4.GetID()) && (gd_1_list[2].GetID() == gc3.GetID())));
    }
  }
  if(gd_2_list.size()){
    if(gd_2_list.size() == 2){
      ENSURE(((gd_2_list[0].GetID() == gc1.GetID()) && (gd_2_list[1].GetID() == gc2.GetID()))||
	     ((gd_2_list[0].GetID() == gc2.GetID()) && (gd_2_list[1].GetID() == gc1.GetID())));
    }else{
      ENSURE(((gd_2_list[0].GetID() == gc4.GetID()) && (gd_2_list[1].GetID() == gc5.GetID()) && (gd_2_list[2].GetID() == gc3.GetID())) ||
	     ((gd_2_list[0].GetID() == gc4.GetID()) && (gd_2_list[1].GetID() == gc3.GetID()) && (gd_2_list[2].GetID() == gc5.GetID())) ||
	     ((gd_2_list[0].GetID() == gc3.GetID()) && (gd_2_list[1].GetID() == gc4.GetID()) && (gd_2_list[2].GetID() == gc5.GetID())) ||
	     ((gd_2_list[0].GetID() == gc3.GetID()) && (gd_2_list[1].GetID() == gc5.GetID()) && (gd_2_list[2].GetID() == gc4.GetID())) ||
	     ((gd_2_list[0].GetID() == gc5.GetID()) && (gd_2_list[1].GetID() == gc3.GetID()) && (gd_2_list[2].GetID() == gc4.GetID())) ||
	     ((gd_2_list[0].GetID() == gc5.GetID()) && (gd_2_list[1].GetID() == gc4.GetID()) && (gd_2_list[2].GetID() == gc3.GetID())));
    }
  }
  if(gd_3_list.size()){
    if(gd_3_list.size() == 2){
      ENSURE(((gd_3_list[0].GetID() == gc1.GetID()) && (gd_3_list[1].GetID() == gc2.GetID()))||
	     ((gd_3_list[0].GetID() == gc2.GetID()) && (gd_3_list[1].GetID() == gc1.GetID())));
    }else{
      ENSURE(((gd_3_list[0].GetID() == gc4.GetID()) && (gd_3_list[1].GetID() == gc5.GetID()) && (gd_3_list[2].GetID() == gc3.GetID())) ||
	     ((gd_3_list[0].GetID() == gc4.GetID()) && (gd_3_list[1].GetID() == gc3.GetID()) && (gd_3_list[2].GetID() == gc5.GetID())) ||
	     ((gd_3_list[0].GetID() == gc3.GetID()) && (gd_3_list[1].GetID() == gc4.GetID()) && (gd_3_list[2].GetID() == gc5.GetID())) ||
	     ((gd_3_list[0].GetID() == gc3.GetID()) && (gd_3_list[1].GetID() == gc5.GetID()) && (gd_3_list[2].GetID() == gc4.GetID())) ||
	     ((gd_3_list[0].GetID() == gc5.GetID()) && (gd_3_list[1].GetID() == gc3.GetID()) && (gd_3_list[2].GetID() == gc4.GetID())) ||
	     ((gd_3_list[0].GetID() == gc5.GetID()) && (gd_3_list[1].GetID() == gc4.GetID()) && (gd_3_list[2].GetID() == gc3.GetID())));
    }
  }
}

TEST(get_mctree_from_frame){

  I3Particle p;
  I3Particle c1;
  I3Particle c2;
  I3Particle c3;

  I3Particle gc1;
  I3Particle gc2;
  I3Particle gc3;
  I3Particle gc4;
  I3Particle gc5;

  c1.GetComposite().push_back(gc1);
  c1.GetComposite().push_back(gc2);

  c2.GetComposite().push_back(gc3);
  c2.GetComposite().push_back(gc4);
  c2.GetComposite().push_back(gc5);

  p.GetComposite().push_back(c1);
  p.GetComposite().push_back(c2);
  p.GetComposite().push_back(c3);

  I3MCListPtr l(new I3MCList);
  l->push_back(p);

  I3FramePtr frame(new I3Frame(I3Frame::Physics));
  frame->Put("TestI3MCList",l);

  I3MCTreeConstPtr t = I3MCTreeUtils::Get(frame,"TestI3MCList","BLAH");
  ENSURE(t->size() == 9); 

  I3MCTreeConstPtr t2 = I3MCTreeUtils::Get(frame,"BLAH","TestI3MCList");
  ENSURE(t2->size() == 9); 

  frame->Put(t);
  I3MCTreeConstPtr t3 = I3MCTreeUtils::Get(frame,"I3MCTree","BLAH");
  I3MCTreeConstPtr t4 = I3MCTreeUtils::Get(frame,"BLAH","I3MCTree");
  I3MCTreeConstPtr t5 = I3MCTreeUtils::Get(frame,"I3MCTree");
  I3MCTreeConstPtr t6 = I3MCTreeUtils::Get(frame,"TestI3MCList");


  ENSURE(t3->size() == 9); 
  ENSURE(t4->size() == 9); 
  ENSURE(t5->size() == 9); 
  ENSURE(t6->size() == 9); 
}
