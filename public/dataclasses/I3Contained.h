/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Contained.h,v 1.6 2004/06/09 21:56:34 dule Exp $
 *
 * @file I3Contained.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/06/09 21:56:34 $
 * @author pretz
 */
#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include "I3Units.h"
#include "I3Distance.h"
#include <cmath>
/**
 * @brief This class services the 'geometrical' part of an I3Track interface.
 *
 * Has a starting postion, a length, and a direction.  So the full interface
 * is implemented.  Assumes the particle is relativistic.
 */
class I3Contained
{
 private:
/*   Double_t fStartX; */
/*   Double_t fStartY; */
/*   Double_t fStartZ; */
  I3Position fStartPos;
  Double_t fStartT;
  Double_t fZenith;
  Double_t fAzimuth;
  Double_t fLength;
 public:
  /**
   * indicates that the track is starting
   */
  Bool_t IsStarting() const {return true;}

  /**
   * indicates that the track is stopping
   */
  Bool_t IsStopping() const {return true;}

  /**
   * indicates that the track has a direction
   */
  Bool_t HasDirection() const {return true;}

  /**
   * gives the starting x postion
   */
  Double_t StartX() const {return fStartPos.X();}

  /**
   * gives the starting y postion
   */
  Double_t StartY() const {return fStartPos.Y();}

  /**
   * gives the starting z postion
   */
  Double_t StartZ() const {return fStartPos.Z();}

  /**
   * sets the starting x positon
   */
  void StartX(Double_t startx){fStartPos.SetX(startx);}

  /**
   * sets the starting y positon
   */
  void StartY(Double_t starty){fStartPos.SetY(starty);}

  /**
   * sets the starting z positon
   */
  void StartZ(Double_t startz){fStartPos.SetZ(startz);}

  /**
   * gets the starting time
   */
  Double_t StartT() const {return fStartT;}

  /**
   * sets the starting time
   */
  void StartT(Double_t startt) {fStartT = startt;}

  /**
   * gets the starting position
   */
  I3Position StartPos() const {return fStartPos;}

  /**
   * sets the starting position
   */
  void StartPos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position in any reference frame
   */
  void StartPos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * returns the starting x position as a position along the track
   */
  Double_t X() const {return fStartPos.X();}

  /**
   * returns the starting y position as a position along the track
   */
  Double_t Y() const {return fStartPos.Y();}

  /**
   * returns the starting z position as a position along the track
   */
  Double_t Z() const {return fStartPos.Z();}

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  Double_t T() const {return fStartT;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position Pos() const {return fStartPos;}

  /**
   * sets the starting positition as a position on the track
   */
  void Pos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position as a position along the track
   * in any reference frame
   */
  void Pos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * gives the zenith of the track
   */
  Double_t Zenith() const {return fZenith;}

  /**
   * gives the azimuth of the track
   */
  Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the zenith of the track
   */
  void Zenith(Double_t theta){fZenith = theta;}

  /**
   * sets the azimuth of the track
   */
  void Azimuth(Double_t phi){fAzimuth = phi;}

  /**
   * gives the length of the track
   */
  Double_t Length() const {return fLength;}

  /**
   * sets the length of the track
   */
  void Length(Double_t length) {fLength = length;}

  /**
   * computes the stoping x position of the track
   */
  Double_t StopX() const {
    return fStartPos.X() + fLength * sin(fZenith) * cos (fAzimuth);
  }

  /**
   * computes the stoping y position of the track
   */
  Double_t StopY() const 
    {
      return fStartPos.Y() + fLength * sin(fZenith) * sin(fAzimuth);
    }

  /**
   * computes the stoping z position of the track
   */
  Double_t StopZ() const 
    {
      return fStartPos.Z() + fLength * cos(fZenith);
    }

  /**
   * computes the stopping t of the track
   */
  Double_t StopT() const 
    {
      return fStartT + fLength / Speed();
    }
  
  /**
   * computes the stopping position of the track
   */
  I3Position StopPos() const
    {
      I3Position p;
      Double_t x,y,z;
      x = fStartPos.X() - fLength * sin(fZenith) * cos (fAzimuth);
      y = fStartPos.Y() - fLength * sin(fZenith) * sin(fAzimuth);
      z = fStartPos.Z() - fLength * cos(fZenith);
      // According to IceCube angle definitions, zenith is from -z,
      // and azimuth is from -x toward -y.
      // This means that there is a minus sign in the calculations.
      p.SetPosition(x,y,z,I3Position::car);
      return p;
/*       return I3Distance::ShiftAlongTrack(this, fLength); */
    }

  /**
   * returns the speed of light
   */
  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  /**
   * copies all the interal data into destination if a dynamic cast
   * to I3Contained succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Contained* contained = dynamic_cast<I3Contained*>(&destination);
      if(contained){
	contained->fStartPos = fStartPos;
	contained->fStartT = fStartT;
	contained->fAzimuth = fAzimuth;
	contained->fZenith = fZenith;
	contained->fLength = fLength;
      }
    }

  private:
    //ROOT macro
  ClassDef(I3Contained,1)
};

#endif //I3CONTAINED_H
