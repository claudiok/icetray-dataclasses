/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3HitTest.cxx,v 1.1 2004/03/03 15:37:01 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/03/03 15:37:01 $
    @author Troy D. Straszheim

    @todo

*/
#include "test/tut.h"
#include "dataclasses/I3Hit.h"

// this is an example of a minimal testsuite

namespace tut
{
  
  struct I3HitTest { };
  typedef test_group<I3HitTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3Hit tests");
}

namespace tut
{
  /**
   * Checks assignment/copy construction
   */
  template<> template<>
  void object::test<1>()
  {
    I3Hit h, j;
    ensure(h.Time() == 0);
    j.Time(rand()/0.3234);
    h = j;
    ensure_distance("simple assignment", j.Time(), h.Time(), 0.0001);
    ensure (h==j);
    I3Hit k(h);
    ensure (k==j);
  }

  /**
   * checks chains of operations
   */
  template<> template<>
  void object::test<2>()
  {
    I3Hit u, v, w, x;
    x.Time(rand()/0.235234);
    u = u = v = v = w = x;
    ensure_distance("chain of assignment operators", u.Time(), x.Time(), 0.0001);
  }
}

