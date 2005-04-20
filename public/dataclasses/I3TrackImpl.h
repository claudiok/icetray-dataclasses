/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3TrackImpl.h
 * @version $Revision: 1.14 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3TRACKIMPL_H
#define I3TRACKIMPL_H

#include <TObject.h>
#include "dataclasses/I3Track.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * @brief A class which modularizes how the I3Track interface is implemented.
 *
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
   * indicates that the 'StartPos() ... ' parameters are valid
   */
  virtual bool IsStarting() const {return GeometricalType::IsStarting();}

  /**
   * indicates that the 'StopPos() ...' parameters are valid
   */
  virtual bool IsStopping() const {return GeometricalType::IsStopping();}

  /**
   * indicates that the particle is infinite
   */
  virtual bool IsInfinite() const 
    {
      if (GeometricalType::IsStarting() || GeometricalType::IsStopping())
	return false;
      return true;
    }

  /**
   * indicates that the particle is starting and stopping
   */
  virtual bool IsContained() const 
    {
      if(GeometricalType::IsStarting() && GeometricalType::IsStopping())
	return true;
      return false;
    }

  /**
   * indicates that the track has an energy
   */
  virtual bool HasEnergy() const {return EnergeticType::HasEnergy();}

  /**
   * indicates that the track is a composite track
   */
  virtual bool IsComposite() const {return CompositeType::IsComposite();}

  /**
   * indicates that Zenith() and Azimuth() are valid
   */
  virtual bool HasDirection() const 
    {
      return GeometricalType::HasDirection();
    }

  /**
   * gets the direction
   */
  virtual I3Direction GetDir() const 
    {
      return GeometricalType::GetDir();
    }

  /**
   * gets the zenith
   */
  virtual double GetZenith() const {return GeometricalType::GetZenith();}

  /**
   * gets the azimuth
   */
  virtual double GetAzimuth() const {return GeometricalType::GetAzimuth();}

  /**
   * the time the track was at X, Y and Z
   */
  virtual double GetT() const {return GeometricalType::GetT();}

  /**
   * the Position of the track at time T()
   */
  virtual I3Position GetPos() const 
    {
      return GeometricalType::GetPos();
    }

  /**
   * the speed of the particle
   */
  virtual double GetSpeed() const {return GeometricalType::GetSpeed();}

  /**
   * the length of the particle
   */
  virtual double GetLength() const {return GeometricalType::GetLength();}

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

  virtual void ToStream(ostream& o) const
    {
      I3Track::ToStream(o);
      GeometricalType::ToStream(o);
      EnergeticType::ToStream(o);
      CompositeType::ToStream(o);
    }

 protected:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3Track", base_object<I3Track>(*this));
    ar & make_nvp("GeometricalType", base_object<GeometricalType>(*this));
    ar & make_nvp("EnergeticType", base_object<EnergeticType>(*this));
    ar & make_nvp("CompositeType", base_object<CompositeType>(*this));
  }
  // ROOT macro
  ClassDef(I3TrackImpl,1);
};


#endif
