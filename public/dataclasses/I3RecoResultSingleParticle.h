/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultSingleParticle.h,v 1.6 2005/04/12 23:11:18 olivas Exp $
 *
 * @file I3RecoResultSingleParticle.h
 * @version $Revision: 1.6 $
 * @date $Date: 2005/04/12 23:11:18 $
 * @author dule
 */

#ifndef I3RECORESULTSINGLEPARTICLE_H
#define I3RECORESULTSINGLEPARTICLE_H

#include "I3RecoResult.h"
#include "I3Particle.h"

/**
 * @brief This is a reco result base class for both InIce and IceTop reconstruction result objects.
 */
class I3RecoResultSingleParticle : public I3RecoResult
{
	I3ParticlePtr particle_;
  
	// TDS FIXME most of this has/get/set stuff can go away.  You just
	// get the pointer out, it either points to something valid or it
	// points to nothing.

 public:
	/**
	 * constructor
	 */
	I3RecoResultSingleParticle() { } // particle will automatically be "NULL" 

	/**
	 * destructor
	 */
	virtual ~I3RecoResultSingleParticle() { }

	/**
	 * Retrieves the particle in this reco result as a constant object
	 */
	const I3ParticlePtr GetParticle() const { return particle_; }

	/**
	 * Retrieves the particle of this reco result as a non-const object
	 */
	I3ParticlePtr GetParticle() { return particle_; }

	/**
	 * indicates that there is a particle in the result
	 */
	bool HasParticle() const {
		//TDS: the smart pointer automagically converts to bool
		return particle_;
	}
  
	/**
	 * sets the particle in the result
	 * Fails the program if it is already set.
	 */
	void SetParticle(I3ParticlePtr particle) {
	  if (particle_) {
	    log_fatal("I3RecoResultSingleParticle::SetParticle() particle exists already");
	    return;
	  }
	  particle_ = particle;
	}

	/**
	 * Puts the contents of the container (a reco result) into the stream
	 */
	virtual void ToStream(ostream& o) const {
	  I3RecoResult::ToStream(o);
	  o<<"The Particle:\n";
	  if(particle_)
	    o<<*particle_<<"\n";
	  else
	    o<<"NULL Particle\n";
	}
  
 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Particle", particle_);
  }
  
  // ROOT macro
  ClassDef(I3RecoResultSingleParticle, 1);
};

BOOST_CLASS_EXPORT(I3RecoResultSingleParticle);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultSingleParticle>  I3RecoResultSingleParticlePtr;

#endif
