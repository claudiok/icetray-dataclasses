/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitVect.h,v 1.2 2004/07/03 18:40:57 troy Exp $
 *
 * @file I3RecoHitVect.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/03 18:40:57 $
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
class I3RecoHitVect : public TObject, public VectorPolicy<I3RecoHitPtr>::ThePolicy
{
 public:
  /**
   *constructor
   */
  I3RecoHitVect() {};

  /**
   * destructor
   */
  virtual ~I3RecoHitVect() {};

 private:
  // copy and assignment are private:
  I3RecoHitVect (const I3RecoHitVect& rhs);
  const I3RecoHitVect& operator= (const I3RecoHitVect&);

  // ROOT macro
  ClassDef(I3RecoHitVect,1);
};

typedef PtrPolicy<I3RecoHitVect>::ThePolicy I3RecoHitVectPtr;

#endif

