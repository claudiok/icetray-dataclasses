/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: TriggerKey.h 13154 2005-12-01 21:45:55Z tschmidt $
 *
 * @file TriggerKey.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 * @author blaufuss
 */
#ifndef TRIGGER_KEY_H_INCLUDED
#define TRIGGER_KEY_H_INCLUDED


#include <string>

#include <icetray/I3Logging.h>
#include <dataclasses/Utility.h>


/**
 * @brief A small class which is the "key" for the trigger status/config map 
 * in I3DetectorStatus.
 * 
 * In DAQ, triggers are identified in "event data" by three IDs.
 * These three IDs make a "unique" identifier that can be used to look up
 * additional trigger information like "prescale" for "MIN_BIAS" triggers
 * or "threshold" and "timeWindow" for "SIMPLE_MULTIPLICITY" triggers.
 * 
 * Those three pieces are:
 *  - Source ID
 *  - Type ID
 *  - Config ID
 *
 * 
 * 
 * (Go bug the DAQ SW folks for more info. I can't make this stuff up.)
 */
class TriggerKey
{
public:
  /**
   * Enumeration describing what "subdetector" issued a trigger.
   */
  enum SourceID	     // probably incomplete enumeration of trigger sources
  {
    IN_ICE = 0,           //InIce trigger system
    ICE_TOP = 10,         //IceTop trigger system
    AMANDA_TWR_DAQ = 20,  //AMANDA TWR DAq triggers
    EXTERNAL = 30,        //Some external trigger
    GLOBAL = 40,          //IceCube global trigger system
    AMANDA_MUON_DAQ = 50, //AMANDA Mu daq triggers
    SPASE = 70,           //A trigger from the SPASE shack
    UNKNOWN_SOURCE = 80   //A mysterious source
  };

  /**
   * Enumeration describing what "algorithm" issued a trigger.
   *  More details about a specific trigger can be stored in the
   *   I3TriggerStatus map in the I3Detector Status frame
   */
  enum TypeID         // probably incomplete enumeration of trigger types
  {
    SIMPLE_MULTIPLICITY = 0,   // Any trigger the uses summed multiplicity
    CALIBRATION = 10,          // A calibration trigger
    MIN_BIAS = 20,             // Minumum bias trigger
    THROUGHPUT = 30,           // An IceCube global trigger pass-thru trigger
    TWO_COINCIDENCE = 40,      // IceCube global trigger:  combined 2 trigs
    THREE_COINCIDENCE = 50,    // IceCube global trigger:  combined 3 trigs
    MERGED = 70,               // A trigger from a merging of events
    FRAGMENT_MULTIPLICITY = 105, //TWR trigger based on fragment counts
    STRING = 120,              // A trigger based on # hits in a string
    VOLUME = 125,              // A volume/geometry specific trigger
    SPHERE = 127,
    SPASE_2 = 170,             // SPASE trigger
    UNKNOWN_TYPE = 180               
  };


  /**
   * Returns the name of a source ID.
   *
   * @param source The source ID.
   * @return The name.
   */
  static const char* GetSourceString(SourceID source);

  /**
   * Returns the name of a type ID.
   * 
   * @param type The type ID.
   * @return The name.
   */
  static const char* GetTypeString(TypeID type);

private:
  SourceID source_;
  TypeID type_;
  int configID_;
  bool configIDSet_;

public:
  /**
   * Default constructor.
   */
  TriggerKey()
    : source_(UNKNOWN_SOURCE), type_(UNKNOWN_TYPE),
      configIDSet_(false) {}

  /**
   * Constructor.
   * 
   * @param source Source ID.
   * @param type Type ID.
   */
  TriggerKey(SourceID source, TypeID type)
    : source_(source), type_(type), configIDSet_(false) {}

  /**
   * Constructor.
   * 
   * @param source Source ID.
   * @param type Type ID.
   * @param configID Configuration ID.
   */
  TriggerKey(SourceID source, TypeID type, int configID)
    : source_(source), type_(type), configID_(configID), configIDSet_(true) {}

  /**
   * Destructor.
   */
  virtual ~TriggerKey();
  
  /**
   * Retrieves the source ID.
   * 
   * @return Source ID.
   */
  SourceID GetSource() const
  {
    return source_;
  }

  /**
   * Returns the name of the source ID.
   * 
   * @return The name.
   */
  const char* GetSourceString() const
  {
    return GetSourceString(source_);
  }

  /**
   * Sets the source ID.
   * 
   * @param source Source ID.
   */
  void SetSource(SourceID source)
  {
    source_ = source;
  }

