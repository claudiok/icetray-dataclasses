/**
    $Id: I3TankHit.cxx,v 1.3 2005/04/04 15:49:24 pretz Exp $
    @file I3TankHit.h
    @version $Revision: 1.3 $
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
float I3TankHit::Time () const
{
  return fTime;
}

/*************************************************************/

// Set the time
void I3TankHit::Time (float time)
{
  fTime = time;
}

/*************************************************************/

// Get the Amplitude
float I3TankHit::Signal () const
{
  return fSignal;
}

/*************************************************************/

// Set the Amplitude
void I3TankHit::Signal (float signal)
{
  fSignal = signal;
}

