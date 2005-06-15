#ifndef I3CALIBRATEDDOMSTATUS_H
#define I3CALIBRATEDDOMSTATUS_H

/**
 * This is an object which goes in the DetectorStatus stream.  Not the
 * Calibration stream.  It is the result of applying the calibrations
 * to the raw dom status.
 */
class I3CalibratedDOMStatus
{
  double samplingRateA_;
  double samplingRateB_;
  double PMTGain_;
  double peakToValley_;
  double speMean_;
  double speWidth_;
 public:
  I3CalibratedDOMStatus(){}
  virtual ~I3CalibratedDOMStatus(){}

  double GetSamplingRateA() const {return samplingRateA_;}

  void SetSamplingRateA(double rate){samplingRateA_ = rate;}

  double GetSamplingRateB() const {return samplingRateB_;}
  
  void SetSamplingRateB(double rate){samplingRateB_ = rate;}

  double GetPMTGain()const {return PMTGain_;}

  void SetPMTGain(double gain){PMTGain_ = gain;}

  void SetPeakToValley(double p2v){peakToValley_ = p2v;}
  
  double GetPeakToValley() const {return peakToValley_;}
  
  void SetSPEMean(double mean){speMean_ = mean;}
  
  double GetSPEMean() const {return speMean_;}
  
  void SetSPEWidth(double width){speWidth_ = width;}
  
  double GetSPEWidth() const {return speWidth_;}

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("samplingRateA",samplingRateA_);
    ar & make_nvp("samplingRateB",samplingRateB_);
    ar & make_nvp("PMTGain",PMTGain_);
    ar & make_nvp("peakToValley",peakToValley_);
    ar & make_nvp("speMean",speMean_);
    ar & make_nvp("speWidth",speWidth_);
  }

};

typedef shared_ptr<I3CalibratedDOMStatus> I3CalibratedDOMStatusPtr;

#endif
