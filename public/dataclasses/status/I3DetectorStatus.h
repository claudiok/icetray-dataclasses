/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3DetectorStatus.h
 * @date $Date$
 */

#ifndef I3DETECTORSTATUS_H_INCLUDED
#define I3DETECTORSTATUS_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/TriggerKey.h"
#include "dataclasses/status/I3TriggerStatus.h"
#include "dataclasses/status/I3DOMStatus.h"
#include "dataclasses/I3Time.h"
#include "dataclasses/OMKey.h"
#include <icetray/I3FrameTraits.h>
#include <sstream>

/**
 * @brief This is the state of the aspects of the detector that people have 
 * direct control over.  Contains the "per run" settings.
 *
 * Stuff that is a 'knob' on the detector.  This is a
 * top-level object in the frame related to this 'Detector Status' information.
 * Contains:  map of per DOM configurations (also the list of active DOMs)
 *            map of active triggers (and their configurations)
 *            map of active domhubs (and their settings)...eventually
 *
 */
#include <TObject.h>

struct I3DetectorStatus : public TObject
{
  I3Time startTime;
  I3Time endTime;
  map<OMKey,I3DOMStatus> domStatus;
  map<TriggerKey, I3TriggerStatus> triggerStatus;
  
  I3DetectorStatus() {};
  
  virtual ~I3DetectorStatus();
  
  //These might be good someday.  Impl when needed
  //DaqMode daqMode;
  //FilterMode filterMode;
  

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

template<>
struct I3FrameTraits<I3DetectorStatus>
{
  static const char* defaultName;
};

template<>
struct I3FrameTraits<const I3DetectorStatus>
{
  static const char* defaultName;
};

I3_POINTER_TYPEDEFS(I3DetectorStatus);

#endif // I3DETECTORSTATUS_H_INCLUDED

