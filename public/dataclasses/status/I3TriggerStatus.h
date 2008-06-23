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
 * Additionally, the per-trigger readout instructions:
 *  readoutTimeMinus  : time before the trigger time to set the readout window
 *  readoutTimePlus  : time after the trigger time to set the readout window
 *  readoutTimeOffset : time shift relatve to the trigger time to set the readout windoow
 */
static const unsigned i3triggerstatus_version_ = 1;

class I3TriggerStatus 
{
 private:
  std::string name_;
  map<std::string, int> settings_;
  double readoutTimeMinus_;
  double readoutTimePlus_;
  double readoutTimeOffset_;

 public:
  /**
   * Default constructor.
   */
  I3TriggerStatus():
	readoutTimeMinus_(NAN),
	readoutTimePlus_(NAN),
	readoutTimeOffset_(NAN)
	 {}
  
  /**
   * Constructor.
   * 
   * @param name Name of the trigger.
   * @param settings Trigger settings: string, integer values.
   */
  I3TriggerStatus(const std::string& name,
                  const map<std::string, int>& settings,
		  double readoutTimeMinus,
		  double readoutTimePlus,
		  double readoutTimeOffset)
    : name_(name), settings_(settings), readoutTimeMinus_(readoutTimeMinus),
    readoutTimePlus_(readoutTimePlus), readoutTimeOffset_(readoutTimeOffset) {}
  
  /**
   * Destructor.
   */
  virtual ~I3TriggerStatus();
  
  /**
   * Get trigger name.
   * 
   * @return Name of trigger.
   */
  virtual const std::string& GetTriggerName() const { return name_; }
  virtual std::string& GetTriggerName() { return name_; }

  /**
   *  Get the time window settings
   */
  double GetReadoutTimeMinus() const { return readoutTimeMinus_; }
  double GetReadoutTimePlus() const { return readoutTimePlus_; }
  double GetReadoutTimeOffset() const { return readoutTimeOffset_; }

  /**
   *  Set the time window settings
   */
  void SetReadoutTimeMinus(double timeMinus) { readoutTimeMinus_ = timeMinus; }
  void SetReadoutTimePlus(double timePlus) { readoutTimePlus_ = timePlus; }
  void SetReadoutTimeOffset(double timeOffset) { readoutTimeOffset_ = timeOffset; }

  /**
   * Get trigger settings.
   * 
   * @return Trigger settings: string, integer values
   * (contents vary by trigger type).
   */
  virtual const map<std::string, int>& GetTriggerSettings() const { return settings_; }
  virtual map<std::string, int>& GetTriggerSettings() { return settings_; }  

 private:
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

