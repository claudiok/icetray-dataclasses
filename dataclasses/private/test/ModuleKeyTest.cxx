/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: ModuleKeyTest.cxx 77426 2011-06-30 00:51:32Z olivas $

    @version $Revision: 1.3 $
    @date $Date: 2011-06-29 19:51:32 -0500 (Wed, 29 Jun 2011) $
    @author pretz

    @todo
*/

#include <I3Test.h>

#include "dataclasses/ModuleKey.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

TEST_GROUP(ModuleKeyTest);


TEST(comparison_operator)
{
  ENSURE(ModuleKey(1,1) != ModuleKey(1,2),"different keys are different");
  ENSURE(ModuleKey(1,3) != ModuleKey(2,3),"different keys are different");
  ENSURE(ModuleKey(1,0) < ModuleKey(1,1),"operator< works as expected");
  ENSURE(ModuleKey(1,0) < ModuleKey(2,0),"operator< works as expected");
  ENSURE(ModuleKey(1,1) < ModuleKey(2,2),"operator< works as expected");
  
}
