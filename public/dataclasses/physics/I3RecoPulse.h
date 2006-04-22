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

using namespace std;

/**
 * @brief Base class for recopulse.
 *
 * A storage base class for extracted pulses from a feature extractor
 * A readout independent representation of a waveform feature or Analog
 *  readout.
 */
class I3RecoPulse 
{
  int hitID_;
  double time_;
  double charge_;
  double width_;

  public:

  I3RecoPulse() {hitID_=0; time_=NAN; width_=NAN; charge_=NAN;}

  double GetTime() const {return time_;}

  void SetTime(double time) {time_ = time;}

  int GetID() const {return hitID_;}

  void SetID(const int hitid) {hitID_ = hitid;}

    /**
     * GetCharge() - Returns the number of PE's seen in this pulse
     *       PEs are used since they are independent of HW, gain, etc.
     */

  double GetCharge() const {return charge_;}

    /**
     * SetCharge() - Sets the number of PE's seen in this pulse
     *       PEs are used since they are independent of HW, gain, etc.
     */

  void SetCharge(double charge) {charge_ = charge;}

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


