/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3RecoHit.h
 * @date $Date$
 */

#ifndef I3RECOHIT_H_INCLUDED
#define I3RECOHIT_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"


/**
 * @brief A base class for reconstruted hits.  
 *
 * Carries no information beyond 'hit'
 * but can be sub-classed as part of a hit series reconstruction.
 *
 */
class I3RecoHit 
{
  public:
  I3RecoHit() : time_(NAN),hitID_(-1){}

  virtual ~I3RecoHit();

  double GetTime() const { return time_; }

  void SetTime(double time) { time_ = time; }

  int GetID() const { return hitID_; }

  void SetID(const int hitid) { hitID_ = hitid; }

 private:

  double time_;

  int hitID_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};


I3_POINTER_TYPEDEFS(I3RecoHit);

typedef I3Vector<I3RecoHit> I3RecoHitSeries;
typedef I3Map<OMKey, I3RecoHitSeries> I3RecoHitSeriesMap;

I3_POINTER_TYPEDEFS(I3RecoHitSeriesMap);

#endif //I3RECOHIT_H_INCLUDED


