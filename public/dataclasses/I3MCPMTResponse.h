/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponse.h,v 1.4 2004/04/25 20:40:27 ehrlich Exp $
 *
 * This is now a base class for the Monte-Carlo generated PMT response
 * The Chiba PMT response will inherit from this.  
 *
 * @version $Revision: 1.4 $
 * @date $Date: 2004/04/25 20:40:27 $
 * @author klein
 *
 * @todo 
 */

#ifndef I3MCPMTRESPONSE_H
#define I3MCPMTRESPONSE_H
#include <TObject.h>

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
  
    /*   PMT output voltage as f(time) */
  
//   virtual Float_t PMToutvoltage(Float_t time)

    /*  First time that is meaningful (non-zero) */

   Float_t StartTime() const {return fStartTime;}

  /*    Last time that is meaningful (non-zero) */

   Float_t EndTime() const {return fEndTime;}

  private:
  // copy and assignment are private
   I3MCPMTResponse(const I3MCPMTResponse&); 
   I3MCPMTResponse& operator=(const I3MCPMTResponse&); 

  // ROOT macro
  ClassDef(I3MCPMTResponse,1);
};
#endif

