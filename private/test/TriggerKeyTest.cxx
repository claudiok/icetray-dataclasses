#include <I3Test.h>
#include "dataclasses/TriggerKey.h"
#include "dataclasses/I3TriggerDict.h"
#include "dataclasses/I3Trigger.h"

// Let;s play with trigger Keys...

TEST_GROUP(TriggerKeyTests);

TEST(setandget)
{
  TriggerKeyPtr tkp(new TriggerKey);
  tkp->SetTriggerType(123);
  tkp->SetTriggerConfigID(456);
  tkp->SetSourceID(4000);
  
  ENSURE(tkp->GetTriggerType() == 123);
  ENSURE(tkp->GetTriggerConfigID() == 456);
  ENSURE(tkp->GetSourceID() == 4000);
}

TEST(comparison_operators)
  //Comparison very important for map storage
{
  ENSURE(TriggerKey(1,0,0)!=TriggerKey(2,0,0),"Different trigger Keys not OK");
  ENSURE(TriggerKey(1,1,0)!=TriggerKey(1,2,0),"Different trigger Keys not OK");
  ENSURE(TriggerKey(1,1,0)!=TriggerKey(1,1,1),"Different trigger Keys not OK");
  ENSURE(TriggerKey(1,1,1)==TriggerKey(1,1,1),"SAME trigger Keys not OK");

  ENSURE(TriggerKey(1,0,0)<TriggerKey(2,0,0),"Less < compare trigger Keys not OK");
  ENSURE(!(TriggerKey(3,0,0)<TriggerKey(2,0,0)),"Less < compare trigger Keys not OK");
  ENSURE(TriggerKey(1,1,0)<TriggerKey(1,2,0),"Less < compare trigger Keys not OK");
  ENSURE(TriggerKey(1,1,1)<TriggerKey(1,1,2),"Less < compare trigger Keys not OK");
  ENSURE(!(TriggerKey(1,1,2)<TriggerKey(1,1,1)),"Less < compare trigger Keys not OK");
}

TEST(jam_triggers_into_map)
{
  //Get us a triggerDict.
  I3TriggerDict tdp;
  //Now. round me up a trigger
  I3TriggerPtr trig(new I3Trigger());
  trig->SetTriggerTime(10.0);
  TriggerKey mykey(123,456,4000);
  string themapkey = TriggerKey::GenerateName(mykey);

 //Now, jam into triggerdict.
  tdp[themapkey] = trig;

  //alright smartass, you've stored it, Now find it....
  const I3TriggerPtr mytrig = tdp.find(themapkey)->second;
  ENSURE_DISTANCE(mytrig->GetTriggerTime(),10.0,0.01,"triggers do` not match");

}
