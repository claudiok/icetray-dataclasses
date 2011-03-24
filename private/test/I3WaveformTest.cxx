/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3WaveformTest.cxx 9281 2005-06-19 17:06:10Z tschmidt $

    @version $Revision: 1.3 $
    @date $Date: 2005-06-19 19:06:10 +0200 (Sun, 19 Jun 2005) $
    @author tschmidt
*/

#include <I3Test.h>

#include <dataclasses/physics/I3Waveform.h>


using namespace std;


TEST_GROUP(I3WaveformTest);


TEST(GetStatusFromWaveformInformation)
{
  vector<I3Waveform::StatusCompound> waveformInfo;
  I3Waveform::StatusCompound virginal;
  I3Waveform::StatusCompound shady;
  I3Waveform::StatusCompound adulterated;
  I3Waveform::StatusCompound undershot;
  
  virginal.SetStatus(I3Waveform::VIRGINAL);
  shady.SetStatus(I3Waveform::COMBINED);
  adulterated.SetStatus(I3Waveform::SATURATED);
  undershot.SetStatus(I3Waveform::UNDERSHOT);
  
  ENSURE_EQUAL(I3Waveform::GetStatus(waveformInfo), (unsigned)I3Waveform::VIRGINAL);
  
  waveformInfo.push_back(virginal);
  ENSURE_EQUAL(I3Waveform::GetStatus(waveformInfo), (unsigned)I3Waveform::VIRGINAL);
  
  waveformInfo.push_back(shady);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::COMBINED);
  ENSURE(!(I3Waveform::GetStatus(waveformInfo) & I3Waveform::SATURATED));
  ENSURE(!(I3Waveform::GetStatus(waveformInfo) & I3Waveform::UNDERSHOT));
  
  waveformInfo.push_back(virginal);
  ENSURE_EQUAL(I3Waveform::GetStatus(waveformInfo), (unsigned)I3Waveform::COMBINED);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::COMBINED);
  ENSURE(!(I3Waveform::GetStatus(waveformInfo) & I3Waveform::SATURATED));
  ENSURE(!(I3Waveform::GetStatus(waveformInfo) & I3Waveform::UNDERSHOT));
  
  waveformInfo.push_back(adulterated);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::COMBINED);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::SATURATED);
  ENSURE(!(I3Waveform::GetStatus(waveformInfo) & I3Waveform::UNDERSHOT));
  
  waveformInfo.push_back(shady);
  waveformInfo.push_back(virginal);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::COMBINED);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::SATURATED);
  ENSURE(!(I3Waveform::GetStatus(waveformInfo) & I3Waveform::UNDERSHOT));

  waveformInfo.push_back(undershot);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::COMBINED);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::SATURATED);
  ENSURE(I3Waveform::GetStatus(waveformInfo) & I3Waveform::UNDERSHOT);

  waveformInfo.clear();
  waveformInfo.push_back(shady);
  waveformInfo.push_back(shady);  
  ENSURE_EQUAL(I3Waveform::GetStatus(waveformInfo), (unsigned)I3Waveform::COMBINED);
}
