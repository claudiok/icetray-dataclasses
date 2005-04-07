//
//  $Id: I3DOMCalibration.cxx,v 1.11 2005/04/07 18:25:06 olivas Exp $
//
//
#include "dataclasses/I3DOMCalibration.h"

ClassImp(I3DOMCalibration);

I3DOMCalibration::I3DOMCalibration()
    : fDate(NAN), fDOMId(0), fTemperature(NAN),
      fFADCGain(NAN), fFADCPedestal(NAN),
      fPMTHighVoltage(NAN), fPedestalVoltage(NAN),
      fPeakToValley(NAN), fSPEMean(NAN), fSPEWidth(NAN),
      fSamplingRate0(NAN), fSamplingRate1(NAN)
{};

void I3DOMCalibration::SetCalibrationConstants()
{};

void I3DOMCalibration::SetATWDParameters(int id, int channel, int bin,
					 double slope, double intercept, double regress_coeff)
{
    struct LinearFit fit;
    
    fit.fSlope = slope;
    fit.fIntercept = intercept;
    fit.fRegressCoeff = regress_coeff;
    
    GetATWDById(id)[channel][127-bin] = fit;
}

double I3DOMCalibration::GetATWDVoltage(int id,  int channel, 
					  int bin, int count)
{
    if ( ! GetATWDById(id).count(channel) )
    {
	log_fatal("Invalid ATWD channel in I3DOMCalibration");
    }

    if ( ! GetATWDById(id)[channel].count(bin) )
    {
	log_fatal("Invalid ATWD bin in I3DOMCalibration");
    }
    
    struct LinearFit fit = GetATWDById(id)[channel][bin];
       
    return ((fit.fSlope*count + fit.fIntercept) - fPedestalVoltage) / GetATWDGain(channel);
}

map<int,map<int,LinearFit> >& 
I3DOMCalibration::GetATWDById(int id)
{
    switch(id)
    {
    case 0:
	return fATWD0;
    case 1:
	return fATWD1;
    default:
      {
	log_fatal("Invalid ATWD Id in I3DOMCalibration");
	return *static_cast<map<int,map<int,LinearFit> >*>(0);
      }
    }
    
}


void I3DOMCalibration::SetATWDGain(int channel, double gain, double gainErr)
{
    fAmpGains.insert(pair<int,double> (channel, gain));
    fAmpGainErrs.insert(pair<int,double> (channel, gainErr));
}

double I3DOMCalibration::GetATWDGain(int channel)
{
    if ( ! fAmpGains.count(channel) )
    {
	log_fatal("Gain not found for ATWD channel in I3DOMCalibration");
    }
    
    return fAmpGains[channel];
}

double I3DOMCalibration::GetATWDGainErr(int channel)
{
    if ( ! fAmpGainErrs.count(channel) )
    {
	log_fatal("Gain error not found for ATWD channel in I3DOMCalibration");
    }
    
    return fAmpGainErrs[channel];
}

void I3DOMCalibration::SetSamplingRate(int id, double rate)
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
	log_fatal("Invalid ATWD Id in I3DOMCalibration");
    }
}

double I3DOMCalibration::GetSamplingRate(int id)
{
    switch(id)
    {
    case 0:
	return fSamplingRate0;
    case 1:
	return fSamplingRate1;
    default:	
	log_fatal("Sampling rate not found for ATWD ID in I3DOMCalibration");
    }
    return 0;
}

