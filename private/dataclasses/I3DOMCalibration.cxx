//
//  $Id$
//
//
#include <dataclasses/BoostHeaders.h>
#include "dataclasses/I3DOMCalibration.h"
#include "dataclasses/I3Units.h"

const unsigned int I3DOMCalibration::N_ATWD_BINS = 128;

I3DOMCalibration::I3DOMCalibration()
    : 
      temperature_(NAN),
      fadcGain_(NAN), fadcPedestal_(NAN)
{};

void I3DOMCalibration::SetATWDBinParameters(unsigned int id, 
					    unsigned int channel, 
					    unsigned int bin,
					    double slope, 
					    double intercept, 
					    double regress_coeff)
{
    struct LinearFit fit;
    
    fit.slope = slope;
    fit.intercept = intercept;
    fit.regressCoeff = regress_coeff;
    
    GetATWDBinParameters(id)[channel][(N_ATWD_BINS-1)-bin] = fit;
}

void I3DOMCalibration::SetATWDFreqParameters(unsigned int chip, 
					     double slope, 
					     double intercept, 	
					     double regress_coeff)
{
    struct LinearFit fit;
    
    fit.slope = slope;
    fit.intercept = intercept;
    fit.regressCoeff = regress_coeff;
    atwdFreq_.insert(pair<int, LinearFit> (chip, fit));
}

void I3DOMCalibration::SetATWDBaselineParameters(unsigned int id, 
						 unsigned int channel,
						 double HV, 
						 double baseline)
{
    GetATWDBaselineParameters(id)[channel][HV] = baseline;
}

double I3DOMCalibration::GetATWDVoltage(unsigned int id,  
					unsigned int channel, 
					unsigned int bin, 
					double fe_pedestal,
					double pmtHV, 
					int count)
{
    if ( ! GetATWDBinParameters(id).count(channel) )
    {
	log_fatal("Invalid ATWD channel in I3DOMCalibration::GetATWDVoltage()");
    }

    if ( ! GetATWDBinParameters(id)[channel].count(bin) )
    {
	log_fatal("Invalid ATWD bin in I3DOMCalibration::GetATWDVoltage()");
    }
    
    struct LinearFit fit = GetATWDBinParameters(id)[channel][bin];
       
    double voltage = (fit.slope*count + fit.intercept);
    voltage = voltage - (fe_pedestal + GetATWDBaseline(id, channel, pmtHV));
    return voltage/GetATWDGain(channel);
}

double I3DOMCalibration::GetATWDCount(unsigned int id, 
				      unsigned int channel,
				      unsigned int bin,
				      double fe_pedestal,
				      double pmtHV,
				      double voltage)
{
    if ( ! GetATWDBinParameters(id).count(channel) )
    {
	log_fatal("Invalid ATWD channel in I3DOMCalibration::GetATWDCount()");
    }

    if ( ! GetATWDBinParameters(id)[channel].count(bin) )
    {
	log_fatal("Invalid ATWD bin in I3DOMCalibration::GetATWDCount()");
    }
    
    struct LinearFit fit = GetATWDBinParameters(id)[channel][bin];

    double count =  GetATWDGain(channel)*voltage;
    count += fe_pedestal + GetATWDBaseline(id, channel, pmtHV) - fit.intercept;
    return count/fit.slope;
}

double I3DOMCalibration::GetATWDBaseline(unsigned int id, 
					 unsigned int channel, 
					 double HV)
{
    if ( ! GetATWDBaselineParameters(id).count(channel) )
    {
	log_fatal("Invalid ATWD channel in I3DOMCalibration::GetATWDBaseline");
    }
 
    double baselineBelow;
    double baselineAbove;
    
    bool upperRangeFound = false;
    bool lowerRangeFound = false;

    double voltageBelow = 0.0;
    double voltageAbove = 0.0;

    for ( map<double,double>::iterator baselineIT = 
	      GetATWDBaselineParameters(id)[channel].begin();
	  baselineIT != 
	      GetATWDBaselineParameters(id)[channel].end();	
	  baselineIT++ )
    {
	double voltage = baselineIT->first;
	
	// If we're above the voltage in the
	// map that's the lower bound
	if ( HV > voltage )
	{
	    voltageBelow = voltage;
	    baselineBelow = baselineIT->second;
	    lowerRangeFound = true;
	}
	
	// If we're less than the voltage in
	// the map, that's the upper bound and
	// we don't want to go any further, so
	// we break
	if ( HV < voltage )
	{
	    voltageAbove = voltage;
	    baselineAbove = baselineIT->second;
	    upperRangeFound = true;
	    break;
	}		
    }
 
    // If neither an upper nor a lower range is found
    // then the HV value is invalid for these 
    // parameters and that's bad, so very bad.
    if ( ! lowerRangeFound  || ! upperRangeFound )
	log_fatal("HV out of range in I3DOMCalibration::GetATWDBaseline");
    
    double coeff = (HV-voltageBelow)/(voltageAbove-voltageBelow);
    return coeff*(baselineAbove-baselineBelow) + baselineBelow;
}

map<unsigned int,map<unsigned int,LinearFit> >& 
I3DOMCalibration::GetATWDBinParameters(unsigned int id)
{
    switch(id)
    {
    case 0:
	return atwdBin0_;
    case 1:
	return atwdBin1_;
    default:
      {
	log_fatal("Invalid ATWD Id in I3DOMCalibration::GetATWDBinParameters(Id)");
	return *static_cast<map<unsigned int,map<unsigned int,LinearFit> >*>(0);
      }
    }
}

map<unsigned int, map<double,double> >&
I3DOMCalibration::GetATWDBaselineParameters(unsigned int id)
{
    switch(id)
    {
    case 0:
	return atwdBaseline0_;
    case 1:
	return atwdBaseline1_;
    default:
	{
	    log_fatal("Invalid ATWD Id in I3DOMCalibration::GetATWDBaselineParameters(Id)");
	    return *static_cast<map<unsigned int,map<double,double> >*>(0);
	}
    }
}

void I3DOMCalibration::SetATWDGain(unsigned int channel, 
				   double gain, 
				   double gainErr)
{
    ampGains_.insert(pair<int,double> (channel, gain));
    ampGainErrs_.insert(pair<int,double> (channel, gainErr));
}

double I3DOMCalibration::GetATWDGain(unsigned int channel)
{
    if ( ! ampGains_.count(channel) )
    {
	log_fatal("Gain not found for ATWD channel in I3DOMCalibration");
    }
    
    return ampGains_[channel];
}

double I3DOMCalibration::GetATWDGainErr(unsigned int channel)
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
    ar & make_nvp("ampGains",ampGains_);
    ar & make_nvp("ampGainErrs",ampGainErrs_);
    ar & make_nvp("atwdFreq",atwdFreq_);
    ar & make_nvp("atwd0BinParameters",atwdBin0_);
    ar & make_nvp("atwd1BinParameters",atwdBin1_);
    ar & make_nvp("atwd0BaselineParameters",atwdBaseline0_);
    ar & make_nvp("atwd1BaselineParameters",atwdBaseline1_);
    ar & make_nvp("chargeHistograms",chargeHistograms_);
}

I3_SERIALIZABLE(I3DOMCalibration);


