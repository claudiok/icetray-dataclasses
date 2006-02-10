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
#include "dataclasses/status/I3IceCubeDOMStatusDict.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/TriggerKey.h";
#include "dataclasses/status/I3TriggerStatus.h"
#include "dataclasses/I3Time.h"
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
class I3DetectorStatus : public TObject
{
  I3Time startTime_;
  I3Time endTime_;
 public:
  // @todo Make sure this is correct and complete w/Chucks list
  //  Impl when needed
  //enum DaqMode { PhysicsRun = 0, CalibRun = 1, TestRun=2, Other=3 };
  //enum FilterMode { PhysicsFilt = 0, RandomFilt = 1, NoFilt =2 } ;
  I3DetectorStatus() {};
  
  virtual ~I3DetectorStatus();
  
  /**
   * @return the InIce DOM settings dict 
   */
  const I3IceCubeDOMStatusDict& GetIceCubeDOMStatus() const 
    { return icecubeDOMStatus_; }

  /**
   * @return the InIce DOM settings dict as a non-const object
   */
  I3IceCubeDOMStatusDict& GetIceCubeDOMStatus() 
    { return icecubeDOMStatus_; }

  /**
   * @return the IceTop DOM settings dict 
   */
  const I3IceCubeDOMStatusDict& GetIceTopDOMStatus() const 
    { return icetopDOMStatus_; }

  /**
   * @return the IceTop DOM settings dict as a non-const object
   */
  I3IceCubeDOMStatusDict& GetIceTopDOMStatus() 
    { return icetopDOMStatus_; }

  /**
   * @return the trigger settings 
   */
  const I3Map<TriggerKey, I3TriggerStatus>& GetTriggerStatus() const 
    { return trigStatus_; }

  /**
   * @return the trigger settings dict as a non-const object
   */
  I3Map<TriggerKey, I3TriggerStatus>& GetTriggerStatus() 
    { return trigStatus_; }
  
  I3Time GetStartTime() const { return startTime_; }
  
  void SetStartTime(const I3Time& t) { startTime_ = t; }
  
  void SetEndTime(const I3Time& t){ endTime_ = t; }
  
  I3Time GetEndTime() const { return endTime_; }

  virtual void ToStream(ostream& o) const
    {
      o<<" [ InIce I3DetectorDOMStatus ]"
       << icecubeDOMStatus_
      <<" [ IceTop I3DetectorDOMStatus ]"
       << icetopDOMStatus_
      <<" [ I3DetectorTriggerStatus ]";
      for(I3Map<TriggerKey, I3TriggerStatus>::const_iterator iter = trigStatus_.begin();
          iter != trigStatus_.end();
          ++iter)
        o<< "(" << iter->first << ", " << iter->second << ")";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
   I3IceCubeDOMStatusDict icecubeDOMStatus_;
   //icetop gets another one for now. Until they do something special
   I3IceCubeDOMStatusDict icetopDOMStatus_;
   I3Map<TriggerKey, I3TriggerStatus> trigStatus_;
   //@todo  DOM hubs have settings. Impl when needed. 
   //I3IceCubeHubStatusDict icecubeHubStatus_;
   //@todo Presumably AMANDA has some per run settings, impl when needed
   //I3AMANDAStatus amandaStatus_;
   //These might be good someday.  Impl when needed
   //DaqMode daqMode_;
   //FilterMode filterMode_;

  // copy and assignment private
  I3DetectorStatus(const I3DetectorStatus& rhs);
  const I3DetectorStatus& operator=(const I3DetectorStatus& rhs);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o,const I3DetectorStatus& stat)
{
  stat.ToStream(o);
  return o;
}

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

