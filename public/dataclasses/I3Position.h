/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Position.h,v 1.1.2.4 2004/04/21 16:03:10 pretz Exp $
 *
 * @file I3Position.h
 * @version $Revision: 1.1.2.4 $
 * @date $Date: 2004/04/21 16:03:10 $
 * @author pretz
 *
 */
#ifndef I3POSITION_H
#define I3POSITION_H

#include "TObject.h"
/**
 * A basic position class.  Just getters and setters for x,y,z.   
 * @todo implement other coordinate system getters.
 * @todo implement stuff like dot product etc
 * @todo can probably get some lessons from AliPosition
 *
 */
class I3Position : public TObject
{
 private:
  Double_t fX;
  Double_t fY;
  Double_t fZ;
 public:
  /**
   * constructor
   */
  I3Position() : fX(0),fY(0),fZ(0){}

  /**
   * constructor
   * @param x the initial x position
   * @paray y the initial y position
   * @param z the initial z position
   */
  I3Position(Double_t x,Double_t y,Double_t z) :fX(x),fY(y),fZ(z){}

  /**
   * gets the x value
   */
  Double_t X() {return fX;}

  /**
   * sets the x value
   */
  void X(Double_t x) {fX = x;}

  /**
   * gets the Y value
   */
  Double_t Y() {return fY;}

  /**
   * sets the y value
   */
  void Y(Double_t y) {fY = y;}

  /**
   * gets the Z value
   */
  Double_t Z() {return fZ;}

  /**
   * sets the z value
   */
  void Z(Double_t z) {fZ = z;}

 private:
  // ROOT macro
  ClassDef(I3Position,1);
};

#endif // I3POSITION
