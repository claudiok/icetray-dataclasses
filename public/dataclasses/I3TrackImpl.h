/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackImpl.h,v 1.1.2.9 2004/04/21 16:03:10 pretz Exp $
 *
 * @file I3TrackImpl.h
 * @version $Revision: 1.1.2.9 $
 * @date $Date: 2004/04/21 16:03:10 $
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3TRACKIMPL_H
#define I3TRACKIMPL_H

#include <TObject.h>
#include "dataclasses/I3Track.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * A class which modularizes how the I3Track interface is implemented.
 * To pick a particular I3Track implementation, you need to first select
 * a Geometrical Type, an EnergeticType, and a Composite Type, which implements
 * the appropriate pieces of the interface.
 * 
 */
template <class GeometricalType,
          class EnergeticType,
          class CompositeType>
class I3TrackImpl : public I3Track,
                    public GeometricalType,
                    public EnergeticType,
                    public CompositeType
{
 public:
  I3TrackImpl() {};

  virtual ~I3TrackImpl() {};

  virtual Bool_t IsStarting() const {return GeometricalType::IsStarting();}
  virtual Bool_t IsStopping() const {return GeometricalType::IsStopping();}
  virtual Bool_t IsInfinite() const 
    {
      if (GeometricalType::IsStarting() || GeometricalType::IsStopping())
	return false;
      return true;
    }
  virtual Bool_t IsContained() const 
    {
      if(GeometricalType::IsStarting() && GeometricalType::IsStopping())
	return true;
      return false;
    }
  virtual Bool_t IsEnergetic() const {return EnergeticType::IsEnergetic();}
  virtual Bool_t IsComposite() const {return CompositeType::IsComposite();}
  virtual Bool_t IsDirectional() const {return GeometricalType::IsDirectional();}

  virtual Double_t Zenith() const {return GeometricalType::Zenith();}
  virtual void Zenith(Double_t theta) {GeometricalType::Zenith(theta);}

  virtual Double_t Azimuth() const {return GeometricalType::Azimuth();}
  virtual void Azimuth(Double_t phi) {GeometricalType::Azimuth(phi);}

  virtual Double_t StartX() const {return GeometricalType::StartX();}
  virtual void StartX(Double_t startx) {GeometricalType::StartX(startx);}

  virtual Double_t StartY() const {return GeometricalType::StartY();}
  virtual void StartY(Double_t starty){GeometricalType::StartY(starty);}

  virtual Double_t StartZ() const {return GeometricalType::StartZ();}
  virtual void StartZ(Double_t startz){GeometricalType::StartZ(startz);}

  virtual Double_t StartT() const {return GeometricalType::StartT();}
  virtual void StartT(Double_t startt){GeometricalType::StartT(startt);}

  virtual I3Position StartPos() const 
    {
      return I3Position(StartX(),StartY(),StartZ());
    }

  virtual Double_t StopX() const {return GeometricalType::StopX();}
  virtual void StopX(Double_t stopx) {GeometricalType::StopX(stopx);}

  virtual Double_t StopY() const {return GeometricalType::StopY();}
  virtual void StopY(Double_t stopy) {GeometricalType::StopY(stopy);}

  virtual Double_t StopZ() const {return GeometricalType::StopZ();}
  virtual void StopZ(Double_t stopz) {GeometricalType::StopZ(stopz);}

  virtual Double_t StopT() const {return GeometricalType::StopT();}
  virtual void StopT(Double_t stopt) {GeometricalType::StopT(stopt);}

  virtual I3Position StopPos() const 
    {
      return I3Position(StopX(),StopY(),StopZ());
    }

  virtual Double_t X() const {return GeometricalType::X();}
  virtual void X(Double_t x) {GeometricalType::X(x);}

  virtual Double_t Y() const {return GeometricalType::Y();}
  virtual void Y(Double_t y){GeometricalType::Y(y);}

  virtual Double_t Z() const {return GeometricalType::Z();}
  virtual void Z(Double_t z){GeometricalType::Z(z);}

  virtual Double_t T() const {return GeometricalType::T();}
  virtual void T(Double_t t){GeometricalType::T(t);}

  virtual I3Position Pos() const 
    {
      return I3Position(X(),Y(),Z());
    }

  virtual Double_t Energy() const {return EnergeticType::Energy();}
  virtual void Energy(Double_t energy) {EnergeticType::Energy(energy);}

  virtual Double_t Speed() const {return GeometricalType::Speed();}
  virtual void Speed(Double_t speed) {GeometricalType::Speed(speed);}

  virtual Double_t Length() const {return GeometricalType::Length();}
  virtual void Length(Double_t length) {GeometricalType::Length(length);}

  virtual int NumConstituents() const {return CompositeType::NumConstituents();}
  virtual const I3Particle& Constituent(int i) const 
    {
      return CompositeType::Constituent(i);
    }

  virtual void CopyTo(I3Particle& destination) const 
    {
      I3Track::CopyTo(destination);
      GeometricalType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
      CompositeType::CopyTo(destination);
    }
  
 protected:
  

  ClassDef(I3TrackImpl,1);
};


#endif
