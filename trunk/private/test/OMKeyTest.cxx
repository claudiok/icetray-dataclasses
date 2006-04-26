/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.3 $
    @date $Date$
    @author pretz

    @todo
*/

#include <I3Test.h>

#include "dataclasses/OMKey.h"
#include "TFile.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

TEST_GROUP(OMKeyTest);


TEST(comparison_operator)
{
  ENSURE(OMKey(1,1) != OMKey(1,2),"different keys are different");
  ENSURE(OMKey(1,3) != OMKey(2,3),"different keys are different");
  ENSURE(OMKey(1,0) < OMKey(1,1),"operator< works as expected");
  ENSURE(OMKey(1,0) < OMKey(2,0),"operator< works as expected");
  ENSURE(OMKey(1,1) < OMKey(2,2),"operator< works as expected");
  
}
