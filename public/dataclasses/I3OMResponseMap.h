/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponseMap.h,v 1.1 2004/07/13 12:30:55 pretz Exp $
 *
 * @file I3OMResponseMap.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/13 12:30:55 $
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
#include "OMKey.h"
#include <map>

using namespace std;

/**
 * @brief An event-level container for the OMResponse's of the Event.  
 *
 * @todo implement the 'FindOMResponse' as a smarter search, STL???
 *
 */
class I3OMResponseMap : public TObject, public map<OMKey,I3OMResponsePtr>
{
  public:
  /**
   * constructor
   */
  I3OMResponseMap(){};

  /**
   * destructor
   */
  virtual ~I3OMResponseMap(){};
  
  /**
   * loops through the omresponses looking for one with a number 'omnumber'
   * and returns it.  Returns 0 if none are found
   */
/*   const I3OMResponsePtr FindOMResponse(unsigned int omnumber) const  */
/*   {  */
/*     const_iterator iter; */
/*     for(iter = begin() ; iter!= end() ; iter++){ */
/*       if(*iter != 0) */
/* 	if((*iter)->GetOMNumber()==omnumber) */
/* 	  return *iter; */
/*     } */
/*     //FIXME: ugly */
/*     return I3OMResponsePtr(); */
/*   } */

  private:
  // copy and assignment private
  I3OMResponseMap(const I3OMResponseMap&);
  const I3OMResponseMap& operator=(const I3OMResponseMap&);

  // ROOT macro
  ClassDef(I3OMResponseMap,1);
};

inline ostream& operator<<(ostream& o,const I3OMResponseMap& v)
{
  o<<"[ I3OMResponseMap: \n";
  I3OMResponseMap::const_iterator iter;
  for(iter=v.begin();iter!=v.end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3OMResponsePtr((I3OMResponse*)0))
	o<<"Null I3OMResponse";
      else
	o<<*(iter->second);
    }
  o<<"]\n";
  return o;
   
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMResponseMap>::ThePolicy I3OMResponseMapPtr;

#endif
