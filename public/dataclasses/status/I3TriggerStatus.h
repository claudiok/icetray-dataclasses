/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerStatus.h 13154 2005-12-01 21:45:55Z  $
 *
 * @file I3TriggerStatus.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 * @author blaufuss
 */
#ifndef I3_TRIGGER_STATUS_H_INCLUDED
#define I3_TRIGGER_STATUS_H_INCLUDED


#include <string>

#include <dataclasses/Utility.h>
#include <map>


/**
 * @brief A trigger status/configuration object.
 *
 * A class describing all additional trigger information beside source, type
 * and subtype that are encapsulated in a TriggerKey already.
 * It only consists of 
 * - a name and
 * - a map of trigger settings:  string, integer values,
 * since most trigger information varies by trigger type.
 *
 * For IceCube triggers, these settings are most probably ...<BR>
 * <BR>... simple multiplicity trigger:<BR>
 * "threshold" - number of hits required in a time window<BR>
 * "timeWindow" - length of sliding time window (in ns)<BR>
 * <BR>... calibration trigger<BR>
 * "hitType" - type of hit to trigger on (0 (test), 1 (CPU), 2 (SPE), 3 (flasher))<BR>
 * <BR>... min bias trigger<BR>
 * "prescale" - one over the fraction of hits to trigger on<BR>
 * <BR>... two coincidence trigger<BR>
 * "triggerType1" - trigger type of first trigger<BR>
 * "triggerConfigId1" - trigger config ID of first trigger<BR>
 * "sourceId1" - source ID of first trigger<BR>
 * "triggerType2" - trigger type of second trigger<BR>
 * "triggerConfigId2" - trigger config ID of second trigger<BR>
 * "sourceId2" - source ID of second trigger<BR>
 * <BR>... three coincidence trigger<BR>
 * "triggerType1" - trigger type of first trigger<BR>
 * "triggerConfigId1" - trigger config ID of first trigger<BR>
 * "sourceId1" - source ID of first trigger<BR>
 * "triggerType2" - trigger type of second trigger<BR>
 * "triggerConfigId2" - trigger config ID of second trigger<BR>
 * "sourceId2" - source ID of second trigger<BR>
 * "triggerType3" - trigger type of third trigger<BR>
 * "triggerConfigId3" - trigger config ID of third trigger<BR>
 * "sourceId3" - source ID of third trigger<BR>
 * 
 * Additionally, the per-trigger readout instructions, specified for each subdetector:
 *  readoutTimeMinus  : time before the trigger time to set the readout window
 *  readoutTimePlus  : time after the trigger time to set the readout window
 *  readoutTimeOffset : time shift relatve to the trigger time to set the readout windoow
 */
static const unsigned i3triggerstatus_version_ = 2;
static const unsigned i3triggerreadoutconfig_version_ = 0;

/**
 *  A simple struct to hold the per-subdetector readout configurations.
 */
struct I3TriggerReadoutConfig
{
  double readoutTimeMinus;
  double readoutTimePlus;
  double readoutTimeOffset;
  template <class Archive>
  void serialize(Archive& ar, unsigned version);

  I3TriggerReadoutConfig()
  {
    readoutTimeMinus = NAN;
    readoutTimePlus = NAN;
    readoutTimeOffset = NAN;
  }

};

BOOST_CLASS_VERSION(I3TriggerReadoutConfig, i3triggerreadoutconfig_version_);

class I3TriggerStatus 
{
 public:

  /**
   * Subdetector enum, values match the daq labeling for subdirs.
   *  0 = ALL doms (InIce, IceTop) together
   *  1 = IceTop portion
   *  2 = InIce DOMS
   */
  enum Subdetector{
    ALL=0, 
    ICETOP=1,
    INICE=2
  };

  /**
   * Default constructor.
   */
  I3TriggerStatus()
    {};
  
  /**
   * Constructor.
   * 
   * @param name Name of the trigger.
   * @param settings Trigger settings: string, integer values.
   */
  I3TriggerStatus(const std::string& name,
                  const map<std::string, int>& settings)
    : name_(name), settings_(settings) {}
  
  /**
   * Destructor.
   */
  virtual ~I3TriggerStatus();
  
  /**
   * Get trigger name.
   * 
   * @return Name of trigger.
   */
  const std::string& GetTriggerName() const { return name_; }
  std::string& GetTriggerName() { return name_; }

  /**
   * Get trigger settings.
   * 
   * @return Trigger settings: string, integer values
   * (contents vary by trigger type).
   */
  const map<std::string, int>& GetTriggerSettings() const { return settings_; }
  map<std::string, int>& GetTriggerSettings() { return settings_; }  

  const map<Subdetector, I3TriggerReadoutConfig>& 
    GetReadoutSettings() const { return readoutconfigs_; }
  map<Subdetector, I3TriggerReadoutConfig>& 
    GetReadoutSettings() { return readoutconfigs_; }  

 private:
  std::string name_;
  map<std::string, int> settings_;
  map<Subdetector, I3TriggerReadoutConfig> readoutconfigs_;

  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);


  // logging
  SET_LOGGER("I3TriggerStatus");
};

/**
 * pointer type to insulate users from memory management
 */
I3_POINTER_TYPEDEFS(I3TriggerStatus);
BOOST_CLASS_VERSION(I3TriggerStatus, i3triggerstatus_version_);

#endif

