/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCHitTest.cxx,v 1.6 2004/08/09 12:13:10 troy Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/08/09 12:13:10 $
    @author Troy D. Straszheim

    @todo

*/
#include "TUT/tut.h"
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
    ensure(h.GetWeight() == 0);
    ensure(h.GetParticleID() == 0);
    j.SetWeight(rand()/0.3234);
    j.SetParticleID(rand()%256);
    h = j;
    ensure_distance("simple assignment", j.GetWeight(), h.GetWeight(), (float)0.0001);
    ensure(j.GetParticleID() == j.GetParticleID());
  }

  /**
   * checks chains of operations
   */
  template<> template<>
  void object::test<2>()
  {
    I3MCHit u, v, w, x;
    x.SetTime(rand()/0.235234);
    u = u = v = v = w = x;
    ensure_distance("chain of assignment operators", 
		    u.GetTime(), 
		    x.GetTime(), 
		    0.0001);
  }
}

