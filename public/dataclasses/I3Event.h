/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Event.h,v 1.10 2004/02/23 16:31:25 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/23 16:31:25 $
    @author

    @todo

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


/**
 * I3Event 
 * This class provides access to the all data containers which are 
 * related to each event. Additionally it stores event information
 * such as time, id, etc. (it is planned to store this kind of 
 * information in a separate header class).
 * @version $Id: I3Event.h,v 1.10 2004/02/23 16:31:25 pretz Exp $
 * @author Ralf Ehrlich
 */
class I3Event : public TObject
{
  ULong_t  fRunId;
  ULong_t  fEventId;
  Double_t fTime;
  ULong_t  fDay;

  I3TriggerData    triggerdata; //||
  I3FilterData     filterdata; //||
  I3MCTrackData    mctrackdata; //||
  I3OMResponseData omresponsedata; //||
  I3RecoResultData recoresultdata;
  I3Bag            bag;

  public:
  
  ULong_t RunID() const { return fRunId; }
  void RunID(ULong_t runid_) { fRunId = runid_; }

  ULong_t EventID() const { return fEventId; }
  void EventID(ULong_t eventid_) { fEventId = eventid_; }
  
  Double_t Time() const { return fTime; }
  void Time(Double_t time_) { fTime = time_; }

  ULong_t Day() const { return fDay; }
  void Day(ULong_t d) { fDay = d; }
  
  const I3TriggerData& TriggerData() const { return triggerdata; }
  I3TriggerData& TriggerData() { return triggerdata; }

  const I3FilterData& FilterData() const { return filterdata; }
  I3FilterData& FilterData() { return filterdata; }

  const I3MCTrackData& MCTrackData() const { return mctrackdata; }
  I3MCTrackData& MCTrackData(){ return mctrackdata; }

  const I3OMResponseData& OMResponseData() const { return omresponsedata; }
  I3OMResponseData& OMResponseData() { return omresponsedata; }

  const I3RecoResultData& RecoResultData() const { return recoresultdata; }
  I3RecoResultData& RecoResultData() { return recoresultdata; }

  const I3Bag& Bag() const { return bag; }
  I3Bag& Bag() { return bag; }



  I3Event();
  
  ~I3Event();


  ClassDef(I3Event, 1);
};
#endif
