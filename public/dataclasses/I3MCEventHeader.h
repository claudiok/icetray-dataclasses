/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3MCEventHeader.h
 * @version $Revision: 1.3 $
 * @date $Date$
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

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCEventHeader", base_object<I3EventHeader>(*this));
  }
  
  // ROOT Macro
  ClassDef(I3MCEventHeader,1);
};

BOOST_SHARED_POINTER_EXPORT(I3MCEventHeader);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCEventHeader> I3MCEventHeaderPtr;

#endif //I3MCEVENTHEADER_H
