/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MonitoringHeader.h,v 1.2 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3MonitoringHeader.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 */
#ifndef I3MONITORINGHEADER_H
#define I3MONITORINGHEADER_H

// includes
#include "I3DataHeader.h"
#include "StoragePolicy.h"
#include <string>
using namespace std;
/**
 * @brief The header for the data on the Monitoring stream 
 *
 * I3Monitoring Header is summary information for the Monitoring object 
 * which you can store in a file if you don't want to store the whole 
 * Monitoring object.
 * It's will have enough data to reconstruct the full Monitoring object
 * from the database
 */

class I3MonitoringHeader : public I3DataHeader
{
 public:
  /**
   * constructor
   */
  I3MonitoringHeader(){}

  /**
   * destructor
   */
  virtual ~I3MonitoringHeader() {;}

  /**
   * copy constructor just uses assignment
   */
  I3MonitoringHeader(const I3MonitoringHeader& rhs){*this = rhs;}

  /**
   * assignment is just a member-wise assignment
   */
  const I3MonitoringHeader& operator=(const I3MonitoringHeader& rhs){
    if(this == &rhs) return *this;
    I3DataHeader::operator=(rhs);
    return *this;
  }

  // note that it is not a reference returned, we need that copy constructor
  /**
   * @return the name of the stream on which this header belongs"
   */
  const string DataStream() { return "Monitoring"; }

 private:
  
  // ROOT macro
  ClassDef(I3MonitoringHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MonitoringHeader>::ThePolicy I3MonitoringHeaderPtr;

#endif //I3GEOMETRYHEADER_H
