//
//  $Id$
//
//
#include <dataclasses/BoostHeaders.h>
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

/*
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
   
    return (count*fit.slope)/GetATWDGain(channel);
}
*/
/*
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
*/

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
	log_fatal("Invalid ATWD channel in I3DOMCalibration::GetATWDVoltage()");
    }

    if ( ! GetATWDById(id)[channel].count(bin) )
    {
	log_fatal("Invalid ATWD bin in I3DOMCalibration::GetATWDVoltage()");
    }
    
    struct LinearFit fit = GetATWDById(id)[channel][bin];
       
    return ((fit.slope*count + fit.intercept) - fe_pedestal) / GetATWDGain(channel);
}

double I3DOMCalibration::GetATWDCount(int id, 
				      int channel,
				      int bin,
				      double fe_pedestal,
				      double voltage)
{
    if ( ! GetATWDById(id).count(channel) )
    {
	log_fatal("Invalid ATWD channel in I3DOMCalibration::GetATWDCount()");
    }

    if ( ! GetATWDById(id)[channel].count(bin) )
    {
	log_fatal("Invalid ATWD bin in I3DOMCalibration::GetATWDCount()");
    }
    
    struct LinearFit fit = GetATWDById(id)[channel][bin];

    // NOTE: check units!

    return (GetATWDGain(channel)*voltage - (fit.intercept - fe_pedestal))/ fit.slope;
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


template <class Archive>
void 
LinearFit::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("slope",slope);
  ar & make_nvp("intercept",intercept);
  ar & make_nvp("regressCoeff",regressCoeff);
}

I3_SERIALIZABLE(LinearFit);

template <class Archive>
void 
ChargeHistogramEntry::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("charge",charge);
  ar & make_nvp("count",count);
}

I3_SERIALIZABLE(ChargeHistogramEntry);

template <class Archive>
void 
ChargeHistogram::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("exponentialAmplitude",exponentialAmplitude);
  ar & make_nvp("exponentialWidth",exponentialWidth);
  ar & make_nvp("gaussianAmplitude",gaussianAmplitude);
  ar & make_nvp("gaussianAmplitude",gaussianAmplitude);
  ar & make_nvp("gaussianMean",gaussianMean);
  ar & make_nvp("gaussianWidth",gaussianWidth);
  ar & make_nvp("voltage",voltage);
  ar & make_nvp("convergent",convergent);
  ar & make_nvp("peakToValley",peakToValley);
  ar & make_nvp("noiseRate",noiseRate);
  ar & make_nvp("entries",entries);
}

I3_SERIALIZABLE(ChargeHistogram);

template <class Archive>
void 
I3DOMCalibration::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("mainboardId",mainboardId_);
  ar & make_nvp("temperature",temperature_);
  ar & make_nvp("fadcGain",fadcGain_);
  ar & make_nvp("fadcPedestal",fadcPedestal_);
  ar & make_nvp("pedestalVoltage",pedestalVoltage_);
  ar & make_nvp("ampGains",ampGains_);
  ar & make_nvp("ampGainErrs",ampGainErrs_);
  ar & make_nvp("atwdFreq",atwdFreq_);
  ar & make_nvp("atwd0",atwd0_);
  ar & make_nvp("atwd1",atwd1_);
  ar & make_nvp("chargeHistograms",chargeHistograms_);
}

I3_SERIALIZABLE(I3DOMCalibration);


