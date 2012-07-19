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



  const map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig>& testconfig = 
    mydecode.GetReadoutSettings();
  I3TriggerReadoutConfig mytest = testconfig.find(I3TriggerStatus::INICE)->second;
  
  ENSURE_DISTANCE(5000.0, mytest.readoutTimeMinus/I3Units::ns, 0.01,
		  "Readout configs do not match.");
  ENSURE_DISTANCE(6000.0, mytest.readoutTimePlus/I3Units::ns, 0.01,
		  "Readout configs do not match.");
  ENSURE_DISTANCE(-1000.0, mytest.readoutTimeOffset/I3Units::ns, 0.01,
		  "Readout configs do not match.");

}

TEST(TriggerStatusSettingsTest)
{

  I3TriggerStatus myts; 

  std::string good_int_key("good_int");
  int int_value(42);  
  myts.SetTriggerConfigValue(good_int_key,int_value);

  int int_test_value(INT_MAX);
  myts.GetTriggerConfigValue(good_int_key, int_test_value);
  ENSURE( int_value == int_test_value,"Get/Set not working properly for ints." );

  std::string good_float_key("good_float");
  float float_value(0.5);
  myts.SetTriggerConfigValue(good_float_key, float_value);

  float float_test_value(NAN);
  myts.GetTriggerConfigValue(good_float_key, float_test_value);
  ENSURE_DISTANCE( float_value, float_test_value, 1e-9,
		   "Get/Set not working properly for floats." );

}

TEST(WellFormedFloats)
{

  // this first group are going to be
  // the  most common forms
  ENSURE( WellFormedFloat("+0.5") );
  ENSURE( WellFormedFloat("0.5") );
  ENSURE( WellFormedFloat("-0.5") );
  ENSURE( WellFormedFloat("+.5") );
  ENSURE( WellFormedFloat(".5") );
  ENSURE( WellFormedFloat("-.5") );
  ENSURE( WellFormedFloat("+0.5") );
  ENSURE( WellFormedFloat("+5") );
  ENSURE( WellFormedFloat("5") );
  ENSURE( WellFormedFloat("-5") );

  // we might see some exponential forms
  ENSURE( WellFormedFloat("0.5e10") );
  ENSURE( WellFormedFloat("0.5e-10") );
  ENSURE( WellFormedFloat("0.5E10") );
  ENSURE( WellFormedFloat("0.5E-10") );
  ENSURE( WellFormedFloat("0.5e0.1") );
  ENSURE( WellFormedFloat("0.5E0.1") );

  ENSURE( WellFormedFloat("-0.5e0.1") );
  ENSURE( WellFormedFloat("-0.5E0.1") );
  ENSURE( WellFormedFloat("+0.5e0.1") );
  ENSURE( WellFormedFloat("+0.5E0.1") );

  ENSURE( WellFormedFloat("-0.5e-0.1") );
  ENSURE( WellFormedFloat("-0.5E-0.1") );
  ENSURE( WellFormedFloat("+0.5e-0.1") );
  ENSURE( WellFormedFloat("+0.5E-0.1") );

  ENSURE( WellFormedFloat("-0.5e+0.1") );
  ENSURE( WellFormedFloat("-0.5E+0.1") );
  ENSURE( WellFormedFloat("+0.5e+0.1") );
  ENSURE( WellFormedFloat("+0.5E+0.1") );

  // Test that pathological inputs correctly
  // return false
  ENSURE( !WellFormedFloat("+0.5E+.0.1") );
  ENSURE( !WellFormedFloat("+e0.5E+0.1") );
  // replace 'zero' with the letter 'O'
  ENSURE( !WellFormedFloat("O.5") );

  ENSURE( !WellFormedFloat("+-0.5e+0.1") );
  ENSURE( !WellFormedFloat("--0.5E+0.1") );
  ENSURE( !WellFormedFloat("-+0.5e+0.1") );
  ENSURE( !WellFormedFloat("++0.5E+0.1") );

}

TEST(SettingsFromString)
{

  I3TriggerStatus myts; 

  myts.SetTriggerConfigValue("good_float","0.5");
  myts.SetTriggerConfigValue("good_exp_float","3.14e-3");
  myts.SetTriggerConfigValue("good_Exp_float","3.14E-3");
  myts.SetTriggerConfigValue("good_int","10");
  myts.SetTriggerConfigValue("good_negative_int","-10");

  myts.SetTriggerConfigValue("bad_float","e-1.0");
  myts.SetTriggerConfigValue("bad_int","0.5");

  float float_value(NAN);

  myts.GetTriggerConfigValue("good_float", float_value);  
  ENSURE_DISTANCE( float_value, 0.5, 1e-9 );

  myts.GetTriggerConfigValue("good_exp_float", float_value);  
  ENSURE_DISTANCE( float_value, 3.14e-3, 1e-9 );

  myts.GetTriggerConfigValue("good_Exp_float", float_value);  
  ENSURE_DISTANCE( float_value, 3.14e-3, 1e-9 );

  myts.GetTriggerConfigValue("bad_float", float_value);
  ENSURE( isnan( float_value ) );

  int int_value(INT_MAX);
  myts.GetTriggerConfigValue("good_int", int_value);
  ENSURE( int_value == 10 );

  myts.GetTriggerConfigValue("good_negative_int", int_value);
  ENSURE( int_value == -10 );

  myts.GetTriggerConfigValue("bad_int", int_value);
  ENSURE( int_value == INT_MIN );
  
  myts.GetTriggerConfigValue("good_float", int_value);
  ENSURE( int_value == INT_MIN );

  myts.GetTriggerConfigValue("bad_float", int_value);
  ENSURE( int_value == INT_MIN );
  
}
