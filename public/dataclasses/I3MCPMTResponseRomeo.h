/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponseRomeo.h,v 1.4 2005/02/08 22:45:51 ehrlich Exp $
 *
 * @file I3MCPMTResponseRomeo.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005/02/08 22:45:51 $
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
  vector<Float_t> fWaveform;
  Float_t         fBinSize;

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
    if(time < fStartTime || time > fEndTime) return(0);
    ULong_t t = (ULong_t)((time-fStartTime)/fBinSize);
    if(t>=fWaveform.size()) return(0);
    return(fWaveform[t]);
  }

  /**
   * Get the waveform
   */
  const vector<Float_t>& GetWaveform() const {return fWaveform;}

  vector<Float_t>& GetWaveform() {return fWaveform;}

  /**
   * Get bin size
   */
  const Float_t GetBinSize() const {return fBinSize;}

  Float_t GetBinSize() {return fBinSize;}

  /**
   * Set bin size
   */
  void SetBinSize(Float_t binsize) {fBinSize=binsize;}

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
