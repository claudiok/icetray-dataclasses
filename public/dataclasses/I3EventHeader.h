#ifndef I3EVENTHEADER_H
#define I3EVENTHEADER_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3EventHeader.h,v 1.5 2004/02/25 20:10:24 pretz Exp $
 *
 * I3Event Header is supposed to be a header for the event that
 * you can store in a file if you don't want to store the event.
 * It's supposed to have enough data to reconstruct the full event
 * from the database
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo needs the data that is currently in I3Event.  Times and such.
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
 * @version $Id: I3EventHeader.h,v 1.5 2004/02/25 20:10:24 pretz Exp $
 * @author pretz
 */
class I3EventHeader : public I3DataHeader{
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
   * @return the name of the stream this header is for.
   * ... "Physics"
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
