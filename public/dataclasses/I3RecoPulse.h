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
  int hitID_;
  double time_;
  double amp_;
  double width_;

  public:

  I3RecoPulse() {hitID_=0; time_=NAN; width_=NAN; amp_=NAN;}

  /**
   * @return the time at which the Pulse occured
   */
  double GetTime() const {return time_;}

  /**
   * @param time the new time of the pulse
   */
  void SetTime(double time) {time_ = time;}

  /**
   * @return the unique ID of this pulse
   */
  int GetHitID() const {return hitID_;}
  int GetID() const {return hitID_;}

  /**
   * @param hitid the ID number to assign to this hit.  Should be
   * unique, but no checking is done.
   */
  void SetHitID(const int hitid) {hitID_ = hitid;}
  void SetID(const int hitid) {hitID_ = hitid;}

  /**
   * @return the Pulse Amplitude
   */
  double GetAmplitude() const {return amp_;}

  /**
   * @param set the pulse amplitude
   */
  void SetAmplitude(double amp) {amp_ = amp;}

  /**
   * @return the Pulse Width
   */
  double GetWidth() const {return width_;}

  /**
   * @param set pulse width
   */
  void SetWidth(double width) {width_ = width;}

  virtual ~I3RecoPulse() {}
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


