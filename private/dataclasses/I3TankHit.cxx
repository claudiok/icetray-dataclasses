/**
    $Id: I3TankHit.cxx,v 1.1 2004/07/13 15:37:53 niessen Exp $
    @file I3TankHit.h
    @version $Revision: 1.1 $
    @date Fri Jul  9 21:55:18 EDT 2004
    @author rulrich
*/

#include "dataclasses/I3TankHit.h"

ClassImp(I3TankHit);

/*************************************************************/

// copy constructor

I3TankHit::I3TankHit (const I3TankHit &)
{
}

/*************************************************************/

// assignment
const I3TankHit& I3TankHit::operator= (const I3TankHit &)
{
}

/*************************************************************/

// Get the time
Float_t I3TankHit::Time () const
{
  return fTime;
}

/*************************************************************/

// Set the time
void I3TankHit::Time (Float_t time)
{
  fTime = time;
}

/*************************************************************/

// Get the Amplitude
Float_t I3TankHit::Signal () const
{
  return fSignal;
}

/*************************************************************/

// Set the Amplitude
void I3TankHit::Signal (Float_t signal)
{
  fSignal = signal;
}

