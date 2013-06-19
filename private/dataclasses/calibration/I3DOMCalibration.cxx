
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
    domcalVersion_("unknown"), 
    atwdResponseWidth_(NAN),
    fadcResponseWidth_(NAN),
    relativeDomEff_(NAN),
    noiseRate_(NAN)
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
      switch(id)
	{
	case 0:
	  {
	    const LinearFit& fit = atwdBin0_[channel][bin];
	    return fit;
	  }
	case 1:
	  {
	    const LinearFit& fit = atwdBin1_[channel][bin];
	    return fit;
	  }
	default:
	  log_fatal("Invalid ATWD Id in I3DOMCalibration::SetATWDBinCalibFit");
	}
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
  switch(id)
    {
    case 0:
      atwdBin0_[channel][(N_ATWD_BINS-1)-bin] = fitParams;
      return;
    case 1:
      atwdBin1_[channel][(N_ATWD_BINS-1)-bin] = fitParams;
      return;
    default:
      log_fatal("Invalid ATWD Id in I3DOMCalibration::SetATWDBinCalibFit");
    }
}


QuadraticFit 
I3DOMCalibration::GetATWDFreqFit (unsigned int chip) const
{
  //map<unsigned int, QuadraticFit>::const_iterator iter = atwdFreq_.find(chip);
  
  if(chip == 0 || chip ==1 )
    {
      return atwdFreq_[chip];
    }
  else
    {
      log_fatal("Frequency calib not found for ATWD chip in I3DOMCalibration");
    }
}

void 
I3DOMCalibration::SetATWDFreqFit (unsigned int chip, 
				  QuadraticFit fitParams)
{
  if(chip == 0 || chip ==1 )
    {
      atwdFreq_[chip] = fitParams;
    }
  else
    {
      log_fatal("Invalid chip specified in I3DOMCalibration::SetATWDFreqFit");
    }
}

void 
I3DOMCalibration::SetATWDGain (unsigned int channel, 
			       double gain) 
{
  if(channel == 0 || channel == 1 || channel == 2)
    {
      ampGains_[channel]=gain;
    }
  else
    {
      log_fatal("Invalid channel specified in I3DOMCalibration::SetATWDGain");
    }
}

double 
I3DOMCalibration::GetATWDGain (unsigned int channel) const
{
  if(channel == 0 || channel == 1 || channel == 2)
    {
      return ampGains_[channel];
    }
  else
    {
      log_fatal("Invalid ATWD channel requested I3DOMCalibration::GetATWDGain");
    }
}

void 
I3DOMCalibration::SetATWDDeltaT (unsigned int chip, 
			       double deltat) 
{
  if(chip == 0 || chip == 1)
    {
      atwdDeltaT_[chip]=deltat;
    }
  else
    {
      log_fatal("Invalid chip id specified in I3DOMCalibration::SetATWDDeltaT");
    }
}

double 
I3DOMCalibration::GetATWDDeltaT (unsigned int chip) const
{
  if(chip == 0 || chip == 1)
    {
      return atwdDeltaT_[chip];
    }
  else
    {
      log_fatal("Invalid chip id requested I3DOMCalibration::GetATWDDeltaT");
    }
}

double I3DOMCalibration::GetATWDBaseline(unsigned int id,	
		       unsigned int channel,
		       unsigned int bin) const
{
  //apply some bounds checks
  if( (id == 0 || id ==1) && 
      ( channel == 0 || channel == 1 || channel == 2) &&
      ( bin>=0 && bin <128) )
    {
      return atwdBaselines_[id][channel][bin];
    }
  else
    {
      log_fatal("Invalid id, channel, bin specified for GetATWDBaseline");
    }
}

