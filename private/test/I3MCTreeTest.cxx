/**
 * @file I3MCTreeTest.cxx
 * @brief
 * 
 * copyright (C) 2013 the icecube collaboration
 * 
 * $Id$
 * @version $Revision$
 * @date $Date$
 */
#include <vector>
#include <algorithm>
#include <I3Test.h>
#include <dataclasses/physics/I3MCTree.h>
//#include <dataclasses/physics/I3MCTreeUtils.h>
#include <icetray/I3Frame.h>
#include <sstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>


using namespace std;

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3MCTreeTest);

I3Particle makeParticle()
{
  I3Particle p;
  p.SetTime(0.0);
  p.SetLength(0.0);
  p.SetEnergy(0.0);
  p.SetPos(0.0,0.0,0.0);
  p.SetDir(0.0,0.0);
  return p;
}


// Run all the TreeBase::Tree tests

TEST(constructors)
{
  I3MCTree t;
  I3MCTree tt;
  ENSURE( t == tt , "empty trees are not equal");
  
  I3MCTree t1;
  I3Particle p1 = makeParticle();
  t1.insert(p1);
  
  ENSURE( t1.begin() != t1.end() , "Tree t1 is empty");
  ENSURE( t1.get_head() , "Tree is empty");
  
  ENSURE( t1.get_head() == p1 , "Particle does not match");
  
  I3MCTree t2(p1);
  ENSURE( t2.get_head() == p1 , "Particle2 does not match");
  ENSURE( t2.begin() != t2.end() , "Tree t2 is empty");
  ENSURE( t1 == t2 , "Particle constructor failed");
  
  I3MCTree t3 = t1;
  ENSURE( t3.begin() != t3.end() , "Tree t3 is empty");
  ENSURE( t1 == t3 , "assignment operator failed");
  
  I3MCTree t4(makeParticle());
  ENSURE( t4.begin() != t4.end() , "Tree t4 is empty");
  ENSURE( t1 != t4 , "!= operator failed");
}

TEST(pre_order_iterator)
{
  I3MCTree t1;
  ENSURE( t1.begin() == t1.end() );
  I3MCTree t2(makeParticle());
  I3MCTree::iterator iter(t2);
  ENSURE( iter != t2.end() , "begin() == end()");
  ENSURE( t2.get_head() == *iter , "begin() != head");
  iter++;
  ENSURE( iter == t2.end() , "iter does not reach end()");
  I3Particle head = makeParticle();
  I3MCTree t3(head);
  I3Particle p1 = makeParticle();
  t3.append_child(head,p1);
  I3Particle p2 = makeParticle();
  t3.append_child(head,p2);
  I3Particle p3 = makeParticle();
  t3.append_child(p1,p3);
  I3Particle p4 = makeParticle();
  t3.append_child(p2,p4);
  iter = t3.begin();
  ENSURE( iter != t3.end() , "hit end instead of head" );
  ENSURE( *iter == head );
  iter++;
  ENSURE( iter != t3.end() , "hit end instead of p1" );
  ENSURE( *iter == p1);
  iter++;
  ENSURE( iter != t3.end() , "hit end instead of p3" );
  ENSURE( *iter == p3);
  iter++;
  ENSURE( iter != t3.end() , "hit end instead of p2" );
  ENSURE( *iter == p2);
  iter++;
  ENSURE( iter != t3.end() , "hit end instead of p4" );
  ENSURE( *iter == p4);
  iter++;
  ENSURE( iter == t3.end() );
}

