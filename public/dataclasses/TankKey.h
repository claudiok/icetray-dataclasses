/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: TankKey.h 15516 2006-02-09 23:39:21Z tschmidt $
 * @file TankKey.h
 * @date $Date: 2006-02-10 00:39:21 +0100 (Fri, 10 Feb 2006) $
 */

#ifndef TANKKEY_H_INCLUDED
#define TANKKEY_H_INCLUDED

#include <utility>
#include "Utility.h"
#include <iostream>
/**
 * @brief A small class which is the string number and tank number
 * for an IceTop tank
 *
 */
static const unsigned tankkey_version_ = 0;

class TankKey 
{
 public:
  enum TankID {TankA=0,TankB=1};
 private:
  int stringNumber_;
  TankID tankID_;
 public:
  TankKey() : stringNumber_(0), tankID_(TankA) {}

  TankKey(int str,TankID tank) 
    : stringNumber_(str), tankID_(tank){}

  virtual ~TankKey(); 

  /**
   * retrieves the string number for this TankKey
   */
  int GetString() const { return stringNumber_; }

  /**
   * Sets the string number for this Tank
   */
  void SetString(int str){ stringNumber_ = str; }

  /**
   * gets the Tank number on the station
   */
  TankID GetTank() const { return tankID_; }

  /**
   * sets the Tank number on the station
   */
  void SetTank(TankID tank){ tankID_ = tank; }

  /**
   * equality operator.  
   * @return true if the string and tank numbers of the two TankKey's match
   * @param rhs the TankKey to compare this one to.
   */
  bool operator==(const TankKey& rhs) const
    {
      if(rhs.tankID_ == tankID_ && rhs.stringNumber_ == stringNumber_)
	return true;
      return false;
    }

  /**
   * inequality operator
   * @return false if the string or tank numbers are different
   * @param rhs the TankKey to compare this one to.
   */
  bool operator!=(const TankKey& rhs) const
    {
      if(rhs == *this)
	return false;
      return true;
    }


 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);
};

/**
 * comparison operator.  First compares the string numbers, then compares
 * the tank numbers.  Required to put TankKeys as the key of a map
 * @param lhs the left-hand TankKey
 * @param rhs the right-hand TankKey
 * @return true if the lhs should be ordered before the rhs
 */
inline bool operator<(const TankKey& lhs,const TankKey& rhs)
{
  if(lhs.GetString() < rhs.GetString())
    return true;
  if(lhs.GetString() > rhs.GetString())
    return false;
  if(lhs.GetTank() < rhs.GetTank())
    return true;
  return false;
}

I3_POINTER_TYPEDEFS(TankKey);
BOOST_CLASS_VERSION(TankKey, tankkey_version_);

#endif //TANKKEY_H_INCLUDED
