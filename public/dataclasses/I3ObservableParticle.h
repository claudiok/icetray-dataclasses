/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3ObservableParticle.h,v 1.3 2004/04/23 16:37:08 pretz Exp $
 *
 * @file I3ObservableParticle.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/23 16:37:08 $
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3OBSERVABLEPARTICLE_H
#define I3OBSERVABLEPARTICLE_H

#include "dataclasses/I3Particle.h"

/**
 * This class is a base class for the different particles that can appear in 
 * the physical detector (as opposed to Primaries).
 */
class I3ObservableParticle : public I3Particle
{
 public:
  /**
   * indicates that this particle is a Cascade, and so dynamic casting to
   * I3Cascade should be ok
   */
  virtual Bool_t IsCascade() =0;

  /**
   * indicates that this particle is a track and so dynamic casting to I3Track
   * should be ok
   */
  virtual Bool_t IsTrack() =0;

  /**
   * Gives an X along the track, corresponding to Y,Z and T.
   */
  virtual Double_t X() const = 0;

  /**
   * Gives a Y along the track, corresponding to X, Z and T
   */
  virtual Double_t Y() const = 0;

  /**
   * Gives a Z along the track, corresponding to X, Y and T
   */
  virtual Double_t Z() const  = 0;

  /**
   * Gives a T along the track, corresponding to X,Y and Z
   */
  virtual Double_t T() const = 0;
 private:
  //ROOT macro
  ClassDef(I3ObservableParticle,1);
};

#endif //I3OBSERVABLEPARTICLE_H
