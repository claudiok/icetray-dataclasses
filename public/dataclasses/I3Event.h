#ifndef I3EVENT_H
#define I3EVENT_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3TriggerData.h"
#include "I3FilterData.h"
#include "I3MCTrackData.h"
#include "I3OMResponseData.h"
#include "I3RecoResultData.h"


class I3Event : public TObject
{

  unsigned long  runid;
  unsigned long  eventid;
  double         time;
  unsigned long  day;

  I3TriggerData    *triggerdata;
  I3FilterData     *filterdata;
  I3MCTrackData    *mctrackdata;
  I3OMResponseData *omresponsedata;
  I3RecoResultData *recoresultdata;

  public:
  I3Event();
  ~I3Event();

  unsigned long GetRunID() const;
  unsigned long GetEventID() const;
  double        GetTime() const;
  unsigned long GetDay() const;
  void SetRunID(unsigned long runid_);
  void SetEventID(unsigned long eventid_);
  void SetTime(double time_);
  void SetDay(unsigned long day_);

  bool HasTriggerData() const;
  bool HasFilterData() const;
  bool HasMCTrackData() const;
  bool HasOMResponseData() const;
  bool HasRecoResultData() const;
  
  I3TriggerData&    GetTriggerData() const;
  I3FilterData&     GetFilterData() const;
  I3MCTrackData&    GetMCTrackData() const;
  I3OMResponseData& GetOMResponseData() const;
  I3RecoResultData& GetRecoResultData() const;
  
  void SetTriggerData(I3TriggerData* triggerdata_);
  void SetFilterData(I3FilterData* filterdata_);
  void SetMCTrackData(I3MCTrackData* mctrackdata_);
  void SetOMResponseData(I3OMResponseData* omresponsedata_);
  void SetRecoResultData(I3RecoResultData* recoresultdata_);

  ClassDef(I3Event, 1);
};
#endif
