#ifndef I3RECORESULTMULTITRACKS_H
#define I3RECORESULTMULTITRACKS_H

#include "I3RecoResult.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultMultiTracks.h,v 1.2 2004/04/25 20:40:27 ehrlich Exp $
 *
 * Reco results with more than one track
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/25 20:40:27 $
 * @author ehrlich
 *
 * @todo 
 *
 */

class I3RecoResultMultiTracks : public I3RecoResult, public VecPointainerPolicy<I3ParticlePtr>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3RecoResultMultiTracks(){}

  /**
   * destructor
   */
  virtual ~I3RecoResultMultiTracks(){}

  private:
  // copy and assignment private
  I3RecoResultMultiTracks(const I3RecoResultMultiTracks&);
  const I3RecoResultMultiTracks operator=(const I3RecoResultMultiTracks);

  //ROOT macro
  ClassDef(I3RecoResultMultiTracks,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultMultiTracks>::ThePolicy I3RecoResultMultiTracksPtr;
#endif
