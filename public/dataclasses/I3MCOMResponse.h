/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCOMResponse.h,v 1.8 2004/07/19 15:33:42 pretz Exp $

    @file I3MCOMResponse.h
    @version $Revision: 1.8 $
    @date $Date: 2004/07/19 15:33:42 $
    @author ehrlich
    @author troy
    @author pretz
    @author klein
*/
#ifndef I3MCOMRESPONSE_H
#define I3MCOMRESPONSE_H

#include "I3MCHitSeries.h"
#include "I3MCPMTResponse.h"
#include "I3OMResponse.h"
#include "I3MCPhotonVect.h"

/**
 * @brief The response of an OM in a single event, including Monte
 * Carlo truth info
 *
 * In addition to the regular I3OMResponse information related to
 * the observed OM response and reconstructed hit series, this class
 * holds the 'true' Monte Carlo hits and the simulated PMT response.
 *
 * @todo This class needs to contain a _pointer_ to the MCPMTResponse since
 * it is supposed to be subclassed -J.Pretz
 */
class I3MCOMResponse : public I3OMResponse
{
  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment
  I3MCHitSeries       fMCHitSeries; //||
  I3MCPMTResponse     fMCPMTResponse; //||
  I3MCPhotonVect      fMCPhotonVect; //||

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
    const I3MCPMTResponse& GetMCPMTResponse() const {return fMCPMTResponse;}
  
  /**
   * @return the PMTResponse as a non-const object
   */
    I3MCPMTResponse& GetMCPMTResponse() { return fMCPMTResponse;}

  /**
   * @return the pe hit series for this om response, as read-only.
   * These are PE's, not  photon arrivals
   */
  const I3MCHitSeries& GetMCHitSeries() const {return fMCHitSeries;}

  /**
   * Gives the MC truth for this response as a non-const object
   * These are pes, not photon arrivals.
   * @return the MCHitSeries for this class
   */
  I3MCHitSeries& GetMCHitSeries() {return fMCHitSeries;}

  /**
   * Gives the MC Photon series for this om response as a read-only
   * object.  This is the  MC truth for photon arrivals, not pes.
   * @return the MC Photon Vect for this om response
   */
  const I3MCPhotonVect& GetMCPhotonVect() const { return fMCPhotonVect;}


  /**
   * Gives the MC Photon series for this om response as a non-const object
   * This is the MC truth for the photon arrivals, not pes.
   * @return the MC Photon Vect for this om response
   */
  I3MCPhotonVect& GetMCPhotonVect() { return fMCPhotonVect;}

  private:
  // copy and assignment are private
   I3MCOMResponse(const I3MCOMResponse&); 
   const I3MCOMResponse& operator=(const I3MCOMResponse&); 

  // ROOT macro
  ClassDef(I3MCOMResponse,1);
};

typedef PtrPolicy<I3MCOMResponse>::ThePolicy I3MCOMResponsePtr;

#endif

