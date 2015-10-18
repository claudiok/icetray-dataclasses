#include <I3Test.h>
#include <dataclasses/physics/I3Trigger.h>
#include <dataclasses/status/I3DetectorStatus.h>
#include <dataclasses/payload/I3SuperDSTTrigger.h>



TEST_GROUP(I3SuperDSTTriggerTest);

TEST(i3objects_constructor)
{
  I3Trigger trigger = I3Trigger();
  I3DetectorStatus detectorstatus = I3DetectorStatus();
  I3SuperDSTTrigger(trigger,detectorstatus);
  
}

TEST(idx_constructor)
{
  uint32_t key_idx = 0;
  uint32_t startcode = 0;
  uint32_t lengthcode = 0;

  I3SuperDSTTrigger superdsttrigger(key_idx,startcode,lengthcode);
}
