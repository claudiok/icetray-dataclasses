/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponse.h,v 1.19 2004/03/10 19:17:52 pretz Exp $

    @version $Revision: 1.19 $
    @date $Date: 2004/03/10 19:17:52 $
    @author

    @todo

*/
#ifndef I3OMRESPONSE_H
#define I3OMRESPONSE_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>

#include "I3DataExecution.h"
#include "I3OMGeo.h"
#include "I3MCHitSeries.h"
#include "I3DataReadoutList.h"
#include "I3RecoHitSeriesData.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponse.h,v 1.19 2004/03/10 19:17:52 pretz Exp $
 *
 * The container for all the OMResponse-related data in the event
 * Has the monte-carlo truth, the hardware response, and the reconstructed
 * hit series'.    
 *
 * @version $Revision: 1.19 $
 * @date $Date: 2004/03/10 19:17:52 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */
class I3OMResponse : public TObject
{
  UShort_t fOMNumber;

  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment
  I3MCHitSeries       fMCHitSeries; //||
  I3DataReadoutList   fDataReadoutList; //||
  I3RecoHitSeriesData fRecoHitSeriesData; //||

 public:
  /**
   * constructor
   */
  I3OMResponse() {fOMNumber = 0;}
  
  /**
   * destructor
   */
  virtual ~I3OMResponse() {;}
  
  /**
   * @return the number of the OM for this response
   */
  UShort_t OMNumber() const { return fOMNumber; }

  /**
   * @param omnumber the new omnumber associated with this response
   */
  void OMNumber(UShort_t omnumber) { fOMNumber = omnumber; }
  
  /**
   * @return the MCTruth for this response as a const object
   */
  const I3MCHitSeries& MCHitSeries() const {return fMCHitSeries;}

  /**
   * @return the MC truth for this response as a non-const object
   */
  I3MCHitSeries& MCHitSeries() {return fMCHitSeries;}

  /**
   * @return the the hardware data for this response as a const object
   */
  const I3DataReadoutList& DataReadoutList() const {return fDataReadoutList;}
  
  /**
   * @return the hardware data for this response as a non-const object
   */
  I3DataReadoutList& DataReadoutList() {return fDataReadoutList;}

  /**
   * @return the reco hit series data as a const object
   */
  const I3RecoHitSeriesData& RecoHitSeriesData() const {return fRecoHitSeriesData;}
  
  /**
   * @return the reco hit series data as a non-const object
   */
  I3RecoHitSeriesData& RecoHitSeriesData() {return fRecoHitSeriesData;}

  private:
  // copy and assignment are private
   I3OMResponse(const I3OMResponse&); 
   const I3OMResponse& operator=(const I3OMResponse&); 

  // ROOT macro
  ClassDef(I3OMResponse,1);
};

typedef I3OMResponse* I3OMResponsePtr;
#endif

