/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TWRLaunch.cxx 1378 2005-04-01 22:38:41Z olivas $

    @version $Revision: 1.1 $
    @date $Date: 2005-04-01 17:38:41 -0500 (Fri, 01 Apr 2005) $
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3TWRLaunch.h"
#include "dataclasses/I3DigitalLaunch.h"

TEST_GROUP(I3TWRLaunch);

I3_SERIALIZATION_TEST(I3TWRLaunch);

I3_VIRTUAL_SERIALIZATION_TEST(I3DigitalLaunch,I3TWRLaunch);
