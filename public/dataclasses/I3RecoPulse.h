/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: $
 *
 * @file I3RecoPulse.h
 * @version $Revision: 1.26 $
 * @date $Date: $
 * @author ehrlich
 * @author blaufuss
 */

#ifndef I3RECOPULSE_H
#define I3RECOPULSE_H

#include "dataclasses/StoragePolicy.h"

/**
 * @brief Base class for recopulse.
 *
 * A storage base class for extracted pulses from a feature extractor
 * A readout independent representation of a waveform feature or Analog
 *  readout.
 */
class I3RecoPulse : public TObject
{
public:
   I3RecoPulse() { time_ = 0; hitID_ = 0; }

  /**
   * equality operator
   * @param rhs the right hand side of the equality
   * @return true if the times are equal
   */      
  bool operator==(const I3RecoPulse& rhs) const 
  { 
    return time_ == rhs.time_ && hitID_ == rhs.hitID_; 
  }

  bool operator!=(const I3RecoPulse& rhs) const 
  { 
    return !(*this==rhs); 
  }

  /**
   * @return the time at which the Pulse occured
   */
  double GetTime() const { return time_; }

  /**
   * @param time the new time of the pulse
   */
  void SetTime(double time) { time_ = time; }

  /**
   * @return the unique ID of this pulse
   */
  int GetID() const { return hitID_; }

  /**
   * @param hitid the ID number to assign to this hit.  Should be
   * unique, but no checking is done.
   */
  void SetID(const int hitid) { hitID_ = hitid; }

  /**
   * @return the Pulse Amplitude
   */
  double GetAmplitude() const { return pulseAmp_; }

  /**
   * @param set the pulse amplitude
   */
  void SetAmplitude(double ampl) { pulseAmp_ = ampl; }

  /**
   * @return the Pulse Width
   */
  double GetWidth() const { return width_; }

  /**
   * @param set pulse width
   */
  void SetWidth(double width) { width_ = width; }

  virtual ~I3RecoPulse() {}
  virtual void ToStream(ostream& o) const
    {
      o<<"[I3RecoPulse:  Time:"<<time_<< "\n"
       <<"               PulseAmpl:"<<pulseAmp_<< "\n"
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

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Time", time_);
    ar & make_nvp("HitID", hitID_);
    ar & make_nvp("PulseAmp", pulseAmp_);
    ar & make_nvp("Width", width_);
  }
  
  double time_;
  int hitID_;
  double pulseAmp_;
  double width_;

  ClassDef(I3RecoPulse,1);
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

#endif

