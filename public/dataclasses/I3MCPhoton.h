#/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPhoton.h,v 1.5 2005/04/01 22:38:41 olivas Exp $
 *
 * @file I3MCPhoton.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/04/01 22:38:41 $
 * @author pretz
 */
#ifndef I3MCPHOTON_H
#define I3MCPHOTON_H

#include "TObject.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A class that indicates the arrival of a photon at a particular OM.
 *
 * @todo Perhaps should have stuff like 'Arrival Angle' and 'Wavelength'
 */
class I3MCPhoton : public TObject
{
  double time_;
 public:
  /**
   * default constructor
   */

  I3MCPhoton(){}

  /**
   * default destructor
   */
  virtual ~I3MCPhoton(){}

  /**
   * Gets the photon arrival time at a PMT
   * @return the photon arrival time
   */
  double GetTime() { return time_;}

  /**
   * Sets the photon arrival time at the PMT
   * @param time the new arrival time
   */
  void SetTime(double time) { time_ = time;}

  virtual void ToStream(ostream& o) const
    {
      o<<"[ MCPhoton ]"
       <<"Time :"<<time_;

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
  }

  //ROOT macro
  ClassDef(I3MCPhoton,1);
};

inline ostream& operator<<(ostream& o,const I3MCPhoton& photon)
{
  photon.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management schemes
 */
typedef PtrPolicy<I3MCPhoton>::ThePolicy I3MCPhotonPtr;

#endif //I3MCPHOTON_H
