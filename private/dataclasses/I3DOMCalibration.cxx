//
//  $Id: I3DOMCalibration.cxx,v 1.7 2004/12/01 22:40:57 tmccauley Exp $
//
//
#include "dataclasses/I3DOMCalibration.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3DOMCalibration);

I3DOMCalibration::I3DOMCalibration()
    : fDate(NAN), fDOMId(0), fTemperature(NAN),
      fFADCGain(NAN), fFADCPedestal(NAN),
      fPMTHighVoltage(NAN), fPedestalVoltage(NAN),
      fSamplingRate0(NAN), fSamplingRate1(NAN),
      fPeakToValley(NAN), fSPEMean(NAN), fSPEWidth(NAN)
{};

void I3DOMCalibration::SetCalibrationConstants()
{};

void I3DOMCalibration::SetATWDParameters(Int_t id, Int_t channel, Int_t bin,
					 Double_t slope, Double_t intercept, Double_t regress_coeff)
{
    struct LinearFit fit;
    
    fit.fSlope = slope;
    fit.fIntercept = intercept;
    fit.fRegressCoeff = regress_coeff;
    
    GetATWDById(id)[channel][bin] = fit;
}

Double_t I3DOMCalibration::GetATWDVoltage(Int_t id,  Int_t channel, 
					  Int_t bin, Int_t count)
{
    if ( ! GetATWDById(id).count(channel) )
    {
	I3DataExecution::Instance().Fatal("Invalid ATWD channel in I3DOMCalibration");
    }

    if ( ! GetATWDById(id)[channel].count(bin) )
    {
	I3DataExecution::Instance().Fatal("Invalid ATWD bin in I3DOMCalibration");
    }
    
    struct LinearFit fit = GetATWDById(id)[channel][bin];
       
    return ((fit.fSlope*count + fit.fIntercept) - fPedestalVoltage) / GetATWDGain(channel);
}

map<Int_t,map<Int_t,LinearFit> >& 
I3DOMCalibration::GetATWDById(Int_t id)
{
    switch(id)
    {
    case 0:
	return fATWD0;
    case 1:
	return fATWD1;
    default:
      {
	I3DataExecution::Instance().Fatal("Invalid ATWD Id in I3DOMCalibration");
	return *static_cast<map<Int_t,map<Int_t,LinearFit> >*>(0);
      }
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

void I3DOMCalibration::SetSamplingRate(Int_t id, Double_t rate)
{
    switch(id)
    {
    case 0:
	fSamplingRate0 = rate;
	break;
    case 1:
	fSamplingRate1 = rate;
	break;
    default:
	I3DataExecution::Instance().Fatal("Invalid ATWD Id in I3DOMCalibration");
    }
}

Double_t I3DOMCalibration::GetSamplingRate(Int_t id)
{
    switch(id)
    {
    case 0:
	return fSamplingRate0;
    case 1:
	return fSamplingRate1;
    default:	
	I3DataExecution::Instance().Fatal("Sampling rate not found for ATWD ID in I3DOMCalibration");
    }
    return 0;
}