TEST(post_order_iterator)
{
  I3MCTree t1;
  ENSURE( t1.begin_post() == t1.end_post() );
  I3MCTree t2(makeParticle());
  I3MCTree::post_order_iterator iter(t2);
  ENSURE( iter != t2.end_post() , "begin() == end()");
  ENSURE( t2.get_head() == *iter , "begin() != head");
  iter++;
  ENSURE( iter == t2.end_post() , "iter does not reach end()");
  I3Particle head = makeParticle();
  I3MCTree t3(head);
  I3Particle p1 = makeParticle();
  t3.append_child(head,p1);
  I3Particle p2 = makeParticle();
  t3.append_child(head,p2);
  I3Particle p3 = makeParticle();
  t3.append_child(p1,p3);
  I3Particle p4 = makeParticle();
  t3.append_child(p2,p4);
  iter = t3.begin_post();
  ENSURE( iter != t3.end_post() , "hit end instead of p3" );
  ENSURE( *iter == p3);
  iter++;
  ENSURE( iter != t3.end_post() , "hit end instead of p1" );
  ENSURE( *iter == p1);
  iter++;
  ENSURE( iter != t3.end_post() , "hit end instead of p4" );
  ENSURE( *iter == p4);
  iter++;
  ENSURE( iter != t3.end_post() , "hit end instead of p2" );
  ENSURE( *iter == p2);
  iter++;
  ENSURE( iter != t3.end_post() , "hit end instead of head" );
  ENSURE( *iter == head );
  iter++;
  ENSURE( iter == t3.end_post() );
}

TEST(sibling_iterator)
{
  I3MCTree t1;
  ENSURE( t1.begin_post() == t1.end_post() );
  I3MCTree t2(makeParticle());
  I3MCTree::sibling_iterator iter(t2);
  ENSURE( iter != t2.end_sibling() , "begin() == end()");
  ENSURE( t2.get_head() == *iter , "begin() != head");
  iter++;
  ENSURE( iter == t2.end_sibling() , "iter does not reach end()");
  I3Particle head = makeParticle();
  I3MCTree t3(head);
  I3Particle p1 = makeParticle();
  t3.append_child(head,p1);
  I3Particle p2 = makeParticle();
  t3.append_child(head,p2);
  I3Particle p3 = makeParticle();
  t3.append_child(p1,p3);
  I3Particle p4 = makeParticle();
  t3.append_child(p2,p4);
  iter = t3.begin_sibling(head);
  ENSURE( iter != t3.end_sibling() , "hit end instead of head" );
  ENSURE( *iter == head );
  iter++;
  ENSURE( iter == t3.end_sibling() );
  iter = t3.begin_sibling(p1);
  ENSURE( iter != t3.end_sibling() , "hit end instead of p1" );
  ENSURE( *iter == p1);
  iter++;
  ENSURE( iter != t3.end_sibling() , "hit end instead of p2" );
  ENSURE( *iter == p2);
  iter++;
  ENSURE( iter == t3.end_sibling() );
  iter = t3.begin_sibling(p2);
  ENSURE( iter != t3.end_sibling() , "hit end instead of p2" );
  ENSURE( *iter == p2);
  iter++;
  ENSURE( iter == t3.end_sibling() );
  iter = t3.begin_sibling(p3);
  ENSURE( iter != t3.end_sibling() , "hit end instead of p3" );
  ENSURE( *iter == p3);
  iter++;
  ENSURE( iter == t3.end_sibling() );
  iter = t3.begin_sibling(p4);
  ENSURE( iter != t3.end_sibling() , "hit end instead of p4" );
  ENSURE( *iter == p4);
  iter++;
  ENSURE( iter == t3.end_sibling() );
}

TEST(fast_iterator)
{
  I3MCTree t1;
  ENSURE( t1.begin_fast() == t1.end_fast() );
  I3MCTree t2(makeParticle());
  I3MCTree::fast_iterator iter(t2);
  ENSURE( iter != t2.end_fast() , "begin() == end()");
  ENSURE( t2.get_head() == *iter , "begin() != head");
  iter++;
  ENSURE( iter == t2.end_fast() , "iter does not reach end()");
  I3Particle head = makeParticle();
  I3MCTree t3(head);
  I3Particle p1 = makeParticle();
  t3.append_child(head,p1);
  I3Particle p2 = makeParticle();
  t3.append_child(head,p2);
  I3Particle p3 = makeParticle();
  t3.append_child(p1,p3);
  I3Particle p4 = makeParticle();
  t3.append_child(p2,p4);
  iter = t3.begin_fast();
  std::vector<I3Particle> nodes;
  for (;iter != t3.end_fast();iter++)
    nodes.push_back(*iter);
  ENSURE( !nodes.empty() , "nodes is empty" );
  ENSURE( std::find(nodes.begin(),nodes.end(),head) != nodes.end() , "head not found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p1) != nodes.end() , "p1 not found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p2) != nodes.end() , "p2 not found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p3) != nodes.end() , "p3 not found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p4) != nodes.end() , "p4 not found");
  ENSURE( nodes.size() == t3.size() , "nodes.size() incorrect" );
}

