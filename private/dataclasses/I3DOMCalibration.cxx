//
//  $Id: I3DOMCalibration.cxx,v 1.12 2005/04/12 18:55:28 dule Exp $
//
//
#include "dataclasses/I3DOMCalibration.h"

ClassImp(I3DOMCalibration);

I3DOMCalibration::I3DOMCalibration()
    : date_(NAN), DOMId_(0), temperature_(NAN),
      FADCGain_(NAN), FADCPedestal_(NAN),
      PMTHighVoltage_(NAN), pedestalVoltage_(NAN),
      peakToValley_(NAN), SPEMean_(NAN), SPEWidth_(NAN),
      samplingRate0_(NAN), samplingRate1_(NAN)
{};

void I3DOMCalibration::SetCalibrationConstants()
{};

void I3DOMCalibration::SetATWDParameters(int id, int channel, int bin,
					 double slope, double intercept, double regress_coeff)
{
    struct LinearFit fit;
    
    fit.slope_ = slope;
    fit.intercept_ = intercept;
    fit.regressCoeff_ = regress_coeff;
    
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
       
    return ((fit.slope_*count + fit.intercept_) - pedestalVoltage_) / GetATWDGain(channel);
}

map<int,map<int,LinearFit> >& 
I3DOMCalibration::GetATWDById(int id)
{
    switch(id)
    {
    case 0:
		 return ATWD0_;
    case 1:
		 return ATWD1_;
    default:
      {
			log_fatal("Invalid ATWD Id in I3DOMCalibration");
			return *static_cast<map<int,map<int,LinearFit> >*>(0);
      }
    }
    
}


void I3DOMCalibration::SetATWDGain(int channel, double gain, double gainErr)
{
    ampGains_.insert(pair<int,double> (channel, gain));
    ampGainErrs_.insert(pair<int,double> (channel, gainErr));
}

double I3DOMCalibration::GetATWDGain(int channel)
{
    if ( ! ampGains_.count(channel) )
    {
	log_fatal("Gain not found for ATWD channel in I3DOMCalibration");
    }
    
    return ampGains_[channel];
}

double I3DOMCalibration::GetATWDGainErr(int channel)
{
    if ( ! ampGainErrs_.count(channel) )
    {
	log_fatal("Gain error not found for ATWD channel in I3DOMCalibration");
    }
    
    return ampGainErrs_[channel];
}

void I3DOMCalibration::SetSamplingRate(int id, double rate)
{
    switch(id)
    {
    case 0:
		 samplingRate0_ = rate;
		 break;
    case 1:
		 samplingRate1_ = rate;
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
		 return samplingRate0_;
    case 1:
		 return samplingRate1_;
    default:	
		 log_fatal("Sampling rate not found for ATWD ID in I3DOMCalibration");
    }
    return 0;
}

