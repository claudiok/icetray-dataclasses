/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultSingleTrack.h,v 1.6 2004/03/08 21:22:51 pretz Exp $
 *
 * This is a reco result which just contains a single track
 *
 * @version $Revision: 1.6 $
 * @date $Date: 2004/03/08 21:22:51 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3RECORESULTSINGLETRACK_H
#define I3RECORESULTSINGLETRACK_H

#include "I3RecoResult.h"
#include "I3RecoTrack.h"

class I3RecoResultSingleTrack : public I3RecoResult
{
  I3RecoTrack fTrack;
  
 public:
  /**
   * constructor
   */
  I3RecoResultSingleTrack(){}

  /**
   * destructor
   */
  virtual ~I3RecoResultSingleTrack(){}

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3RecoTrack& Track() const {return fTrack;}

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3RecoTrack& Track() {return fTrack;}

 private:
  // copy and assignment are private
  I3RecoResultSingleTrack(const I3RecoResultSingleTrack& rhs);
  const I3RecoResultSingleTrack& operator=(const I3RecoResultSingleTrack&);

  // ROOT macro
  ClassDef(I3RecoResultSingleTrack, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultSingleTrack>::ThePolicy I3RecoResultSingleTrackPtr;

#endif