TEST(leaf_iterator)
{
  I3MCTree t1;
  ENSURE( t1.begin_leaf() == t1.end_leaf() );
  I3MCTree t2(makeParticle());
  I3MCTree::leaf_iterator iter(t2);
  ENSURE( iter != t2.end_leaf() , "begin() == end()");
  ENSURE( t2.get_head() == *iter , "begin() != head");
  iter++;
  ENSURE( iter == t2.end_leaf() , "iter does not reach end()");
  I3Particle head = makeParticle();
  I3MCTree t3(head);
  I3Particle p1 = makeParticle();
  t3.append_child(head,p1);
  I3Particle p2 = makeParticle();
  t3.append_child(head,p2);
  I3Particle p3 = makeParticle();
  t3.append_child(p1,p3);
  I3Particle p4 = makeParticle();
  t3.append_child(p1,p4);
  iter = t3.begin_leaf();
  std::vector<I3Particle> nodes;
  for (;iter != t3.end_leaf();iter++)
    nodes.push_back(*iter);
  ENSURE( !nodes.empty() , "nodes is empty" );
  ENSURE( std::find(nodes.begin(),nodes.end(),head) == nodes.end() , "head found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p1) == nodes.end() , "p1 found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p2) != nodes.end() , "p2 not found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p3) != nodes.end() , "p3 not found");
  ENSURE( std::find(nodes.begin(),nodes.end(),p4) != nodes.end() , "p4 not found");
  ENSURE( nodes.size() == 3 , "nodes.size() incorrect" );
}

TEST(empty)
{
  I3MCTree t1;
  ENSURE( t1.empty() , "tree is not empty");
  
  I3MCTree t2(makeParticle());
  ENSURE( !t2.empty() , "tree is empty");
}

TEST(clear)
{
  I3MCTree t1(makeParticle());
  ENSURE( !t1.empty() , "tree is empty");
  
  t1.clear();
  ENSURE( t1.empty() , "tree did not clear");
}

TEST(append_child)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  
  ENSURE( t1.get_head() , "can't get head node");
  
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  
  std::vector<I3Particle> children = t1.children(p1);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.front() == p2 , "child not there");
  
  I3Particle p3 = makeParticle();
  t1.append_child(p1,p3);
  
  std::vector<I3Particle> children2 = t1.children(p1);
  ENSURE( !children2.empty() , "no children2");
  ENSURE( children2.front() == p2 , "p2 is not first child");
  ENSURE( children2.at(1) == p3 , "p3 is not second child");
  
  I3MCTree t2(makeParticle());
  t2.append_child(*t2.get_head(),t1,p1);
  
  std::vector<I3Particle> children3 = t2.children(*t2.get_head());
  ENSURE( !children3.empty() , "no children3");
  ENSURE( children3.front() == p1 , "p1 is not first child of t2");
  ENSURE( children3.size() == 1 , "children3.size != 1");
  
  std::vector<I3Particle> children4 = t2.children(p1);
  ENSURE( !children4.empty() , "no children4");
  ENSURE( children4.front() == p2 , "p2 is not first child of t2.p1");
  ENSURE( children4.at(1) == p3 , "p3 is not second child of t2.p1");
  
  I3MCTree t3(makeParticle());
  I3Particle p4 = *t3.get_head();
  std::vector<I3Particle> newchildren;
  for (int i=0;i<50;i++) {
    newchildren.push_back(makeParticle());
  }
  t3.append_children(p4,newchildren);
  std::vector<I3Particle> children5 = t3.children(p4);
  ENSURE( !children5.empty() , "no children5");
  ENSURE( children5 == newchildren , "added children incorrect");
}

