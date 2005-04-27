/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3RecoResultSingleTrack.h"

TEST_GROUP(I3RecoResultSingleTrack);

I3_SERIALIZATION_TEST(I3RecoResultSingleTrack);

I3_VIRTUAL_SERIALIZATION_TEST(I3RecoResult,I3RecoResultSingleTrack);
