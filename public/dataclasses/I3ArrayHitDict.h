/**
    $Id: I3ArrayHitDict.h,v 1.2 2004/08/01 00:41:01 pretz Exp $
    @file I3ArrayHitDict.h
    @version $Revision: 1.2 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
    @author blaufuss
*/

#ifndef I3ArrayHitDict_H
#define I3ArrayHitDict_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/I3ArrayHit.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3ArrayHitDict : public TObject,
	 public MapPolicy<string, I3ArrayHitPtr>::ThePolicy {

 public:
  /**
   * constructor
   */
  I3ArrayHitDict() {}
  
  /**
   * destructor
   */
  virtual ~I3ArrayHitDict() {}
  
 private:
  // copy and assignment are private
  I3ArrayHitDict(const I3ArrayHitDict&); 
  const I3ArrayHitDict& operator=(const I3ArrayHitDict&); 

  // ROOT macro
  ClassDef(I3ArrayHitDict,1);
};

/**
 * pointer typedeffed away to insulate users from memory managment
 */
typedef PtrPolicy<I3ArrayHitDict>::ThePolicy I3ArrayHitDictPtr;

#endif