void I3DOMCalibration::SetATWDBaseline(unsigned int id,
		       unsigned int channel,
		       unsigned int bin,
		       double baseval)
{
  if( (id == 0 || id ==1) && 
      ( channel == 0 || channel == 1 || channel == 2) &&
      ( bin>=0 && bin <128) )
    {
      // Don't forget the domcal information is stored in correct time
      //   ordering (reversed in domcal raw data)
      atwdBaselines_[id][channel][(N_ATWD_BINS-1)-bin] = baseval;
    }
  else
    {
      log_fatal("Invalid id, channel, bin specified for SetATWDBaseline");
    }
}

//
// these are some beeeeautiful serialization functions.
//
template <class Archive>
void 
LinearFit::serialize(Archive& ar, unsigned version)
{
  if (version>linearfit_version_)
    log_fatal("Attempting to read version %u from file but running version %u of LinearFit class.",version,linearfit_version_);

  ar & make_nvp("slope",slope);
  ar & make_nvp("intercept",intercept);
}

I3_SERIALIZABLE(LinearFit);

template <class Archive>
void 
QuadraticFit::serialize(Archive& ar, unsigned version)
{
  if (version>quadraticfit_version_)
    log_fatal("Attempting to read version %u from file but running version %u of QuadraticFit class.",version,quadraticfit_version_);

  ar & make_nvp("quadraticA",quadFitA);
  ar & make_nvp("quadraticB",quadFitB);
  ar & make_nvp("quadraticC",quadFitC);
}

I3_SERIALIZABLE(QuadraticFit);

template <class Archive>
void 
TauParam::serialize(Archive& ar, unsigned version)
{
  if (version>tauparam_version_)

    log_fatal("Attempting to read version %u from file but running version %u of TuaParam class.",version,tauparam_version_);

  ar & make_nvp("P0",P0);
  ar & make_nvp("P1",P1);
  ar & make_nvp("P2",P2);
  ar & make_nvp("P3",P3);
  ar & make_nvp("P4",P4);
  ar & make_nvp("P5",P5);
  ar & make_nvp("TauFrac",TauFrac);
}

I3_SERIALIZABLE(TauParam);


