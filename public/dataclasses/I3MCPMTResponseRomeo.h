/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponseRomeo.h,v 1.1 2004/12/01 02:27:07 ehrlich Exp $
 *
 * @file I3MCPMTResponseRomeo.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/12/01 02:27:07 $
 * @author klein
 * @author deyoung
 * @author ehrlich
 */

#ifndef I3MCPMTRESPONSEROMEO_H
#define I3MCPMTRESPONSEROMEO_H
#include "dataclasses/I3MCPMTResponse.h"
#include <TF1.h>

/**
 * @brief Implementation class for PMT response, simulated by ROMEO
 *
 * This class contains the PMT-level (pre-DAQ/readout) response to the
 * hits in the event.  It represents the voltage produced at the PMT
 * output, simulated by ROMEO.
 *
 */
class I3MCPMTResponseRomeo : public I3MCPMTResponse 
{
  vector<TF1> fWaveform;

  public:
  
  /**
   * constructor
   */
  I3MCPMTResponseRomeo() {}; 
  
  /**
   * destructor
   */
  virtual ~I3MCPMTResponseRomeo() {};
  
  /**   
   * PMT output voltage as f(time) 
   */
  virtual Float_t GetPMTVoltage(Float_t time) 
  {
    if (time < fStartTime || time > fEndTime) { return 0.; };

    Int_t    n = fWaveform.size();
    Double_t voltage = 0;

    for(Int_t i=0; i<n; i++) {voltage+=fWaveform[i].Eval(time);}

    return voltage;
  };

  /** 
   * Get the waveform
   */
  const vector<TF1>& GetWaveform() const {return fWaveform;}
  
  vector<TF1>& GetWaveform() {return fWaveform;}

  private:

  // copy and assignment are private to disable them
  I3MCPMTResponseRomeo(const I3MCPMTResponseRomeo&); 
  I3MCPMTResponseRomeo& operator=(const I3MCPMTResponseRomeo&); 
  
  // ROOT macro
  ClassDef(I3MCPMTResponseRomeo,1);
};

/** 
 * pointer type to insulate users from memory managemnt issues
 */
typedef PtrPolicy<I3MCPMTResponseRomeo>::ThePolicy I3MCPMTResponseRomeoPtr;

#endif
