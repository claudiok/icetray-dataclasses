/**
    $Id: I3ArrayHitData.h,v 1.2 2004/07/13 16:24:52 niessen Exp $
    @file I3ArrayHitData.h
    @version $Revision: 1.2 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
*/

#ifndef I3ArrayHitData_H
#define I3ArrayHitData_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/I3ArrayHit.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3ArrayHitData : public TObject,
	 public MapPolicy<string, I3ArrayHitPtr>::ThePolicy {

 public:
  /**
   * constructor
   */
  I3ArrayHitData() {}
  
  /**
   * destructor
   */
  virtual ~I3ArrayHitData() {}
  
 private:
  // copy and assignment are private
  I3ArrayHitData(const I3ArrayHitData&); 
  const I3ArrayHitData& operator=(const I3ArrayHitData&); 

  // ROOT macro
  ClassDef(I3ArrayHitData,1);
};


typedef PtrPolicy<I3ArrayHitData>::ThePolicy I3ArrayHitDataPtr;

#endif
