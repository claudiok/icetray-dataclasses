#ifndef I3RECORESULTLIKELIHOOD_H
#define I3RECORESULTLIKELIHOOD_H

#include "I3RecoResultSingleTrack.h"
#include "dataclasses/I3DataExecution.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultLikelihood.h,v 1.5 2004/03/14 15:07:12 pretz Exp $
 *
 * The results of a likelihood fit.  Just spits out a likelihood in addition
 * to the tracks.
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/03/14 15:07:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */
class I3RecoResultLikelihood : public I3RecoResultSingleTrack
{
  Double_t fLogLikelihood;

  public:
  /**
   * constructor
   */
  I3RecoResultLikelihood() : fLogLikelihood(0){}

  /**
   * destructor
   */
  virtual ~I3RecoResultLikelihood(){}

  /**
   * @return the log likelihood of this solution 
   * @note this should be a negative number.
   */
  Double_t LogLikelihood() const { return fLogLikelihood; }

  /**
   * @param likelihood the new log likelihood for the solution
   * @note this should be a negative number
   */
  void LogLikelihood(Double_t likelihood) { 
    if(likelihood > 0)
      I3DataExecution::Instance().GetLogger().Warn("I3RecoResultLikelihood::LogLikelihood setting log likelihood to non-physical ('positive') number");
    fLogLikelihood = likelihood; 
  }

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

