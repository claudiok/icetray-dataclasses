/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPMTResponse.h,v 1.2 2004/04/22 15:51:25 pretz Exp $
 *
 * This contains the Monte-Carlo generated PMT response
 * The PMT response is handled as a function, with output in volts
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:51:25 $
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

  /** @todo Missing here is any method for storing the function
     This will have to be provided by the Chiba folks */

 public:
  /**
   * constructor
   */
  I3MCPMTResponse(){} 
  
  /**
   * destructor
   */
  virtual ~I3MCPMTResponse(){}
  
    /*   PMT output voltage as f(time) */

    Float_t PMToutvoltage(Float_t time){return 0;}

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

