/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoTrackList.h,v 1.11 2004/02/25 21:36:49 pretz Exp $
 *
 * @version $Revision: 1.11 $
 * @date $Date: 2004/02/25 21:36:49 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo decide whether or not copy should be private
 *
 */
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "StoragePolicy.h"

class I3RecoTrackList : public VectorPolicy<I3RecoTrack>::ThePolicy
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
/*   // copy and assignment private */
/*   I3RecoTrackList(const I3RecoTrackList& rhs); */
/*   const I3RecoTrackList& operator=(const I3RecoTrackList& rhs); */

  // ROOT macro
  ClassDef(I3RecoTrackList, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoTrackList>::ThePolicy I3RecoTrackListPtr;

#endif
