/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultDict.h,v 1.2 2004/07/03 18:40:57 troy Exp $
 *
 * @file I3RecoResultDict.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/03 18:40:57 $
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

#include "I3RecoResult.h"
#include "StoragePolicy.h"

/**
 * @brief This is the container for all the Track reconstruction results in
 * the event
 *
 */
class I3RecoResultDict : public TObject, public MapPolicy<I3RecoResultPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3RecoResultDict() {};

  /**
   * destructor
   */
  virtual ~I3RecoResultDict() {};

 private:
  // copy and assignment are private
  I3RecoResultDict(const I3RecoResultDict&);
  const I3RecoResultDict& operator=(const I3RecoResultDict&);

  // ROOT macro
  ClassDef(I3RecoResultDict,1);

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultDict>::ThePolicy I3RecoResultDictPtr;

#endif
