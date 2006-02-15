/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: TriggerKey.h 13154 2005-12-01 21:45:55Z  $
 *
 * @file TriggerKey.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 * @author blaufuss
 */
#ifndef TRIGGER_KEY_H_INCLUDED
#define TRIGGER_KEY_H_INCLUDED


#include <string>
#include <iostream>
#include <sstream>
#include <TObject.h>

#include "icetray/services/I3Logging.h"


/**
 * @brief A small class which is the "key" for trigger maps.
 * 
 * In DAQ, triggers are identified in "event data" by three 
 * flags. These three IDs make a "unique" identifier that can be
 * used to look up other trigger information.
 * 
 * Those 3 pieces are:
 *  - sourceID
 *  - triggerType
 *  - triggerConfigID
 *
 * Go bug the DAQ SW folks for more info. I can't make this stuff up.
 */
class TriggerKey : public TObject
{
public:
  /**
   */
  enum SourceID	                // incomplete enumeration of trigger sources
  {
    IN_ICE = 0,
    ICE_TOP,
    AMANDA,
    EXTERNAL,
    GLOBAL,                     // -^-^-^ used for IceCube data
    AMANDA_MUON_DAQ,
    AMANDA_TWR_DAQ,
    SPASE,                      // -^-^-^ used for AMANDA data
    UNKNOWN_SOURCE              // UNKNOWN should always be the last enum
  };

  /**
   */
  enum TypeID                   // incomplete enumeration of trigger types
  {
    SIMPLE_MULTIPLICITY = 0,
    CALIBRATION,
    MIN_BIAS,
    THROUGHPUT,
    TWO_COINCIDENCE,
    THREE_COINCIDENCE,
    AMANDA_MULTIPLICITY,
    MERGED,
    UNKNOWN_TYPE                // UNKNOWN should always be the last enum
  };

  /**
   * GenerateName - a static member function to convert a trigger key 
   * to a corresponding "unique" string that is "mappable".
   * 
   * @param myKey A trigger key.
   * @return The corresponding "unique" String.
   */
  static std::string GenerateName(const TriggerKey& myKey);

  /*
   * ParseName - a static member function to take a "unique" string
   * (generated by GenerateName) and return the corresponding trigger key.
   * 
   * @param myName "Unique" string (generated by GenerateName).
   * @return The corresponding trigger key
   */
  static TriggerKey ParseName(const std::string& myName);

private:
  static SourceID CheckTriggerSource(SourceID source);
  
  static TypeID CheckTriggerType(TypeID type);


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
    : source_(CheckTriggerSource(source)), type_(CheckTriggerType(type)),
      configIDSet_(false) {}

  /**
   * Constructor.
   * 
   * @param source Source ID.
   * @param type Type ID.
   * @param configID Configuration ID.
   */
  TriggerKey(SourceID source, TypeID type, int configID)
    : source_(CheckTriggerSource(source)), type_(CheckTriggerType(type)),
      configID_(configID), configIDSet_(true) {}

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
   * Sets the source ID.
   * 
   * @param source Source ID.
   */
  void SetSource(SourceID source)
  {
    source_ = CheckTriggerSource(source);
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
   * Sets the type ID.
   * 
   * @param type Type ID.
   */
  void SetType(TypeID type)
  {
    type_ = CheckTriggerType(type);
  }

  /**
   * Indicates, if a configuration ID is set.
   * 
   * The triplet of (SourceID source, TypeID type, int configID)
   * corresponds to a trigger configuration used in the IceCube DAQ.
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

  virtual const std::string ToString() const
  {
    std::ostringstream out;
    ToStream(out);
    return out.str();
  }

  virtual void ToStream(std::ostream& o) const
  {
    o << "[ TriggerKey ] (SrcID = "
      << source_ << ", TypeID = "
      << type_ <<  ", ConfigID = ";
    if(configIDSet_)
      o << configID_;
    else
      o << "?";
    o << ")";
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

  template <class Archive> void serialize (Archive& ar, unsigned version);

  // logging
  SET_LOGGER("TriggerKey");
};

/**
 * pointer type to insulate users from memory management
 */


/**
 * Comparison operator. Required to use TriggerKeys as a key of a map.
 * @param lhs the left-hand trigger key.
 * @param rhs the right-hand trigger key.
 * @return true if the lhs should be ordered before the rhs.
 *
 * Precedence between source ID, type ID and configuration ID is somewhat arbitrary,
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


/**
 * Streams a trigger key to an arbitrary ostream.
 * 
 * @param o An arbitrary ostream.
 * @param key A trigger key.
 * @return The ostream.
 */
inline std::ostream&
operator<< (std::ostream& o, const TriggerKey& key)
{
  key.ToStream(o);
  
  return o;
}

#endif
