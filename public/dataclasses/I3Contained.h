/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Contained.h,v 1.9 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3Contained.h
 * @version $Revision: 1.9 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 */
#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include "I3Units.h"
#include "I3Constants.h"
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
  Double_t GetStartX() const {return fStartPos.GetX();}

  /**
   * gives the starting y postion
   */
  Double_t GetStartY() const {return fStartPos.GetY();}

  /**
   * gives the starting z postion
   */
  Double_t GetStartZ() const {return fStartPos.GetZ();}

  /**
   * sets the starting x positon
   */
  void SetStartX(Double_t startx){fStartPos.SetX(startx);}

  /**
   * sets the starting y positon
   */
  void SetStartY(Double_t starty){fStartPos.SetY(starty);}

  /**
   * sets the starting z positon
   */
  void SetStartZ(Double_t startz){fStartPos.SetZ(startz);}

  /**
   * gets the starting time
   */
  Double_t GetStartT() const {return fStartT;}

  /**
   * sets the starting time
   */
  void SetStartT(Double_t startt) {fStartT = startt;}

  /**
   * gets the starting position
   */
  I3Position GetStartPos() const {return fStartPos;}

  /**
   * sets the starting position
   */
  void SetStartPos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position in any reference frame
   */
  void SetStartPos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * returns the starting x position as a position along the track
   */
  Double_t GetX() const {return fStartPos.GetX();}

  /**
   * returns the starting y position as a position along the track
   */
  Double_t GetY() const {return fStartPos.GetY();}

  /**
   * returns the starting z position as a position along the track
   */
  Double_t GetZ() const {return fStartPos.GetZ();}

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  Double_t GetT() const {return fStartT;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position GetPos() const {return fStartPos;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position as a position along the track
   * in any reference frame
   */
  void SetPos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * gives the zenith of the track
   */
  Double_t GetZenith() const {return fZenith;}

  /**
   * gives the azimuth of the track
   */
  Double_t GetAzimuth() const {return fAzimuth;}

  /**
   * sets the zenith of the track
   */
  void SetZenith(Double_t theta){fZenith = theta;}

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(Double_t phi){fAzimuth = phi;}

  /**
   * gives the length of the track
   */
  Double_t GetLength() const {return fLength;}

  /**
   * sets the length of the track
   */
  void SetLength(Double_t length) {fLength = length;}

  /**
   * computes the stoping x position of the track
   */
  Double_t GetStopX() const {
    return fStartPos.GetX() + fLength * sin(fZenith) * cos (fAzimuth);
  }

  /**
   * computes the stoping y position of the track
   */
  Double_t GetStopY() const 
    {
      return fStartPos.GetY() + fLength * sin(fZenith) * sin(fAzimuth);
    }

  /**
   * computes the stoping z position of the track
   */
  Double_t GetStopZ() const 
    {
      return fStartPos.GetZ() + fLength * cos(fZenith);
    }

  /**
   * computes the stopping t of the track
   */
  Double_t GetStopT() const 
    {
      return fStartT + fLength / GetSpeed();
    }
  
  /**
   * computes the stopping position of the track
   */
  I3Position GetStopPos() const
    {
      I3Position p;
      Double_t x,y,z;
      x = fStartPos.GetX() - fLength * sin(fZenith) * cos (fAzimuth);
      y = fStartPos.GetY() - fLength * sin(fZenith) * sin(fAzimuth);
      z = fStartPos.GetZ() - fLength * cos(fZenith);
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
  Double_t GetSpeed() const {return I3Constants::c;}

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
