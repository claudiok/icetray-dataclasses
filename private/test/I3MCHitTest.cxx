/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCHitTest.cxx,v 1.1 2004/03/03 15:37:01 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/03/03 15:37:01 $
    @author Troy D. Straszheim

    @todo

*/
#include "test/tut.h"
#include "dataclasses/I3MCHit.h"

// this is an example of a minimal testsuite

namespace tut
{
  
  struct I3MCHitTest { };
  typedef test_group<I3MCHitTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3MCHit tests");
}

namespace tut
{
  /**
   * Checks assignment/copy construction
   */
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

