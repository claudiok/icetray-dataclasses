#ifndef I3EVENTHEADER_H
#define I3EVENTHEADER_H
/**
 * Class: I3EventHeader
 *
 * Version: $Id: I3EventHeader.h,v 1.1 2004/01/30 21:00:25 pretz Exp $
 *
 * Date: 13 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

// includes
#include "I3DataHeader.h"

/**
 * I3Event Header is supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 * @version $Id: I3EventHeader.h,v 1.1 2004/01/30 21:00:25 pretz Exp $
 * @author pretz
 */
class I3EventHeader : public I3DataHeader{
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
   * retrieves the name of the stream this header is for.
   * ... "Event"
   */
  const Char_t* GetDataStream();
 private:
  // copy and assignment are private
  I3EventHeader(const I3EventHeader&);
  I3EventHeader& operator=(const I3EventHeader&);

  // instance data
  
  // ROOT Macro
  ClassDef(I3EventHeader,1);
};

#endif //I3EVENTHEADER_H
