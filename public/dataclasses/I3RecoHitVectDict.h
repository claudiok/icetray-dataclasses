#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitVectDict.h,v 1.5 2004/07/15 20:29:25 deyoung Exp $
 *
 * @file I3RecoHitVectDict.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/07/15 20:29:25 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#include "I3RecoHitVect.h"
#include "StoragePolicy.h"
#include "TObject.h"

/// This is the container for all the hit series reconstructions
/**
 * Feature extraction routines which attempt to reconstruct the times
 * at which photoelectrons ("hits") were produced store their results
 * as an I3RecoHitVect, a series of I3RecoHits.  The I3RecoHitVectDict
 * is the container of all I3RecoHitVect's.  'Dict' indicates that it
 * is a map, with each I3RecoHitVect identified by a name chosen by
 * the module which produced it.  The syntax for accessing elements in
 * the map is inherited from the MapPolicy, which is currently set to
 * STLMapStoragePolicy.
 */
class I3RecoHitVectDict : public TObject, 
      	public MapPolicy<string,I3RecoHitVectPtr>::ThePolicy
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

