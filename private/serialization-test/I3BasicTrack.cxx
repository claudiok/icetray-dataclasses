/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrack.cxx 1360 2005-03-31 17:38:00Z troy $

    @version $Revision: 1.1 $
    @date $Date: 2005-03-31 12:38:00 -0500 (Thu, 31 Mar 2005) $
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
#include "dataclasses/I3BasicTrack.h"
#include "dataclasses/I3Particle.h"
#include "dataclasses/I3InIceParticle.h"
#include "dataclasses/I3Track.h"

TEST_GROUP(I3BasicTrack);

I3_SERIALIZATION_TEST(I3BasicTrack);

I3_VIRTUAL_SERIALIZATION_TEST(I3Particle,I3BasicTrack);

I3_VIRTUAL_SERIALIZATION_TEST(I3InIceParticle,I3BasicTrack);

I3_VIRTUAL_SERIALIZATION_TEST(I3Track,I3BasicTrack);
