/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoTrackList.h,v 1.15 2004/03/10 19:31:12 pretz Exp $
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/03/10 19:31:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "StoragePolicy.h"

class I3RecoTrackList : public TObject, public VecPointainerPolicy<I3RecoTrackPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3RecoTrackList(){}

  /**
   * destructor
   */
  virtual ~I3RecoTrackList(){};
 private:
  // copy and assignment private
  I3RecoTrackList(const I3RecoTrackList& rhs);
  const I3RecoTrackList& operator=(const I3RecoTrackList& rhs);

  // ROOT macro
  ClassDef(I3RecoTrackList, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoTrackList>::ThePolicy I3RecoTrackListPtr;

#endif
