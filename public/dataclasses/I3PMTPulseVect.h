/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3PMTPulseVect.h,v 1.1 2004/12/01 02:27:07 ehrlich Exp $
 *
 * @file I3PMTPulseVect.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/12/01 02:27:07 $
 * @author deyoung
 */

#ifndef I3PMTPULSEVECT_H_INCLUDED
#define I3PMTPULSEVECT_H_INCLUDED
#include <TObject.h>
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
  
  

private:
  // copy and assignment are private
  I3PMTPulseVect(const I3PMTPulseVect&); 
  I3PMTPulseVect& operator=(const I3PMTPulseVect&); 

  // ROOT macro
  ClassDef(I3PMTPulseVect,1);
};

/** 
 * pointer type to insulate users from memory managemnt issues
 */
typedef PtrPolicy<I3PMTPulseVect>::ThePolicy I3PMTPulseVectPtr;

#endif

