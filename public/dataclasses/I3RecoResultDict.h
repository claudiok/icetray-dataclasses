/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultDict.h,v 1.3 2004/07/12 15:30:49 pretz Exp $
 *
 * @file I3RecoResultDict.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/12 15:30:49 $
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
class I3RecoResultDict : public TObject, public MapPolicy<I3RecoResultPtr>::ThePolicy
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

 private:
  // copy and assignment are private
  I3RecoResultDict(const I3RecoResultDict&);
  const I3RecoResultDict& operator=(const I3RecoResultDict&);

  // ROOT macro
  ClassDef(I3RecoResultDict,1);

};

inline ostream& operator<<(ostream& o,const I3RecoResultDict& v)
{
  o<<"[ I3RecoResultDict: \n";
  I3RecoResultDict::const_iterator iter;
  for(iter=v.begin();iter!=v.end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3RecoResultPtr((I3RecoResult*)0))
	o<<"Null I3RecoResult";
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
typedef PtrPolicy<I3RecoResultDict>::ThePolicy I3RecoResultDictPtr;

#endif
