#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeries.h,v 1.19 2004/03/10 19:31:12 pretz Exp $
 *
 * @version $Revision: 1.19 $
 * @date $Date: 2004/03/10 19:31:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */

#include "I3RecoHit.h"
#include "StoragePolicy.h"

class I3RecoHitSeries : public TObject, public VecPointainerPolicy<I3RecoHitPtr>::ThePolicy
{
 public:
  /**
   *constructor
   */
  I3RecoHitSeries(){};

  /**
   * destructor
   */
  virtual ~I3RecoHitSeries(){};

 private:
  // copy and assignment are private:
  I3RecoHitSeries(const I3RecoHitSeries& rhs);
  const I3RecoHitSeries& operator=(const I3RecoHitSeries&);

  // ROOT macro
  ClassDef(I3RecoHitSeries,1);
};

typedef PtrPolicy<I3RecoHitSeries>::ThePolicy I3RecoHitSeriesPtr;

#endif

