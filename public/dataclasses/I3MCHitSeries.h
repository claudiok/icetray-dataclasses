#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3MCHit.h"
#include "StoragePolicy.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCHitSeries.h,v 1.15 2004/03/10 17:54:43 pretz Exp $
 *
 *
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/03/10 17:54:43 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo decide whether or not copy and assignment should be private
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
  Double_t Weight() { return fWeight; }

  /**
   * @param weight the new weight for this series
   */
  void Weight(Double_t weight) { fWeight = weight; }

  private:
/*   // copy and assignment are private */
/*   I3MCHitSeries(const I3MCHitSeries&); */
/*   const I3MCHitSeries& operator=(const I3MCHitSeries&); */

  //ROOT Macro
  ClassDef(I3MCHitSeries,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCHitSeries>::ThePolicy I3MCHitSeriesPtr;

#endif
