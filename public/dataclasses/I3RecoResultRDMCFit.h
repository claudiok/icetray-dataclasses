/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultRDMCFit.h,v 1.11.2.1 2005/02/04 06:11:43 troy Exp $
 *
 * @file I3RecoResultRDMCFit.h
 * @version $Revision: 1.11.2.1 $
 * @date $Date: 2005/02/04 06:11:43 $
 * @author pretz
 */

#ifndef I3RECORESULTRDMCFIT_H
#define I3RECORESULTRDMCFIT_H

#include "I3RecoResultSingleTrack.h"
#include "dataclasses/I3DataExecution.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 * @brief A container for RDMC fits.  
 * 
 * Contains a vector of Double_ts which are
 * the fit parameters and a vector of ints which are the tubes used by
 * the fit.
 *
 * @todo make sure the map<string,Double_t> works in interpreted code
 */
class I3RecoResultRDMCFit : public I3RecoResultSingleTrack
{
  map<string,Double_t> fParameters;
  vector<UShort_t> fUsedHits;
  string fFitName;

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
  const string& GetFitName() const {return fFitName;}

  /**
   * @return the type of this fit as non-const object
   */
  string& GetFitName() {return fFitName;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a const object
   */
  const map<string,Double_t>& GetParameters() const {return fParameters;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a non-const object
   */
  map<string,Double_t>& GetParameters() {return fParameters;}

  /**
   * @return tubes used by this fit as a const object
   */
  const vector<UShort_t>& GetUsedHits() const {return fUsedHits;}

  /**
   * @return the tubes used by this fit as a non-const object
   */
  vector<UShort_t>& GetUsedHits() {return fUsedHits;}

  virtual void ToStream(ostream& o) const
    {
      I3RecoResultSingleTrack::ToStream(o);
      o<<"Fit Parameters:\n";
      map<string,Double_t>::const_iterator params;
      for(params = fParameters.begin() ; 
	  params != fParameters.end() ; 
	  params++)
	{
	  o<<params->first<<": "<<params->second<<"\n";
	}
      o<<"Used Hits:\n";
      vector<UShort_t>::const_iterator hits;
      for(hits = fUsedHits.begin();
	  hits != fUsedHits.end();
	  hits++)
	{
	  o<<*hits<<" ";
	}
      o<<"\n";
	
    }

 private:

  // ROOT macro
  ClassDef(I3RecoResultRDMCFit,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultRDMCFit>::ThePolicy I3RecoResultRDMCFitPtr;


#endif

