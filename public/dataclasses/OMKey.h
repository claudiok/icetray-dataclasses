/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file OMKey.h
 * @date $Date$
 */

#ifndef OMKEY_H_INCLUDED
#define OMKEY_H_INCLUDED

#include <utility>
#include "TObject.h"
#include "StoragePolicy.h"
#include <iostream>

using namespace std;

/**
 * @brief A small class which is the string number and om number
 * for an om
 *
 * It inhierits from pair<int,unsigned int> so it gets the 
 * comparison operator needed to sort these into a map for free.
 *
 */
class OMKey : public TObject //, public pair<int,unsigned int>
{
  int stringNumber_;
  unsigned int omNumber_;
 public:
  OMKey() : stringNumber_(0), omNumber_(0) {} //: pair<int,unsigned int>(0,0){}

  OMKey(int str,unsigned int om) 
    : stringNumber_(str), omNumber_(om){}

  ~OMKey(); 

  /**
   * retrieves the string number for this OMKey
   */
  int GetString() const { return stringNumber_;}

  /**
   * Sets the string number for this OM
   */
  void SetString(int str){stringNumber_ = str;}

  /**
   * gets the OM number on the string
   */
  unsigned int GetOM() const { return omNumber_;}

  /**
   * sets the OM number on the string
   */
  void SetOM(unsigned int om){omNumber_ = om;}

  /**
   * equality operator.  
   * @return true if the string and om numbers of the two OMKey's match
   * @param rhs the OMKey to compare this one to.
   */
  bool operator==(const OMKey& rhs) const
    {
      if(rhs.omNumber_ == omNumber_ && rhs.stringNumber_ == stringNumber_)
	return true;
      return false;
    }

  /**
   * inequality operator
   * @return false if the string or om numbers are different
   * @param rhs the OMKey to compare this one to.
   */
  bool operator!=(const OMKey& rhs) const
    {
      if(rhs == *this)
	return false;
      return true;
    }
 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

  // ROOT macro
  //ClassDef(OMKey,1);
};

/**
 * comparison operator.  First compares the string numbers, then compares
 * the om numbers.  Required to put OMKeys as the key of a map
 * @param lhs the left-hand OMKey
 * @param rhs the right-hand OMKey
 * @return true if the lhs should be ordered before the rhs
 */
inline bool operator<(const OMKey& lhs,const OMKey& rhs)
{
  if(lhs.GetString() < rhs.GetString())
    return true;
  if(lhs.GetString() > rhs.GetString())
    return false;
  if(lhs.GetOM() < rhs.GetOM())
    return true;
  return false;
}

/**
 * streams an OMKey to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const OMKey& key)
{
/*   o<<a<<key.GetString()<<b<<key.GetOM<<c; */
   o<<"("<<key.GetString()<<","<<key.GetOM()<<")"; 
   return o; 
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<OMKey>  OMKeyPtr;

#endif //OMKEY_H_INCLUDED
