#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitVectDict.h,v 1.2 2004/07/01 01:31:06 pretz Exp $
 *
 * @file I3RecoHitVectDict.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/01 01:31:06 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#include "I3RecoHitVect.h"
#include "StoragePolicy.h"
#include "TObject.h"

/**
 * @brief This is the container for all the hit series reconstructions
 */
class I3RecoHitVectDict : public TObject, 
      	public MapPointainerPolicy<I3RecoHitVectPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */ 
  I3RecoHitVectDict(){}

  /**
   * destructor
   */
  virtual ~I3RecoHitVectDict(){};

 private:
/*   // copy and assignment are private */
  I3RecoHitVectDict(const I3RecoHitVectDict& rhs);
  const I3RecoHitVectDict& operator=(const I3RecoHitVectDict&);

  // ROOT macro
  ClassDef(I3RecoHitVectDict,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoHitVectDict>::ThePolicy I3RecoHitVectDictPtr;

#endif

