//
//  $Id$
//
//
#include <icetray/serialization.h>
#include <dataclasses/calibration/I3DOMCalibration.h>
#include <dataclasses/I3Units.h>

I3DOMCalibration::~I3DOMCalibration() { } 

I3DOMCalibration::I3DOMCalibration()
  : temperature_(NAN),
    fadcGain_(NAN),
    fadcDeltaT_(NAN),
    frontEndImpedance_(NAN),
    domcalVersion_("unknown")
{ }

/**
   Little convenience function that gets something out of a const map
   and throws on failure.
*/
template <typename K, typename V>
static 
const V& 
at (const map<K, V>& a_map, const K& key) 
{
  typename map<K, V>::const_iterator iter = a_map.find(key);
  if (iter == a_map.end())
    log_fatal("Failure to find key in map.  I know this error message is vague.");
  return iter->second;
}

/**
 * @todo  should put some checks on the channel, bin.  Make sure they are legit
 */
const LinearFit& 
I3DOMCalibration::GetATWDBinCalibFit (unsigned int id, 
				      unsigned int channel, 
				      unsigned int bin) const 

{
  if(channel<N_ATWD_CHANNELS&&bin<N_ATWD_BINS)
    {
      // do these one at a time, one per line, so you can see wtf is
      // happening.
      const ATWDBinParam_t& atwd = GetATWDBinParameters(id);
      const map<unsigned, LinearFit>& fitmap = at(atwd, channel);
      const LinearFit& fit = at(fitmap, bin);
      return fit;
    }
  else
    {
      log_fatal("No ATWD bin calibration for requested bin %ui channel %ui",
		bin,channel);
    }
}

void 
I3DOMCalibration::SetATWDBinCalibFit (unsigned int id, 
				      unsigned int channel, 
				      unsigned int bin,
				      LinearFit fitParams)
{
  GetATWDBinParameters(id)[channel][(N_ATWD_BINS-1)-bin] = fitParams;
}


QuadraticFit 
I3DOMCalibration::GetATWDFreqFit (unsigned int chip) const
{
  map<unsigned int, QuadraticFit>::const_iterator iter = atwdFreq_.find(chip);
  if ( iter == atwdFreq_.end() )
    {
      log_fatal("Frequency calib not found for ATWD chip in I3DOMCalibration");
    }
  return  iter->second;    
}

void 
I3DOMCalibration::SetATWDFreqFit (unsigned int chip, 
				  QuadraticFit fitParams)
{
  atwdFreq_[chip] = fitParams;
}

const map<unsigned int,map<unsigned int,LinearFit> >& 
I3DOMCalibration::GetATWDBinParameters (unsigned int id) const
{
  switch(id)
    {
    case 0:
      return atwdBin0_;
    case 1:
      return atwdBin1_;
    default:
      log_fatal("Invalid ATWD Id in I3DOMCalibration::GetATWDBinParameters(Id)");
    }
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
      log_fatal("Invalid ATWD Id in I3DOMCalibration::GetATWDBinParameters(Id)");
    }
}


void 
I3DOMCalibration::SetATWDGain (unsigned int channel, 
			       double gain) 
{
  ampGains_[channel]=gain;
}

double 
I3DOMCalibration::GetATWDGain (unsigned int channel) const
{
  map<unsigned int, double>::const_iterator iter = ampGains_.find(channel);

  if ( iter == ampGains_.end() )
    log_fatal("Gain not found for ATWD channel in I3DOMCalibration");
  
  return iter->second;      
}

//
// these are some beeeeautiful serialization functions.
//
template <class Archive>
void 
LinearFit::serialize(Archive& ar, unsigned version)
{
  if (version>i3domcalibration_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3DOMCalibration class.",version,i3domcalibration_version_);

  ar & make_nvp("slope",slope);
  ar & make_nvp("intercept",intercept);
}

I3_SERIALIZABLE(LinearFit);

template <class Archive>
void 
QuadraticFit::serialize(Archive& ar, unsigned version)
{
  if (version>i3domcalibration_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3DOMCalibration class.",version,i3domcalibration_version_);

  ar & make_nvp("quadraticA",quadFitA);
  ar & make_nvp("quadraticB",quadFitB);
  ar & make_nvp("quadraticC",quadFitC);
}

I3_SERIALIZABLE(QuadraticFit);


template <class Archive>
void 
I3DOMCalibration::serialize(Archive& ar, unsigned version)
{
  if (version>i3domcalibration_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3DOMCalibration class.",version,i3domcalibration_version_);

  ar & make_nvp("temperature",temperature_);
  ar & make_nvp("fadcGain",fadcGain_);
  ar & make_nvp("fadcBaseline",fadcBaselineFit_);

  if(version > 0)
  {
    ar & make_nvp("fadcDeltaT", fadcDeltaT_);
  }
  ar & make_nvp("ampGains",ampGains_);
  ar & make_nvp("atwdFreq",atwdFreq_);
  ar & make_nvp("atwd0BinParameters",atwdBin0_);
  ar & make_nvp("atwd1BinParameters",atwdBin1_);
  ar & make_nvp("pmtTransitTime",pmtTransitTime_);
  ar & make_nvp("hvGainRelation",hvGainRelation_);
  if(version > 1)
  {
    ar & make_nvp("frontEndImpedance", frontEndImpedance_);
  }

  if (version > 1)
    {
      ar & make_nvp("domcalVersion", domcalVersion_);
    }
  if (version > 2)
    {
      ar & make_nvp("tauparameters", tauparameters_);
      
    }
  
}

I3_SERIALIZABLE(I3DOMCalibration);

