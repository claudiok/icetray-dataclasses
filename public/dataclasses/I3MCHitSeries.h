/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCHitSeries.h,v 1.20 2004/08/02 15:29:52 blaufuss Exp $
 *
 * @file I3MCHitSeries.h
 * @version $Revision: 1.20 $
 * @date $Date: 2004/08/02 15:29:52 $
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

  private:
/*   // copy and assignment are private */
  I3MCHitSeries(const I3MCHitSeries&); 
  const I3MCHitSeries& operator=(const I3MCHitSeries&); 

  //ROOT Macro
  ClassDef(I3MCHitSeries,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCHitSeries>::ThePolicy I3MCHitSeriesPtr;

#endif
