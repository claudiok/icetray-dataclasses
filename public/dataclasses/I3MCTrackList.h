/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackList.h,v 1.20 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3MCTrackList.h
 * @version $Revision: 1.20 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include "I3ObservableParticle.h"
#include "StoragePolicy.h"

/**
 * @brief A list of MCTracks.
 *
 * @todo figure out how to make copy and assignment private
 */
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
