#include "dataclasses/I3DOMCalibration.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3DOMCalibration);

I3DOMCalibration::I3DOMCalibration()
    : fDate(0.0), fDOMId(0), fTemperature(0.0),
      fFADCGain(0.0), fFADCPedestal(0.0)
{};

void I3DOMCalibration::SetCalibrationConstants()
{};

void I3DOMCalibration::SetATWDParameters(Int_t id, 
					 Int_t channel,
					 Int_t bin,
					 Double_t val)
{
    GetATWDById(id)[channel][bin] = val;
}

void I3DOMCalibration::SetATWDParameters(Int_t id, Int_t channel,
					 map<Int_t,Double_t>& countMap)
{}

Double_t I3DOMCalibration::GetATWDVoltage(Int_t id, Int_t channel, 
					  Int_t bin, Double_t count)
{
    if ( ! GetATWDById(id).count(channel) )
    {
	I3DataExecution::Instance().Fatal("Invalid ATWD channel in I3DOMCalibration");
    }

    if ( ! GetATWDById(id)[channel].count(bin) )
    {
	I3DataExecution::Instance().Fatal("Invalid ATWD bin in I3DOMCalibration");
    }
    
    return GetATWDById(id)[channel][bin];
}

map<Int_t, Double_t>& I3DOMCalibration::GetATWDVoltage(Int_t id, Int_t channel)
{}

map<Int_t,map<Int_t,Double_t> >& 
I3DOMCalibration::GetATWDById(Int_t id)
{
    if ( id == 0 )
    {
	return fATWD0;
    }
    
    if ( id == 1 )
    {
	return fATWD1;
    }
    
     else 
    {
	I3DataExecution::Instance().Fatal("Invalid ATWD Id in I3DOMCalibration");
    }
}


void I3DOMCalibration::SetATWDGain(Int_t channel, Double_t gain, Double_t gainErr)
{
    fAmpGains.insert(pair<Int_t,Double_t> (channel, gain));
    fAmpGainErrs.insert(pair<Int_t,Double_t> (channel, gainErr));
}

Double_t I3DOMCalibration::GetATWDGain(Int_t channel)
{
    if ( ! fAmpGains.count(channel) )
    {
	I3DataExecution::Instance().Fatal("Gain not found for ATWD channel in I3DOMCalibration");
    }
    
    return fAmpGains[channel];
}

Double_t I3DOMCalibration::GetATWDGainErr(Int_t channel)
{
    if ( ! fAmpGainErrs.count(channel) )
    {
	I3DataExecution::Instance().Fatal("Gain error not found for ATWD channel in I3DOMCalibration");
    }
    
    return fAmpGainErrs[channel];
}

