#ifndef I3ALTTRACKSRECORESULT_H
#define I3ALTTRACKSRECORESULT_H

#include "dataclasses/I3RecoTrackList.h"
#include "dataclasses/I3RecoResult.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AltTracksRecoResult.h,v 1.1 2004/03/09 14:36:05 pretz Exp $
 *
 * A reco result which can't decide among several possible tracks and returns
 * them all
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/09 14:36:05 $
 * @author pretz
 *
 * @todo 
 *
 */

class I3AltTracksRecoResult : public I3RecoResult{
  I3RecoTrackList fTrackList;

 public:
  /**
   * constructor
   */
  I3AltTracksRecoResult(){}

  /**
   * destructor
   */
  virtual ~I3AltTracksRecoResult(){}

  /**
   * @return the tracks that this result thinks are in the event as a const object
   */
  const I3RecoTrackList& TrackList() const {return fTrackList;}

  /**
   * @return the tracks that this result thinks are in the event as a non-const object
   */
  I3RecoTrackList& TrackList(){return fTrackList;}

 private:
  // copy and assignment private
  I3AltTracksRecoResult(const I3AltTracksRecoResult&);
  const I3AltTracksRecoResult operator=(const I3AltTracksRecoResult);

  //ROOT macro
  ClassDef(I3AltTracksRecoResult,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AltTracksRecoResult>::ThePolicy I3AltTracksRecoResultPtr;
#endif
