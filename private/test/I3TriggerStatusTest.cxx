/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: TriggerStatusTest.cxx 9281 2005-06-19 17:06:10Z blaufuss $

*/

#include <I3Test.h>

#include "dataclasses/status/I3TriggerStatus.h"
#include "icetray/I3Units.h"

#include <iostream>
#include <string>

using namespace std;

TEST_GROUP(I3TriggerStatusTest);

TEST(TriggerStatusSetGet)
{

  I3TriggerStatus myts; 

  map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig> & readoutconfig = 
    myts.GetReadoutSettings();

  I3TriggerReadoutConfig myreadout;
  myreadout.readoutTimeMinus = 5000.0*I3Units::ns;
  myreadout.readoutTimePlus = 6000.0*I3Units::ns;
  myreadout.readoutTimeOffset = -1000.0*I3Units::ns;

  readoutconfig[I3TriggerStatus::INICE] = myreadout;
  const map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig> & testconfig = 
    myts.GetReadoutSettings();
  I3TriggerReadoutConfig mytest = testconfig.find(I3TriggerStatus::INICE)->second;
  
  ENSURE_DISTANCE(5000.0, mytest.readoutTimeMinus/I3Units::ns, 0.01,
		  "Readout configs do not match.");
  ENSURE_DISTANCE(6000.0, mytest.readoutTimePlus/I3Units::ns, 0.01,
		  "Readout configs do not match.");
  ENSURE_DISTANCE(-1000.0, mytest.readoutTimeOffset/I3Units::ns, 0.01,
		  "Readout configs do not match.");

}

TEST(TriggerStatusSerialize)
{

  I3TriggerStatus myts; 

  map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig> & readoutconfig = 
    myts.GetReadoutSettings();

  I3TriggerReadoutConfig myreadout;
  myreadout.readoutTimeMinus = 5000.0*I3Units::ns;
  myreadout.readoutTimePlus = 6000.0*I3Units::ns;
  myreadout.readoutTimeOffset = -1000.0*I3Units::ns;

  readoutconfig[I3TriggerStatus::INICE] = myreadout;

 // Build a binary stringtream and serialize the I3TriggerStatus
        std::ostringstream oss(std::ostringstream::binary);
        {
                boost::archive::portable_binary_oarchive outAr( oss );
                outAr & make_nvp("Test", myts);;
        }
  
  // Deserialize a second I3DOMLaunch from the serialized stream for comparison
        I3TriggerStatus mydecode;
        std::istringstream iss( oss.str(), std::istringstream::binary );
        {
                boost::archive::portable_binary_iarchive inAr( iss );
                inAr & make_nvp("Test", mydecode);
        }



  const map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig> & testconfig = 
    mydecode.GetReadoutSettings();
  I3TriggerReadoutConfig mytest = testconfig.find(I3TriggerStatus::INICE)->second;
  
  ENSURE_DISTANCE(5000.0, mytest.readoutTimeMinus/I3Units::ns, 0.01,
		  "Readout configs do not match.");
  ENSURE_DISTANCE(6000.0, mytest.readoutTimePlus/I3Units::ns, 0.01,
		  "Readout configs do not match.");
  ENSURE_DISTANCE(-1000.0, mytest.readoutTimeOffset/I3Units::ns, 0.01,
		  "Readout configs do not match.");

}
