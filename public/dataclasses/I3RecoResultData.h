/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultData.h,v 1.17 2004/04/22 15:55:44 pretz Exp $
 *
 * This is the container for all the Track reconstruction results in
 * the event
 *
 * @version $Revision: 1.17 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author ehrlich
 * @author pretz
 *
 * @todo
 *
 */

#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

#include "I3RecoResult.h"
#include "StoragePolicy.h"

class I3RecoResultData : public TObject, public MapPointainerPolicy<I3RecoResultPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3RecoResultData() {};

  /**
   * destructor
   */
  virtual ~I3RecoResultData() {};

 private:
  // copy and assignment are private
  I3RecoResultData(const I3RecoResultData&);
  const I3RecoResultData& operator=(const I3RecoResultData&);

  // ROOT macro
  ClassDef(I3RecoResultData,1);

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultData>::ThePolicy I3RecoResultDataPtr;

#endif
