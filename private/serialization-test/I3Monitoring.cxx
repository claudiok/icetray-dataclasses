/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Monitoring.cxx 7032 2005-04-27 21:44:45Z olivas $

    @version $Revision: 1.1 $
    @date $Date: 2005-04-27 17:44:45 -0400 (Wed, 27 Apr 2005) $
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3Monitoring.h"

TEST_GROUP(I3Monitoring);

I3_SERIALIZATION_TEST(I3Monitoring);
