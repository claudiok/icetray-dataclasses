/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3MCPMTResponseRomeo.h
 * @version $Revision: 1.8 $
 * @date $Date$
 * @author klein
 * @author deyoung
 * @author ehrlich
 */

#ifndef I3MCPMTRESPONSEROMEO_H
#define I3MCPMTRESPONSEROMEO_H
#include "dataclasses/I3MCPMTResponse.h"

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
  vector<float> waveform_;
  float         binSize_;

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
  virtual float GetPMTVoltage(float time)
  {
    if(time < startTime_ || time > endTime_) return(0);
    unsigned long t = (unsigned long)((time-startTime_)/binSize_);
    if(t>=waveform_.size()) return(0);
    return(waveform_[t]);
  }

  /**
   * Get the waveform
   */
  const vector<float>& GetWaveform() const {return waveform_;}

  vector<float>& GetWaveform() {return waveform_;}

  /**
   * Get bin size
   */
  const float GetBinSize() const {return binSize_;}

  float GetBinSize() {return binSize_;}

  /**
   * Set bin size
   */
  void SetBinSize(float binsize) {binSize_=binsize;}

  private:

  // copy and assignment are private to disable them
  I3MCPMTResponseRomeo(const I3MCPMTResponseRomeo&);
  I3MCPMTResponseRomeo& operator=(const I3MCPMTResponseRomeo&);

  // ROOT macro
  ClassDef(I3MCPMTResponseRomeo,1);

  friend class boost::serialization::access;
  template <class Archive>
    void serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3MCPMTResponse",base_object<I3MCPMTResponse>(*this));
    ar & make_nvp("Waveform",waveform_);
    ar & make_nvp("BinSize",binSize_);
  }
};

BOOST_SHARED_POINTER_EXPORT(I3MCPMTResponseRomeo);

/** 
 * pointer type to insulate users from memory managemnt issues
 */
typedef shared_ptr<I3MCPMTResponseRomeo>  I3MCPMTResponseRomeoPtr;

#endif
