/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3MCHit.h
 * @date $Date$
 */

#ifndef I3MCHIT_H_INCLUDED
#define I3MCHIT_H_INCLUDED

#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"

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
class I3Particle;

class I3MCHit
{
 public:

  enum HitSource{
    UNKOWN = 0,
    SPE = 10,
    RANDOM = 20,
    AFTER_PULSE = 30,
    PRE_PULSE = 40,
    LATE_PULSE = 50
  };

  I3MCHit() : 
    time_(NAN), 
    hitID_(-1),
    weight_(NAN), 
    particleID_(-1), 
    particleMajorID_(0), 
    cherenkovDistance_(NAN),
    amplitude_(1){ }

  virtual ~I3MCHit();

  double GetTime() const { return time_;}

  void SetTime(double time){time_ = time;}

  int GetHitID() const { return hitID_;}

  void SetHitID(int hitID){hitID_ = hitID;}

  double GetWeight() const { return weight_; }

  void SetWeight(double weight) { weight_ = weight; }

  int GetParticleID() const { 
    log_warn("I3MCHit::GetParticleID is deprecated.  Please use I3MCHit::GetParticleMinorID");
    return particleID_; 
  }

  int GetParticleMinorID() const { return particleID_; }

  uint64_t GetParticleMajorID() const { return particleMajorID_; }

  void SetParticleID(const I3Particle& );

  /**
   * @return the direct path distance to the track which caused this hit
   */
  double GetCherenkovDistance() const { return cherenkovDistance_; }

  /**
   * @param CherenkovDistance set the direct path distance to track which 
   * caused this hit
   */
  void SetCherenkovDistance(double CherenkovDistance) { cherenkovDistance_ = CherenkovDistance; }

  /**
   * Sets/Gets the source of the MCHit
   */
  void SetHitSource(HitSource s){ source_= s; }
  HitSource GetHitSource() const { return source_; }

  /**
   * Sets/Gets the number of PEs, or after pulses, or pre-pulses, etc...
   */
  unsigned int GetAmplitude() const { return amplitude_; }

  void SetAmplitude(unsigned int n) { amplitude_ = n; }

 private:

  double time_;
  int hitID_;
  double  weight_;
  int    particleID_;
  uint64_t    particleMajorID_;
  double  cherenkovDistance_;
  HitSource source_;
  unsigned int amplitude_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};

BOOST_CLASS_VERSION(I3MCHit,2);

I3_POINTER_TYPEDEFS(I3MCHit);

typedef std::vector<I3MCHit> I3MCHitSeries;
typedef I3Map<OMKey, I3MCHitSeries> I3MCHitSeriesMap; 

I3_POINTER_TYPEDEFS(I3MCHitSeries);
I3_POINTER_TYPEDEFS(I3MCHitSeriesMap);

#endif //I3MCHIT_H_INCLUDED

