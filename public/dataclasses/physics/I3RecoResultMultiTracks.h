/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3RecoResultMultiTracks.h
 * @date $Date$
 */

#ifndef I3RECORESULTMULTITRACKS_H_INCLUDED
#define I3RECORESULTMULTITRACKS_H_INCLUDED

#include "I3RecoResult.h"
#include "I3Particle.h"
#include "dataclasses/I3Vector.h"

/**
 * @brief Reco results with more than one track
 */
class I3RecoResultMultiTracks : public I3RecoResult, public I3Vector<I3ParticlePtr>
{
  public:

  I3RecoResultMultiTracks(){}

  virtual ~I3RecoResultMultiTracks();

  /**
   * Print out all information about the I3Position to the given ostream
   */
  virtual void ToStream(ostream& o) const
    {
      I3ParticlePtr particle;
      for (unsigned i=0; i<this->size(); i++) {
        o<<"printing MultiTracks["<<i<<"]...\n";
	//particle = dynamic_pointer_cast<I3Particle>((*this)[i]);
	//particle->ToStream(o);
	o<<endl;
      }
    };

  private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  //ClassDef(I3RecoResultMultiTracks,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultMultiTracks> I3RecoResultMultiTracksPtr;
#endif //I3RECORESULTMULTITRACKS_H_INCLUDED

