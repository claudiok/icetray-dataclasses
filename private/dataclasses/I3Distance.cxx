/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Distance.cxx,v 1.2 2004/06/14 22:28:03 dule Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/06/14 22:28:03 $
    @author

    @todo

*/
#include "dataclasses/I3Distance.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------
// Calculate distance to position Pos() on track
Double_t I3Distance::Distance(I3Track* track, I3Position& pos)
{
  return pos.CalcDistance(track->Pos());
}

//--------------------------------------------------------------
// Calculate distance to START position on track
Double_t I3Distance::StartDistance(I3Track* track, I3Position& pos)
{
  if (track->IsStarting() || track->IsContained()) {
    return pos.CalcDistance(track->StartPos());
  }
  return NAN;
}

//--------------------------------------------------------------
// Calculate distance to STOP position on track
Double_t I3Distance::StopDistance(I3Track* track, I3Position& pos)
{
  if (track->IsStopping() || track->IsContained()) {
    return pos.CalcDistance(track->StopPos());
  }
  return NAN;
}

//--------------------------------------------------------------
// Calculate distance to CLOSEST APPROACH to track
void I3Distance::ClosestApproach(I3Track* track,     // input
				 I3Position& pos,    // input
				 I3Position& appos,  // output 
				 Double_t& apdist,   // output
				 I3Position& chpos,  // output
				 Double_t& chtime,   // output
				 Double_t ChAngle)   // input
{
  //--Only calculate if track has direction
  if (track->HasDirection()) {
    I3Position P(pos);   // position (P) of a DOM or whatnot

    //--Calculate position and distance of closest approach
    Double_t PT = P.CalcDistance(track->Pos()); // T=track->Pos()
    P.Translate(track->Pos());
    P.RotateZ(-(track->Azimuth()));
    P.RotateY(pi()/2-(track->Zenith()));
    Double_t TA = P.X();
    Double_t PA = sqrt(PT*PT-TA*TA);

    //--Return position and distance of closest approach
    appos = ShiftAlongTrack(track,TA); // position A
    apdist = PA; // distance of closest approach

    //--Calculate Cherenkov photon... position on track and time of PMT hit
    Double_t CA = PA/tan(ChAngle);
    Double_t CP = PA/sin(ChAngle);
    Double_t TC = TA-CA;
    chpos = ShiftAlongTrack(track,TC); // Cherenkov position C
    chtime = (TC+CP)/track->Speed()/I3Units::ns;
               // total photon time from T (on track) through C to P.

    //--Is point of closest approach (A) on track?
    //--Is Cherenkov origin point (C) on track?
    if (track->IsStarting()) 
      if (track->IsStopping()) {
      //-contained track...............................
	if (TA<0) {
	  // if A is before STARTING position
	  appos = track->StartPos();
	  apdist = P.CalcDistance(track->StartPos());
	} else if (TA>track->Length()) {
	  // if A is beyond STOPPING position
	  appos = track->StopPos();
	  apdist = P.CalcDistance(track->StopPos());
	}
	if (TC<0) {
	  // if C is before STARTING position
	  chpos.NullPosition();
	  chtime = NAN;
	} else if (TC>track->Length()) {
	  // if C is beyond STOPPING position
	  chpos.NullPosition();                                               
          chtime = NAN;
	}
      } else {
      //-starting track................................
	if (TA<0) {
	  // if A is before STARTING position
	  appos = track->StartPos();
	  apdist = P.CalcDistance(track->StartPos());
	}
	if (TC<0) {
	  // if C is before STARTING position
	  chpos.NullPosition();
	  chtime = NAN;
	}
      }
    else
      if (track->IsStopping()) {
      //-stopping track................................
	if (TA>0) {
	  // if A is beyond STOPPING position
	  appos = track->StopPos();
	  apdist = P.CalcDistance(track->StopPos());
	}
	if (TC>0) {
	  // if C is beyond STOPPING position
	  chpos.NullPosition();
	  chtime = NAN;
	}
      } else {
      //-infitine track................................
      }

    //--Don't calculate if track does not have direction
  } else {
    cout <<"I3Distance::ClosestApproach - Track has no direction. Not calculating.\n";
    appos.NullPosition();
    apdist=NAN;
    chpos.NullPosition();
    chtime=NAN;
  }
}

//--------------------------------------------------------------
// Calculate a position on track, which is a distance 'dist' 
// away from track.Pos().
I3Position I3Distance::ShiftAlongTrack(I3Track* track, Double_t dist)
{
  I3Position p;
  Double_t x,y,z;
  x = track->Pos().X() + dist*sin(track->Zenith())*cos(track->Azimuth());
  y = track->Pos().Y() + dist*sin(track->Zenith())*sin(track->Azimuth());
  z = track->Pos().Z() + dist*cos(track->Zenith());
  p.SetPosition(x,y,z,I3Position::car);
  return p;
}

//--------------------------------------------------------------
// Is a given position on a track
Bool_t I3Distance::IsOnTrack(I3Track* track, 
			     I3Position& pos, 
			     Double_t Precision)
{
  I3Position appos,chpos;
  Double_t apdist,chtime;
  ClosestApproach(track,pos,appos,apdist,chpos,chtime);
  if (apdist<=Precision) return kTRUE;
  else return kFALSE;
}

//--------------------------------------------------------------
