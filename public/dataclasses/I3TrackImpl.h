/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackImpl.h,v 1.7 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3TrackImpl.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/06/30 17:20:26 $
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
  virtual Bool_t HasEnergy() const {return EnergeticType::HasEnergy();}

  /**
   * indicates that the track is a composite track
   */
  virtual Bool_t IsComposite() const {return CompositeType::IsComposite();}

  /**
   * indicates that Zenith() and Azimuth() are valid
   */
  virtual Bool_t HasDirection() const 
    {
      return GeometricalType::HasDirection();
    }

  /**
   * gets the zenith
   */
  virtual Double_t GetZenith() const {return GeometricalType::GetZenith();}

  /**
   * gets the azimuth
   */
  virtual Double_t GetAzimuth() const {return GeometricalType::GetAzimuth();}

  /**
   * starting x position
   */
  virtual Double_t GetStartX() const {return GeometricalType::GetStartX();}

  /**
   * starting y position
   */
  virtual Double_t GetStartY() const {return GeometricalType::GetStartY();}

  /**
   * starting z position
   */
  virtual Double_t GetStartZ() const {return GeometricalType::GetStartZ();}

  /**
   * starting time
   */
  virtual Double_t GetStartT() const {return GeometricalType::GetStartT();}

  /**
   * the starting position as an I3Position
   */
  virtual I3Position GetStartPos() const 
    {
      return GeometricalType::GetStartPos();
    }

  /**
   * the stopping x position
   */
  virtual Double_t GetStopX() const {return GeometricalType::GetStopX();}

  /**
   * the stopping y position
   */
  virtual Double_t GetStopY() const {return GeometricalType::GetStopY();}

  /**
   * the stopping z position
   */
  virtual Double_t GetStopZ() const {return GeometricalType::GetStopZ();}

  /**
   * the stopping time
   */
  virtual Double_t GetStopT() const {return GeometricalType::GetStopT();}

  /**
   * the stopping position as an I3Position
   */
  virtual I3Position GetStopPos() const 
    {
      return GeometricalType::GetStopPos();;
    }

  /**
   * some X position along the track, corresponding to Y(),Z(), and T()
   */
  virtual Double_t GetX() const {return GeometricalType::GetX();}

  /**
   * some Y position along the track corresponding to X(), Z() and T()
   */
  virtual Double_t GetY() const {return GeometricalType::GetY();}

  /**
   * some Z position along the track corresponding to X(), Y() and T()
   */
  virtual Double_t GetZ() const {return GeometricalType::GetZ();}

  /**
   * the time the track was at X(), Y() and Z()
   */
  virtual Double_t GetT() const {return GeometricalType::GetT();}

  /**
   * the Position of the track at time T()
   */
  virtual I3Position GetPos() const 
    {
      return GeometricalType::GetPos();
    }

  /**
   * The energy of the particle
   */
  virtual Double_t GetEnergy() const {return EnergeticType::GetEnergy();}

  /**
   * the speed of the particle
   */
  virtual Double_t GetSpeed() const {return GeometricalType::GetSpeed();}

  /**
   * the length of the particle
   */
  virtual Double_t GetLength() const {return GeometricalType::GetLength();}

  /**
   * the number of particles that go into making up this composite track
   */
  virtual int GetNumConstituents() const 
    {
      return CompositeType::GetNumConstituents();
    }
  
  /**
   * the ith particle making up this composite track
   */
  virtual const I3Particle& GetConstituent(int i) const 
    {
      return CompositeType::GetConstituent(i);
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
