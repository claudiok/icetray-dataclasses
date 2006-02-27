/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3MCHit.h
 * @date $Date$
 */

#ifndef I3MCHIT_H_INCLUDED
#define I3MCHIT_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"
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
class I3MCHit
{
  double time_;
  int hitID_;
  double  weight_;
  int    particleID_;
  double  cherenkovDistance_;

 public:

  I3MCHit() : 
    time_(NAN), 
    hitID_(-1),
    weight_(NAN), 
    particleID_(-1), 
    cherenkovDistance_(NAN) { }

  virtual ~I3MCHit();

  double GetTime() const { return time_;}

  void SetTime(double time){time_ = time;}

  int GetHitID() const { return hitID_;}

  void SetHitID(int hitID){hitID_ = hitID;}

  double GetWeight() const { return weight_; }

  void SetWeight(double weight) { weight_ = weight; }

  int GetParticleID() const { return particleID_; }

  void SetParticleID(int ParticleID) { particleID_ = ParticleID; }

  /**
   * @return the direct path distance to the track which caused this hit
   */
  double GetCherenkovDistance() const { return cherenkovDistance_; }

  /**
   * @param CherenkovDistance set the direct path distance to track which 
   * caused this hit
   */
  void SetCherenkovDistance(double CherenkovDistance) { cherenkovDistance_ = CherenkovDistance; }


 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ClassDef(I3MCHit,1);
};

I3_POINTER_TYPEDEFS(I3MCHit);

typedef I3Vector<I3MCHit> I3MCHitSeries;
typedef I3Map<OMKey, I3MCHitSeries> I3MCHitSeriesMap; 

#endif //I3MCHIT_H_INCLUDED

