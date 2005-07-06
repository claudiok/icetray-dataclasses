/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoResultMultiTracks.h
 * @version $Revision: 1.8 $
 * @date $Date$
 * @author ehrlich
 */
#ifndef I3RECORESULTMULTITRACKS_H
#define I3RECORESULTMULTITRACKS_H

#include "I3RecoResult.h"
#include "I3Particle.h"

/**
 * @brief Reco results with more than one track
 */
class I3RecoResultMultiTracks : public I3RecoResult, public STLVectorStoragePolicy<I3ParticlePtr>
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
	//particle = dynamic_pointer_cast<I3Particle>((*this)[i]);
	//particle->ToStream(o);
	o<<endl;
      }
    };

  private:

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResult",base_object<I3RecoResult>(*this));
    ar & make_nvp("I3ParticlePtrVector",base_object< STLVectorStoragePolicy<I3ParticlePtr> >(*this));
  }

  //ROOT macro
  ClassDef(I3RecoResultMultiTracks,1);
};

BOOST_SHARED_POINTER_EXPORT(I3RecoResultMultiTracks);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultMultiTracks> I3RecoResultMultiTracksPtr;
#endif
