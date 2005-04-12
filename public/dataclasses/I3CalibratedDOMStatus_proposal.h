#ifndef I3CALIBRATEDDOMSTATUS_PROPOSAL_H
#define I3CALIBRATEDDOMSTATUS_PROPOSAL_H

/**
 * This is an object which goes in the DetectorStatus stream.  Not the
 * Calibration stream.  It is the result of applying the calibrations
 * to the raw dom status.
 */
class I3CalibratedDOMStatus_proposal
{
 public:
  I3CalibratedDOMStatus_proposal(){}
  virtual ~I3CalibratedDOMStatus_proposal(){}

  double GetSamplingRateA();

  void SetSamplingRateA(double rate);

  double GetSamplingRateB();
  
  void SetSamplingRateB(double rate);

  double GetPMTGain();

  void SetPMTGain(double gain);

};

#endif
