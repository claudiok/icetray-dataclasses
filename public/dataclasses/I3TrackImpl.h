/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackImpl.h,v 1.2 2004/04/22 15:55:44 pretz Exp $
 *
 * @file I3TrackImpl.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:55:44 $
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
  /**
   * constructor
   */
  I3TrackImpl() {};

  /**
   * destructor
   */
  virtual ~I3TrackImpl() {};

  /**
   * indicates that the 'StartX() ... ' parameters are valid
   */
  virtual Bool_t IsStarting() const {return GeometricalType::IsStarting();}

  /**
   * indicates that the 'StopX() ...' parameters are valid
   */
  virtual Bool_t IsStopping() const {return GeometricalType::IsStopping();}

  /**
   * indicates that the particle is infinite
   */
  virtual Bool_t IsInfinite() const 
    {
      if (GeometricalType::IsStarting() || GeometricalType::IsStopping())
	return false;
      return true;
    }

  /**
   * indicates that the particle is starting and stopping
   */
  virtual Bool_t IsContained() const 
    {
      if(GeometricalType::IsStarting() && GeometricalType::IsStopping())
	return true;
      return false;
    }

  /**
   * indicates that the track has an energy
   */
  virtual Bool_t IsEnergetic() const {return EnergeticType::IsEnergetic();}

  /**
   * indicates that the track is a composite track
   */
  virtual Bool_t IsComposite() const {return CompositeType::IsComposite();}

  /**
   * indicates that Zenith() and Azimuth() are valid
   */
  virtual Bool_t IsDirectional() const 
    {
      return GeometricalType::IsDirectional();
    }

  /**
   * gets the zenith
   */
  virtual Double_t Zenith() const {return GeometricalType::Zenith();}
  using GeometricalType::Zenith;

  /**
   * gets the azimuth
   */
  virtual Double_t Azimuth() const {return GeometricalType::Azimuth();}
  using GeometricalType::Azimuth;

  /**
   * starting x position
   */
  virtual Double_t StartX() const {return GeometricalType::StartX();}
  using GeometricalType::StartX;

  /**
   * starting y position
   */
  virtual Double_t StartY() const {return GeometricalType::StartY();}
  using GeometricalType::StartY;

  /**
   * starting z position
   */
  virtual Double_t StartZ() const {return GeometricalType::StartZ();}
  using GeometricalType::StartZ;

  /**
   * starting time
   */
  virtual Double_t StartT() const {return GeometricalType::StartT();}
  using GeometricalType::StartT;

  /**
   * the starting position as an I3Position
   */
  virtual I3Position StartPos() const 
    {
      return I3Position(StartX(),StartY(),StartZ());
    }

  /**
   * the stopping x position
   */
  virtual Double_t StopX() const {return GeometricalType::StopX();}
  using GeometricalType::StopX;

  /**
   * the stopping y position
   */
  virtual Double_t StopY() const {return GeometricalType::StopY();}
  using GeometricalType::StopY;

  /**
   * the stopping z position
   */
  virtual Double_t StopZ() const {return GeometricalType::StopZ();}
  using GeometricalType::StopZ;

  /**
   * the stopping time
   */
  virtual Double_t StopT() const {return GeometricalType::StopT();}
  using GeometricalType::StopT;

  /**
   * the stopping position as an I3Position
   */
  virtual I3Position StopPos() const 
    {
      return I3Position(StopX(),StopY(),StopZ());
    }

  /**
   * some X position along the track, corresponding to Y(),Z(), and T()
   */
  virtual Double_t X() const {return GeometricalType::X();}
  using GeometricalType::X;

  /**
   * some Y position along the track corresponding to X(), Z() and T()
   */
  virtual Double_t Y() const {return GeometricalType::Y();}
  using GeometricalType::Y;

  /**
   * some Z position along the track corresponding to X(), Y() and T()
   */
  virtual Double_t Z() const {return GeometricalType::Z();}
  using GeometricalType::Z;

  /**
   * the time the track was at X(), Y() and Z()
   */
  virtual Double_t T() const {return GeometricalType::T();}
  using GeometricalType::T;

  /**
   * the Position of the track at time T()
   */
  virtual I3Position Pos() const 
    {
      return I3Position(X(),Y(),Z());
    }


  /**
   * The energy of the particle
   */
  virtual Double_t Energy() const {return EnergeticType::Energy();}
  using EnergeticType::Energy;

  /**
   * the speed of the particle
   */
  virtual Double_t Speed() const {return GeometricalType::Speed();}
  using GeometricalType::Speed;

  /**
   * the length of the particle
   */
  virtual Double_t Length() const {return GeometricalType::Length();}
  using GeometricalType::Length;

  /**
   * the number of particles that go into making up this composite track
   */
  virtual int NumConstituents() const 
    {
      return CompositeType::NumConstituents();
    }
  
  /**
   * the ith particle making up this composite track
   */
  virtual const I3Particle& Constituent(int i) const 
    {
      return CompositeType::Constituent(i);
    }

  /**
   * copies over data from this particle to the destination particle
   * Only copies that data which the two have in common
   */
  virtual void CopyTo(I3Particle& destination) const 
    {
      I3Track::CopyTo(destination);
      GeometricalType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
      CompositeType::CopyTo(destination);
    }
  
 protected:

  // ROOT macro
  ClassDef(I3TrackImpl,1);
};


#endif
