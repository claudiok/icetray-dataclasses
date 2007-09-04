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
#include <dataclasses/I3Time.h>

#include <string>
#include <icetray/I3FrameObject.h>
#include <icetray/I3DefaultName.h>

using namespace std;
static const unsigned i3eventheader_version_ = 2;

/**
 * @brief The header for data on the Event stream.
 *
 * Supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 */
class I3EventHeader : public I3FrameObject
{
  unsigned  runID_;
  int32_t   subRunID_;
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
      return endTime_;
    }

  void SetEndTime(I3Time time)
    {
      endTime_ = time;
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
   * @return the subrun id for the event
   */
  unsigned GetSubRunID() const { return subRunID_; }

  /**
   * @param runid the new subrun id for the event
   */
  void SetSubRunID(int32_t runid) { subRunID_ = runid; }

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

BOOST_CLASS_VERSION(I3EventHeader, i3eventheader_version_);
I3_POINTER_TYPEDEFS(I3EventHeader);
I3_DEFAULT_NAME(I3EventHeader);

#endif //I3EVENTHEADER_H_INCLUDED

