/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3MCPMTResponse.h
 * @date $Date$
 */

#ifndef I3MCPMTRESPONSE_H_INCLUDED
#define I3MCPMTRESPONSE_H_INCLUDED
#include <TObject.h>
#include <TClass.h>
#include <sstream>
#include "dataclasses/StoragePolicy.h"

/**
 * @brief Base class for the Monte Carlo generated PMT response
 *
 * This class contains the PMT-level (pre-DAQ/readout) response to the
 * hits in the event.  It represents the voltage produced at the PMT
 * output.  The Chiba PMT response will inherit from this.  
 *
 */
class I3MCPMTResponse : public TObject {

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
  
  virtual void ToStream(ostream& o) const {
    o<<"[ I3MCPMTResponse ]\n"
     <<"StartTime: "<<startTime_
     <<"EndTime: "<<endTime_;
  }

  virtual std::string ToString() const {
    std::ostringstream out;
    ToStream(out);
    return out.str();
  }

private:
  // copy and assignment are private
  I3MCPMTResponse(const I3MCPMTResponse&); 
  I3MCPMTResponse& operator=(const I3MCPMTResponse&); 

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3MCPMTResponse,1);
};

inline ostream& operator<<(ostream& o, const I3MCPMTResponse& resp)
{
  resp.ToStream(o);
  return o;
}

/** 
 * pointer type to insulate users from memory managemnt issues
 */
typedef shared_ptr<I3MCPMTResponse>  I3MCPMTResponsePtr;

#endif //I3MCPMTRESPONSE_H_INCLUDED


