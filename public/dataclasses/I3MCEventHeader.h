/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCEventHeader.h,v 1.2 2004/08/04 20:46:32 ehrlich Exp $
 *
 * @file I3MCEventHeader.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/08/04 20:46:32 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3MCEVENTHEADER_H
#define I3MCEVENTHEADER_H

// includes
#include "I3EventHeader.h"

#include <string>

using namespace std;

/**
 * @brief The header for data on the MCEvent stream.
 *
 * This class exists only to be consistent with the policy that
 * we need to have a header class for all streams,
 * I3EventHeader for I3Event, I3GeometryHeader for I3Geometry, ...
 * The policy is used for dataio which expects always a pair I3xxxxHeader/I3xxxx.
 */
class I3MCEventHeader : public I3EventHeader
{
 public:
  /**
   * constructor
   */
  I3MCEventHeader() {;}

  /**
   * destructor
   */
  virtual ~I3MCEventHeader() {;}

 private:
  // instance data
  
  // ROOT Macro
  ClassDef(I3MCEventHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCEventHeader>::ThePolicy I3MCEventHeaderPtr;

#endif //I3MCEVENTHEADER_H
