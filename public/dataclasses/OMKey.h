/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: OMKey.h,v 1.1 2004/07/07 19:05:57 pretz Exp $
 *
 * @file OMKey.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/07 19:05:57 $
 * @author pretz
 */

#ifndef OMKEY
#define OMKEY

#include <utility>

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
class OMKey : public pair<int,unsigned int>
{
 public:
  /**
   * constructor
   */
  OMKey() : pair<int,unsigned int>(0,0){}

  /**
   * destructor
   */
  OMKey(int str,unsigned int om) 
    : pair<int,unsigned int>(str,om){}

  /**
   * retrieves the string number for this OMKey
   */
  int GetString() const { return this->first;}

  /**
   * Sets the string number for this OM
   */
  void SetString(int str){this->first = str;}

  /**
   * gets the OM number on the string
   */
  unsigned int GetOM() const { return this->second;}

  /**
   * sets the OM number on the string
   */
  void SetOM(unsigned int om){this->second = om;}

  //  int operator>(const OMKey& key) {return fKey.operator>(key.fKey);}

};

#endif
