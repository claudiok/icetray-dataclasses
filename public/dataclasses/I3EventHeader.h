/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3EventHeader.h,v 1.14 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3EventHeader.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005/04/12 18:55:28 $
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
  unsigned long  runId_;
  unsigned long  eventId_;
  
 public:
  /**
   * constructor
   */
  I3EventHeader() { };

  /**
   * destructor
   */
  virtual ~I3EventHeader() { };

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
  unsigned long GetRunID() const { return runId_; }

  /**
   * @param runid the new run id for the event
   */
  void SetRunID(unsigned long runid) { runId_ = runid; }

  /**
   * @return the event id for this event
   */
  unsigned long GetEventID() const { return eventId_; }

  /**
   * @param eventid the new event id for the event
   */
  void SetEventID(unsigned long eventid) { eventId_ = eventid; }
  
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
typedef shared_ptr<I3EventHeader>  I3EventHeaderPtr;

#endif //I3EVENTHEADER_H
