/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3EventHeader.h
 * @version $Revision: 1.14 $
 * @date $Date$
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
  unsigned long  runID_;
  unsigned long  eventID_;
  
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
    //Where is this I3DataHeader::operator= defined? 
    //TObject!?
    this->SetRunID(rhs.GetRunID());
    this->SetEventID(rhs.GetEventID());
    return *this;
  }

  /**
   * @return the run id for the event
   */
  unsigned long GetRunID() const { return runID_; }

  /**
   * @param runid the new run id for the event
   */
  void SetRunID(unsigned long runid) { runID_ = runid; }

  /**
   * @return the event id for this event
   */
  unsigned long GetEventID() const { return eventID_; }

  /**
   * @param eventid the new event id for the event
   */
  void SetEventID(unsigned long eventid) { eventID_ = eventid; }
  
  /**
   * @return the name of the stream this header is for.... "Physics"
   */
  const string GetDataStream(){ return "Physics";}

 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataHeader", base_object<I3DataHeader>(*this));
    ar & make_nvp("RunID", runID_);
    ar & make_nvp("EventID", eventID_);
  }
  
  // ROOT Macro
  ClassDef(I3EventHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3EventHeader>  I3EventHeaderPtr;

#endif //I3EVENTHEADER_H
