/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCHitSeries.h,v 1.23.4.1 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3MCHitSeries.h
 * @version $Revision: 1.23.4.1 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3MCHit.h"
#include "StoragePolicy.h"
#include <sstream>

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
   * earliest hit time
   */
  Double_t GetFirstHitTime() {
    if (this->size()) { 
      Double_t min = (*this->begin()).GetTime();
      I3MCHitSeries::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++) {
	if(min>(*iter).GetTime()) min=(*iter).GetTime();
      }
      return(min);
    }
    else return(NAN);       
  };

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

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
  private:
/*   // copy and assignment are private */
  I3MCHitSeries(const I3MCHitSeries&); 
  const I3MCHitSeries& operator=(const I3MCHitSeries&); 

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
