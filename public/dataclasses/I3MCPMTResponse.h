/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponse.h,v 1.13 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3MCPMTResponse.h
 * @version $Revision: 1.13 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author klein
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
  float fStartTime;
  float fEndTime;
  
public:
  /**
   * constructor
   */
  I3MCPMTResponse(){fStartTime=0.; fEndTime=0.;} 
  
  /**
   * destructor
   */
  virtual ~I3MCPMTResponse(){}
  
  /**   
   * PMT output voltage as f(time) 
   */
  virtual float GetPMTVoltage(float time) { return 0.; };

  /**  
   * First time that is meaningful (non-zero) 
   */
  float GetStartTime() const {return fStartTime;}

  /** 
   * Last time that is meaningful (non-zero) 
   */
  float GetEndTime() const {return fEndTime;}

  void SetStartTime(const float time) { fStartTime = time;}

  void SetEndTime(const float time) { fEndTime = time;}
  
  virtual void ToStream(ostream& o) const {
    o<<"[ "<<IsA()->GetName()<<" ]\n"
     <<"StartTime: "<<fStartTime
     <<"EndTime: "<<fEndTime;
  }

  virtual string ToString() const {
    ostringstream out;
    ToStream(out);
    return out.str();
  }

private:
  // copy and assignment are private
  I3MCPMTResponse(const I3MCPMTResponse&); 
  I3MCPMTResponse& operator=(const I3MCPMTResponse&); 

  // ROOT macro
  ClassDef(I3MCPMTResponse,1);
};

inline ostream& operator<<(ostream& o, const I3MCPMTResponse& resp)
{
  resp.ToStream(o);
  return o;
}

/** 
 * pointer type to insulate users from memory managemnt issues
 */
typedef PtrPolicy<I3MCPMTResponse>::ThePolicy I3MCPMTResponsePtr;

#endif

