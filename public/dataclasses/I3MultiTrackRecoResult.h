#ifndef I3MULTITRACKRECORESULT_H
#define I3MULTITRACKRECORESULT_H

#include "dataclasses/I3RecoTrackList.h"
#include "dataclasses/I3RecoResult.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MultiTrackRecoResult.h,v 1.2 2004/03/09 14:36:05 pretz Exp $
 *
 * A reco result which spits out several tracks expected to be in the event
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/03/09 14:36:05 $
 * @author pretz
 *
 * @todo 
 *
 */

class I3MultiTrackRecoResult : public I3RecoResult{
  I3RecoTrackList fTrackList;

 public:
  /**
   * constructor
   */
  I3MultiTrackRecoResult(){}

  /**
   * destructor
   */
  virtual ~I3MultiTrackRecoResult(){}

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
  I3MultiTrackRecoResult(const I3MultiTrackRecoResult&);
  const I3MultiTrackRecoResult operator=(const I3MultiTrackRecoResult);

  //ROOT macro
  ClassDef(I3MultiTrackRecoResult,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MultiTrackRecoResult>::ThePolicy I3MultiTrackRecoResultPtr;
#endif
