/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @file I3OMResponse.h
    @version $Revision: 1.42 $
    @date $Date$
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
#include "I3RecoPulseSeriesDict.h"
#include <sstream>

/**
 * @brief The container for all the OMResponse-related data in the event
 *
 * Has the hardware response, and the reconstructed hit series'.    
 * The Monte Carlo information is now in I3MCOMResponse.h
 */
class I3OMResponse : public TObject
{
  I3DataReadoutDict     dataReadoutDict_; 
  I3RecoHitSeriesDict   recoHitSeriesDict_; 
  I3RecoPulseSeriesDict recoPulseSeriesDict_; 

  public:
  /**
   * constructor
   */
  I3OMResponse() {}
  
  /**
   * destructor
   */
  virtual ~I3OMResponse();
  
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
  const I3RecoHitSeriesDict& GetRecoHitSeriesDict() const {return recoHitSeriesDict_;}
  
  /**
   * @return the reco hit series data as a non-const object
   */
  I3RecoHitSeriesDict& GetRecoHitSeriesDict() {return recoHitSeriesDict_;}

  /**
   * @return the reco pulse series data as a const object
   */
  const I3RecoPulseSeriesDict& GetRecoPulseSeriesDict() const {return recoPulseSeriesDict_;}

  /**
   * @return the reco pulse series data as a non-const object
   */
  I3RecoPulseSeriesDict& GetRecoPulseSeriesDict() {return recoPulseSeriesDict_;}

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

  template <class Archive> void serialize(Archive & ar, unsigned version);
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