TEST(erase)
{
  I3MCTree t1(makeParticle());
  I3Particle head = t1.get_head();
  I3Particle p1 = makeParticle();
  t1.append_child(head,p1);
  I3Particle p2 = makeParticle();
  t1.append_child(head,p2);
  I3Particle p3 = makeParticle();
  t1.append_child(head,p3);
  ENSURE( !t1.empty() , "tree is empty");
  
  t1.erase(p3);
  ENSURE( !t1.at(p3) , "child was not erased");
  ENSURE( !t1.empty() , "tree is empty after erasing child");
  
  t1.erase(head);
  ENSURE( !t1.at(head) , "head was not erased");
  ENSURE( !t1.at(p1) , "p1 was not erased");
  ENSURE( !t1.at(p2) , "p2 was not erased");
  ENSURE( t1.empty() , "tree did not clear");
}

TEST(erase_children)
{
  I3MCTree t1(makeParticle());
  t1.append_child(*t1.get_head(),makeParticle());
  t1.append_child(*t1.get_head(),makeParticle());
  t1.append_child(*t1.get_head(),makeParticle());
  ENSURE( !t1.empty() , "tree is empty");
  
  t1.erase_children(*t1.get_head());
  ENSURE( !t1.empty() , "tree is empty after erase_children");
  
  std::vector<I3Particle> children = t1.children(*t1.get_head());
  ENSURE( children.empty() , "did not delete all children");
}

TEST(manual_traversal)
{
  I3MCTree t1(makeParticle());
  t1.append_child(*t1.get_head(),makeParticle());
  t1.append_child(*t1.get_head(),makeParticle());
  t1.append_child(*t1.get_head(),makeParticle());
  ENSURE( !t1.empty() , "tree is empty");
  
  ENSURE( t1.get_head() , "tree does not have a head");
  I3Particle head = t1.get_head();
  ENSURE( t1.at(head) , "at(head) failed");
  ENSURE( *t1.at(head) == head , "at(head) != head");
  
  std::vector<I3Particle> children = t1.children(head);
  ENSURE( !children.empty() , "no children of head");
  ENSURE( children.size() == 3 , "there are not three children");
  ENSURE( head == *t1.parent(children.at(0)) , "children.at(0) parent != head");
  ENSURE( head == *t1.parent(children.at(1)) , "children.at(1) parent != head");
  ENSURE( head == *t1.parent(children.at(2)) , "children.at(2) parent != head");
  I3Particle child1 = children.front();
  
  ENSURE( t1.at(child1) , "at(child1) failed");
  ENSURE( t1.parent(child1) , "child1 does not have a parent");
  ENSURE( head == *t1.parent(child1) , "child1 parent != head");
  
  ENSURE( t1.next_sibling(child1) , "child1 does not have a next_sibling");
  I3Particle child2 = t1.next_sibling(child1);
  ENSURE( child2 == children.at(1) , "child2 is not the second child");
  
  ENSURE( t1.previous_sibling(child2) , "child2 does not have a previous_sibling");
  I3Particle prev_sib = t1.previous_sibling(child2);
  ENSURE( t1.at(prev_sib) , "previous_sibling not in tree");
  ENSURE( prev_sib == children.at(0) , "prev_sibling is not the first child");
  ENSURE( !( prev_sib == children.at(1) ), "prev_sibling = children.at(1)");
  ENSURE( !( prev_sib == children.at(2) ), "prev_sibling = children.at(2)");
  ENSURE( child1 == prev_sib , "siblings do not match");
  
  ENSURE( t1.parent(child2) , "child2 does not have a parent");
  ENSURE( head == *t1.parent(child2) , "child2 parent != head");
}

