/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCHitTest.cxx 9995 2005-07-14 15:31:47Z blaufuss $

    @version $Revision: 1.8 $
    @date $Date: 2005-07-14 11:31:47 -0400 (Thu, 14 Jul 2005) $
    @author Troy D. Straszheim

    @todo

*/
#include <I3Test.h>
#include "dataclasses/physics/I3MCPrimary.h"

// this is a typical minimal testsuite

// This string identifies the test suite in the list of test suites.
TEST_GROUP(I3MCPrimary);

/**
 * Checks assignment/copy construction
 */
// the string here is used to identify this specific test.
TEST(stream_method)
{
  I3MCPrimary h;

  ostringstream oss;
  oss<<h;

  ENSURE(oss.str().size()>16,"ToStream isn't that informative");
  //There are 16 characters in "[ I3MCPrimary ]"
  //including the terminating NULL
}

