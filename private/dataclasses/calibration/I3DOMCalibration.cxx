//
//  $Id$
//
//
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3DOMCalibration.h>
#include <dataclasses/I3Units.h>

I3DOMCalibration::~I3DOMCalibration() {}

const unsigned int I3DOMCalibration::N_ATWD_BINS = 128;

//Number of ATWD channels is set to 3 (4th ATWD channel doesn't have DOMCAL now)
const unsigned int I3DOMCalibration::N_ATWD_CHANNELS = 3;

I3DOMCalibration::I3DOMCalibration()
    : temperature_(NAN),
      fadcGain_(NAN), fadcPedestal_(NAN)
    {};

/**
 * @todo  should put some checks on the channel, bin.  Make sure they are legit
 */
LinearFit I3DOMCalibration::GetATWDBinCalibFit (unsigned int id, 
						     unsigned int channel, 
						     unsigned int bin) const 

    {
    if(channel<N_ATWD_CHANNELS&&bin<N_ATWD_BINS)
	{
	return GetATWDBinParameters(id)[channel][bin];
	}
    else
	{
	log_fatal("No ATWD bin calibration for requested bin %ui channel %ui",
		  bin,channel);
	}
    }

void I3DOMCalibration::SetATWDBinCalibFit(unsigned int id, 
					  unsigned int channel, 
					  unsigned int bin,
					  LinearFit fitParams)
    {
    GetATWDBinParameters(id)[channel][(N_ATWD_BINS-1)-bin] = fitParams;
    }

//EKB
QuadraticFit I3DOMCalibration::GetATWDFreqFit(unsigned int chip)const
    {
      map<unsigned int, QuadraticFit>::const_iterator iter = atwdFreq_.find(chip);
      if ( iter == atwdFreq_.end() )
	{
	  log_fatal("Frequency calib not found for ATWD chip in I3DOMCalibration");
	}
      return  iter->second;    
    }

//EKB
void I3DOMCalibration::SetATWDFreqFit(unsigned int chip, 
				      QuadraticFit fitParams)
    {
    atwdFreq_.insert(pair<int, QuadraticFit> (chip, fitParams));
    }

//EKB
map<unsigned int,map<unsigned int,LinearFit> >& 
I3DOMCalibration::GetATWDBinParameters(unsigned int id) const
    {
    switch(id)
	{
	case 0:
	    return const_cast < map< unsigned int, map<unsigned int,LinearFit> >& > (atwdBin0_);
	case 1:
	    return const_cast < map< unsigned int, map<unsigned int,LinearFit> >& > (atwdBin1_);
	default:
	{
	log_fatal("Invalid ATWD Id in I3DOMCalibration::GetATWDBinParameters(Id)");
	return *static_cast<map<unsigned int,map<unsigned int,LinearFit> >*>(0);
	}
	}
    }
//EKB
void I3DOMCalibration::SetATWDGain(unsigned int channel, 
				   double gain) 
    {
    ampGains_.insert(pair<int,double> (channel, gain));
    }
//EKB
 double I3DOMCalibration::GetATWDGain(unsigned int channel) const
    {
      map<unsigned int, double>::const_iterator iter = ampGains_.find(channel);
      if ( iter == ampGains_.end() )
	{
	  log_fatal("Gain not found for ATWD channel in I3DOMCalibration");
	}
      return  iter->second;      
    }

template <class Archive>
void 
LinearFit::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("slope",slope);
  ar & make_nvp("intercept",intercept);
}

I3_SERIALIZABLE(LinearFit);

template <class Archive>
void 
QuadraticFit::serialize(Archive& ar, unsigned version)
    {
    ar & make_nvp("quadraticA",quadFitA);
    ar & make_nvp("quadraticB",quadFitB);
    ar & make_nvp("quadraticC",quadFitC);
    }

I3_SERIALIZABLE(QuadraticFit);


template <class Archive>
void 
I3DOMCalibration::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("temperature",temperature_);
  ar & make_nvp("fadcGain",fadcGain_);
  ar & make_nvp("fadcPedestal",fadcPedestal_);
  ar & make_nvp("ampGains",ampGains_);
  ar & make_nvp("atwdFreq",atwdFreq_);
  ar & make_nvp("atwd0BinParameters",atwdBin0_);
  ar & make_nvp("atwd1BinParameters",atwdBin1_);
  ar & make_nvp("pmtTransitTime",pmtTransitTime_);
  ar & make_nvp("hvGainRelation",hvGainRelation_);
}

I3_SERIALIZABLE(I3DOMCalibration);

