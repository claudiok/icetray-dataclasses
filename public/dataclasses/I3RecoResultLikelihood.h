/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultLikelihood.h,v 1.3 2004/02/25 21:36:49 pretz Exp $
 *
 * The results of a likelihood fit.  Just spits out a likelihood in addition
 * to the tracks.
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/02/25 21:36:49 $
 * @author
 *
 * @todo Shouldn't it be LogLikelihood?  Or is that equivalent in Physics-speak
 *
 */
#ifndef I3RECORESULTLIKELIHOOD_H
#define I3RECORESULTLIKELIHOOD_H

#include "I3RecoResultSingleTrack.h"

class I3RecoResultLikelihood : public I3RecoResultSingleTrack
{
  Float_t fLikelihood;

  public:
  /**
   * constructor
   */
  I3RecoResultLikelihood() { fLikelihood = 0; }

  /**
   * destructor
   */
  virtual ~I3RecoResultLikelihood(){}

  /**
   * @return the likelihood of this solution
   * @todo isn't it LogLikelihood
   */
  Float_t Likelihood() const { return fLikelihood; }

  /**
   * @param likelihood the new likelihood
   */
  void  Likelihood(Float_t likelihood) { fLikelihood = likelihood; }

 private:
  // copy and assignment are private
  I3RecoResultLikelihood(const I3RecoResultLikelihood& rhs);
  const I3RecoResultLikelihood& operator=(const I3RecoResultLikelihood&);

  // ROOT macro
  ClassDef(I3RecoResultLikelihood, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultLikelihood>::ThePolicy I3RecoResultLikelihoodPtr;

#endif

