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
#include <icetray/OMKey.h>
#include <iostream>
/**
 * @brief A small class which is the string number and tank number
 * for an IceTop tank
 *
 */
static const unsigned tankkey_version_ = 0;

struct TankKey {
public:
  enum TankID { TankA=0, TankB=1 };

  int string;
  TankID tank;


  TankKey()
    : string(0), tank(TankA)
  {}

  TankKey(int str,TankID tank_)
    : string(str), tank(tank_)
  {}
  
  explicit TankKey(const OMKey& omKey)
  {
    SetOMKey(omKey);
  }

  
  /**
   * Sets the stringNumber and tankID of this tank according to the OMKey
   */
  void SetOMKey(const OMKey& omKey);
  
  /**
   * Returns a tank label
   */
  std::string str() const;
    
  /**
   * equality operator.  
   * @return true if the string and tank numbers of the two TankKey's match
   * @param rhs the TankKey to compare this one to.
   */
  bool operator==(const TankKey& rhs) const
  {
    if(rhs.tank == tank && rhs.string == string)
      return true;
    return false;
  }

  /**
   * inequality operator
   * @return false if the string or tank numbers are different
   * @param rhs the TankKey to compare this one to.
   */
  bool operator!=(const TankKey& rhs) const { return !(rhs == *this); }


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
inline bool operator<(const TankKey& lhs, const TankKey& rhs)
{
  if(lhs.string < rhs.string)
    return true;
  if(lhs.string > rhs.string)
    return false;
  if(lhs.tank < rhs.tank)
    return true;
  return false;
}

/**
 * streams an TankKey to an arbitrary ostream.
 */
std::ostream& operator<<(std::ostream&, const TankKey& key);


I3_POINTER_TYPEDEFS(TankKey);
BOOST_CLASS_VERSION(TankKey, tankkey_version_);

#endif //TANKKEY_H_INCLUDED
