/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: OMKey.h,v 1.7.4.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file OMKey.h
 * @version $Revision: 1.7.4.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author pretz
 */

#ifndef OMKEY_H
#define OMKEY_H

#include <utility>
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
  Int_t fStringNumber;
  UInt_t fOMNumber;
 public:
  /**
   * constructor
   */
  OMKey() : fStringNumber(0), fOMNumber(0) {} //: pair<int,unsigned int>(0,0){}

  /**
   * destructor
   */
  OMKey(int str,unsigned int om) 
    : fStringNumber(str), fOMNumber(om){}

  /**
   * retrieves the string number for this OMKey
   */
  int GetString() const { return fStringNumber;}

  /**
   * Sets the string number for this OM
   */
  void SetString(int str){fStringNumber = str;}

  /**
   * gets the OM number on the string
   */
  UInt_t GetOM() const { return fOMNumber;}

  /**
   * sets the OM number on the string
   */
  void SetOM(unsigned int om){fOMNumber = om;}

  /**
   * equality operator.  
   * @return true if the string and om numbers of the two OMKey's match
   * @param rhs the OMKey to compare this one to.
   */
  bool operator==(const OMKey& rhs) const
    {
      if(rhs.fOMNumber == fOMNumber && rhs.fStringNumber == fStringNumber)
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
  // ROOT macro

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
typedef PtrPolicy<OMKey>::ThePolicy OMKeyPtr;

#endif
