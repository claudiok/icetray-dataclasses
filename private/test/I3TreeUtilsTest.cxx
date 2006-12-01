/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TreeUtilsTest.cxx 10872 2005-08-31 16:19:29Z dule $

    @version $Revision: 1.8 $
    @date $Date: 2005-08-31 12:19:29 -0400 (Wed, 31 Aug 2005) $
    @author dule
*/
#include <vector>
#include <algorithm>
#include <sstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <I3Test.h>
#include <dataclasses/I3TreeUtils.h>

using namespace std;

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3TreeUtilsTest);

class int_t
{
public:
  int id;
  const int GetID() const { return id; }
  int_t(int i) : id(i) { }
};

TEST(a_insert_and_append)
{
  I3Tree<int_t> t;
  
  ENSURE(t.empty());
  ENSURE_EQUAL(0, t.size());
  ENSURE(!t.is_valid(t.begin()));
  ENSURE(t.begin() == t.end());

  int_t one(1);
  I3TreeUtils::AddPrimary<int_t>(t, one);

  ENSURE(!t.empty());
  ENSURE_EQUAL(1, t.size());
  ENSURE(t.begin() != t.end());
  I3Tree<int_t>::iterator iter1 = t.begin();
  ENSURE(t.begin() == iter1);
  ENSURE(t.is_valid(iter1));
  ENSURE_EQUAL(0, t.depth(iter1));
  ENSURE_EQUAL(1, iter1->GetID());
  ENSURE_EQUAL(0u, iter1.number_of_children());
  ENSURE_EQUAL(0u, t.number_of_siblings(iter1));
  
  int_t two(2);
  I3TreeUtils::AppendChild<int_t>(t, one, two);

  ENSURE_EQUAL(2, t.size());
  ENSURE_EQUAL(1u, t.begin().number_of_children());
  iter1++;
  ENSURE(t.is_valid(iter1));
  ENSURE_EQUAL(1, t.depth(iter1));
  ENSURE_EQUAL(2, iter1->GetID());
  ENSURE_EQUAL(0u, iter1.number_of_children());
  ENSURE_EQUAL(0u, t.number_of_siblings(iter1));
  ENSURE_EQUAL(2, (t.child(t.begin(), 0))->GetID());
  
  int_t three(3);
  I3TreeUtils::AppendChild<int_t>(t, one, three);

  ENSURE_EQUAL(3, t.size());
  ENSURE_EQUAL(2u, t.begin().number_of_children());
  iter1++;
  ENSURE(t.is_valid(iter1));
  ENSURE_EQUAL(1, t.depth(iter1));
  ENSURE_EQUAL(3, iter1->GetID());
  ENSURE_EQUAL(0u, iter1.number_of_children());
  ENSURE_EQUAL(0u, t.number_of_siblings(iter1));
  iter1--;
  ENSURE_EQUAL(1u, t.number_of_siblings(iter1));
  ENSURE_EQUAL(3, (t.child(t.begin(), 1))->GetID());
}

namespace UtilsTest
{
  void FillTree(I3Tree<int_t>& t)
  {
    int_t one(1);
    int_t two(2);
    int_t three(3);
    int_t four(4);
    int_t five(5);
    I3TreeUtils::AddPrimary<int_t>(t, one);
    I3TreeUtils::AppendChild<int_t>(t, one, two);
    I3TreeUtils::AppendChild<int_t>(t, one, three);
    I3TreeUtils::AppendChild<int_t>(t, two, four);
    I3TreeUtils::AppendChild<int_t>(t, two, five);
    int_t eleven(11);
    int_t twelve(12);
    I3TreeUtils::AddPrimary<int_t>(t, eleven);
    I3TreeUtils::AppendChild<int_t>(t, eleven, twelve);
  }
}

TEST(b_get_object)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  int_t i = I3TreeUtils::GetObject<int_t>(t,5);
  ENSURE_EQUAL(i.GetID(),5);

  i = I3TreeUtils::GetObject<int_t>(t,2);
  ENSURE_EQUAL(i.GetID(),2);
}

TEST(c_get_primaries)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  vector<int_t> v = I3TreeUtils::GetPrimaries<int_t>(t);
  ENSURE((int)v.size() > 0);
  ENSURE_EQUAL(v[0].GetID(), 1);
}

TEST(d_get_daughters)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  vector<int_t> v = I3TreeUtils::GetPrimaries<int_t>(t);
  ENSURE((int)v.size() > 0);

  vector<int_t> v1 = I3TreeUtils::GetDaughters<int_t>(t,v[0]);
  ENSURE_EQUAL((int)v1.size(), 2);
  ENSURE_EQUAL(v1[0].GetID(), 2);
  ENSURE_EQUAL(v1[1].GetID(), 3);

  vector<int_t> v2 = I3TreeUtils::GetDaughters<int_t>(t,v1[0]);
  ENSURE_EQUAL((int)v2.size(), 2);
  ENSURE_EQUAL(v2[0].GetID(), 4);
  ENSURE_EQUAL(v2[1].GetID(), 5);
}

TEST(e_is_primary)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  int_t i1(1);
  ENSURE(I3TreeUtils::IsPrimary<int_t>(t,i1));

  int_t i2(2);
  ENSURE(!I3TreeUtils::IsPrimary<int_t>(t,i2));
}

TEST(f_has_parent)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  int_t i1(1);
  ENSURE(!(I3TreeUtils::HasParent<int_t>(t,i1)));
  int_t i2(2);
  ENSURE(I3TreeUtils::HasParent<int_t>(t,i2));
  int_t i3(3);
  ENSURE(I3TreeUtils::HasParent<int_t>(t,i3));
  int_t i4(4);
  ENSURE(I3TreeUtils::HasParent<int_t>(t,i4));
  int_t i5(5);
  ENSURE(I3TreeUtils::HasParent<int_t>(t,i5));

  int_t i11(11);
  ENSURE(!I3TreeUtils::HasParent<int_t>(t,i11));
  int_t i12(12);
  ENSURE(I3TreeUtils::HasParent<int_t>(t,i12));
}

TEST(g_get_parent)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  int_t i1(3);
  ENSURE_EQUAL(I3TreeUtils::GetParent<int_t>(t,i1).GetID(), 1);
  int_t i2(5);
  ENSURE_EQUAL(I3TreeUtils::GetParent<int_t>(t,i2).GetID(), 2);

  int_t i3(12);
  ENSURE_EQUAL(I3TreeUtils::GetParent<int_t>(t,i3).GetID(), 11);
}

TEST(h_get_nonexistant_parent)
{
  I3Tree<int_t> t;
  UtilsTest::FillTree(t);

  int_t i1(1);
  try {
    ENSURE_EQUAL(I3TreeUtils::GetParent<int_t>(t,i1).GetID(), 0);
  }
  catch(const std::exception &e){
    cerr<<"Error: This LOG_FATAL was expected when getting parent of primary: "
	<<e.what()<<" ... test passed!"<<endl;
  }

  int_t i2(20);
  try {
    ENSURE_EQUAL(I3TreeUtils::GetParent<int_t>(t,i2).GetID(), 0);
  }
  catch(const std::exception &e){
    cerr<<"Error: This LOG_FATAL was expected when getting parent of object "
      "which is not in th tree: "<<e.what()<<" ... test passed!"<<endl;
  }

}
