/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultMultiTracks.h,v 1.5 2004/08/12 17:33:33 pretz Exp $
 *
 * @file I3RecoResultMultiTracks.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/12 17:33:33 $
 * @author ehrlich
 */
#ifndef I3RECORESULTMULTITRACKS_H
#define I3RECORESULTMULTITRACKS_H

#include "I3RecoResult.h"
#include "I3Particle.h"

/**
 * @brief Reco results with more than one track
 */
class I3RecoResultMultiTracks : public I3RecoResult, public VectorPolicy<I3ParticlePtr>::ThePolicy
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
