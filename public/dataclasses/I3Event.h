/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Event.h,v 1.16 2004/03/10 17:54:43 pretz Exp $
 *
 * This class provides access to the all data containers which are 
 * related to each event. Additionally it stores event information
 * such as time, id, etc. (it is planned to store this kind of 
 * information in a separate header class).
 *
 * @version $Revision: 1.16 $
 * @date $Date: 2004/03/10 17:54:43 $
 * @author Ralf Ehrlich
 *
 * @todo 
 */

#ifndef I3EVENT_H
#define I3EVENT_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3TriggerData.h"
#include "I3FilterData.h"
#include "I3MCTrackData.h"
#include "I3OMResponseData.h"
#include "I3RecoResultData.h"
#include "I3Bag.h"

class I3Event : public TObject
{
  I3TriggerData    fTriggerData; //||
  I3FilterData     fFilterData; //||
  I3MCTrackData    fMCTrackData; //||
  I3OMResponseData fOMResponseData; //||
  I3RecoResultData fRecoResultData; //||
  I3Bag            fBag; //||
  
 public:
  /**
   * default constructor
   */
  I3Event();
  
  /**
   * default destructor
   */
  virtual ~I3Event();

  /**
   * @return the TriggerData as constant
   */
  const I3TriggerData& TriggerData() const { return fTriggerData; }

  /**
   * @return the TriggerData as non-const
   */
  I3TriggerData& TriggerData() { return fTriggerData; }

  /**
   * @return the FilterData as a constant object
   */
  const I3FilterData& FilterData() const { return fFilterData;}

  /**
   * @return the FilterData as a non-constant object
   */
  I3FilterData& FilterData() { return fFilterData;}

  /**
   * @return the MCTrackData as a constant object.
   */
  const I3MCTrackData& MCTrackData() const { return fMCTrackData;}

  /**
   * @return the MCTrackData as a non-const object.
   */
  I3MCTrackData& MCTrackData(){ return fMCTrackData;}

  /**
   * @return the OMResponseData of the event as a non-constant object
   */
  const I3OMResponseData& OMResponseData() const { return fOMResponseData; }

  /**
   * @return the OMResponseData as constant object
   */
  I3OMResponseData& OMResponseData() { return fOMResponseData; }

  /**
   * @return the RecoResult Data as a constant object
   */
  const I3RecoResultData& RecoResultData() const { return fRecoResultData; }

  /**
   * @return the RecoResultData as a non-constant object
   */
  I3RecoResultData& RecoResultData() { return fRecoResultData; }

  /**
   * @return the Bag for this event as a constant object
   */
  const I3Bag& Bag() const { return fBag; }

  /**
   * @return the Bag for this event as a non-constant object
   */
  I3Bag& Bag() { return fBag; }

 private:
  // copy and assignment private
  I3Event(const I3Event& rhs);
  const I3Event& operator=(const I3Event& rhs);

  //ROOT macro
  ClassDef(I3Event, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Event>::ThePolicy I3EventPtr;

#endif
