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
#include "dataclasses/I3Vector.h"
#include "icetray/I3Frame.h"
#include<vector>
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
  I3FlasherInfoVectPtr vct(new I3FlasherInfoVect());
  ENSURE(ptr,"NULL pointer.");
  ENSURE(vct,"NULL vector.");
}

TEST(SetAndGet){
  int seed = time(0);
  I3FlasherInfoPtr flasherInfoPtr(new I3FlasherInfo);
  I3FlasherInfoPtr flasherInfoPtr2(new I3FlasherInfo);
  I3FlasherInfoVectPtr flasherInfoVect(new I3FlasherInfoVect());
  {
    srand(seed);
    int string_i = (rand() % 80)+1;
    unsigned int om_i = (rand() % 60)+1;
    double flashTime_i = (double)rand()/(double)rand();
    double atwdBinSize_i = (double)rand()/(double)rand();
    int ledBrightness_i = rand();
    unsigned int mask_i = rand();
    int width_i = rand();
    OMKey omKey_i(string_i,om_i);

    flasherInfoPtr->SetFlashingOM(omKey_i);
    flasherInfoPtr->SetFlashTime(flashTime_i);
    flasherInfoPtr->SetATWDBinSize(atwdBinSize_i);
    flasherInfoPtr->SetLEDBrightness(ledBrightness_i);
    flasherInfoPtr->SetMask(mask_i);
    flasherInfoPtr->SetWidth(width_i);

    flasherInfoPtr2->SetFlashingOM(omKey_i);
    flasherInfoPtr2->SetFlashTime(flashTime_i);
    flasherInfoPtr2->SetATWDBinSize(atwdBinSize_i);
    flasherInfoPtr2->SetLEDBrightness(ledBrightness_i);
    flasherInfoPtr2->SetMask(mask_i);
    flasherInfoPtr2->SetWidth(width_i);
  }
  flasherInfoVect->push_back(*flasherInfoPtr);
  flasherInfoVect->push_back(*flasherInfoPtr2);
  int vsize=flasherInfoVect->size();
  ENSURE_EQUAL(vsize,2,"flasher info vector has size not equal to 2");
  {
    srand(seed);
    int string_f = (rand() % 80)+1;
    unsigned int om_f = (rand() % 60)+1;
    double flashTime_f = (double)rand()/(double)rand();
    double atwdBinSize_f = (double)rand()/(double)rand();
    int ledBrightness_f = rand();
    unsigned int mask_f = rand();
    int width_f = rand();
    OMKey omKey_f(string_f,om_f);

    ENSURE(flasherInfoPtr->GetFlashingOM() == omKey_f,"OMKey is not the same");
    ENSURE(flasherInfoPtr->GetFlashTime() == flashTime_f,"FlashTime is not the same");
    ENSURE(flasherInfoPtr->GetATWDBinSize() == atwdBinSize_f,"ATWDBinSize is not the same");
    ENSURE(flasherInfoPtr->GetLEDBrightness() == ledBrightness_f,"LEDBrightness is not the same");
    ENSURE(flasherInfoPtr->GetMask() == mask_f,"Mask is not the same");
    ENSURE(flasherInfoPtr->GetWidth() == width_f,"Width is not the same");
    
    int count=0;

    for(vector<I3FlasherInfo>::iterator iter = flasherInfoVect->begin() ; 
	iter != flasherInfoVect->end() ; 
	iter++)
      {
	
	ENSURE(iter->GetFlashingOM() == omKey_f,"OMKey is not the same");
	ENSURE(iter->GetFlashTime() == flashTime_f,"FlashTime is not the same");
	ENSURE(iter->GetATWDBinSize() == atwdBinSize_f,"ATWDBinSize is not the same");
	ENSURE(iter->GetLEDBrightness() == ledBrightness_f,"LEDBrightness is not the same");
	ENSURE(iter->GetMask() == mask_f,"Mask is not the same");
	ENSURE(iter->GetWidth() == width_f,"Width is not the same");
	count++;
      }
    ENSURE_EQUAL(count,2,"Loop did not count twice");
  }    
}


