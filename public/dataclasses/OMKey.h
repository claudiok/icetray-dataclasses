/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: OMKey.h,v 1.3 2004/07/31 02:38:00 pretz Exp $
 *
 * @file OMKey.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/31 02:38:00 $
 * @author pretz
 */

#ifndef OMKEY
#define OMKEY

#include <utility>
#include "TObject.h"

using namespace std;

/**
 * @brief A small class which is the string number and om number
 * for an om
 *
 * It inhierits from pair<int,unsigned int> so it gets the 
 * comparison operator needed to sort these into a map for free.
 *
 * @todo implement operator<<
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
  unsigned int GetOM() const { return fOMNumber;}

  /**
   * sets the OM number on the string
   */
  void SetOM(unsigned int om){fOMNumber = om;}

  bool operator==(const OMKey& rhs) const
    {
      if(rhs.fOMNumber == fOMNumber && rhs.fStringNumber == fStringNumber)
	return true;
      return false;
    }

  bool operator!=(const OMKey& rhs) const
    {
      if(rhs == *this)
	return false;
      return true;
    }
  ClassDef(OMKey,1);
};

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

inline ostream& operator<<(ostream& o,const OMKey& key)
{
  o<<"("<<key.GetString()<<","<<key.GetOM()<<")";
  return o;
}

#endif
