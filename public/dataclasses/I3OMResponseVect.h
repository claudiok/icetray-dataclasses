/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponseVect.h,v 1.3 2004/07/12 12:23:11 pretz Exp $
 *
 * @file I3OMResponseVect.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/12 12:23:11 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3DataExecution.h"
#include "I3OMResponse.h"
#include "StoragePolicy.h"

/**
 * @brief An event-level container for the OMResponse's of the Event.  
 *
 * @todo implement the 'FindOMResponse' as a smarter search, STL???
 *
 */
class I3OMResponseVect : public TObject, public VectorPolicy<I3OMResponsePtr>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3OMResponseVect(){};

  /**
   * destructor
   */
  virtual ~I3OMResponseVect(){};
  
  /**
   * loops through the omresponses looking for one with a number 'omnumber'
   * and returns it.  Returns 0 if none are found
   */
  const I3OMResponsePtr FindOMResponse(unsigned int omnumber) const 
  { 
    const_iterator iter;
    for(iter = begin() ; iter!= end() ; iter++){
      if(*iter != 0)
	if((*iter)->GetOMNumber()==omnumber)
	  return *iter;
    }
    //FIXME: ugly
    return I3OMResponsePtr();
  }

  private:
  // copy and assignment private
  I3OMResponseVect(const I3OMResponseVect&);
  const I3OMResponseVect& operator=(const I3OMResponseVect&);

  // ROOT macro
  ClassDef(I3OMResponseVect,1);
};

inline ostream& operator<<(ostream& o,const I3OMResponseVect& v)
{
  I3OMResponseVect::const_iterator iter;
  for(iter=v.begin();iter!=v.end();iter++)
    {
      if(*iter==I3OMResponsePtr((I3OMResponse*)0))
	o<<"Null OMRespone";
      else
	o<<**iter;
    }
   
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMResponseVect>::ThePolicy I3OMResponseVectPtr;

#endif
