/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id$
 *
 * @file I3PMTPulseVect.h
 * @version $Revision: 1.5 $
 * @date $Date$
 * @author deyoung
 */

#ifndef I3PMTPULSEVECT_H_INCLUDED
#define I3PMTPULSEVECT_H_INCLUDED
#include <TObject.h>
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/physics/I3PMTPulse.h"

/**
 * @brief List of PMT pulses produced by individual hits
 *
 * This class contains the PMT voltage curves produced in response to
 * each hit in the event.  The total voltage at any point in time
 * should be obtained from the MCPMTResponse, since the individual
 * pulses may not include saturation or other non-linear effects.
 *
 */
class I3PMTPulseVect : public TObject,
		       public vector<I3PMTPulsePtr>
{

public:
  /**
   * constructor
   */
  I3PMTPulseVect(){}

  /**
   * destructor
   */
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

/**
 * pointer type to insulate users from memory managemnt issues
 */
typedef shared_ptr<I3PMTPulseVect>  I3PMTPulseVectPtr;

#endif


