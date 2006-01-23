/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Particle.cxx 9995 2005-07-14 15:31:47Z blaufuss $

    @version $Revision: 1.8 $
    @date $Date: 2005-07-14 11:31:47 -0400 (Thu, 14 Jul 2005) $
    @author E Blaufuss

    @todo

*/
#include <I3Test.h>
#include "dataclasses/I3BasicTrack.h"

// This string identifies the test suite in the list of test suites.

TEST_GROUP(I3Particle);

/**
 * Checks assignment/copy construction
 */
// the string here is used to identify this specific test.
TEST(Particle_reconame)
{
  I3BasicTrack part;
  const string myname="bobo";
  
  part.SetRecoName(myname);
  string testname = part.GetRecoName();
  ENSURE(testname == myname,"Particle RecoName set/get is borked!");

}

