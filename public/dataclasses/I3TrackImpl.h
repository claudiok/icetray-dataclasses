/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TrackImpl.h,v 1.1.2.1 2004/04/16 17:10:56 pretz Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/16 17:10:56 $
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
          class SpeedyType,
          class CompositeType>
class I3TrackImpl : public I3Track,
                    public IdentifiableType,
                    public GeometricalType,
                    public EnergeticType,
                    public SpeedyType,
                    public CompositeType
{
 public:
  I3TrackImpl() {};

  virtual ~I3TrackImpl() {};

  virtual bool IsIdentifiable() const 
    {
      return IdentifiableType::IsIdentifiable();
    }
  virtual bool IsLengthy() const {return GeometricalType::IsLengthy();}
  virtual bool IsStarting() const {return GeometricalType::IsStarting();}
  virtual bool IsStopping() const {return GeometricalType::IsStopping();}
  virtual bool IsInfinite() const {return GeometricalType::IsInfinite();}
  virtual bool IsContained() const 
    {
      if(GeometricalType::IsStarting() && GeometricalType::IsStopping())
	return true;
      return false;
    }
  virtual bool IsEnergetic() const {return EnergeticType::IsEnergetic();}
  virtual bool IsSpeedy() const {return SpeedyType::IsSpeedy();}
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
  virtual void StartT(double startt){GeometricalType::StartT();}

  virtual double StopX() const {return GeometricalType::StopX();}
  virtual void StopX(double stopx) {GeometricalType::StopX();}

  virtual double StopY() const {return GeometricalType::StopY();}
  virtual void StopY(double stopy) {GeometricalType::StopY();}

  virtual double StopZ() const {return GeometricalType::StopZ();}
  virtual void StopZ(double stopz) {GeometricalType::StopZ(stopz);}

  virtual double StopT() const {return GeometricalType::StopT();}
  virtual void StopT(double stopt) {GeometricalType::StopT(stopt);}

  virtual double X() const {return GeometricalType::X();}
  virtual void X(double x) {GeometricalType::X(x);}

  virtual double Y() const {return GeometricalType::Y();}
  virtual void Y(double y){GeometricalType::Y(y);}

  virtual double Z() const {return GeometricalType::Z();}
  virtual void Z(double z){GeometricalType::Z(z);}

  virtual double T() const {return GeometricalType::T();}
  virtual void T(double t){GeometricalType::T(t);}

  virtual double Energy() const {return EnergeticType::Energy();}
  virtual void Energy(double energy) {EnergeticType::Energy(energy);}

  virtual double Speed() const {return SpeedyType::Speed();}
  virtual void Speed(double speed) {SpeedyType::Speed(speed);}

  virtual double Length() const {return GeometricalType::Length();}
  virtual void Length(double length) {GeometricalType::Length();}

  virtual int NumConstituents() const {return CompositeType::NumConstituents();}
  virtual const I3Particle& Constituent(int i) const 
    {
      return CompositeType::Constituent(i);
    }

  ClassDef(I3TrackImpl,1);
};

#endif
