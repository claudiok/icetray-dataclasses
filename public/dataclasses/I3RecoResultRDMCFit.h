/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultRDMCFit.h,v 1.15 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3RecoResultRDMCFit.h
 * @version $Revision: 1.15 $
 * @date $Date: 2005/04/09 03:02:10 $
 * @author pretz
 */

#ifndef I3RECORESULTRDMCFIT_H
#define I3RECORESULTRDMCFIT_H

#include "I3RecoResultSingleTrack.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 * @brief A container for RDMC fits.  
 * 
 * Contains a vector of doubles which are
 * the fit parameters and a vector of ints which are the tubes used by
 * the fit.
 *
 * @todo make sure the map<string,double> works in interpreted code
 */
class I3RecoResultRDMCFit : public I3RecoResultSingleTrack
{
  map<string,double> fParameters;
  vector<unsigned short> fUsedHits;
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
  const map<string,double>& GetParameters() const {return fParameters;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a non-const object
   */
  map<string,double>& GetParameters() {return fParameters;}

  /**
   * @return tubes used by this fit as a const object
   */
  const vector<unsigned short>& GetUsedHits() const {return fUsedHits;}

  /**
   * @return the tubes used by this fit as a non-const object
   */
  vector<unsigned short>& GetUsedHits() {return fUsedHits;}

  virtual void ToStream(ostream& o) const
    {
      I3RecoResultSingleTrack::ToStream(o);
      o<<"Fit Parameters:\n";
      map<string,double>::const_iterator params;
      for(params = fParameters.begin() ; 
	  params != fParameters.end() ; 
	  params++)
	{
	  o<<params->first<<": "<<params->second<<"\n";
	}
      o<<"Used Hits:\n";
      vector<unsigned short>::const_iterator hits;
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
typedef shared_ptr<I3RecoResultRDMCFit>  I3RecoResultRDMCFitPtr;


#endif

