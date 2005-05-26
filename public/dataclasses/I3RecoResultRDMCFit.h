/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoResultRDMCFit.h
 * @version $Revision: 1.16 $
 * @date $Date$
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
  map<string,double> parameters_;
  string fitName_;

 public:
  I3RecoResultRDMCFit(){}
  virtual ~I3RecoResultRDMCFit(){}

  /**
   * @return the type of this fit as a const object
   */
  const string& GetFitName() const {return fitName_;}

  /**
   * @return the type of this fit as non-const object
   */
  string& GetFitName() {return fitName_;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a const object
   */
  const map<string,double>& GetParameters() const {return parameters_;}

  /**
   * The parameters of the RDMC fit in the order they appear in the f2k file
   * @return the parameters of this fit as a non-const object
   */
  map<string,double>& GetParameters() {return parameters_;}

  virtual void ToStream(ostream& o) const
  {
    I3RecoResultSingleTrack::ToStream(o);
    o<<"Fit Parameters:\n";
    map<string,double>::const_iterator params;
    for(params=parameters_.begin(); params!=parameters_.end(); params++)
    {
      o<<params->first<<": "<<params->second<<"\n";
    }
    o<<"\n";
  }

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultSingleTrack", base_object<I3RecoResultSingleTrack>(*this));
    ar & make_nvp("FitName", fitName_);
    ar & make_nvp("Parameters", parameters_);
  }

  // ROOT macro
  ClassDef(I3RecoResultRDMCFit,1);
};

BOOST_SHARED_POINTER_EXPORT(I3RecoResultRDMCFit);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultRDMCFit>  I3RecoResultRDMCFitPtr;


#endif

