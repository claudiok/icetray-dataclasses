/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DetectorStatusHeader.h
 * @version $Revision: 1.4 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3DETECTORSTATUSHEADER_H
#define I3DETECTORSTATUSHEADER_H

// includes
#include "I3DataHeader.h"
#include "StoragePolicy.h"
#include <string>
using namespace std;
/**
 * @brief The header for data on the DetectorStatus stream
 *
 * I3DetectorStatus Header is summary information for the DetectorStatus object
 * which you can store in a file if you don't want to store the whole 
 * DetectorStatus object.
 * It's will have enough data to reconstruct the full DetectorStatus object
 * from the database
 *
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
  virtual ~I3DetectorStatusHeader();

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
  const string GetDataStream() { return "DetectorStatus"; }

 private:
  
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DetectorStatusHeader>  I3DetectorStatusHeaderPtr;

#endif 

