/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultRDMCFit.h,v 1.1 2004/03/08 22:34:45 pretz Exp $
 *
 * The results of a likelihood fit.  Just spits out a likelihood in addition
 * to the tracks.
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/08 22:34:45 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */
#ifndef I3RECORESULTRDMCFIT_H
#define I3RECORESULTRDMCFIT_H

#include "I3RecoResultSingleTrack.h"
#include "dataclasses/I3DataExecution.h"

class I3RecoResultRDMCFit : public I3RecoResultSingleTrack
{
  Double_t fLogRDMCFit;

  public:
  /**
   * constructor
   */
  I3RecoResultRDMCFit(){}

  /**
   * destructor
   */
  virtual ~I3RecoResultRDMCFit(){}

 private:
  // copy and assignment are private
  I3RecoResultRDMCFit(const I3RecoResultRDMCFit& rhs);
  const I3RecoResultRDMCFit& operator=(const I3RecoResultRDMCFit&);

  // ROOT macro
  ClassDef(I3RecoResultRDMCFit, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultRDMCFit>::ThePolicy I3RecoResultRDMCFitPtr;


#endif

