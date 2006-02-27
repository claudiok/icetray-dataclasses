/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3MCPMTResponse.h
 * @date $Date$
 */

#ifndef I3MCPMTRESPONSE_H_INCLUDED
#define I3MCPMTRESPONSE_H_INCLUDED
#include <sstream>
#include "dataclasses/Utility.h"

/**
 * @brief Base class for the Monte Carlo generated PMT response
 *
 * This class contains the PMT-level (pre-DAQ/readout) response to the
 * hits in the event.  It represents the voltage produced at the PMT
 * output.  The Chiba PMT response will inherit from this.  
 *
 */
class I3MCPMTResponse 
{
protected:
  float startTime_;
  float endTime_;
  
public:

  I3MCPMTResponse(){startTime_=0.; endTime_=0.;} 
  
  virtual ~I3MCPMTResponse();
  
  /**   
   * PMT output voltage as f(time) 
   */
  virtual float GetPMTVoltage(float time) { return 0.; };

  /**  
   * First time that is meaningful (non-zero) 
   */
  float GetStartTime() const {return startTime_;}

  /** 
   * Last time that is meaningful (non-zero) 
   */
  float GetEndTime() const {return endTime_;}

  void SetStartTime(const float time) { startTime_ = time;}

  void SetEndTime(const float time) { endTime_ = time;}

private:
  // copy and assignment are private
  I3MCPMTResponse(const I3MCPMTResponse&); 
  I3MCPMTResponse& operator=(const I3MCPMTResponse&); 

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3MCPMTResponse,1);
};


I3_POINTER_TYPEDEFS(I3MCPMTResponse);

#endif //I3MCPMTRESPONSE_H_INCLUDED