TEST(insert)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  
  ENSURE( t1.get_head() , "can't get head node");
  
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  
  std::vector<I3Particle> children = t1.children(p1);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.front() == p2 , "child not there");
  
  I3Particle p3 = makeParticle();
  t1.insert(p2,p3);
  
  std::vector<I3Particle> children2 = t1.children(p1);
  ENSURE( !children2.empty() , "no children2");
  ENSURE( children2.front() == p3 , "p3 is not first child");
  ENSURE( children2.at(1) == p2 , "p2 is not second child");
  
  I3Particle p4 = makeParticle();
  t1.insert(p2,p4);
  
  std::vector<I3Particle> children3 = t1.children(p1);
  ENSURE( !children3.empty() , "no children3");
  ENSURE( children3.front() == p3 , "p3 is not first child");
  ENSURE( children3.at(1) == p4 , "p4 is not second child");
  ENSURE( children3.at(2) == p2 , "p2 is not third child");
}

TEST(insert_after)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  
  ENSURE( t1.get_head() , "can't get head node");
  
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  
  std::vector<I3Particle> children = t1.children(p1);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.front() == p2 , "child not there");
  
  I3Particle p3 = makeParticle();
  t1.insert_after(p2,p3);
  
  std::vector<I3Particle> children2 = t1.children(p1);
  ENSURE( !children2.empty() , "no children2");
  ENSURE( children2.front() == p2 , "p2 is not first child");
  ENSURE( children2.at(1) == p3 , "p3 is not second child");
  
  I3Particle p4 = makeParticle();
  t1.insert_after(p2,p4);
  
  std::vector<I3Particle> children3 = t1.children(p1);
  ENSURE( !children3.empty() , "no children3");
  ENSURE( children3.front() == p2 , "p2 is not first child");
  ENSURE( children3.at(1) == p4 , "p4 is not second child");
  ENSURE( children3.at(2) == p3 , "p3 is not third child");
}

TEST(insert_subtree)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  t1.append_child(p1,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p1,p3);
  t1.append_child(p1,makeParticle());
  
  I3Particle head = makeParticle();
  I3MCTree t2(head);
  I3Particle firstChild = makeParticle();
  t2.append_child(head,firstChild);
  
  t2.insert_subtree(firstChild,t1,p3);
  
  std::vector<I3Particle> children = t2.children(head);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.front() == p3 , "p3 not there");
  ENSURE( children.back() == firstChild , "firstChild not there");
  
  I3Particle head2 = makeParticle();
  I3MCTree t3(head2);
  t3.append_child(head2,makeParticle());
  t3.append_child(head2,makeParticle());
  t3.append_child(head2,makeParticle());
  
  t2.insert_subtree(firstChild,t3,head2);
  
  std::vector<I3Particle> children2 = t2.children(head);
  ENSURE( !children2.empty() , "no children2");
  ENSURE( children2.front() == p3 , "p3 is not first child");
  ENSURE( children2.at(1) == head2 , "head2 is not second child");
  ENSURE( children2.at(2) == firstChild , "firstChild is not third child");
  
  std::vector<I3Particle> children3 = t2.children(children2.at(1));
  ENSURE( !children3.empty() , "no children3");
  ENSURE( children3.size() == 3 , "children3.size != 3");
}

TEST(insert_subtree_after)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  t1.append_child(p1,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p1,p3);
  t1.append_child(p1,makeParticle());
  
  I3Particle head = makeParticle();
  I3MCTree t2(head);
  I3Particle firstChild = makeParticle();
  t2.append_child(head,firstChild);
  
  t2.insert_subtree_after(firstChild,t1,p3);
  
  std::vector<I3Particle> children = t2.children(head);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.back() == p3 , "firstChild not there");
  ENSURE( children.front() == firstChild , "p3 not there");
  
  I3Particle head2 = makeParticle();
  I3MCTree t3(head2);
  t3.append_child(head2,makeParticle());
  t3.append_child(head2,makeParticle());
  t3.append_child(head2,makeParticle());
  
  t2.insert_subtree_after(firstChild,t3,head2);
  
  std::vector<I3Particle> children2 = t2.children(head);
  ENSURE( !children2.empty() , "no children2");
  ENSURE( children2.front() == firstChild , "firstChild is not first child");
  ENSURE( children2.at(1) == head2 , "head2 is not second child");
  ENSURE( children2.at(2) == p3 , "p3 is not third child");
  
  std::vector<I3Particle> children3 = t2.children(children2.at(1));
  ENSURE( !children3.empty() , "no children3");
  ENSURE( children3.size() == 3 , "children3.size != 3");
}

