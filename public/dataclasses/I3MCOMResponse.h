/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCOMResponse.h,v 1.12 2005/01/24 23:17:44 ehrlich Exp $

    @file I3MCOMResponse.h
    @version $Revision: 1.12 $
    @date $Date: 2005/01/24 23:17:44 $
    @author ehrlich
    @author troy
    @author pretz
    @author klein
    @author deyoung
*/
#ifndef I3MCOMRESPONSE_H_INCLUDED
#define I3MCOMRESPONSE_H_INCLUDED

#include "I3MCHitSeries.h"
#include "I3MCPMTResponse.h"
#include "I3OMResponse.h"
#include "I3MCPhotonVect.h"
#include "I3PMTPulseVect.h"

/**
 * @brief The response of an OM in a single event, including Monte
 * Carlo truth info
 *
 * In addition to the regular I3OMResponse information related to
 * the observed OM response and reconstructed hit series, this class
 * holds pointers to the 'true' Monte Carlo hits and the simulated PMT
 * response.  These are pointers to allow the objects to be
 * subclassed.  There are also containers for the MC true photons and
 * for the single-PE PMT pulses. 
 */
class I3MCOMResponse : public I3OMResponse
{
  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment
  // @todo Is this still true?  TDY
  I3MCHitSeries       fMCHitSeries; //||
  I3MCPMTResponsePtr  fMCPMTResponse; //||
  I3MCPhotonVect      fMCPhotonVect; //||
  I3PMTPulseVect      fPMTPulseVect; //||

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
   * @return a pointer to the PMTResponse as a const object
   */
  const I3MCPMTResponsePtr GetMCPMTResponse() const {return fMCPMTResponse;}
  
  /**
   * @return a pointer to the PMTResponse as a non-const object
   */
  I3MCPMTResponsePtr GetMCPMTResponse() { return fMCPMTResponse;}

  /** 
   * Add a MCPMTResponse to the MCOMResponse by setting the pointer
   */
  void SetMCPMTResponse(I3MCPMTResponsePtr fResp_) {
    if(fMCPMTResponse) {
      I3DataExecution::Instance().Fatal("An MC PMT Response already exists.");
      return;
    }
    fMCPMTResponse = fResp_;
  }

  /**
   * @return a pointer to the pe hit series for this om response, as read-only.
   * These are PE's, not photon arrivals
   */
  const I3MCHitSeries& GetMCHitSeries() const {return fMCHitSeries;}

  /**
   * Gives the MC truth for this response as a non-const object
   * These are PEs, not photon arrivals.
   * @return a pointer to the MCHitSeries for this class
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

  /**
   * Gives the vector of individual PMT pulses for this OM response as
   * a read-only object.  These are the individual pulses, not
   *  containing any saturation or other nonlinear effects.
   * @return the PMT Pulse Vector for this OM Response
   */ 
  const I3PMTPulseVect& GetPMTPulseVect() const { return fPMTPulseVect;}

  /**
   * Gives the vector of individual PMT pulses for this om response as
   *  a non-const object. 
   * @return the PMT Pulse Vector for this OM Response
   */
  I3PMTPulseVect& GetPMTPulseVect() { return fPMTPulseVect;}

  private:

  // ROOT macro
  ClassDef(I3MCOMResponse,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MCOMResponse>::ThePolicy I3MCOMResponsePtr;

#endif

