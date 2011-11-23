
//
//  $Id$
//
//
#include <map>
#include <icetray/serialization.h>
#include <dataclasses/calibration/I3DOMCalibration.h>
#include <icetray/I3Units.h>

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
{
  fadcBeaconBaseline_ = NAN;
  atwdBeaconBaselines_[0][0] = NAN;
  atwdBeaconBaselines_[0][1] = NAN;
  atwdBeaconBaselines_[0][2] = NAN;
  atwdBeaconBaselines_[1][0] = NAN;
  atwdBeaconBaselines_[1][1] = NAN;
  atwdBeaconBaselines_[1][2] = NAN;
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
      ( bin<128) )
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
      ( bin<128) )
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

double
I3DOMCalibration::GetATWDBeaconBaseline(unsigned int id, unsigned int channel) const
{
  if ((id == 0 || id ==1) && 
      ( channel == 0 || channel == 1 || channel == 2)) {
    return atwdBeaconBaselines_[id][channel];
  } else {
    log_fatal("Invalid id, channel specified for GetATWDBeaconBaseline");
  }
}

void
I3DOMCalibration::SetATWDBeaconBaseline(unsigned int id, unsigned int channel, double bsl)
{
  if ((id == 0 || id ==1) && 
      ( channel == 0 || channel == 1 || channel == 2)) {
    atwdBeaconBaselines_[id][channel] = bsl;
  } else {
    log_fatal("Invalid id, channel specified for SetATWDBeaconBaseline");
  }
}

void
I3DOMCalibration::SetTemperature(double temperature)
{
  temperature_ = temperature;
  SetTauParameters(tauparameters_);
}

void
I3DOMCalibration::SetTauParameters(TauParam tauparameters)
{
  tauparameters_ = tauparameters;
  
  droopTimeConstants_[0] = tauparameters_.P0 + tauparameters_.P1 /
      (1.0 + exp(-((temperature_-273.0)/tauparameters_.P2)));
  droopTimeConstants_[1] = tauparameters_.P3 + tauparameters_.P4 /
      (1.0 + exp(-((temperature_-273.0)/tauparameters_.P5)));
}

void I3DOMCalibration::InitPulseTemplates()
{
	// Fill default pulse templates
	const double causalityShift = -11.5;
	
	if (toroidType_ == NEW_TOROID) {
		atwdSPETemplate_[0] = SPETemplate(17.899 / 14.970753076313095, -4.24 - 5 - causalityShift, 5.5, 42);
		atwdSPETemplate_[1] = SPETemplate(1.6581978, -11.70227755 - causalityShift, 5.4664884, 36.22319705);
		atwdSPETemplate_[2] = SPETemplate(17.899 / 14.970753076313095, -4.24 - 5 - causalityShift, 5.5, 42);
		
		atwdSPEDroopTemplate_[0] = SPETemplate(-0.8644871211757873, -0.39712728498041222, 2.2153931795324807e-08, 0.18265408524009966);
		atwdSPEDroopTemplate_[1] = SPETemplate(-0.60714457126191879, 1.0708609673531526, 0.85478360796100328, 0.22084066752348605);
		atwdSPEDroopTemplate_[2] = SPETemplate(-1.4510165738141465, -0.29659623453192685, 7.5567807067886802e-09, 0.18209846421412432);
	} else {
		atwdSPETemplate_[0] = SPETemplate(15.47 / 13.292860653948139, -3.929 - 5 - causalityShift, 4.7, 39.);
		atwdSPETemplate_[1] = SPETemplate(2.07399312, -10.95781298 - causalityShift, 4.86019733, 30.74826947);
		atwdSPETemplate_[2] = SPETemplate(1.35835821, -9.68624195 - causalityShift, 3.5016398, 30.96897853);
		
		atwdSPEDroopTemplate_[0] = SPETemplate(-0.87271352029389926, -0.37445896923019595, 0.05292192451474604, 0.2015123032569355);
		atwdSPEDroopTemplate_[1] = SPETemplate(-0.48448879003182993, 0.035060687415361419, 0.044493411456291751, 0.25894387769482058);
		atwdSPEDroopTemplate_[2] = SPETemplate(-0.74959447466950724, 0.16580945347622786, 0.055065176963265461, 0.25173422056591982);
	}
	
	fadcSPETemplate_ = SPETemplate(25.12 / 71.363940160184669, 61.27 - 50 - causalityShift, 30., 186.);
	fadcSPEDroopTemplate_ = SPETemplate(-2.8837584956162883, 0.57888025049064207, 0.81965713180496758, 0.04299648444652391);
}

