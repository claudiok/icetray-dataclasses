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

/**
 * @brief Base class for recopulse.
 *
 * A storage base class for extracted pulses from a feature extractor
 * A readout independent representation of a waveform feature or Analog
 *  readout.
 */
static const unsigned i3recopulse_version_ = 1;

class I3RecoPulse 
{
  int hitID_;
  double time_;
  double charge_;
  double width_;
  int sourceIndex_;

  public:

  I3RecoPulse() {hitID_=0; time_=NAN; width_=NAN; charge_=NAN;sourceIndex_=-1;}

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

/**
 *  GetSourceIndex - The Source Index can be used to keep track
 *    of which rawReadout index (from readout vector, like DOMLaunchSeries,
 *    that gave rise to this pariticular hit.  Index value defaults to -1.
 */

  int GetSourceIndex() const { return sourceIndex_; }
/**
 *  SetSourceIndex - The Source Index can be used to keep track
 *    of which rawReadout index (from readout vector, like DOMLaunchSeries,
 *    that gave rise to this pariticular hit.  Index value defaults to -1.
 */
  void SetSourceIndex(const int srcid) { sourceIndex_ = srcid; }

  virtual ~I3RecoPulse();

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3RecoPulse);
BOOST_CLASS_VERSION(I3RecoPulse, i3recopulse_version_);

typedef std::vector<I3RecoPulse> I3RecoPulseSeries;
typedef I3Map<OMKey, I3RecoPulseSeries> I3RecoPulseSeriesMap;
typedef I3Map<OMKey, I3RecoPulse> I3RecoPulseMap;

I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMap);
I3_POINTER_TYPEDEFS(I3RecoPulseMap);

#endif //I3RECOPULSE_H_INCLUDED


