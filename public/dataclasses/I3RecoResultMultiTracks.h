/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultMultiTracks.h,v 1.7.2.3 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3RecoResultMultiTracks.h
 * @version $Revision: 1.7.2.3 $
 * @date $Date: 2005/02/04 21:51:03 $
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

  /**
   * Print out all information about the I3Position to the given ostream
   */
  virtual void ToStream(ostream& o) const
    {
      I3ParticlePtr particle;
      for (unsigned i=0; i<this->size(); i++) {
        o<<"printing MultiTracks["<<i<<"]...\n";
	particle = dynamic_pointer_cast<I3Particle>((*this)[i]);
	particle->ToStream(o);
	o<<endl;
      }
    };

  private:

  //ROOT macro

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultMultiTracks>::ThePolicy I3RecoResultMultiTracksPtr;
#endif
