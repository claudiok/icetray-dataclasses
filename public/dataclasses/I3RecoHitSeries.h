#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeries.h,v 1.14 2004/02/25 20:57:14 pretz Exp $
 *
 * @version $Revision: 1.14 $
 * @date $Date: 2004/02/25 20:57:14 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo this class shouldn't have a 'confidence' but rather be a base for classes which themselves might have a confidence
 *
 */

#include "I3RecoHit.h"
#include "StoragePolicy.h"

class I3RecoHitSeries : public VectorPolicy<I3RecoHit>::ThePolicy
{
  float fConfidence;
 public:
  /**
   *constructor
   */
  I3RecoHitSeries(){};

  /**
   * destructor
   */
  virtual ~I3RecoHitSeries(){};

  /**
   * @return the confidence of this hit
   */
  float Confidence() { return fConfidence; }

  /**
   * @param confidence the new confidence in this hit
   */
  void Confidence(float confidence) { fConfidence = confidence; }

 private:
  // copy and assignment are private:
  I3RecoHitSeries(const I3RecoHitSeries& rhs);
  const I3RecoHitSeries& operator=(const I3RecoHitSeries&);

  // ROOT macro
  ClassDef(I3RecoHitSeries,1);
};

typedef PtrPolicy<I3RecoHitSeries>::ThePolicy I3RecoHitSeriesPtr;

#endif

