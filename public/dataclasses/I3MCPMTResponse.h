/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponse.h,v 1.8 2004/07/15 20:29:25 deyoung Exp $
 *
 * @file I3MCPMTResponse.h
 * @version $Revision: 1.8 $
 * @date $Date: 2004/07/15 20:29:25 $
 * @author klein
 */

#ifndef I3MCPMTRESPONSE_H
#define I3MCPMTRESPONSE_H
#include <TObject.h>

/**
 * @brief Base class for the Monte Carlo generated PMT response
 *
 * This class contains the PMT-level (pre-DAQ/readout) response to the
 * hits in the event.  It represents the voltage produced at the PMT
 * output.  The Chiba PMT response will inherit from this.  
 *
 */
class I3MCPMTResponse : public TObject
{

  Float_t fStartTime;
  Float_t fEndTime;

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
  //virtual Float_t PMToutvoltage(Float_t time)=0;

  /**  
   * First time that is meaningful (non-zero) 
   */
   Float_t GetStartTime() const {return fStartTime;}

  /** 
   * Last time that is meaningful (non-zero) 
   */
   Float_t GetEndTime() const {return fEndTime;}

  private:
  // copy and assignment are private
   I3MCPMTResponse(const I3MCPMTResponse&); 
   I3MCPMTResponse& operator=(const I3MCPMTResponse&); 

  // ROOT macro
  ClassDef(I3MCPMTResponse,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3MCPMTResponse>::ThePolicy I3MCPMTResponsePtr;

#endif

