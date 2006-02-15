/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3EventHeader.h
 * @date $Date$
 */

#ifndef I3EVENTHEADER_H_INCLUDED
#define I3EVENTHEADER_H_INCLUDED

// includes
#include "dataclasses/I3Time.h"
#include <string>
#include <TObject.h>

using namespace std;

/**
 * @brief The header for data on the Event stream.
 *
 * Supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 */
class I3EventHeader : public TObject
{
  unsigned  runID_;
  unsigned  eventID_;

  I3Time startTime_;
  I3Time endTime_;

 public:

  I3EventHeader();

  virtual ~I3EventHeader();

  I3Time GetStartTime() const
    {
      return startTime_;
    }

  void SetStartTime(I3Time time)
    {
      startTime_ = time;
    }

  I3Time GetEndTime() const
    {
      return startTime_;
    }

  void SetEndTime(I3Time time)
    {
      startTime_ = time;
    }

  /**
   * assignment operator.  Just a member-wise copy.
   */

  /**
   * @return the run id for the event
   */
  unsigned GetRunID() const { return runID_; }

  /**
   * @param runid the new run id for the event
   */
  void SetRunID(unsigned runid) { runID_ = runid; }

  /**
   * @return the event id for this event
   */
  unsigned GetEventID() const { return eventID_; }

  /**
   * @param eventid the new event id for the event
   */
  void SetEventID(unsigned eventid) { eventID_ = eventid; }
  
  /**
   * @return the name of the stream this header is for.... "Physics"
   */
  const string GetDataStream(){ return "Physics";}

 private:
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};

I3_POINTER_TYPEDEFS(I3EventHeader);

#endif //I3EVENTHEADER_H_INCLUDED

