#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackList.h,v 1.18 2004/04/23 19:47:40 deyoung Exp $
 *
 * A list of MCTracks.
 *
 * @version $Revision: 1.18 $
 * @date $Date: 2004/04/23 19:47:40 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo figure out how to make copy and assignment private
 *
 */

#include "I3MCTrack.h"
#include "StoragePolicy.h"

class I3MCTrackList : public TObject, public VecPointainerPolicy<I3ObservableParticlePtr>::ThePolicy
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
/*   I3MCTrackList(const I3MCTrackList&);  */
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
