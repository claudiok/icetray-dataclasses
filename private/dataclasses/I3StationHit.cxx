/**
    $Id: I3StationHit.cxx,v 1.1.2.1 2004/07/19 22:24:20 ehrlich Exp $
    @file I3StationHit.C
    @version $Revision: 1.1.2.1 $
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
}

/***************************************************************/

UShort_t I3StationHit::StationNumber () const
{
  return fStationNumber;
}

/***************************************************************/

void I3StationHit::StationNumber (UShort_t station_number)
{
  fStationNumber = station_number;
}

/***************************************************************/
/*
RU:
see the public file for these out-commentments

Float_t I3StationHit::Amplitude () const
{
  return fAmplitude;
}


void I3StationHit::Amplitude (Float_t amplitude)
{
  fAmplitude = amplitude;
}


Float_t I3StationHit::Time () const
{
  return fTime;
}


void I3StationHit::Time (Float_t time)
{
  fTime = time;
}


Float_t I3StationHit::X () const
{
  return fX;
}


void I3StationHit::X (Float_t x)
{
  fX = x;
}


Float_t I3StationHit::Y () const
{
  return fY;
}


void I3StationHit::Y (Float_t y)
{
  fY = y;
}
*/