template <class Archive>
void 
I3DOMCalibration::serialize(Archive& ar, unsigned version)
{
  if (version>10)
    log_fatal("Attempting to read version %u from file but running version %u of I3DOMCalibration class.",version,i3domcalibration_version_);
  ar & make_nvp("temperature",temperature_);
  ar & make_nvp("fadcGain",fadcGain_);
  ar & make_nvp("fadcBaseline",fadcBaselineFit_);

  if(version > 0)
  {
    ar & make_nvp("fadcDeltaT", fadcDeltaT_);
  }
  if(version < 4)
    {
      //In this case, we need to convert the old map<> struct to simple array
      map<unsigned int, double> ampGains_temp;
      ar & make_nvp("ampGains",ampGains_temp);
      map<unsigned int, double>::iterator iter = ampGains_temp.begin();
      while(iter != ampGains_temp.end())
	{
	  if(iter->first < 3)
	    {
	      ampGains_[iter->first] = iter->second;
	    }
	  else
	    {
	      log_fatal("Invalid channel for ampGains in I3DOMCalibration::serialize");
	    }
          iter++;
	}
    }
  else
    {
      ar & make_nvp("ampGains",ampGains_);
    }
  if(version < 4)
    {
      //In this case, we need to convert the old map<> struct to simple array
      map<unsigned int, QuadraticFit> atwdFreq_temp;
      ar & make_nvp("atwdFreq",atwdFreq_temp);
      map<unsigned int, QuadraticFit>::iterator iter = atwdFreq_temp.begin();
      while(iter !=  atwdFreq_temp.end())
	{
	  if(iter->first < 2)
	    {
	      atwdFreq_[iter->first] = iter->second;
	    }
	  else
	    {
	      log_fatal("Invalid chip number for atwdFreq in I3DOMCalibration::serialize");
	    }
          iter++;
	}
    }
  else
    {
      ar & make_nvp("atwdFreq",atwdFreq_);
    }
  if(version < 4)
    {
      //In this case, we need to convert the old map<> struct to simple array
      map<unsigned, map<unsigned, LinearFit> > atwdBin0_temp;
      map<unsigned, map<unsigned, LinearFit> > atwdBin1_temp;
      ar & make_nvp("atwd0BinParameters",atwdBin0_temp);
      ar & make_nvp("atwd1BinParameters",atwdBin1_temp);
      //  For atwdBin0:
      //first iterate over the outer map, this is over all channels (0-2)
      map<unsigned, map<unsigned, LinearFit> >::iterator iter_nch = atwdBin0_temp.begin();
      while(iter_nch != atwdBin0_temp.end())
	{
	  if(iter_nch->first <3)
	    {
	      // now for each channel, iterate over all bins (0-127)
	      map<unsigned, LinearFit>::iterator iter_nbin = iter_nch->second.begin();
	      while(iter_nbin != iter_nch->second.end() )
		{
		  if(iter_nbin->first<128)
		    {
		      atwdBin0_[iter_nch->first][iter_nbin->first] = iter_nbin->second;
		    }
		  else
		    {
		      log_fatal("Invalid bin for atwdBin_ in I3DOMCalibration::serialize");
		    }
                  iter_nbin++;
		}
	    }
	  else
	    {
	      log_fatal("Invalid channel for atwdBin_ in I3DOMCalibration::serialize");
	    }
          iter_nch++;
	}
      //  For atwdBin1:
      //first iterate over the outer map, this is over all channels (0-2)
      iter_nch = atwdBin1_temp.begin();
      while(iter_nch != atwdBin1_temp.end())
	{
	  if(iter_nch->first <3)
	    {
	      // now for each channel, iterate over all bins (0-127)
	      map<unsigned, LinearFit>::iterator iter_nbin = iter_nch->second.begin();
	      while(iter_nbin != iter_nch->second.end() )
		{
		  if(iter_nbin->first<128)
		    {
		      atwdBin1_[iter_nch->first][iter_nbin->first] = iter_nbin->second;
		    }
		  else
		    {
		      log_fatal("Invalid bin for atwdBin_ in I3DOMCalibration::serialize");
		    }
                  iter_nbin++;
		}
	    }
	  else
	    {
	      log_fatal("Invalid channel for atwdBin_ in I3DOMCalibration::serialize");
	    }
          iter_nch++;
	}
    }
  else
    {
      ar & make_nvp("atwd0BinParameters",atwdBin0_);
      ar & make_nvp("atwd1BinParameters",atwdBin1_);
    }
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
      ar & make_nvp("ATWDBaselines", atwdBaselines_);
      ar & make_nvp("ATWDResponseWidth", atwdResponseWidth_);
      ar & make_nvp("FADCResponseWidth", fadcResponseWidth_);
      
    }
  if (version > 4)
    {
      ar & make_nvp("atwdDeltaT", atwdDeltaT_);
    }
  if (version > 5)
    {
      ar & make_nvp("speDiscrimCalib", speDiscrimCalib_);
      ar & make_nvp("mpeDiscrimCalib", mpeDiscrimCalib_);
    }
  if (version > 6)
    {
      ar & make_nvp("pmtDiscrimCalib", pmtDiscrimCalib_);
    }
  if (version > 7)
    {
      ar & make_nvp("relativeDomEff", relativeDomEff_);
      ar & make_nvp("noiseRate", noiseRate_);
    }
  if (version > 9)
    {
      double junk = 0;
      ar & make_nvp("noiseThermalRate", junk);
      ar & make_nvp("noiseDecayRate", junk);
      ar & make_nvp("noiseScintillationMean", junk);
      ar & make_nvp("noiseScintillationSigma", junk);
      ar & make_nvp("noiseScintillationHits", junk);
    }

}

I3_SERIALIZABLE(I3DOMCalibration);