TEST(replace)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  t1.append_child(p1,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p1,p3);
  t1.append_child(p1,makeParticle());

  I3Particle p2 = makeParticle();
  t1.replace(p3,p2);
  
  ENSURE( !t1.at(p3) , "p3 is still in tree");
  ENSURE( t1.at(p2) , "p2 is not in tree");
  std::vector<I3Particle> children = t1.children(p1);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.at(1) == p2 , "p2 not second child");
  
  I3Particle head = makeParticle();
  I3MCTree t2(head);
  t2.append_child(head,makeParticle());
  t2.append_child(head,makeParticle());
  t2.append_child(head,makeParticle());
  
  t1.replace(p2,t2,head);
  
  ENSURE( !t1.at(p2) , "p2 is still in tree");
  ENSURE( t1.at(head) , "head is not in tree");
  children = t1.children(p1);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.at(1) == head , "head not second child");
  std::vector<I3Particle> children2 = t1.children(head);
  ENSURE( !children2.empty() , "no children2");
  ENSURE( children2.size() == 3 , "3 children of t2 not in t1");
}

TEST(flatten)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  I3Particle p3 = makeParticle();
  t1.append_child(p2,p3);
  I3Particle p4 = makeParticle();
  t1.append_child(p2,p4);
  I3Particle p5 = makeParticle();
  t1.append_child(p3,p5);
  
  t1.flatten(p2);
  
  std::vector<I3Particle> children = t1.children(p1);
  ENSURE( !children.empty() , "no children");
  ENSURE( children.size() == 3 , "children.size != 3");
  ENSURE( children.at(0) == p2 , "p2 not first child");
  ENSURE( children.at(1) == p3 , "p3 not second child");
  ENSURE( children.at(2) == p4 , "p4 not third child");
  
  children = t1.children(p3);
  ENSURE( !children.empty() , "no children2");
  ENSURE( children.size() == 1 , "children2.size != 1");
  ENSURE( children.at(0) == p5 , "p5 not first child of children2");
}

TEST(reparent)
{
  I3Particle p1 = makeParticle();
  I3MCTree t1(p1);
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  I3Particle p3 = makeParticle();
  t1.append_child(p2,p3);
  I3Particle p4 = makeParticle();
  t1.append_child(p2,p4);
  I3Particle p5 = makeParticle();
  t1.append_child(p3,p5);
  
  t1.reparent(p4,p3);
  
  std::vector<I3Particle> children = t1.children(p3);
  ENSURE( children.empty() , "p3 still has children");
  
  children = t1.children(p4);
  ENSURE( !children.empty() , "no children of p4");
  ENSURE( children.size() == 1 , "children(p4).size != 1");
  ENSURE( children.at(0) == p5 , "p5 not first child of children(p4)");
}

TEST(size)
{
  I3Particle head = makeParticle();
  I3MCTree t1(head);
  ENSURE( t1.size() == 1 );
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  ENSURE( t1.size() == 4 );
  I3Particle p1 = makeParticle();
  t1.append_child(head,p1);
  t1.append_child(head,makeParticle());
  t1.append_child(p1,makeParticle());
  t1.append_child(p1,makeParticle());
  ENSURE( t1.size() == 8 );
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  t1.append_child(p2,makeParticle());
  t1.append_child(p2,makeParticle());
  ENSURE( t1.size() == 11 );
}

