#ifndef I3EVENTHEADER_H
#define I3EVENTHEADER_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3EventHeader.h,v 1.6 2004/02/26 19:58:26 pretz Exp $
 *
 * I3Event Header is supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 *
 * @version $Revision: 1.6 $
 * @date $Date: 2004/02/26 19:58:26 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */

// includes
#include "I3DataHeader.h"

#include <string>

using namespace std;

/**
 * I3Event Header is supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 * @version $Id: I3EventHeader.h,v 1.6 2004/02/26 19:58:26 pretz Exp $
 * @author pretz
 */
class I3EventHeader : public I3DataHeader{
  ULong_t  fRunId;
  ULong_t  fEventId;
  Double_t fTime;
  ULong_t  fDay;
  
 public:
  /**
   * constructor
   */
  I3EventHeader();

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
   * destructor
   */
  virtual ~I3EventHeader();

  /**
   * @return the run id for the event
   */
  ULong_t RunID() const { return fRunId; }

  /**
   * @param runid the new run id for the event
   */
  void RunID(ULong_t runid) { fRunId = runid; }

  /**
   * @return the event id for this event
   */
  ULong_t EventID() const { return fEventId; }

  /**
   * @param eventid the new event id for the event
   */
  void EventID(ULong_t eventid) { fEventId = eventid; }
  
  /**
   * @return the name of the stream this header is for.... "Physics"
   */
  const string DataStream(){ return "Physics";}

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
