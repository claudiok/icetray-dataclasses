#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3DataExecution.h"
#include "I3OMResponse.h"
#include "StoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponseData.h,v 1.17 2004/03/10 18:39:56 pretz Exp $
 *
 * An event-level container for the OMResponse's of the Event.  
 *
 * @version $Revision: 1.17 $
 * @date $Date: 2004/03/10 18:39:56 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo implement the 'FindOMResponse' as a smarter search, STL???
 *
 */
class I3OMResponseData : public TObject, public VecPointainerPolicy<I3OMResponsePtr>::ThePolicy
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
  
  /**
   * loops through the omresponses looking for one with a number 'omnumber'
   * and returns it.  Returns 0 if none are found
   */
  const I3OMResponsePtr FindOMResponse(unsigned int omnumber) const 
  { 
    const_iterator iter;
    for(iter = begin() ; iter!= end() ; iter++){
      if(*iter != 0)
	if((*iter)->OMNumber()==omnumber)
	  return *iter;
    }
    return 0;
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
