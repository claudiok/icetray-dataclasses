/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Contained.h,v 1.5 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3Contained.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 */
#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include "I3Units.h"
#include <cmath>
/**
 * @brief This class services the 'geometrical' part of an I3Track interface.
 *
 * Has a starting postion, a length, and a direction.  So the full interface
 * is implemented.  Assumes the particle is relativistic.
 */
class I3Contained{
 private:
  Double_t fStartX;
  Double_t fStartY;
  Double_t fStartZ;
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
  Double_t StartX() const {return fStartX;}

  /**
   * sets the starting x positon
   */
  void StartX(Double_t startx){fStartX = startx;}

  /**
   * gets the starting Y position
   */
  Double_t StartY() const {return fStartY;}

  /**
   * sets the starting y position
   */
  void StartY(Double_t starty){fStartY = starty;}
  
  /**
   * gets the starting z position
   */
  Double_t StartZ() const {return fStartZ;}

  /**
   * sets the starting z position
   */
  void StartZ(Double_t startz) {fStartZ = startz;}

  /**
   * gets the starting time
   */
  Double_t StartT() const {return fStartT;}

  /**
   * sets the starting time
   */
  void StartT(Double_t startt) {fStartT = startt;}

  /**
   * returns the starting x position as a position along the track
   */
  Double_t X() const {return fStartX;}

  /**
   * returns the starting x position as a position along the track
   */ 
  Double_t Y() const {return fStartY;}

  /**
   * returns the starting y position as a position along the track
   */
  Double_t Z() const {return fStartZ;}

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  Double_t T() const {return fStartT;}

  /**
   * gives the zenith of the track
   */
  Double_t Zenith() const {return fZenith;}

  /**
   * sets the zenith of the track
   */
  void Zenith(Double_t theta){fZenith = theta;}

  /**
   * gives the azimuth of the track
   */
  Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the azimuth of the track
   */
  void Azimuth(Double_t phi){fAzimuth = phi;}

  /**
   * gives the length of the track
   */
  Double_t Length() const {return fLength;}

  /**
   * sets the azimuth of the track
   */
  void Length(Double_t length) {fLength = length;}

  /**
   * computes the stoping x of the track
   */
  Double_t StopX() const {
    return fStartX + fLength * sin(fZenith) * cos (fAzimuth);
  }

  /**
   * computes the stopping y of the track
   */
  Double_t StopY() const 
    {
      return fStartX + fLength * sin(fZenith) * sin(fAzimuth);
    }

  /**
   * computes the stopping z of the track
   */
  Double_t StopZ() const 
    {
      return fStartZ + fLength * cos(fZenith);
    }

  /**
   * computes the stopping t of the track
   */
  Double_t StopT() const 
    {
      return fStartT + fLength / Speed();
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
	contained->fStartX = fStartX;
	contained->fStartY = fStartY;
	contained->fStartZ = fStartZ;
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
