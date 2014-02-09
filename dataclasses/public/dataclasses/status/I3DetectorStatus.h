/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3DetectorStatus.h
 * @date $Date$
 */

#ifndef I3DETECTORSTATUS_H_INCLUDED
#define I3DETECTORSTATUS_H_INCLUDED

#include <map>

#include <icetray/I3DefaultName.h>
#include <icetray/I3FrameObject.h>
#include <dataclasses/I3Time.h>
#include <icetray/OMKey.h>
#include <dataclasses/TriggerKey.h>
#include <dataclasses/Utility.h>
#include <dataclasses/status/I3DOMStatus.h>
#include <dataclasses/status/I3TriggerStatus.h>
#include <dataclasses/status/TWRAOMStatus.h>

/**
 * @brief This is the state of the aspects of the detector that people have 
 * direct control over.  Contains the "per run" settings.
 *
 * Stuff that is a 'knob' on the detector.  This is a
 * top-level object in the frame related to this 'Detector Status' information.
 * Contains: 
 * - map of per DOM configurations (also the list of active DOMs),
 * - map of per AOM configurations (including AOMs read out by the TWR DAQ),
 * - map of active icecube triggers (and their configurations),
 * - map of active amanda triggers (and their configurations) and
 * - map of active domhubs (and their settings) ... eventually.
 */
static const unsigned i3detectorstatus_version_ = 3;

typedef std::map<OMKey, I3DOMStatus> I3DOMStatusMap;
I3_POINTER_TYPEDEFS(I3DOMStatusMap);

typedef std::map<TriggerKey, I3TriggerStatus> I3TriggerStatusMap;
I3_POINTER_TYPEDEFS(I3TriggerStatusMap);

class I3DetectorStatus : public I3FrameObject
{
public:
  I3Time startTime;
  I3Time endTime;
  I3DOMStatusMap domStatus;
  std::map<OMKey, TWRAOMStatus> aomStatus;
  I3TriggerStatusMap triggerStatus;
  I3TriggerStatusMap amandaTriggerStatus;
  std::string daqConfigurationName;

  I3DetectorStatus() {}
  
  virtual ~I3DetectorStatus();
  
  //These might be good someday.  Impl when needed
  //DaqMode daqMode;
  //FilterMode filterMode;
  

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

BOOST_CLASS_VERSION(I3DetectorStatus, i3detectorstatus_version_);
I3_DEFAULT_NAME(I3DetectorStatus);
I3_POINTER_TYPEDEFS(I3DetectorStatus);

#endif /*I3DETECTORSTATUS_H_INCLUDED*/

