/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Bag.h,v 1.21 2005/01/24 23:17:44 ehrlich Exp $
 *
 * @file I3Bag.h
 * @version $Revision: 1.21 $
 * @date $Date: 2005/01/24 23:17:44 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3BAG_H
#define I3BAG_H

#include "TObject.h"
#include "StoragePolicy.h"
#include <TClass.h>

#include <sstream>
#include <iostream>

/**
 * pointer typedeffed away to insulate users from memory management
 */ 
typedef PtrPolicy<TObject>::ThePolicy TObjectPtr;


/**
 * @brief I3Bag is a generic keyed TObject container, akin to the
 * Sieglinde bag. 
 *
 * Each Event (and geometry etc) gets one so that it can hold 
 * stuff that  doesn't really fit into the Data structure.  Just for 
 * 'temporary' or 'personal' use.
 */
class I3Bag : public TObject, public MapPolicy<string,TObjectPtr>::ThePolicy
{
 public:
  /**
   * Constructor
   */
  I3Bag() {};

  /**
   * destructor
   */
  ~I3Bag() {};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Bag\n";
      I3Bag::const_iterator iter;
      for(iter = begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==(TObjectPtr((TObject*)0)))
	    o<<"[ Null TObject ]\n";
	  else
        o<<"[ "
         <<iter->second->IsA()->GetName()
         <<" ]"
         <<"\n";
	}
      o<<"]";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  // ROOT macro
  ClassDef(I3Bag,1);
};
/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3Bag& bag)
{
  bag.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Bag>::ThePolicy I3BagPtr;

#endif //I3BAG_H
