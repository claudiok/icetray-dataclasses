/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: $
 * @file I3RecoPulse.h
 * @date $Date: $
 */

#ifndef I3RECOPULSE_H_INCLUDED
#define I3RECOPULSE_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/I3Map.h"
#include <TObject.h>

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

  virtual ~I3RecoPulse();

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3RecoPulse);

typedef I3Vector<I3RecoPulse> I3RecoPulseSeries;
typedef I3Map<OMKey, I3RecoPulseSeries> I3RecoPulseSeriesMap;

I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMap);

#endif //I3RECOPULSE_H_INCLUDED


