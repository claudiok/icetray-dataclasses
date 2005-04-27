/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3GoodOMSelection.h"

TEST_GROUP(I3GoodOMSelection);

I3_SERIALIZATION_TEST(I3GoodOMSelection);

I3_VIRTUAL_SERIALIZATION_TEST(I3OMListSelection,I3GoodOMSelection);

I3_VIRTUAL_SERIALIZATION_TEST(I3OMResponseSelection,I3GoodOMSelection);
