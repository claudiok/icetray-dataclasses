/**
    $Id: I3ArrayHitDict.h,v 1.4 2004/08/31 02:56:29 pretz Exp $
    @file I3ArrayHitDict.h
    @version $Revision: 1.4 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
    @author blaufuss
*/

#ifndef I3ArrayHitDict_H
#define I3ArrayHitDict_H

#include <TObject.h>
#include <TObjArray.h>

#include <sstream>
#include "dataclasses/I3ArrayHit.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3ArrayHitDict : public TObject,
	 public MapPolicy<string, I3ArrayHitPtr>::ThePolicy {

 public:
  /**
   * constructor
   */
  I3ArrayHitDict() {}
  
  /**
   * destructor
   */
  virtual ~I3ArrayHitDict() {}
  
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3ArrayHitDict: \n";
      I3ArrayHitDict::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3ArrayHitPtr((I3ArrayHit*)0))
	    o<<"Null XXX";
	  else
	    o<<*(iter->second);
	}
      o<<"]\n";
    }
  
  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
 private:
  // copy and assignment are private
  I3ArrayHitDict(const I3ArrayHitDict&); 
  const I3ArrayHitDict& operator=(const I3ArrayHitDict&); 

  // ROOT macro
  ClassDef(I3ArrayHitDict,1);
};

inline ostream& operator<<(ostream& o,const I3ArrayHitDict& dict)
{
  dict.ToStream(o);
  return o;
}

/**
 * pointer typedeffed away to insulate users from memory managment
 */
typedef PtrPolicy<I3ArrayHitDict>::ThePolicy I3ArrayHitDictPtr;

#endif
