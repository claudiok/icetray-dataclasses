#ifndef DATACLASSES_I3RECOHITSERIESDICT_H
#define DATACLASSES_I3RECOHITSERIESDICT_H

/**
 * copyright  (C) 2005
 * the IceCube Collaboration
 * $Id: I3RecoHitSeriesDict.h,v 1.4.12.1 2005/02/18 20:54:55 deyoung Exp $
 *
 * @file I3RecoHitSeriesDict.h
 * @version $Revision: 1.4.12.1 $
 * @date $Date: 2005/02/18 20:54:55 $
 * @author ehrlich
 * @author troy
 * @author pretz
 * @author deyoung
 */

#include "I3RecoHitSeries.h"
#include "I3HitSelectionDict.h"
#include "StoragePolicy.h"
#include "TObject.h"

/// Container for all the hit series reconstructions and hit selections
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

  /**
   * @return the HitSelectionDict for this OM as a constant object
   */
  const I3HitSelectionDict& GetHitSelectionDict() const { 
    return hitSelectionDict_; 
  }

  /**
   * @return the HitSelectionDict as a non-constant object
   */
  I3HitSelectionDict& GetHitSelectionDict() { return hitSelectionDict_; }


  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RecoHitSeriesDict: \n";
      I3RecoHitSeriesDict::const_iterator iter;
      for(iter=begin(); iter!=end(); iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3RecoHitSeriesPtr((I3RecoHitSeries*)0))
	    o<<"Null RecoHitSeries";
	  else
	    o<<*(iter->second);
	}
      o << hitSelectionDict_
	<< "]\n";
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

  I3HitSelectionDict hitSelectionDict_; //||

  // ROOT macro
  ClassDef(I3RecoHitSeriesDict,2);
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

