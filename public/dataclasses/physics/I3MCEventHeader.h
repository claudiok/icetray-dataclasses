/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3MCEventHeader.h
 * @date $Date$
 */

#ifndef I3MCEVENTHEADER_H_INCLUDED
#define I3MCEVENTHEADER_H_INCLUDED

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

  I3MCEventHeader() {;}

  virtual ~I3MCEventHeader();

  void SetStartTime(double& startTime){ startTime_ = startTime; };

  const double& GetStartTime(){ return startTime_; };

  void SetStopTime(double& stopTime){ stopTime_ = stopTime; };

  const double& GetStopTime(){ return stopTime_; };

 private:
  // instance data

  double startTime_;
  double stopTime_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};

I3_POINTER_TYPEDEFS(I3MCEventHeader);

#endif //I3MCEVENTHEADER_H_INCLUDED

