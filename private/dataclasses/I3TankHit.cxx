/**
    $Id: I3TankHit.cxx,v 1.2 2004/11/28 06:40:27 troy Exp $
    @file I3TankHit.h
    @version $Revision: 1.2 $
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
  return *this;
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

