/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultSingleTopShower.h,v 1.1 2005/02/23 21:46:58 dule Exp $
 *
 * @file I3RecoResultSingleTopShower.h
 * @version $Revision: 1.1 $
 * @date $Date: 2005/02/23 21:46:58 $
 * @author Peter Niessen
 * @author dule
 */

#ifndef I3RECORESULTSINGLETOPSHOWER_H
#define I3RECORESULTSINGLETOPSHOWER_H

#include "I3DataExecution.h"
#include "dataclasses/I3RecoResultSingleParticle.h"

/**
 * @brief This is a reco result which just contains a single IceTop shower
 */
class I3RecoResultSingleTopShower : public I3RecoResultSingleParticle
{
  
 public:
	/**
	 * constructor
	 */
	I3RecoResultSingleTopShower() { } //particle will automatically be "NULL" 

	/**
	 * destructor
	 */
	virtual ~I3RecoResultSingleTopShower() { }

	/**
	 * Retrieves the track in this reco result as a constant object
	 */
	const I3ParticlePtr GetShower() const { 
		return I3RecoResultSingleTopShower::GetParticle(); 
	}

	/**
	 * Retrieves the track of this reco result as a non-const object
	 */
	I3ParticlePtr GetShower() {
		return I3RecoResultSingleTopShower::GetParticle(); 
	}

	/**
	 * indicates that there is a particle in the result
	 */
	bool HasShower () const { 
		return I3RecoResultSingleTopShower::HasParticle(); 
	}
  
	/**
	 * sets the particle in the result
	 */
	void SetShower (I3ParticlePtr shower) {
		I3RecoResultSingleTopShower::SetParticle(shower);
	}

	/**
	 * Puts the contents of the container (a TopShower reco result) 
	 * into the stream
	 */
	virtual void ToStream(ostream& o) const {
		I3RecoResultSingleTopShower::ToStream(o);
	}

 private:
	// copy and assignment are private
	//I3RecoResultTopShower (const I3RecoResultTopShower& rhs);
	//const I3RecoResultTopShower& operator= (const I3RecoResultTopShower&);

	// ROOT macro
	ClassDef(I3RecoResultSingleTopShower, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultSingleTopShower>::ThePolicy I3RecoResultSingleTopShowerPtr;

#endif
