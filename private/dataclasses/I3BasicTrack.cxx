/**
 * Class: I3Track.h
 *
 * Version $Id: I3BasicTrack.cxx,v 1.1.2.1 2004/04/15 10:33:19 troy Exp $
 *
 * Date: 24 Feb 2004
 *
 * (c) 2004 IceCube Collaboration
 */

#include "dataclasses/I3BasicTrack.h"

#include <iostream>

using namespace std;

void 
I3BasicTrack::ToStream (ostream& s) const
{
  s << "[I3BasicTrack Time=" << fTime 
    << " Zenith=" << fZenith 
    << " Azimuth=" << fAzimuth
    << " Length=" << fLength
    << " Energy=" << fEnergy 
    << " ";
  I3Track::ToStream(s);
  s << " ]";
}

