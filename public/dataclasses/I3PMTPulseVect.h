/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3PMTPulseVect.h,v 1.2.2.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3PMTPulseVect.h
 * @version $Revision: 1.2.2.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author deyoung
 */

#ifndef I3PMTPULSEVECT_H_INCLUDED
#define I3PMTPULSEVECT_H_INCLUDED

#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3PMTPulse.h"

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
		       public VectorPolicy<I3PMTPulsePtr>::ThePolicy
{

public:
  /**
   * constructor
   */
  I3PMTPulseVect(){}

  /**
   * destructor
   */
  virtual ~I3PMTPulseVect(){}

  /**
   * PMT output voltage as f(time). This is a superposition of all pulses
   */
  Float_t GetPMTVoltage(const Float_t time)
  {
    Double_t voltage = 0;
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

};

/**
 * pointer type to insulate users from memory managemnt issues
 */
typedef PtrPolicy<I3PMTPulseVect>::ThePolicy I3PMTPulseVectPtr;

#endif

