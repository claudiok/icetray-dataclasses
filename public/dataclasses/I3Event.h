#ifndef I3EVENT_H
#define I3EVENT_H

/**
 * Class: I3Event
 *
 * Version: $Id: I3Event.h,v 1.6 2004/01/30 18:03:32 ehrlich Exp $
 *
 * Date: 30 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

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

/**
 * I3Event 
 * This class provides access to the all data containers which are 
 * related to each event. Additionally it stores event information
 * such as time, id, etc. (it is planned to store this kind of 
 * information in a separate header class).
 * @version $Id: I3Event.h,v 1.6 2004/01/30 18:03:32 ehrlich Exp $
 * @author Ralf Ehrlich
 */
  
  unsigned long  runid;
  unsigned long  eventid;
  double         time;
  unsigned long  day;

  I3TriggerData    *triggerdata;
  I3FilterData     *filterdata;
  I3MCTrackData    *mctrackdata;
  I3OMResponseData *omresponsedata;
  I3RecoResultData *recoresultdata;
  I3Bag            *bag;

  public:
  
  /**
   * Contructor
   */
  I3Event();
  
  /**
   * Destructor
   */
  ~I3Event();

  /**
   * The following Get methods return the run id, event id, 
   * event time and event dat
   */
  unsigned long GetRunID() const;
  unsigned long GetEventID() const;
  double        GetTime() const;
  unsigned long GetDay() const;
  
  /**
   * The following Set methods can set the run id, event id, 
   * event time and event dat
   */
  void SetRunID(unsigned long runid_);
  void SetEventID(unsigned long eventid_);
  void SetTime(double time_);
  void SetDay(unsigned long day_);

  /**
   * Checks whether a trigger container has been set
   */
  bool HasTriggerData() const;
  
  /**
   * Checks whether a filter container has been set
   */
  bool HasFilterData() const;
  
  /**
   * Checks whether a monte carlo track container has 
   * been set
   */
  bool HasMCTrackData() const;
  
  /**
   * Checks whether an OM response container has 
   * been set
   */
  bool HasOMResponseData() const;
  
  /**
   * Checks whether a reconstruction result container has 
   * been set
   */
  bool HasRecoResultData() const;
  
  /**
   * Checks whether a "bag" container has been set
   * The bag container is used to store additional information
   * which do not fit into the data structure. The bag itself
   * can hold any TObject. It can be used, e.g. to store
   * user defined information of the F2k files.
   */
  bool HasBag() const;
  
  /**
   * Returns the trigger container. If the container has not 
   * been set, a fatal message will be logged.
   * @return trigger container
   */
  I3TriggerData&    GetTriggerData() const;
  
  /**
   * Returns the filter container. If the container has not 
   * been set, a fatal message will be logged.
   * @return filter container
   */
  I3FilterData&     GetFilterData() const;
  
  /**
   * Returns the monte carlo track container. If the container 
   * has not been set, a fatal message will be logged.
   * @return monte carlo container
   */
  I3MCTrackData&    GetMCTrackData() const;
  
  /**
   * Returns the OM response container. If the container 
   * has not been set, a fatal message will be logged.
   * @return OM response container
   */
  I3OMResponseData& GetOMResponseData() const;
  
  /**
   * Returns the reconstruction result container. If the 
   * container has not been set, a fatal message will be logged.
   * @return reconstruction result container
   */
  I3RecoResultData& GetRecoResultData() const;
  
  /**
   * Returns the bag container. If the container has not 
   * been set, a fatal message will be logged.
   * The bag container is used to store additional information
   * which do not fit into the data structure. The bag itself
   * can hold any TObject. It can be used, e.g. to store
   * user defined information of the F2k files.
   * @return bag container
   */
  I3Bag&            GetBag() const;
  
  /**
   * Sets the trigger container. If the container has been set 
   * already, nothing will be done and a message will be logged
   * @param trigger container.
   */
  void SetTriggerData(I3TriggerData* triggerdata_);
  
  /**
   * Sets the filter container. If the container has been set
   * already, nothing will be done and a message will be logged
   * @param filter container.
   */
  void SetFilterData(I3FilterData* filterdata_);
  
  /**
   * Sets the monte carlo track container. If the container has 
   * been set already, nothing will be done and a message will 
   * be logged
   * @param monte carlo track container.
   */
  void SetMCTrackData(I3MCTrackData* mctrackdata_);
  
  /**
   * Sets the OM response container. If the container has 
   * been set already, nothing will be done and a message will 
   * be logged
   * @param OM response container.
   */
  void SetOMResponseData(I3OMResponseData* omresponsedata_);
  
  /**
   * Sets the reconstruction result container. If the container has 
   * been set already, nothing will be done and a message will 
   * be logged
   * @param reconstruction result container.
   */
  void SetRecoResultData(I3RecoResultData* recoresultdata_);
  
  /**
   * Sets the bag container. If the container has been set 
   * already, nothing will be done and a message will 
   * be logged
   * The bag container is used to store additional information
   * which do not fit into the data structure. The bag itself
   * can hold any TObject. It can be used, e.g. to store
   * user defined information of the F2k files.
   * @param bag container.
   */
  void SetBag(I3Bag* bag_);

  ClassDef(I3Event, 1);
};
#endif
