/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCHitSeries.h,v 1.21 2004/08/16 16:22:13 pretz Exp $
 *
 * @file I3MCHitSeries.h
 * @version $Revision: 1.21 $
 * @date $Date: 2004/08/16 16:22:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3MCHit.h"
#include "StoragePolicy.h"

/**
 * @brief Array of I3MCHits
 * 
 * Vector of the I3MCHits produced at an OM in an event.  The weight
 * variable (default 1) can be used to assign a statistical weighting
 * factor to the series as a whole, independent of the individual hits.
 */
class I3MCHitSeries : public TObject, public VectorPolicy<I3MCHit>::ThePolicy 
{
  Double_t fWeight;
 public:
  /**
   * constructor
   */
  I3MCHitSeries(){}

  /**
   * destructor
   */
  virtual ~I3MCHitSeries(){}

  /**
   * @return the weight associated with this series
   */
  Double_t GetWeight() { return fWeight; }

  /**
   * @param weight the new weight for this series
   */
  void SetWeight(Double_t weight) { fWeight = weight; }

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3MCHitSeries: \n";
      I3MCHitSeries::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<*iter;
	}
      o<<"]\n";
    }
  
  private:
/*   // copy and assignment are private */
  I3MCHitSeries(const I3MCHitSeries&); 
  const I3MCHitSeries& operator=(const I3MCHitSeries&); 

  //ROOT Macro
  ClassDef(I3MCHitSeries,1);
};

inline ostream& operator<<(ostream& o,const I3MCHitSeries& series)
{
  series.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCHitSeries>::ThePolicy I3MCHitSeriesPtr;

#endif
