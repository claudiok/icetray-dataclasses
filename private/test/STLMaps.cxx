/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLMaps.cxx 9995 2005-07-14 15:31:47Z blaufuss $

    @version $Revision: 1.8 $
    @date $Date: 2005-07-14 11:31:47 -0400 (Thu, 14 Jul 2005) $
    @author E Blaufuss

    @todo

*/
#include <I3Test.h>
#include "dataclasses/I3TriggerDict.h"
#include "dataclasses/I3Trigger.h"

// This string identifies the test suite in the list of test suites.

TEST_GROUP(STLMaps);

TEST(EmptyMapGet)
{
  I3TriggerDict dict;

  dict.Get("Bob");


}

TEST(FilledMapGetMissing)
{
  I3TriggerDict dict;
  
  I3TriggerPtr joe, betty;

  dict.Add(joe,"joe");
  dict.Add(betty,"betty");


  dict.Get("Bob");


}

TEST(MapAddKeyUsed)
{
  I3TriggerDict dict;
  
  I3TriggerPtr joe, betty, sue;

  dict.Add(joe,"joe");
  dict.Add(betty,"betty");


  dict.Add(sue,"betty");
  I3TriggerDict::iterator iter;

  for(iter = dict.begin(); iter != dict.end(); iter++)
    {
      log_error("Map key: %s",iter->first.c_str());
    }


}

