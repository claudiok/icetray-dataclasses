/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponse.h,v 1.6 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3MCPMTResponse.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author klein
 */

#ifndef I3MCPMTRESPONSE_H
#define I3MCPMTRESPONSE_H
#include <TObject.h>

/**
 * @brief This is now a base class for the Monte-Carlo generated PMT response
 *
 * The Chiba PMT response will inherit from this.  
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
#endif

