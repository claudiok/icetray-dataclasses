//
//  $Id$
//
//
#include "dataclasses/I3DOMCalibration.h"

I3DOMCalibration::I3DOMCalibration()
    : 
      temperature_(NAN),
      fadcGain_(NAN), fadcPedestal_(NAN)
{};

void I3DOMCalibration::SetATWDParameters(int id, int channel, int bin,
					 double slope, double intercept, double regress_coeff)
{
    struct LinearFit fit;
    
    fit.slope = slope;
    fit.intercept = intercept;
    fit.regressCoeff = regress_coeff;
    
    GetATWDById(id)[channel][127-bin] = fit;
}


double I3DOMCalibration::GetPedestalSubtractedVoltage(int id,  int channel, 
						      int bin, double fe_pedestal,
						      int count)
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
   
    return (count*fit.slope + fit.intercept)/GetATWDGain(channel);
}


int I3DOMCalibration::GetPedestalSubtractedCount(int id,  int channel, 
						 int bin, double fe_pedestal,
						 int count)

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
       
    return count-(int)((fe_pedestal- fit.intercept)/fit.slope);
}


void I3DOMCalibration::SetATWDFreqParameters(int chip,
					 double slope, double intercept, double regress_coeff)
{
    struct LinearFit fit;
    
    fit.slope = slope;
    fit.intercept = intercept;
    fit.regressCoeff = regress_coeff;
    atwdFreq_.insert(pair<int, LinearFit> (chip, fit));
}

double I3DOMCalibration::GetATWDVoltage(int id,  int channel, 
					int bin, double fe_pedestal,
					int count)
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
       
    return ((fit.slope*count + fit.intercept) - fe_pedestal) / GetATWDGain(channel);
}

map<int,map<int,LinearFit> >& 
I3DOMCalibration::GetATWDById(int id)
{
    switch(id)
    {
    case 0:
	return atwd0_;
    case 1:
	return atwd1_;
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


