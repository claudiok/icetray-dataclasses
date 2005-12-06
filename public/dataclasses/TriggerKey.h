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

#ifndef TRIGGERKEY_H
#define TRIGGERKEY_H

#include <utility>
#include "TObject.h"
#include "StoragePolicy.h"
#include <iostream>

using namespace std;

/**
 * @brief A small class which is the Key for trigger maps.
 * 
 * In DAQ, triggers are identified in "event data" by three 
 *  flags.  These three IDs make a unique identifier that can be
 *  used to look up other trigger information.
 * 
 * Those 3 pieces are:
 *  -triggerType
 *  -triggerConfigID
 *  -sourceID
 *
 * Go bug the DAQ SW folks for more info.  I can't make this stuff up.
 */
class TriggerKey 
{
  unsigned int sourceID_;
  unsigned int triggerType_;
  unsigned int triggerConfigID_;

 public:
  /**
   * constructor, with some 0 defaults
   */
  TriggerKey() :  sourceID_(0), triggerType_(0), triggerConfigID_(0)  {} 

  /**
   * copy constructor
   */

  TriggerKey(unsigned int sourceID, unsigned int type,unsigned int configID) 
    : sourceID_(sourceID), triggerType_(type), triggerConfigID_(configID)  {}

  ~TriggerKey(); 

  /**
   * retrieves the trigger type
   */
  unsigned int GetTriggerType() const { return triggerType_;}

  /**
   * Sets the trigger type
   */
  void SetTriggerType(unsigned int type){triggerType_ = type;}

  /**
   * retrieves the trigger config ID
   */
  unsigned int GetTriggerConfigID() const { return triggerConfigID_;}

  /**
   * Sets the trigger config id
   */
  void SetTriggerConfigID(unsigned int conf){triggerConfigID_ = conf;}

  /**
   * retrieves the source ID
   */
  unsigned int GetSourceID() const { return sourceID_;}

  /**
   * Sets the source ID
   */
  void SetSourceID(unsigned int sourceID){sourceID_ = sourceID;}


  /**
   * equality operator.  
   * @return true if the string and om numbers of the two TriggerKey's match
   * @param rhs the TriggerKey to compare this one to.
   */
  bool operator==(const TriggerKey& rhs) const
    {
      if(rhs.triggerType_ == triggerType_ && rhs.triggerConfigID_ == triggerConfigID_
	 && rhs.sourceID_ == sourceID_)
	return true;
      return false;
    }

  /**
   * inequality operator
   * @return false if the string or om numbers are different
   * @param rhs the TriggerKey to compare this one to.
   */
  bool operator!=(const TriggerKey& rhs) const
    {
      if(rhs == *this)
	return false;
      return true;
    }
 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("SourceID",  sourceID_);
    ar & make_nvp("TriggerType",  triggerType_);
    ar & make_nvp("TriggerConfigID",  triggerConfigID_);
  }
};

/**
 * comparison operator.  Required to use TriggerKeys as the key of a map
 * @param lhs the left-hand TriggerKey
 * @param rhs the right-hand TriggerKey
 * @return true if the lhs should be ordered before the rhs
 *
 *  Precedence between type, configid and source ID is somewhat arbitrary, so I've
 *  picked:  sourceID, triggerType, configID in order of descending importance.
 */
inline bool operator<(const TriggerKey& lhs,const TriggerKey& rhs)
{
  if(lhs.GetSourceID() < rhs.GetSourceID())
    return true;
  if(lhs.GetSourceID() > rhs.GetSourceID())
    return false;
  //OK, so the sourceID are equal so far...continue.
  if(lhs.GetTriggerType() < rhs.GetTriggerType())
    return true;
  if(lhs.GetTriggerType() > rhs.GetTriggerType())
    return false;
  // OK, so the source ID and trigger type are equal...save us configID!
  if(lhs.GetTriggerConfigID() < rhs.GetTriggerConfigID())
    return true;
  return false;
}

/**
 * streams an TriggerKey to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const TriggerKey& key)
{
   o<<"TriggerKey: ("<<key.GetTriggerType()<<","<<key.GetTriggerConfigID()<<","<<
     key.GetSourceID()<<")"; 
   return o; 
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<TriggerKey>  TriggerKeyPtr;

#endif
