/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponse.h,v 1.38.4.2 2005/02/04 06:11:43 troy Exp $

    @file I3OMResponse.h
    @version $Revision: 1.38.4.2 $
    @date $Date: 2005/02/04 06:11:43 $
    @author ehrlich
    @author troy
    @author pretz
    @author klein
*/
#ifndef I3OMRESPONSE_H
#define I3OMRESPONSE_H

#include "I3DataExecution.h"
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

  I3DataReadoutDict   fDataReadoutDict; //||
  I3RecoHitSeriesDict fRecoHitSeriesDict; //||

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
  const I3DataReadoutDict& GetDataReadoutDict() const {return fDataReadoutDict;}
  
  /**
   * @return the hardware data for this response as a non-const object
   */
  I3DataReadoutDict& GetDataReadoutDict() {return fDataReadoutDict;}

  /**
   * @return the reco hit series data as a const object
   */
  const I3RecoHitSeriesDict& GetRecoHitSeriesDict() const 
    {
      return fRecoHitSeriesDict;
    }
  
  /**
   * @return the reco hit series data as a non-const object
   */
  I3RecoHitSeriesDict& GetRecoHitSeriesDict() {return fRecoHitSeriesDict;}

  /**
   * @todo finish implementing this method
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMResponse\n"
       <<fDataReadoutDict
       <<"]";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

  private:
 
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
typedef PtrPolicy<I3OMResponse>::ThePolicy I3OMResponsePtr;

#endif
