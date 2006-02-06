/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * @version $Id$
 * @file I3PMTPulseVect.h
 * @date $Date$
 */

#ifndef I3PMTPULSEVECT_H_INCLUDED
#define I3PMTPULSEVECT_H_INCLUDED
#include "dataclasses/Utility.h"
#include "dataclasses/physics/I3PMTPulse.h"
#include "dataclasses/I3Vector.h"

/**
 * @brief List of PMT pulses produced by individual hits
 *
 * This class contains the PMT voltage curves produced in response to
 * each hit in the event.  The total voltage at any point in time
 * should be obtained from the MCPMTResponse, since the individual
 * pulses may not include saturation or other non-linear effects.
 *
 */
class I3PMTPulseVect : public I3Vector<I3PMTPulsePtr>
{

public:

  I3PMTPulseVect(){}

  virtual ~I3PMTPulseVect();

  /**
   * PMT output voltage as f(time). This is a superposition of all pulses
   */
  float GetPMTVoltage(const float time)
  {
    double voltage = 0;
    if(this->size())
    {
      I3PMTPulseVect::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++)
        voltage+=(*iter)->GetVoltage(time);
    }
    return voltage;
  }

private:
  // copy and assignment are private
  I3PMTPulseVect(const I3PMTPulseVect&);
  I3PMTPulseVect& operator=(const I3PMTPulseVect&);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3PMTPulseVect);

#endif //I3PMTPULSEVECT_H_INCLUDED


