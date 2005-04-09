/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponse.h,v 1.42 2005/04/09 03:02:10 olivas Exp $

    @file I3OMResponse.h
    @version $Revision: 1.42 $
    @date $Date: 2005/04/09 03:02:10 $
    @author ehrlich
    @author troy
    @author pretz
    @author klein
*/
#ifndef I3OMRESPONSE_H
#define I3OMRESPONSE_H

#include <TObject.h>

#include "I3OMGeo.h"
#include "I3DataReadoutDict.h"
#include "I3RecoHitSeriesDict.h"
#include <sstream>

/**
 * @brief The container for all the OMResponse-related data in the event
 *
 * Has the hardware response, and the reconstructed hit series'.    
 * The Monte Carlo information is now in I3MCOMResponse.h
 */
class I3OMResponse : public TObject
{
  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment

  I3DataReadoutDict   dataReadoutDict_; //||
  I3RecoHitSeriesDict recoHitSeriesDict_; //||

 public:
  /**
   * constructor
   */
  I3OMResponse() {}
  
  /**
   * destructor
   */
  virtual ~I3OMResponse() {;}
  
  /**
   * @return the the hardware data for this response as a const object
   */
  const I3DataReadoutDict& GetDataReadoutDict() const {return dataReadoutDict_;}
  
  /**
   * @return the hardware data for this response as a non-const object
   */
  I3DataReadoutDict& GetDataReadoutDict() {return dataReadoutDict_;}

  /**
   * @return the reco hit series data as a const object
   */
  const I3RecoHitSeriesDict& GetRecoHitSeriesDict() const 
    {
      return recoHitSeriesDict_;
    }
  
  /**
   * @return the reco hit series data as a non-const object
   */
  I3RecoHitSeriesDict& GetRecoHitSeriesDict() {return recoHitSeriesDict_;}

  /**
   * @todo finish implementing this method
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMResponse\n"
       <<dataReadoutDict_
       <<"]";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

  private:
 
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("DataReadoutDict", dataReadoutDict_);
    ar & make_nvp("RecoHitSeriesDict", recoHitSeriesDict_);
  }

  // ROOT macro
  ClassDef(I3OMResponse,1);
};

/**
 * streams an I3OMResponse to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,I3OMResponse& resp)
{
  resp.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3OMResponse>  I3OMResponsePtr;

#endif
