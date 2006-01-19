/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3RecoHit.h
 * @date $Date$
 */

#ifndef I3RECOHIT_H_INCLUDED
#define I3RECOHIT_H_INCLUDED

#include <TObject.h>
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A base class for reconstruted hits.  
 *
 * Carries no information beyond 'hit'
 * but can be sub-classed as part of a hit series reconstruction.
 *
 */
class I3RecoHit : public TObject
{
  public:
  I3RecoHit() : time_(NAN),hitID_(-1){}

  virtual ~I3RecoHit();

  const map<string,double>& GetUserParameters() const {return user_;}

  map<string,double>& GetUserParameters(){return user_;}

  double GetTime() const { return time_; }

  void SetTime(double time) { time_ = time; }

  int GetID() const { return hitID_; }

  void SetID(const int hitid) { hitID_ = hitid; }

 private:

  double time_;

  int hitID_;

  map<string,double> user_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o,const I3RecoHit& key)
{
  o<<"[ I3RecoHit ]\n";
  return o;
}

typedef shared_ptr<I3RecoHit>  I3RecoHitPtr;


#endif //I3RECOHIT_H_INCLUDED


