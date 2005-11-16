/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DetectorStatus.h
 * @version $Revision: 1.9 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3DETECTORSTATUS_H
#define I3DETECTORSTATUS_H

#include "StoragePolicy.h"
#include "dataclasses/I3IceCubeDOMStatusDict.h"
#include "dataclasses/I3TriggerStatusDict.h"
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
 public:
  // @todo Make sure this is correct and complete w/Chucks list
  //  Impl when needed
  //enum DaqMode { PhysicsRun = 0, CalibRun = 1, TestRun=2, Other=3 };
  //enum FilterMode { PhysicsFilt = 0, RandomFilt = 1, NoFilt =2 } ;
  /**
   * constructor
   */
  I3DetectorStatus(){};
  
  /**
   * destructor
   */
  virtual ~I3DetectorStatus(){};
  
  /**
   * @return the InIce DOM settings dict 
   */
  const I3IceCubeDOMStatusDict& GetIceCubeDOMStatus() const 
    { return icecubeDOMStatus_;}

  /**
   * @return the InIce DOM settings dict as a non-const object
   */
  I3IceCubeDOMStatusDict& GetIceCubeDOMStatus() 
    { return icecubeDOMStatus_;}

  /**
   * @return the IceTop DOM settings dict 
   */
  const I3IceCubeDOMStatusDict& GetIceTopDOMStatus() const 
    { return icetopDOMStatus_;}

  /**
   * @return the IceTop DOM settings dict as a non-const object
   */
  I3IceCubeDOMStatusDict& GetIceTopDOMStatus() 
    { return icetopDOMStatus_;}

  /**
   * @return the InIce Trigger settings dict 
   */
  const I3TriggerStatusDict& GetIceCubeTriggerStatus() const 
    { return icecubeTrigStatus_;}

  /**
   * @return the InIce Trigger settings dict as a non-const object
   */
  I3TriggerStatusDict& GetIceCubeTriggerStatus() 
    { return icecubeTrigStatus_;}

  /**
   * @return the InTop Trigger settings dict 
   */
  const I3TriggerStatusDict& GetIceTopTriggerStatus() const 
    { return icetopTrigStatus_;}

  /**
   * @return the InTop Trigger settings dict as a non-const object
   */
  I3TriggerStatusDict& GetIceTopTriggerStatus() 
    { return icetopTrigStatus_;}


  virtual void ToStream(ostream& o) const
    {
      o<<" [ InIce I3DetectorDOMStatus ]"
       << icecubeDOMStatus_
      <<" [ IceTop I3DetectorDOMStatus ]"
       << icetopDOMStatus_
      <<" [ InIce I3DetectorTriggerStatus ]"
       << icecubeTrigStatus_
      <<" [ IceTop I3DetectorTriggerStatus ]"
       << icetopTrigStatus_;
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
   I3TriggerStatusDict icecubeTrigStatus_;
   //icetop gets another one for now. Until they do something special
   I3TriggerStatusDict icetopTrigStatus_;
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

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DetectorStatus>  I3DetectorStatusPtr;


#endif // I3MONITORING_H

