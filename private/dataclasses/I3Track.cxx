/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.cxx,v 1.12.2.4 2004/04/15 11:26:56 troy Exp $

    @version $Revision: 1.12.2.4 $
    @date $Date: 2004/04/15 11:26:56 $
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
  Type(rhs.Type());
  X(rhs.X()); 
  Y(rhs.Y()); 
  Z(rhs.Z());
  Speed(rhs.Speed());
  Time(rhs.Time());
  Zenith(rhs.Zenith());
  Azimuth(rhs.Azimuth());
  Length(rhs.Length());
  Energy(rhs.Energy());
  
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

  return (lhs.X() == rhs.X()) 
    && (lhs.Y() == rhs.Y()) 
    && (lhs.Z() == rhs.Z()) 
    && (lhs.Type() == rhs.Type()) 
    && (lhs.Time() == rhs.Time()) 
    && (lhs.Zenith() == rhs.Zenith()) 
    && (lhs.Azimuth() == rhs.Azimuth()) 
    && (lhs.Speed() == rhs.Speed()) 
    && (lhs.Energy() == rhs.Energy()); 

}


