/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultRDMCFit.h,v 1.5 2004/04/22 15:55:44 pretz Exp $
 *
 * A container for RDMC fits.  Contains a vector of Double_ts which are
 * the fit parameters and a vector of ints which are the tubes used by
 * the fit.
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author pretz
 *
 * @todo make sure the map<string,Double_t> works in interpreted code
 *
 */

#ifndef I3RECORESULTRDMCFIT_H
#define I3RECORESULTRDMCFIT_H

#include "I3RecoResultSingleTrack.h"
#include "dataclasses/I3DataExecution.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class I3RecoResultRDMCFit : public I3RecoResultSingleTrack
{
  map<string,Double_t> fParameters;
  vector<Int_t> fUsedTubes;
  string fFitType;

  public:
  /**
   * constructor
   */
  I3RecoResultRDMCFit(){}

  /**
   * destructor
   */
  virtual ~I3RecoResultRDMCFit(){}

  /**
   * @return the type of this fit as a const object
   */
  const string& FitType() const {return fFitType;}

  /**
   * @return the type of this fit as non-const object
   */
  string& FitName() {return fFitType;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a const object
   */
  const map<string,Double_t>& Parameters() const {return fParameters;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a non-const object
   */
  map<string,Double_t>& Parameters() {return fParameters;}

  /**
   * @return tubes used by this fit as a const object
   */
  const vector<Int_t>& UsedTubes() const {return fUsedTubes;}

  /**
   * @return the tubes used by this fit as a non-const object
   */
  vector<Int_t>& UsedTubes() {return fUsedTubes;}

 private:
  // copy and assignment are private
  I3RecoResultRDMCFit(const I3RecoResultRDMCFit& rhs);
  const I3RecoResultRDMCFit& operator=(const I3RecoResultRDMCFit&);

  // ROOT macro
  ClassDef(I3RecoResultRDMCFit,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultRDMCFit>::ThePolicy I3RecoResultRDMCFitPtr;


#endif

