/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponseData.h,v 1.15 2004/02/27 22:48:21 ehrlich Exp $
 *
 * An event-level container for the OMResponse's of the Event.  
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/02/27 22:48:21 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3DataExecution.h"
#include "I3OMResponse.h"
#include "StoragePolicy.h"

class I3OMResponseData : public TObject, public VectorPolicy<I3OMResponse>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3OMResponseData(){};

  /**
   * destructor
   */
  virtual ~I3OMResponseData(){};
  
  bool HasOMResponseNumber(unsigned int omnumber) const
  {
    for(unsigned int i=0; i<this->size(); i++)
    {if( (*this)[i].OMNumber()==omnumber ) return(true);}
    return(false);
  }
  
  const I3OMResponse& FindOMResponse(unsigned int omnumber) const 
  { 
    for(unsigned int i=0; i<this->size(); i++)
    {
      if( (*this)[i].OMNumber()==omnumber) return((*this)[i]);
    }
    I3DataExecution::Instance().Fatal("I3OMResponseData::FindOMResponse() asked for a non-existent OM response");
    return(*(I3OMResponse*)NULL);
  }

  private:
  // copy and assignment private
  I3OMResponseData(const I3OMResponseData&);
  const I3OMResponseData& operator=(const I3OMResponseData&);

  // ROOT macro
  ClassDef(I3OMResponseData,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMResponseData>::ThePolicy I3OMResponseDataPtr;

#endif
