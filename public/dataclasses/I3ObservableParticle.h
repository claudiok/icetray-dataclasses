/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3ObservableParticle.h,v 1.1.2.2 2004/04/21 16:03:10 pretz Exp $
 *
 * @file I3ObservableParticle.h
 * @version $Revision: 1.1.2.2 $
 * @date $Date: 2004/04/21 16:03:10 $
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

 private:
  //ROOT macro
  ClassDef(I3ObservableParticle,1);
};

#endif //I3OBSERVABLEPARTICLE_H
