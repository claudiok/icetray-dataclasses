/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3DOMLaunch.h"
#include "dataclasses/I3DigitalLaunch.h"

TEST_GROUP(I3DOMLaunch);

I3_SERIALIZATION_TEST(I3DOMLaunch);

I3_VIRTUAL_SERIALIZATION_TEST(I3DigitalLaunch,I3DOMLaunch);
