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
 * $Id: I3OMResponse.h,v 1.16 2004/02/27 22:48:20 ehrlich Exp $
 *
 * The container for all the OMResponse-related data in the event
 * Has the monte-carlo truth, the hardware response, and the reconstructed
 * hit series'.    
 *
 * @version $Revision: 1.16 $
 * @date $Date: 2004/02/27 22:48:20 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo reference to the related GeoOM in the Geometry, or just its index.
 * @todo does this class have 'full value symantics'?
 */
class I3OMResponse : public TObject
{
  UShort_t fOMNumber;
  TRef     fGeometry;

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
  I3OMResponse() {fOMNumber = 0; fGeometry = NULL;}
  
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
  
  bool HasGeometry() const {return((fGeometry.GetObject()==NULL) ? false : true);}
  
  const I3OMGeo& Geometry() const    
  {
    if(HasGeometry()) return(*(I3OMGeo*)fGeometry.GetObject());
    I3DataExecution::Instance().Fatal("I3OMResponse::Geometry() the OMGeo doesn't exist");
    return (*(I3OMGeo*)NULL);
  }

  void Geometry(I3OMGeo& geometry_)
  {
    if(!HasGeometry()) fGeometry=&geometry_;
    else I3DataExecution::Instance().Fatal("I3OMResponse::Geometry() the OMResponse has already been set.");
  }
  
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
/*   I3OMResponse(const I3OMResponse&); */
/*   const I3OMResponse& operator=(const I3OMResponse&); */

  // ROOT macro
  ClassDef(I3OMResponse,1);
};

typedef I3OMResponse* I3OMResponsePtr;
#endif