I3DOMCalibration::DroopedSPETemplate
I3DOMCalibration::DiscriminatorPulseTemplate(bool droopy) const
{
  // FIXME: Add a real, properly timed pulse template for the discriminator
  // For now, use ATWD0 shifted earlier by 25 ns (a made-up number)
  const double discTimeOffset = 25.0;
  SPETemplate shiftedTemplate, shiftedDroopTemplate;
  shiftedTemplate = atwdSPETemplate_[0];
  shiftedTemplate.x0 -= discTimeOffset;
  if(!droopy)
    return(DroopedSPETemplate(shiftedTemplate));
  shiftedDroopTemplate = atwdSPETemplate_[0];
  shiftedDroopTemplate.x0 -= discTimeOffset;
  return(DroopedSPETemplate(shiftedTemplate,
                            shiftedDroopTemplate,
                            tauparameters_.TauFrac,
                            droopTimeConstants_[0],
                            droopTimeConstants_[1]));
}

I3DOMCalibration::DroopedSPETemplate
I3DOMCalibration::ATWDPulseTemplate(unsigned channel, bool droopy) const
{
  if (channel > 2)
    log_fatal("Unknown ATWD channel %u", channel);
  
  if(!droopy)
    return(DroopedSPETemplate(atwdSPETemplate_[channel]));
  return(DroopedSPETemplate(atwdSPETemplate_[channel],
                                atwdSPEDroopTemplate_[channel],
                                tauparameters_.TauFrac,
                                droopTimeConstants_[0],
                                droopTimeConstants_[1]));
}

I3DOMCalibration::DroopedSPETemplate
I3DOMCalibration::FADCPulseTemplate(bool droopy) const
{
  if(!droopy)
    return(DroopedSPETemplate(fadcSPETemplate_));
  return(DroopedSPETemplate(fadcSPETemplate_,
                            fadcSPEDroopTemplate_,
                            tauparameters_.TauFrac,
                            droopTimeConstants_[0],
                            droopTimeConstants_[1]));
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
I3DOMCalibration::SPETemplate::serialize(Archive& ar, unsigned version)
{
  if (version>pulsetemplate_version_)
    log_fatal("Attempting to read version %u from file but running version %u of PulseTemplate class.",version,tauparam_version_);

  ar & make_nvp("c", c);
  ar & make_nvp("x0", x0);
  ar & make_nvp("b1", b1);
  ar & make_nvp("b2", b2);
}

I3_SERIALIZABLE(I3DOMCalibration::SPETemplate);

template <class Archive>
void 
I3DOMCalibration::serialize(Archive& ar, unsigned version)
{
  if (version>i3domcalibration_version_)
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
      std::map<unsigned int, double> ampGains_temp;
      ar & make_nvp("ampGains",ampGains_temp);
      std::map<unsigned int, double>::iterator iter = ampGains_temp.begin();
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
      std::map<unsigned int, QuadraticFit> atwdFreq_temp;
      ar & make_nvp("atwdFreq",atwdFreq_temp);
      std::map<unsigned int, QuadraticFit>::iterator iter = atwdFreq_temp.begin();
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
      std::map<unsigned, std::map<unsigned, LinearFit> > atwdBin0_temp;
      std::map<unsigned, std::map<unsigned, LinearFit> > atwdBin1_temp;
      ar & make_nvp("atwd0BinParameters",atwdBin0_temp);
      ar & make_nvp("atwd1BinParameters",atwdBin1_temp);
      //  For atwdBin0:
      //first iterate over the outer map, this is over all channels (0-2)
      std::map<unsigned, std::map<unsigned, LinearFit> >::iterator iter_nch = atwdBin0_temp.begin();
      while(iter_nch != atwdBin0_temp.end())
      {
        if(iter_nch->first <3)
          {
            // now for each channel, iterate over all bins (0-127)
            std::map<unsigned, LinearFit>::iterator iter_nbin = iter_nch->second.begin();
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
            std::map<unsigned, LinearFit>::iterator iter_nbin = iter_nch->second.begin();
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
      SetTauParameters(tauparameters_);
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
  if (version > 8)
    {
      ar & make_nvp("ATWDBeaconBaselines", atwdBeaconBaselines_);
      ar & make_nvp("FADCBeaconBaselines", fadcBeaconBaseline_);
    }

  toroidType_ = (atwdResponseWidth_ > 0.4) ? NEW_TOROID : OLD_TOROID;
  InitPulseTemplates();
}

I3_SERIALIZABLE(I3DOMCalibration);

