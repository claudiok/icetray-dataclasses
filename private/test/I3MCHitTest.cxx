/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.8 $
    @date $Date$
    @author Troy D. Straszheim

    @todo

*/
#include <I3Test.h>
#include "dataclasses/physics/I3MCHit.h"

// this is a typical minimal testsuite

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3MCHitTest);

/**
 * Checks assignment/copy construction
 */
// the string here is used to identify this specific test.
TEST(assignment_copy)
{
  I3MCHit h, j;
  ENSURE(h.GetWeight() == 0);
  ENSURE(h.GetParticleID() == 0);
  j.SetWeight(M_PI);
  j.SetParticleID(rand()%256);
  j.SetCherenkovDistance(123.45);
  h = j;
  ENSURE_DISTANCE(0.1, 0.1, 0.0001,"ensure test");
  ENSURE_DISTANCE(j.GetWeight(), h.GetWeight(), (float)0.0001,"simple assignment");
  ENSURE_DISTANCE(j.GetCherenkovDistance(),h.GetCherenkovDistance(), 0.01, 
		  "CherenkovDistance test");
  ENSURE(j.GetParticleID() == j.GetParticleID());
}

/**
 * checks chains of operations
 */
TEST(assignment_chain)
{
  I3MCHit u, v, w, x;
  x.SetTime(rand()/0.235234);
  u = u = v = v = w = x;
  ENSURE_DISTANCE(u.GetTime(), 
		  x.GetTime(), 
		  0.0001,"chain of assignment operators");
}


