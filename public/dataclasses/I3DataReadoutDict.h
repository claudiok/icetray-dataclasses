/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadoutDict.h,v 1.3 2004/07/12 15:30:49 pretz Exp $
 *
 * @file I3DataReadoutDict.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/12 15:30:49 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */

#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"

/**
 * @brief Just an list of I3DataReadouts.  
 */
class I3DataReadoutDict : public TObject, public MapPolicy<I3DataReadoutPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */ 
  I3DataReadoutDict(){};

  /**
   * destructor 
   */
  virtual ~I3DataReadoutDict(){};

 private:
  // copy and assignment are private
  I3DataReadoutDict(const I3DataReadout&);
  const I3DataReadoutDict& operator=(const I3DataReadout&);

  // ROOT macro
  ClassDef(I3DataReadoutDict,1);
};

inline ostream& operator<<(ostream& o,const I3DataReadoutDict& v)
{
  o<<"[ I3DataReadoutDict: \n";
  I3DataReadoutDict::const_iterator iter;
  for(iter=v.begin();iter!=v.end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3DataReadoutPtr((I3DataReadout*)0))
	o<<"Null I3DataReadout";
      else
	o<<*(iter->second);
    }
  o<<"]\n";
  return o;
   
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadoutDict>::ThePolicy I3DataReadoutDictPtr;

#endif

