/**
    $Id: I3StationHit.cxx,v 1.3 2005/04/04 15:49:24 pretz Exp $
    @file I3StationHit.C
    @version $Revision: 1.3 $
    @date Fri Jul  9 21:55:18 EDT 2004
    @author rulrich
*/

#include "dataclasses/I3StationHit.h"

ClassImp(I3StationHit);

/***************************************************************/

// copy constr
I3StationHit::I3StationHit (const I3StationHit &) {}

/***************************************************************/

// assignment
const I3StationHit& I3StationHit::operator= (const I3StationHit &)
{
  return *this;
}

/***************************************************************/

unsigned short I3StationHit::StationNumber () const
{
  return fStationNumber;
}

/***************************************************************/

void I3StationHit::StationNumber (unsigned short station_number)
{
  fStationNumber = station_number;
}

/***************************************************************/
/*
RU:
see the public file for these out-commentments

float I3StationHit::Amplitude () const
{
  return fAmplitude;
}


void I3StationHit::Amplitude (float amplitude)
{
  fAmplitude = amplitude;
}


float I3StationHit::Time () const
{
  return fTime;
}


void I3StationHit::Time (float time)
{
  fTime = time;
}


float I3StationHit::X () const
{
  return fX;
}


void I3StationHit::X (float x)
{
  fX = x;
}


float I3StationHit::Y () const
{
  return fY;
}


void I3StationHit::Y (float y)
{
  fY = y;
}
*/
