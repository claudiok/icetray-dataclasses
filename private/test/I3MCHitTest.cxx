/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCHitTest.cxx,v 1.2 2004/03/03 15:50:08 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/03/03 15:50:08 $
    @author Troy D. Straszheim

    @todo

*/
#include "test/tut.h"
#include "dataclasses/I3MCHit.h"

// this is a typical minimal testsuite

namespace tut
{
  // whatever is in this struct will be visible from all object::test routines below
  struct I3MCHitTest { };
  typedef test_group<I3MCHitTest> factory;
  typedef factory::object object;
}

namespace
{
  // this string can be used from the command line to run just this group of tests
  tut::factory t("I3MCHit");
}

namespace tut
{
  /**
   * Checks assignment/copy construction
   */
  // you need the template<> template<> thing because this is a specialization
  // of a template function
  template<> template<>
  void object::test<1>()
  {
    I3MCHit h, j;
    ensure(h.Weight() == 0);
    ensure(h.TrackNumber() == 0);
    j.Weight(rand()/0.3234);
    j.TrackNumber(rand()%256);
    h = j;
    ensure_distance("simple assignment", j.Weight(), h.Weight(), (float)0.0001);
    ensure(j.TrackNumber() == j.TrackNumber());
  }

  // to run just this test, use "runtests I3MCHit 4"
  template<> template<>
  void object::test<4>() 
  {
    fail("this test is supposed to fail, this is on purpose.");
  }

  /**
   * checks chains of operations
   */
  template<> template<>
  void object::test<2>()
  {
    I3MCHit u, v, w, x;
    x.Time(rand()/0.235234);
    u = u = v = v = w = x;
    ensure_distance("chain of assignment operators", u.Time(), x.Time(), 0.0001);
  }
}