TEST(depth)
{
  I3Particle head = makeParticle();
  I3MCTree t1(head);
  ENSURE( t1.depth(head) == 0 );
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  I3Particle p1 = makeParticle();
  t1.append_child(head,p1);
  ENSURE( t1.depth(p1) == 1 );
  t1.append_child(head,makeParticle());
  t1.append_child(p1,makeParticle());
  t1.append_child(p1,makeParticle());
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  ENSURE( t1.depth(p2) == 2 );
  t1.append_child(p2,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p2,p3);
  t1.append_child(p3,makeParticle());
  ENSURE( t1.depth(p3) == 3 );
}

TEST(number_of_children)
{
  I3Particle head = makeParticle();
  I3MCTree t1(head);
  ENSURE( t1.number_of_children(head) == 0 );
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  ENSURE( t1.number_of_children(head) == 2 );
  I3Particle p1 = makeParticle();
  t1.append_child(head,p1);
  t1.append_child(head,makeParticle());
  t1.append_child(p1,makeParticle());
  t1.append_child(p1,makeParticle());
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  ENSURE( t1.number_of_children(p1) == 3 );
  t1.append_child(p2,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p2,p3);
  t1.append_child(p3,makeParticle());
  ENSURE( t1.number_of_children(p2) == 2 );
  ENSURE( t1.number_of_children(p3) == 1 );
}

TEST(number_of_siblings)
{
  I3Particle head = makeParticle();
  I3MCTree t1(head);
  ENSURE( t1.number_of_siblings(head) == 0 );
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  I3Particle p1 = makeParticle();
  t1.append_child(head,p1);
  ENSURE( t1.number_of_siblings(p1) == 2 );
  t1.append_child(head,makeParticle());
  ENSURE( t1.number_of_siblings(p1) == 3 );
  t1.append_child(p1,makeParticle());
  t1.append_child(p1,makeParticle());
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  ENSURE( t1.number_of_siblings(p2) == 2 );
  t1.append_child(p2,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p2,p3);
  t1.append_child(p3,makeParticle());
  ENSURE( t1.number_of_siblings(p3) == 1 );
}

TEST(is_in_subtree)
{
  I3Particle head = makeParticle();
  I3MCTree t1(head);
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  I3Particle p1 = makeParticle();
  t1.append_child(head,p1);
  ENSURE( t1.is_in_subtree(head,p1) ,"cannot find p1");
  t1.append_child(head,makeParticle());
  t1.append_child(p1,makeParticle());
  t1.append_child(p1,makeParticle());
  I3Particle p2 = makeParticle();
  t1.append_child(p1,p2);
  ENSURE( t1.is_in_subtree(head,p2) ,"cannot find p2 under head");
  ENSURE( t1.is_in_subtree(p1,p2) ,"cannot find p2 under p1");
  t1.append_child(p2,makeParticle());
  I3Particle p3 = makeParticle();
  t1.append_child(p2,p3);
  ENSURE( t1.is_in_subtree(head,p3) ,"cannot find p3 under head");
  ENSURE( t1.is_in_subtree(p1,p3) ,"cannot find p3 under p1");
  ENSURE( t1.is_in_subtree(p2,p3) ,"cannot find p3 under p2");
  I3Particle p4 = makeParticle();
  t1.append_child(p1,p4);
  ENSURE( t1.is_in_subtree(head,p4) ,"cannot find p4 under head");
  ENSURE( t1.is_in_subtree(p1,p4) ,"cannot find p4 under p1");
  ENSURE( !t1.is_in_subtree(p2,p4) ,"found p4 under p2, when not there");
}

TEST(subtree_in_tree)
{
  I3Particle head = makeParticle();
  I3MCTree t1(head);
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  t1.append_child(head,makeParticle());
  
  I3Particle head2 = makeParticle();
  I3MCTree t2(head2);
  t2.append_child(head2,makeParticle());
  I3Particle p1 = makeParticle();
  t2.append_child(head2,p1);
  t2.append_child(head2,makeParticle());
  
  ENSURE( !t1.subtree_in_tree(t2,head2) , "a particle from t2 is in t1");
  
  t1.append_child(head,p1);
  ENSURE( t1.subtree_in_tree(t2,head2) , "a particle from t2 is not in t1");
  ENSURE( t1.at(p1) , "p1 is not in t1");
}


