/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3EventHeader.h,v 1.10 2005/02/01 09:29:46 blaufuss Exp $
 *
 * @file I3EventHeader.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/02/01 09:29:46 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3EVENTHEADER_H
#define I3EVENTHEADER_H

// includes
#include "I3DataHeader.h"

#include <string>

using namespace std;

/**
 * @brief The header for data on the Event stream.
 *
 * Supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 */
class I3EventHeader : public I3DataHeader{
  ULong_t  fRunId;
  ULong_t  fEventId;
  ULong_t  fRawStartTime;
  ULong_t  fRawEndTime;
  
 public:
  /**
   * constructor
   */
  I3EventHeader();

  /**
   * destructor
   */
  virtual ~I3EventHeader();

  /**
   * copy constructor.  Uses assignment operator.
   */
  I3EventHeader(const I3EventHeader& rhs){*this = rhs;}

  /**
   * assignment operator.  Just a member-wise copy.
   */
  const I3EventHeader& operator=(const I3EventHeader& rhs){
    if(this == &rhs) return *this;
    I3DataHeader::operator=(rhs);
    return *this;
  }

  /**
   * @return the run id for the event
   */
  ULong_t GetRunID() const { return fRunId; }

  /**
   * @param runid the new run id for the event
   */
  void SetRunID(ULong_t runid) { fRunId = runid; }

  /**
   * @return the event id for this event
   */
  ULong_t GetEventID() const { return fEventId; }

  /**
   * @param eventid the new event id for the event
   */
  void SetEventID(ULong_t eventid) { fEventId = eventid; }

  /**
   * @param return the "Raw" daq event start time, in 0.1 ns counts.
   *     will likely need to be converted to a usuable date/time
   */

  ULong_t GetRawStartTime() const { return fRawStartTime; }

  /**
   * @param set "Raw" daq event start time
   */
  void SetRawStartTime(ULong_t starttime) { fRawStartTime = starttime; }

  /**
   * @param return the "Raw" daq event end time, in 0.1 ns counts.
   *     will likely need to be converted to a usuable date/time
   */

  ULong_t GetRawEndTime() const { return fRawEndTime; }

  /**
   * @param set "Raw" daq event end time
   */
  void SetRawEndTime(ULong_t endtime) { fRawEndTime = endtime; }
  
  /**
   * @return the name of the stream this header is for.... "Physics"
   */
  const string GetDataStream(){ return "Physics";}

 private:
  // instance data
  
  // ROOT Macro
  ClassDef(I3EventHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3EventHeader>::ThePolicy I3EventHeaderPtr;

#endif //I3EVENTHEADER_H
