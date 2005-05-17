/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCPrimary.cxx 7032 2005-04-27 21:44:45Z olivas $

    @version $Revision: 1.1 $
    @date $Date: 2005-04-27 17:44:45 -0400 (Wed, 27 Apr 2005) $
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3Particle.h"

TEST_GROUP(I3MCPrimary);

I3_SERIALIZATION_TEST(I3MCPrimary);

I3_VIRTUAL_SERIALIZATION_TEST(I3Particle,I3MCPrimary);