TEST(xml_serialization)
{
  I3MCTree t1;
  
  ostringstream os;
  {
    boost::archive::xml_oarchive oa(os);
    oa << boost::serialization::make_nvp("mytree", t1);
  }
  
  istringstream is;
  I3MCTree t2;
  is.str(os.str());
  {
    boost::archive::xml_iarchive ia(is);
    ia >> boost::serialization::make_nvp("mytree", t2);
  }
  
  I3MCTree::iterator iter(t1);
  I3MCTree::iterator iter2(t2);
  while(iter != t1.end() && iter2 != t2.end()) {
    ENSURE(*iter == *iter2);
    iter++;
    iter2++;
  }
  ENSURE(t1 == t2);
  
  t2.AddPrimary(makeParticle());
  t2.AddPrimary(makeParticle());
  t2.AddPrimary(makeParticle());
  ostringstream os2;
  {
    boost::archive::xml_oarchive oa2(os2);
    oa2 << boost::serialization::make_nvp("mytree", t2);
  }
  
  istringstream is2;
  I3MCTree t3;
  is2.str(os2.str());
  {
    boost::archive::xml_iarchive ia2(is2);
    ia2 >> boost::serialization::make_nvp("mytree", t3);
  }
  iter = t2.begin();
  iter2 = t3.begin();
  while(iter != t1.end() && iter2 != t2.end()) {
    ENSURE(*iter == *iter2);
    iter++;
    iter2++;
  }
  ENSURE(t2 == t3);
  
  ostringstream os3;
  {
    boost::archive::xml_oarchive oa3(os3);
    oa3 << boost::serialization::make_nvp("mytree", t3);
  }
  
  istringstream is3;
  I3MCTree t4;
  is3.str(os3.str());
  {
    boost::archive::xml_iarchive ia3(is3);
    ia3 >> boost::serialization::make_nvp("mytree", t4);
  }
  iter = t2.begin();
  iter2 = t4.begin();
  while(iter != t1.end() && iter2 != t2.end()) {
    ENSURE(*iter == *iter2);
    iter++;
    iter2++;
  }
  ENSURE(t2 == t4);
}


TEST(xml_serialization_massive)
{
  I3MCTree t1;
  I3Particle p1;
  int nchildren = 0;
  for(int i=0;i<10;i++) {
    vector<I3Particle> children;
    p1 = makeParticle();
    t1.AddPrimary(p1);
    nchildren = 2000+1000*(i%4);
    for(int j=0;j<nchildren;j++) {
      children.push_back(makeParticle());
    }
    t1.append_children(p1,children);
  }
  
  ostringstream os;
  {
    boost::archive::xml_oarchive oa(os);
    oa << boost::serialization::make_nvp("mytree", t1);
  }
  
  istringstream is;
  I3MCTree t2;
  is.str(os.str());
  {
    boost::archive::xml_iarchive ia(is);
    ia >> boost::serialization::make_nvp("mytree", t2);
  }
  
  I3MCTree::iterator iter(t1);
  I3MCTree::iterator iter2(t2);
  while(iter != t1.end() && iter2 != t2.end()) {
    ENSURE(*iter == *iter2);
    iter++;
    iter2++;
  }
  ENSURE(t1 == t2);
  
  ostringstream os2;
  {
    boost::archive::xml_oarchive oa2(os2);
    oa2 << boost::serialization::make_nvp("mytree", t2);
  }
  
  istringstream is2;
  I3MCTree t3;
  is2.str(os2.str());
  {
    boost::archive::xml_iarchive ia2(is2);
    ia2 >> boost::serialization::make_nvp("mytree", t3);
  }
  iter = t1.begin();
  iter2 = t3.begin();
  while(iter != t1.end() && iter2 != t2.end()) {
    ENSURE(*iter == *iter2);
    iter++;
    iter2++;
  }
  ENSURE(t1 == t3);
}

// Now run the I3MCTree tests


