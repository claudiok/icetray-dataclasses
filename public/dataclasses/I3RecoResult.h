/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResult.h,v 1.18 2004/02/25 21:36:49 pretz Exp $
 *
 * @version $Revision: 1.18 $
 * @date $Date: 2004/02/25 21:36:49 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo get/set best stuff
 * @todo Should this base class contain the mechanics for storing reco results or should that be left for derived classes???
 *
 */
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"

#include "StoragePolicy.h"

class I3RecoResult 
: public TObject, 
  public VectorPolicy<I3RecoTrackList>::ThePolicy
{
 public:
  /**
   * constructor
   */ 
  I3RecoResult(){}

  /**
   * destructor
   */
  virtual ~I3RecoResult() {}

 private:
  // copy and assignment are private
  I3RecoResult(const I3RecoResult& rhs);
  const I3RecoResult& operator=(const I3RecoResult&);

  // ROOT macro
  ClassDef(I3RecoResult, 1);
};

typedef PtrPolicy<I3RecoResult>::ThePolicy I3RecoResultPtr;

#endif
