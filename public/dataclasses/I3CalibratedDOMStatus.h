/**
 * Definition of I3CalibratedDOMStatus class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id$
 *
 * @file I3CalibratedDOMStatus.h
 * @version $Revision: 1.14 $
 * @date $Date$
 * @author blaufuss and others

 */
#ifndef I3CALIBRATEDDOMSTATUS_H
#define I3CALIBRATEDDOMSTATUS_H

/**
 * This is an object which goes in the DetectorStatus stream.  Not the
 * Calibration stream.  It is the result of applying the calibrations
 * to the raw dom status. Stores values that have been calculated
 * by combining calibration and status items.
 */
class I3CalibratedDOMStatus
{ 
 private:
  double samplingRateA_;
  double samplingRateB_;
  double PMTGain_;
  double speMean_;

 public:
  I3CalibratedDOMStatus(){}
  virtual ~I3CalibratedDOMStatus(){}
  
  double GetSamplingRateA() const {return samplingRateA_;}
  
  void SetSamplingRateA(double rate){samplingRateA_ = rate;}
  
  double GetSamplingRateB() const {return samplingRateB_;}
  
  void SetSamplingRateB(double rate){samplingRateB_ = rate;}
  
  double GetPMTGain()const {return PMTGain_;}
  
  void SetPMTGain(double gain){PMTGain_ = gain;}
  
  void SetSPEMean(double mean){speMean_ = mean;}
  
  double GetSPEMean() const {return speMean_;}
  
  friend class boost::serialization::access;
  
  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3CalibratedDOMStatus> I3CalibratedDOMStatusPtr;

#endif

