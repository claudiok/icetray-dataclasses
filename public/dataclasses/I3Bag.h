/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Bag.h,v 1.20 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3Bag.h
 * @version $Revision: 1.20 $
 * @date $Date: 2004/08/31 02:56:29 $
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
  // copy and assignment are private
  I3Bag(const I3Bag& rhs);
  const I3Bag& operator=(const I3Bag& rhs);

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
