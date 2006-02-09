/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3Hit.h 15486 2006-02-08 20:57:53Z dule $
 * @file I3Hit.h
 * @date $Date: 2006-02-08 15:57:53 -0500 (Wed, 08 Feb 2006) $
 */

#ifndef I3HIT_H_INCLUDED
#define I3HIT_H_INCLUDED

#include <TObject.h>
#include "dataclasses/Utility.h"
#include <map>
#include <string>

/**
 * @brief A base class for reconstruted hits.  
 *
 * Carries no information beyond 'hit'
 * but can be sub-classed as part of a hit series reconstruction.
 *
 */
class I3Hit : public TObject
{
  public:
  I3Hit() : time_(NAN),hitID_(-1){}

  virtual ~I3Hit();

  const std::map<std::string,double>& GetParameters() const {return user_;}

  std::map<std::string,double>& GetParameters(){return user_;}

  double GetTime() const { return time_; }

  void SetTime(double time) { time_ = time; }

  int GetID() const { return hitID_; }

  void SetID(const int hitid) { hitID_ = hitid; }

 private:

  double time_;

  int hitID_;

  std::map<std::string,double> user_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o,const I3Hit& key)
{
  o<<"[ I3Hit ]\n";
  return o;
}

I3_POINTER_TYPEDEFS(I3Hit);

#endif //I3HIT_H_INCLUDED


