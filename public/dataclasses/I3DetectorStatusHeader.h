#ifndef I3DETECTORSTATUSHEADER_H
#define I3DETECTORSTATUSHEADER_H

// includes
#include "I3DataHeader.h"
#include "StoragePolicy.h"
#include <string>
using namespace std;

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DetectorStatusHeader.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 * I3DetectorStatus Header is summary information for the DetectorStatus object
 * which you can store in a file if you don't want to store the whole 
 * DetectorStatus object.
 * It's will have enough data to reconstruct the full DetectorStatus object
 * from the database
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author pretz
 *
 * @todo 
 */
class I3DetectorStatusHeader : public I3DataHeader
{
 public:
  /**
   * constructor
   */
  I3DetectorStatusHeader(){}

  /**
   * destructor
   */
  virtual ~I3DetectorStatusHeader() {;}

  /**
   * copy constructor just uses assignment
   */
  I3DetectorStatusHeader(const I3DetectorStatusHeader& rhs){*this = rhs;}

  /**
   * assignment is just a member-wise assignment
   */
  const I3DetectorStatusHeader& operator=(const I3DetectorStatusHeader& rhs){
    if(this == &rhs) return *this;
    I3DataHeader::operator=(rhs);
    return *this;
  }

  // note that it is not a reference returned, we need that copy constructor
  /**
   * @return the name of the stream on which this header belongs 
   */
  const string DataStream() { return "DetectorStatus"; }

 private:
  
  // ROOT macro
  ClassDef(I3DetectorStatusHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DetectorStatusHeader>::ThePolicy I3DetectorStatusHeaderPtr;

#endif 
