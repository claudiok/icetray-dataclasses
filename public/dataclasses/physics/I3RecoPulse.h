/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: $
 * @file I3RecoPulse.h
 * @date $Date: $
 */

#ifndef I3RECOPULSE_H_INCLUDED
#define I3RECOPULSE_H_INCLUDED

#include "dataclasses/StoragePolicy.h"
#include <map>
#include <string>

using namespace std;

/**
 * @brief Base class for recopulse.
 *
 * A storage base class for extracted pulses from a feature extractor
 * A readout independent representation of a waveform feature or Analog
 *  readout.
 */
class I3RecoPulse : public TObject
{
  int hitID_;
  double time_;
  double amp_;
  double width_;
  map<string,double> user_;

  public:

  I3RecoPulse() {hitID_=0; time_=NAN; width_=NAN; amp_=NAN;}

  double GetTime() const {return time_;}

  void SetTime(double time) {time_ = time;}

  int GetID() const {return hitID_;}

  void SetID(const int hitid) {hitID_ = hitid;}

  double GetAmplitude() const {return amp_;}

  void SetAmplitude(double amp) {amp_ = amp;}

  double GetWidth() const {return width_;}

  void SetWidth(double width) {width_ = width;}

  const map<string,double>& GetUserParameters() const {return user_;} 

  map<string,double>& GetUserParameters(){return user_;} 

  virtual ~I3RecoPulse();

  virtual void ToStream(ostream& o) const
  {
    o<<"[I3RecoPulse:  Time:"<<time_<< "\n"
     <<"               PulseAmpl:"<<amp_<< "\n"
     <<"               PulseWidth:"<<width_<<" ]\n";
  }

  virtual string ToString() const
  {
    ostringstream out;
    ToStream(out);
    return out.str();
  }

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o,const I3RecoPulse& pulse)
{
  pulse.ToStream(o);
  return o;
}


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoPulse>  I3RecoPulsePtr;

#endif //I3RECOPULSE_H_INCLUDED


