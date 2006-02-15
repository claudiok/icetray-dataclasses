/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3FlasherInfoTest.cxx 9329 2005-06-20 22:36:05Z pretz $

    @version $Revision: 1.3 $
    @date $Date: 2005-06-20 18:36:05 -0400 (Mon, 20 Jun 2005) $
    @author olivas

    @todo
*/

#include <I3Test.h>

#include "dataclasses/physics/I3FlasherInfo.h"
#include "icetray/I3Frame.h"

using std::string;
using std::cout;
using std::endl;

TEST_GROUP(I3FlasherInfoTest);
  
/**
 * check that constructor and destructor work
 */
TEST(const_dest)
{
  I3FlasherInfoPtr ptr(new I3FlasherInfo());
  ENSURE(ptr,"NULL pointer.");
}

TEST(SetAndGet){
  int seed = time(0);
  I3FlasherInfoPtr flasherInfoPtr(new I3FlasherInfo);
  {
    srand(seed);
    int string_i = (rand() % 80)+1;
    unsigned int om_i = (rand() % 60)+1;
    double flashTime_i = (double)rand()/(double)rand();
    double atwdBinSize_i = (double)rand()/(double)rand();
    int ledBrightness_i = rand();
    unsigned int mask_i = rand();
    OMKey omKey_i(string_i,om_i);

    flasherInfoPtr->SetFlashingOM(omKey_i);
    flasherInfoPtr->SetFlashTime(flashTime_i);
    flasherInfoPtr->SetATWDBinSize(atwdBinSize_i);
    flasherInfoPtr->SetLEDBrightness(ledBrightness_i);
    flasherInfoPtr->SetMask(mask_i);
  }
  {
    srand(seed);
    int string_f = (rand() % 80)+1;
    unsigned int om_f = (rand() % 60)+1;
    double flashTime_f = (double)rand()/(double)rand();
    double atwdBinSize_f = (double)rand()/(double)rand();
    int ledBrightness_f = rand();
    unsigned int mask_f = rand();
    OMKey omKey_f(string_f,om_f);

    ENSURE(flasherInfoPtr->GetFlashingOM() == omKey_f,"OMKey is not the same");
    ENSURE(flasherInfoPtr->GetFlashTime() == flashTime_f,"FlashTime is not the same");
    ENSURE(flasherInfoPtr->GetATWDBinSize() == atwdBinSize_f,"ATWDBinSize is not the same");
    ENSURE(flasherInfoPtr->GetLEDBrightness() == ledBrightness_f,"LEDBrightness is not the same");
    ENSURE(flasherInfoPtr->GetMask() == mask_f,"Mask is not the same");
  }    
}


