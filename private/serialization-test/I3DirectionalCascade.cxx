/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DirectionalCascade.cxx 7032 2005-04-27 21:44:45Z olivas $

    @version $Revision: 1.1 $
    @date $Date: 2005-04-27 17:44:45 -0400 (Wed, 27 Apr 2005) $
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3DirectionalCascade.h"
#include "dataclasses/I3InIceParticle.h"
#include "dataclasses/I3Particle.h"

TEST_GROUP(I3DirectionalCascade);

I3_SERIALIZATION_TEST(I3DirectionalCascade);

I3_VIRTUAL_SERIALIZATION_TEST(I3InIceParticle,I3DirectionalCascade);

I3_VIRTUAL_SERIALIZATION_TEST(I3Particle,I3DirectionalCascade);
