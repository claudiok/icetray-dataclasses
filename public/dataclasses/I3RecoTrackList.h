/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoTrackList.h,v 1.16.2.1 2004/04/10 16:38:59 troy Exp $
 *
 * A vector of I3RecoTracks.  May get changed with the upcoming changes
 * to the RecoTrack sector.  Can be included by I3RecoResults if they contain
 * multiple tracks for whatever reason.
 *
 * @version $Revision: 1.16.2.1 $
 * @date $Date: 2004/04/10 16:38:59 $
 * @author ehrlich
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
