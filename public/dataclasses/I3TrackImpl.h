/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TrackImpl.h,v 1.1.2.3 2004/04/19 18:09:53 pretz Exp $

    @version $Revision: 1.1.2.3 $
    @date $Date: 2004/04/19 18:09:53 $
    @author

    @todo

*/

#ifndef I3TRACKIMPL_H
#define I3TRACKIMPL_H

#include <TObject.h>
#include "dataclasses/I3Track.h"
#include <vector>
#include <cmath>

#include <iostream>

template <class IdentifiableType,
          class GeometricalType,
          class EnergeticType,
          class CompositeType>
class I3TrackImpl : public I3Track,
                    public IdentifiableType,
                    public GeometricalType,
                    public EnergeticType,
                    public CompositeType
{
 public:
  I3TrackImpl() {};

  virtual ~I3TrackImpl() {};

  virtual bool IsIdentifiable() const 
    {
      return IdentifiableType::IsIdentifiable();
    }
  virtual bool IsStarting() const {return GeometricalType::IsStarting();}
  virtual bool IsStopping() const {return GeometricalType::IsStopping();}
  virtual bool IsInfinite() const 
    {
      if (GeometricalType::IsStarting() || GeometricalType::IsStopping())
	return false;
      return true;
    }
  virtual bool IsContained() const 
    {
      if(GeometricalType::IsStarting() && GeometricalType::IsStopping())
	return true;
      return false;
    }
  virtual bool IsEnergetic() const {return EnergeticType::IsEnergetic();}
  virtual bool IsComposite() const {return CompositeType::IsComposite();}
  virtual bool IsDirectional() const {return GeometricalType::IsDirectional();}

  virtual ParticleType Type() const {return IdentifiableType::Type();}

  virtual double Zenith() const {return GeometricalType::Zenith();}
  virtual void Zenith(double theta) {GeometricalType::Zenith(theta);}

  virtual double Azimuth() const {return GeometricalType::Azimuth();}
  virtual void Azimuth(double phi) {GeometricalType::Azimuth(phi);}

  virtual double StartX() const {return GeometricalType::StartX();}
  virtual void StartX(double startx) {GeometricalType::StartX(startx);}

  virtual double StartY() const {return GeometricalType::StartY();}
  virtual void StartY(double starty){GeometricalType::StartY(starty);}

  virtual double StartZ() const {return GeometricalType::StartZ();}
  virtual void StartZ(double startz){GeometricalType::StartZ(startz);}

  virtual double StartT() const {return GeometricalType::StartT();}
  virtual void StartT(double startt){GeometricalType::StartT(startt);}

  virtual I3Position StartPos() const 
    {
      return I3Position(StartX(),StartY(),StartZ(),StartT());
    }

  virtual double StopX() const {return GeometricalType::StopX();}
  virtual void StopX(double stopx) {GeometricalType::StopX(stopx);}

  virtual double StopY() const {return GeometricalType::StopY();}
  virtual void StopY(double stopy) {GeometricalType::StopY(stopy);}

  virtual double StopZ() const {return GeometricalType::StopZ();}
  virtual void StopZ(double stopz) {GeometricalType::StopZ(stopz);}

  virtual double StopT() const {return GeometricalType::StopT();}
  virtual void StopT(double stopt) {GeometricalType::StopT(stopt);}

  virtual I3Position StopPos() const 
    {
      return I3Position(StopX(),StopY(),StopZ(),StopT());
    }

  virtual double X() const {return GeometricalType::X();}
  virtual void X(double x) {GeometricalType::X(x);}

  virtual double Y() const {return GeometricalType::Y();}
  virtual void Y(double y){GeometricalType::Y(y);}

  virtual double Z() const {return GeometricalType::Z();}
  virtual void Z(double z){GeometricalType::Z(z);}

  virtual double T() const {return GeometricalType::T();}
  virtual void T(double t){GeometricalType::T(t);}

  virtual I3Position Pos() const 
    {
      return I3Position(X(),Y(),Z(),T());
    }

  virtual double Energy() const {return EnergeticType::Energy();}
  virtual void Energy(double energy) {EnergeticType::Energy(energy);}

  virtual double Speed() const {return GeometricalType::Speed();}
  virtual void Speed(double speed) {GeometricalType::Speed(speed);}

  virtual double Length() const {return GeometricalType::Length();}
  virtual void Length(double length) {GeometricalType::Length(length);}

  virtual int NumConstituents() const {return CompositeType::NumConstituents();}
  virtual const I3Particle& Constituent(int i) const 
    {
      return CompositeType::Constituent(i);
    }

  virtual void CopyTo(I3Particle& destination) const 
    {
      IdentifiableType::CopyTo(destination);
      GeometricalType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
      CompositeType::CopyTo(destination);
    }

  ClassDef(I3TrackImpl,1);
};

#endif
