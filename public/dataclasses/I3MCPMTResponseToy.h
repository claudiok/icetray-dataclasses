/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponseToy.h,v 1.2.2.1 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3MCPMTResponseToy.h
 * @version $Revision: 1.2.2.1 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author klein
 * @author deyoung
 */

#ifndef I3MCPMTRESPONSETOY_H_INCLUDED
#define I3MCPMTRESPONSETOY_H_INCLUDED
#include "dataclasses/I3MCPMTResponse.h"

/**
 * @brief Simple implementation class for PMT response
 *
 * This class contains the PMT-level (pre-DAQ/readout) response to the
 * hits in the event.  It represents the voltage produced at the PMT
 * output.  This is a toy class with very simple functionality.
 *
 */
class I3MCPMTResponseToy : public I3MCPMTResponse {

public:
  /**
   * constructor
   */
  I3MCPMTResponseToy() {}; 
  
  /**
   * destructor
   */
  virtual ~I3MCPMTResponseToy() {};
  
  /**   
   * PMT output voltage as f(time) 
   */
  virtual Float_t GetPMTVoltage(Float_t time) {
    if (fHitTimes.Size() == 0) { return 0.; };
    if (time < fStartTime || time > fEndTime) { return 0.; };

    Float_t amplitude = 0.;
    Float_t sigma = 2. * I3Units::ns;
    Float_t PMTgain = 100 * I3Units::mV;  
    for (UInt_t i = 0; i < fHitTimes.Size(); i++) {
      amplitude += exp( -(fHitTimes[i] - time) * (fHitTimes[i] - time)
			/ (sigma * sigma));
    } 
    return amplitude * PMTgain;
  };

  /** 
   * Set the series of PE times to respond to
   */
  virtual void SetHits(I3MCHitSeries& hits) {
    if (fHitTimes.Size() > 0) {
      I3DataExecution::Instance().Fatal("PMTResponseToy already has a hit series.");
    }

    I3MCHitSeries::iterator iter;
    for (iter = hits.begin(); iter != hits.end(); iter++) {
      fHitTimes.Add(iter->GetTime());
    }
  };

  

private:

  VectorPolicy<Double_t>::ThePolicy fHitTimes;

  // copy and assignment are private to disable them
  I3MCPMTResponseToy(const I3MCPMTResponseToy&); 
  I3MCPMTResponseToy& operator=(const I3MCPMTResponseToy&); 
  
};

/** 
 * pointer type to insulate users from memory managemnt issues
 */
typedef PtrPolicy<I3MCPMTResponseToy>::ThePolicy I3MCPMTResponseToyPtr;

#endif
