/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
#include "dataclasses/I3DigitalReadout.h"
#include "dataclasses/I3DataReadout.h"


TEST_GROUP(I3DigitalReadout);

I3_SERIALIZATION_TEST(I3DigitalReadout);

I3_VIRTUAL_SERIALIZATION_TEST(I3DataReadout,I3DigitalReadout);
