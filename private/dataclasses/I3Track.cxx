/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.cxx,v 1.12.2.3 2004/04/15 10:47:04 troy Exp $

    @version $Revision: 1.12.2.3 $
    @date $Date: 2004/04/15 10:47:04 $
    @author

    @todo

*/
#include "dataclasses/I3Track.h"

#include <iostream>

using namespace std;

void 
I3Track::ToStream (ostream& s) const
{
  s << "[I3Track Type=" << fType << " X=" << fX << " Y=" << fY << " Z=" << fZ << "]";
}

I3Track&
I3Track::operator=(const I3Track& rhs) 
{
  if (this == &rhs) return *this;
  
  // Some want also a "conditional copy" operator that copies only if source fields
  // are not NAN.  Use something funky like "operator<-" ???  Hahahahahahha....

  // This assignment operator is not virtual, but these assignments
  // all done through virtual function calls to avoid necessary
  // redefinition in subclasses...
  X(rhs.X()); 
  Y(rhs.Y()); 
  Z(rhs.Z());
  Time(rhs.Time());
  Type(rhs.Type());
  Zenith(rhs.Zenith());
  Azimuth(rhs.Azimuth());
  Length(rhs.Length());
  Speed(rhs.Speed());
  Energy(rhs.Energy());
  Weight(rhs.Weight());
  
  return *this;
}

// equality operator.  Also not virtual (freestanding, not associated
// with any object).  Virtual function calls on the left and right of
// each comparison.
bool
operator==(const I3Track& lhs, const I3Track& rhs) 
{
  if (&lhs == &rhs) 
    return true;

  // this allows for (NAN==NAN) to evaluate to true
  // ugly, I know.

  return 
    ((isnan(lhs.X()) && isnan(rhs.X())) 
     || (lhs.X() == rhs.X())) &&
    ((isnan(lhs.Y()) && isnan(rhs.Y())) 
     || (lhs.Y() == rhs.Y())) &&
    ((isnan(lhs.Z()) && isnan(rhs.Z())) 
     || (lhs.Z() == rhs.Z())) &&
    ((isnan(lhs.Type()) && isnan(rhs.Type())) 
     || (lhs.Type() == rhs.Type())) &&
    ((isnan(lhs.Time()) && isnan(rhs.Time())) 
     || (lhs.Time() == rhs.Time())) &&
    ((isnan(lhs.Zenith()) && isnan(rhs.Zenith())) 
     || (lhs.Zenith() == rhs.Zenith())) &&
    ((isnan(lhs.Azimuth()) && isnan(rhs.Azimuth())) 
     || (lhs.Azimuth() == rhs.Azimuth())) &&
    ((isnan(lhs.Speed()) && isnan(rhs.Speed())) 
     || (lhs.Speed() == rhs.Speed())) &&
    ((isnan(lhs.Energy()) && isnan(rhs.Energy())) 
     || (lhs.Energy() == rhs.Energy())) &&
    ((isnan(lhs.Weight()) && isnan(rhs.Weight())) 
     || (lhs.Weight() == rhs.Weight()));

}


