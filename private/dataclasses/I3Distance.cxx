/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Distance.cxx,v 1.1 2004/06/09 21:56:34 dule Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/06/09 21:56:34 $
    @author

    @todo

*/
#include "dataclasses/I3Distance.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------
// Constructor 
// I3Distance::I3Distance(I3Position& pos, I3Track& track)
// {
//   fPos.SetPosition(pos);
//   fTrack.SetPos(track.GetPosition());
// }

//--------------------------------------------------------------
// Calculate distance to a position on track
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
void I3Distance::ClosestApproach(I3Track* track,   // input
				 I3Position& pos,    // input
				 I3Position& appos,  // output
				 Double_t& apdist,   // output
				 Bool_t& ontrack)    // output
{
  //--Only calculate if track has direction
  if (track->HasDirection()) {
    I3Position P(pos);   // position (P) of a DOM or whatnot

    //--Calculate position and distance of closest approach
    Double_t PT = P.CalcDistance(track->Pos()); // T=track->Pos()
    cout <<"PT "<< PT <<endl;
    P.Translate(track->Pos());
    P.RotateZ(-(track->Azimuth()));
    P.RotateY(pi()/2-(track->Zenith()));
    Double_t TA = P.X();
    cout <<"TA "<< TA <<endl;
    Double_t PA = sqrt(PT*PT-TA*TA);
    cout <<"PA "<< PA <<endl;
    apdist = PA;  // set output distance value

    //--Is point of closest approach (A) on track?
    if (track->IsStarting()) 
      if (track->IsStopping()) 
	//-contained track
	if (TA>=0 && TA<=track->Length()) ontrack=kTRUE;
	else if (TA>=0 && TA>track->Length()) ontrack=kFALSE;
	else ontrack=kFALSE;
      else 
	//-starting track
	if (TA>=0) ontrack=kTRUE;
	else ontrack=kFALSE;
    else
      if (track->IsStopping())
	//-stopping track
	if (TA>=0) ontrack=kFALSE;
	else ontrack=kTRUE;
      else
	//-infitine track
	ontrack=kTRUE;

    //--Return position of closest approach
    appos=ShiftAlongTrack(track, TA);
    

    //--Don't calculate if track does not have direction
  } else {
    cout <<"I3Distance::ClosestApproach - Track has no direction. Not calculating.\n";
    apdist=NAN;
    appos.SetPosition(999,999,999,I3Position::car);
    ontrack=kFALSE;
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
Bool_t I3Distance::IsOnTrack(I3Track* track, I3Position& pos)
{
  I3Position appos;
  Double_t apdist;
  Bool_t ontrack;
  ClosestApproach(track,pos,appos,apdist,ontrack);
  if (apdist<=Precision() && ontrack==kTRUE) return kTRUE;
  else return kFALSE;
}

//--------------------------------------------------------------

