#ifndef I3RECORESULTALTTRACKS_H
#define I3RECORESULTALTTRACKS_H

#include "I3RecoResult.h"
#include "I3Particle.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultAltTracks.h,v 1.2 2004/04/25 20:40:27 ehrlich Exp $
 *
 * Reco result with several alternative solutions
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/25 20:40:27 $
 * @author ehrlich
 *
 * @todo 
 *
 */

class I3RecoResultAltTracks : public I3RecoResult, public MapPointainerPolicy<I3ParticlePtr>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3RecoResultAltTracks(){}

  /**
   * destructor
   */
  virtual ~I3RecoResultAltTracks(){}

  private:
  // copy and assignment private
  I3RecoResultAltTracks(const I3RecoResultAltTracks&);
  const I3RecoResultAltTracks operator=(const I3RecoResultAltTracks);

  //ROOT macro
  ClassDef(I3RecoResultAltTracks,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultAltTracks>::ThePolicy I3RecoResultAltTracksPtr;
#endif
