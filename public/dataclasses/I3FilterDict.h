/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3FilterDict.h,v 1.3 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3FilterDict.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author blaufuss
 *
 */
#ifndef I3FILTERDICT_H
#define I3FILTERDICT_H

#include <TObject.h>
#include "StoragePolicy.h"
#include "I3Filter.h"
#include <sstream>

/**
 * @brief A place holder for the Filter data within the event
 * 
 * 
 *
 */
class I3FilterDict : public TObject,
		      public MapPolicy<string,I3FilterPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3FilterDict() {};

  /**
   * destructor
   */
  virtual ~I3FilterDict() {};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3FilterDict: \n";
      I3FilterDict::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3FilterPtr((I3Filter*)0))
	    o<<"Null I3Filter";
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
  I3FilterDict(const I3FilterDict&);
  const I3FilterDict& operator=(const I3FilterDict&);
  // ROOT Macro
  ClassDef(I3FilterDict, 1);
};

/**
 * streams the I3FilterDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3FilterDict& v)
{
  v.ToStream(o);
  return o;
}


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3FilterDict>::ThePolicy I3FilterDictPtr;

#endif

