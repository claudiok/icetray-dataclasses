/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3BadOMSelection.h"

TEST_GROUP(I3BadOMSelection);

I3_SERIALIZATION_TEST(I3BadOMSelection);

I3_VIRTUAL_SERIALIZATION_TEST(I3OMListSelection,I3BadOMSelection);

I3_VIRTUAL_SERIALIZATION_TEST(I3OMResponseSelection,I3BadOMSelection);
