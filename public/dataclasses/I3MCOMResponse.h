/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCOMResponse.h,v 1.2 2004/04/22 15:51:25 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/04/22 15:51:25 $
 * @author ehrlich
 * @author troy
 * @author pretz
 * @author klein
     
 * @todo

*/
#ifndef I3MCOMRESPONSE_H
#define I3MCOMRESPONSE_H

#include "I3MCHitSeries.h"
#include "I3MCPMTResponse.h"
#include "I3OMResponse.h"

/**
 * This contains all of the Monte Carlo OM Response information:
 * the 'true' Monte Carlo hits and the simulated PMT response.
 * all of the data and OM output is inherited from I3OMResponse
 */
class I3MCOMResponse : public I3OMResponse
{
  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment
  I3MCHitSeries       fMCHitSeries; //||
  I3MCPMTResponse     fMCPMTResponse; //

 public:
  /**
   * constructor
   */
  I3MCOMResponse(){}
  
  /**
   * destructor
   */
    virtual ~I3MCOMResponse(){}
  
  /**
   * @return the PMTResponse as a const object
   */
    const I3MCPMTResponse& MCMPTResponse() const {return fMCPMTResponse;}
  
  /**
   * @return the MCTruth for this response as a const object
   */
  const I3MCHitSeries& MCHitSeries() const {return fMCHitSeries;}

  /**
   * @return the MC truth for this response as a non-const object
   */
  I3MCHitSeries& MCHitSeries() {return fMCHitSeries;}

  private:
  // copy and assignment are private
   I3MCOMResponse(const I3MCOMResponse&); 
   const I3MCOMResponse& operator=(const I3MCOMResponse&); 

  // ROOT macro
  ClassDef(I3MCOMResponse,1);
};

typedef I3MCOMResponse* I3MCOMResponsePtr;
#endif

