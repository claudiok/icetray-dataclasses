/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.2 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "serialization-test.h"
#include "dataclasses/I3AMANDAAnalogReadout.h"

TEST_GROUP(I3AMANDAAnalogReadout);

I3_SERIALIZATION_TEST(I3AMANDAAnalogReadout);

I3_VIRTUAL_SERIALIZATION_TEST(I3AnalogReadout, I3AMANDAAnalogReadout);

I3_VIRTUAL_SERIALIZATION_TEST(I3DataReadout, I3AMANDAAnalogReadout);
