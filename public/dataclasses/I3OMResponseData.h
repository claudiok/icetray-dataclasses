/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMResponseData.h,v 1.14 2004/02/25 20:10:24 pretz Exp $
 *
 * An event-level container for the OMResponse's of the Event.  
 *
 * @version $Revision: 1.14 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"
#include "StoragePolicy.h"

class I3OMResponseData 
: public TObject, 
  public VectorPolicy<I3OMResponse>::ThePolicy
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
