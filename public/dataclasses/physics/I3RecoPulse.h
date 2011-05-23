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
static const unsigned i3recopulse_version_ = 2;

class I3RecoPulse 
{
  float time_;
  float charge_;
  float width_;
  typedef uint8_t flags_t;
  flags_t flags_;

  public:
	
	enum Flags{
		LC = (1 >> 0),
		ATWD = (1 >> 1),
		FADC = (1 >> 2),
	};

  I3RecoPulse() : time_(NAN), charge_(NAN), width_(NAN), flags_(0) {}

  /*
   * @brief A bitwise combination of I3RecoPulse::Flags
   */
  flags_t GetFlags() const { return flags_; } 

  void SetFlags(flags_t flags) { flags_ = flags; } 

  float GetTime() const {return time_;}

  void SetTime(float time) {time_ = time;}

    /**
     * GetCharge() - Returns the number of PE's seen in this pulse
     *       PEs are used since they are independent of HW, gain, etc.
     */

  float GetCharge() const {return charge_;}

    /**
     * SetCharge() - Sets the number of PE's seen in this pulse
     *       PEs are used since they are independent of HW, gain, etc.
     */

  void SetCharge(float charge) {charge_ = charge;}

  float GetWidth() const {return width_;}

  void SetWidth(float width) {width_ = width;}

  virtual ~I3RecoPulse();

  bool operator==(const I3RecoPulse& rhs) const;

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3RecoPulse);
BOOST_CLASS_VERSION(I3RecoPulse, i3recopulse_version_);

typedef std::vector<I3RecoPulse> I3RecoPulseSeries;
typedef I3Map<OMKey, I3RecoPulseSeries> I3RecoPulseSeriesMap;
typedef I3Map<OMKey, I3RecoPulse> I3RecoPulseMap;

I3_POINTER_TYPEDEFS(I3RecoPulseSeries);
I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMap);
#ifdef I3_USE_FAST_OMKEY_MAP
BOOST_CLASS_VERSION(I3RecoPulseSeriesMap, 1);
#endif
I3_POINTER_TYPEDEFS(I3RecoPulseMap);
#ifdef I3_USE_FAST_OMKEY_MAP
BOOST_CLASS_VERSION(I3RecoPulseMap, 1);
#endif

/*
 * Specialize I3Frame::Get() to turn convert various objects
 * in the frame into I3RecoPulseSeriesMaps.
 */

#include "icetray/I3Frame.h"

template <>
I3RecoPulseSeriesMapConstPtr
I3Frame::Get(const std::string& name, bool quietly, void*, void*) const;

#endif //I3RECOPULSE_H_INCLUDED


