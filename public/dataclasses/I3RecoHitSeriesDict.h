#ifndef I3RECOHITSERIESDICT_H
#define I3RECOHITSERIESDICT_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeriesDict.h,v 1.4 2004/10/27 23:09:40 spencer Exp $
 *
 * @file I3RecoHitSeriesDict.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/10/27 23:09:40 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#include "I3RecoHitSeries.h"
#include "StoragePolicy.h"
#include "TObject.h"

/// This is the container for all the hit series reconstructions
/**
 * Feature extraction routines which attempt to reconstruct the times
 * at which photoelectrons ("hits") were produced store their results
 * as an I3RecoHitSeries, a series of I3RecoHits.  The I3RecoHitSeriesDict
 * is the container of all I3RecoHitSeries's.  'Dict' indicates that it
 * is a map, with each I3RecoHitSeries identified by a name chosen by
 * the module which produced it.  The syntax for accessing elements in
 * the map is inherited from the MapPolicy, which is currently set to
 * STLMapStoragePolicy.
 */
class I3RecoHitSeriesDict : public TObject, 
      	public MapPolicy<string,I3RecoHitSeriesPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */ 
  I3RecoHitSeriesDict(){}

  /**
   * destructor
   */
  virtual ~I3RecoHitSeriesDict(){};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RecoHitSeriesDict: \n";
      I3RecoHitSeriesDict::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3RecoHitSeriesPtr((I3RecoHitSeries*)0))
	    o<<"Null RecoHitSeries";
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
/*   // copy and assignment are private */
  I3RecoHitSeriesDict(const I3RecoHitSeriesDict& rhs);
  const I3RecoHitSeriesDict& operator=(const I3RecoHitSeriesDict&);

  // ROOT macro
  ClassDef(I3RecoHitSeriesDict,1);
};

inline ostream& operator<<(ostream& o, const I3RecoHitSeriesDict& dict)
{
  dict.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoHitSeriesDict>::ThePolicy I3RecoHitSeriesDictPtr;

#endif

