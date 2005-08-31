/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3MCHit.h
 * @version $Revision: 1.19 $
 * @date $Date$
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3MCHIT_H
#define I3MCHIT_H

#include "I3Hit.h"
#include "StoragePolicy.h"

/**
 * @brief Derived I3Hit class with additional 'Weight' and 'Parent
 * track' info
 * 
 * This class records the true (simulated) time at which a
 * photoelectron was produced.  In addition to the time, it contains
 * the identity of the track which was responsible for the hit, and a
 * statistical weight to assign to the hit (default 1).  Also, 
 * CherenkovDistance- direct path distance to the track that generated
 * this hit.
 */
class I3MCHit : public I3Hit
{
  float  weight_;
  int    particleID_;
  double  cherenkovDistance_;

 public:
  /**
   * constructor
   */
  I3MCHit() : weight_(0), particleID_(0), cherenkovDistance_(0) { }

  // default copy constructor, assignment operator explicitly used
  /**
   * @return the weight contributed by this MCHit
   */
  float GetWeight() const { return weight_; }

  /**
   * @param weight the new weight for the hit
   */
  void SetWeight(float weight) { weight_ = weight; }

  /**
   * @return the track number which caused this hit
   */
  int GetParticleID() const { return particleID_; }

  /**
   * @param ParticleID set the track which caused this hit
   */
  void SetParticleID(int ParticleID) { particleID_ = ParticleID; }

  /**
   * @return the direct path distance to the track which caused this hit
   */
  double GetCherenkovDistance() const { return cherenkovDistance_; }

  /**
   * @param CherenkovDistance set the direct path distance to track which caused this hit
   */
  void SetParticleID(double CherenkovDistance) { cherenkovDistance_ = CherenkovDistance; }

  virtual ~I3MCHit() {} 

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize (Archive &ar, unsigned version)
  {
    ar & make_nvp("I3Hit", base_object<I3Hit>(*this));
    ar & make_nvp("Weight", weight_);
    ar & make_nvp("ParticleID", particleID_);
    ar & make_nvp("CherenkovDistance", cherenkovDistance_);
  }     

  ClassDef(I3MCHit,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCHit>  I3MCHitPtr;

#endif
