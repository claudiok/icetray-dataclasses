/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TriggerTest.cxx 10872 2005-08-31 16:19:29Z blaufuss $

    @version $Revision: 1.8 $
    @date $Date: 2005-08-31 12:19:29 -0400 (Wed, 31 Aug 2005) $
    @author Troy D. Straszheim

    @todo

*/
#include <I3Test.h>
#include "dataclasses/I3Trigger.h"

// this is a typical minimal testsuite

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3TriggerTest);

/**
 * Checks assignment/copy construction
 */
// the string here is used to identify this specific test.
TEST(assignment_copy)
{
  I3Trigger h, j;
  //Check that constructor preset values are set properly
  ENSURE(h.GetTriggerFired() == false);
  ENSURE(h.GetTriggerTime() == 0.0);
  ENSURE(h.GetTriggerLength() == 0.0);
  ENSURE(h.GetSubDetector() == Unkown);
  //Now set some values.
  j.SetTriggerTime(12345.67);
  j.SetTriggerLength(1567.89);
  j.SetTriggerFired(true);
  j.SetSubDetector(InIce);
  //test assignment one object to another
  h = j;
  //Check it correct.
  ENSURE_DISTANCE(0.1, 0.1, 0.0001,"ensure test");
  ENSURE_DISTANCE(j.GetTriggerTime(), h.GetTriggerTime, (float)0.0001,
		  "trigger time simple assignment");
  ENSURE_DISTANCE(j.GetTriggerLength(), h.GetTriggerLength, (float)0.0001,
		  "trigger length simple assignment");
  ENSURE(j.GetTriggerFired() == j.GetTriggerFired());
  ENSURE(j.GetSubDetector() == j.GetSubDetector());
}

