/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeries.h,v 1.25 2004/08/16 16:22:13 pretz Exp $
 *
 * @file I3RecoHitSeries.h
 * @version $Revision: 1.25 $
 * @date $Date: 2004/08/16 16:22:13 $
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3RecoHit.h"
#include "StoragePolicy.h"

/**
 * @brief A list of reco hits.
 */
class I3RecoHitSeries : public TObject, public VectorPolicy<I3RecoHitPtr>::ThePolicy
{
 public:
  /**
   *constructor
   */
  I3RecoHitSeries() {};

  /**
   * destructor
   */
  virtual ~I3RecoHitSeries() {};

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RecoHitSeries: \n";
      I3RecoHitSeries::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  if(*iter == I3RecoHitPtr((I3RecoHit*)0))
	    o<<"Null I3RecoHit";
	  else
	    o<<*(*iter);
	}
      o<<"]\n";
    }
  
 private:
  // copy and assignment are private:
  I3RecoHitSeries (const I3RecoHitSeries& rhs);
  const I3RecoHitSeries& operator= (const I3RecoHitSeries&);

  // ROOT macro
  ClassDef(I3RecoHitSeries,1);
};

inline ostream& operator<<(ostream& o, const I3RecoHitSeries& series)
{
  series.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3RecoHitSeries>::ThePolicy I3RecoHitSeriesPtr;

#endif

