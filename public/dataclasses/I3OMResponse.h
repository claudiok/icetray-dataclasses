/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponse.h,v 1.27 2004/06/30 17:20:26 pretz Exp $

    @file I3OMResponse.h
    @version $Revision: 1.27 $
    @date $Date: 2004/06/30 17:20:26 $
    @author ehrlich
    @author troy
    @author pretz
    @author klein
*/
#ifndef I3OMRESPONSE_H
#define I3OMRESPONSE_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3DataExecution.h"
#include "I3OMGeo.h"
#include "I3DataReadoutList.h"
#include "I3RecoHitSeriesData.h"

/**
 * @brief The container for all the OMResponse-related data in the event
 *
 * Has the hardware response, and the reconstructed hit series'.    
 * The Monte Carlo information is now in I3MCOMResponse.h
 */
class I3OMResponse : public TObject
{
  UShort_t fOMNumber;

  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment

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
  UShort_t GetOMNumber() const { return fOMNumber; }

  /**
   * @param omnumber the new omnumber associated with this response
   */
  void SetOMNumber(UShort_t omnumber) { fOMNumber = omnumber; }
  
  /**
   * @return the the hardware data for this response as a const object
   */
  const I3DataReadoutList& GetDataReadoutList() const {return fDataReadoutList;}
  
  /**
   * @return the hardware data for this response as a non-const object
   */
  I3DataReadoutList& GetDataReadoutList() {return fDataReadoutList;}

  /**
   * @return the reco hit series data as a const object
   */
  const I3RecoHitSeriesData& GetRecoHitSeriesData() const {return fRecoHitSeriesData;}
  
  /**
   * @return the reco hit series data as a non-const object
   */
  I3RecoHitSeriesData& GetRecoHitSeriesData() {return fRecoHitSeriesData;}

  private:
  // copy and assignment are private
   I3OMResponse(const I3OMResponse&); 
   const I3OMResponse& operator=(const I3OMResponse&); 

  // ROOT macro
  ClassDef(I3OMResponse,1);
};
typedef PtrPolicy<I3OMResponse>::ThePolicy I3OMResponsePtr;

#endif
