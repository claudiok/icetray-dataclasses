#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackList.h,v 1.13 2004/02/26 03:51:13 pretz Exp $
 *
 * A list of MCTracks.
 *
 * @version $Revision: 1.13 $
 * @date $Date: 2004/02/26 03:51:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo decide if copy and assignment are private
 *
 */

#include "I3MCTrack.h"
#include "StoragePolicy.h"

class I3MCTrackList : public VectorPolicy<I3MCTrack>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCTrackList(){};

  /**
   * destructor
   */
  virtual ~I3MCTrackList(){};

 private:
  // copy and assignment private
/*   I3MCTrackList(const I3MCTrackList&); */
/*   const I3MCTrackList& operator=(const I3MCTrackList&); */

  // ROOT macro
  ClassDef(I3MCTrackList,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCTrackList>::ThePolicy I3MCTrackListPtr;

#endif
