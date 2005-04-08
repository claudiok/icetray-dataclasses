/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultDict.h,v 1.8 2005/04/08 19:24:22 olivas Exp $
 *
 * @file I3RecoResultDict.h
 * @version $Revision: 1.8 $
 * @date $Date: 2005/04/08 19:24:22 $
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

#include "I3RecoResult.h"
#include "StoragePolicy.h"

/**
 * @brief This is the container for all the Track reconstruction results in
 * the event
 *
 */
class I3RecoResultDict : public TObject, 
  public STLMapStoragePolicy<string,I3RecoResultPtr>
{
 public:
  /**
   * constructor
   */
  I3RecoResultDict() {};

  /**
   * destructor
   */
  virtual ~I3RecoResultDict() {};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RecoResultDict: \n";
      I3RecoResultDict::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3RecoResultPtr((I3RecoResult*)0))
	    o<<"Null I3RecoResult";
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
  ClassDef(I3RecoResultDict,1);

};

/**
 * streams a I3RecoResultDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3RecoResultDict& v)
{
  v.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultDict>::ThePolicy I3RecoResultDictPtr;

#endif
