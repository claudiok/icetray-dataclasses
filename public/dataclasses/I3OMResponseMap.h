/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponseMap.h,v 1.7 2005/04/07 18:24:22 olivas Exp $
 *
 * @file I3OMResponseMap.h
 * @version $Revision: 1.7 $
 * @date $Date: 2005/04/07 18:24:22 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"
#include "StoragePolicy.h"
#include "OMKey.h"
#include <map>

using namespace std;

/**
 * @brief An event-level container for the OMResponse's of the Event.  
 *
 * @todo implement the 'FindOMResponse' as a smarter search, STL???
 *
 */
class I3OMResponseMap : public TObject, 
                        public MapPolicy<OMKey,I3OMResponsePtr>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3OMResponseMap(){};

  /**
   * destructor
   */
  virtual ~I3OMResponseMap(){};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMResponseMap: \n";
      I3OMResponseMap::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3OMResponsePtr((I3OMResponse*)0))
	    o<<"Null I3OMResponse";
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

  // ROOT macro
  ClassDef(I3OMResponseMap,1);
};

/**
 * streams an I3OMResponseMap to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3OMResponseMap& v)
{
  v.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMResponseMap>::ThePolicy I3OMResponseMapPtr;

/** 
 * Convenience typedef
 */
typedef I3OMResponseMap::iterator I3OMResponseItr;

#endif