  /**
   * Retrieves the type ID.
   * 
   * @return Type ID.
   */
  TypeID GetType() const
  {
    return type_;
  }

  /**
   * Returns the name of the type ID.
   * 
   * @return The name.
   */
  const char* GetTypeString() const
  {
    return GetTypeString(type_);
  }

  /**
   * Sets the type ID.
   * 
   * @param type Type ID.
   */
  void SetType(TypeID type)
  {
    type_ = type;
  }

  /**
   * Indicates, if a configuration ID is set.
   * 
   * The triplet of (SourceID source, TypeID type, int configID)
   * corresponds to a trigger status/config used in the IceCube DAQ.
   * AMANDA has no such trigger configurations, so that the
   * configuration ID might not be set.
   * @return True, if configuration ID is set.
   */
  bool CheckConfigID() const
  {
    return configIDSet_;
  }

  /**
   * Retrieves the configuration ID.
   * 
   * @return Configuration ID.
   */
  int GetConfigID() const
  {
    if(!configIDSet_)
      log_fatal("No configuration ID set.");
    
    return configID_;
  }

  /**
   * Resets the configuration ID.
   */
  void SetConfigID()
  {
    configIDSet_ = false;
  }

  /**
   * Sets the configuration ID.
   * 
   * @param configID Configuration ID.
   */
  void SetConfigID(int configID)
  {
    configID_ = configID;
    configIDSet_ = true;
  }

  /**
   * Equality operator.
   * 
   * @param rhs The trigger key to compare this one to.
   * @return true if source ID, type ID and configuration ID of the two
   * trigger keys match.
   */
  bool operator==(const TriggerKey& rhs) const
  {
    return((rhs.source_ == source_)
           && (rhs.type_ == type_)
           && ((!rhs.configIDSet_ && !configIDSet_)
               || (rhs.configIDSet_ && configIDSet_
                   && (rhs.configID_ == configID_))));
  }

  /**
   * Inequality operator.
   * 
   * @param rhs The trigger key to compare this one to.
   * @return false if source ID, type ID and configuration ID of the two
   * trigger keys are different.
   */
  bool operator!= (const TriggerKey & rhs) const
  {
    return !(rhs == *this);
  }

private:
  friend class boost::serialization::access;
  template <class Archive> void serialize (Archive& ar, unsigned version);


  // logging
  SET_LOGGER("TriggerKey");
};

/**
 * pointer type to insulate users from memory management
 */
I3_POINTER_TYPEDEFS(TriggerKey);

/**
 * Comparison operator. Required to use TriggerKeys as a key of a map.
 * @param lhs the left-hand trigger key.
 * @param rhs the right-hand trigger key.
 * @return true if the lhs should be ordered before the rhs.
 *
 * Precedence between source ID, type ID and configuration ID is somewhat 
 * arbitrary,
 * so I've picked:
 * source ID, type ID, configuration ID in order of descending importance.
 */
inline bool
operator<(const TriggerKey& lhs, const TriggerKey& rhs)
{
  if(lhs.GetSource() < rhs.GetSource())
    return true;
  if(lhs.GetSource() > rhs.GetSource())
    return false;
  //OK, so the source ID are equal so far ... continue.
  if(lhs.GetType() < rhs.GetType())
    return true;
  if(lhs.GetType() > rhs.GetType())
    return false;

  // OK, so the source ID and type ID are equal ... save us configID!
  return((!lhs.CheckConfigID() && rhs.CheckConfigID())
         || (lhs.CheckConfigID() && rhs.CheckConfigID()
             && lhs.GetConfigID() < rhs.GetConfigID()));
}


/**
 * Comparison operator.
 * @param lhs the left-hand trigger key.
 * @param rhs the right-hand trigger key.
 * @return true if the rhs should be ordered before the lhs
 * or if lhs and rhs are equal.
 */
inline bool
operator>=(const TriggerKey& lhs, const TriggerKey& rhs)
{
  return !(lhs < rhs);
}

/**
 * Comparison operator.
 * @param lhs the left-hand trigger key.
 * @param rhs the right-hand trigger key.
 * @return true if the rhs should be ordered before the lhs.
 */
inline bool
operator>(const TriggerKey& lhs, const TriggerKey& rhs)
{
  return((lhs >= rhs) && (lhs != rhs));
}

/**
 * Comparison operator.
 * @param lhs the left-hand trigger key.
 * @param rhs the right-hand trigger key.
 * @return true if the lhs should be ordered before the rhs
 * or if lhs and rhs are equal.
 */
inline bool
operator<=(const TriggerKey& lhs, const TriggerKey& rhs)
{
  return !(lhs > rhs);
}


#endif
