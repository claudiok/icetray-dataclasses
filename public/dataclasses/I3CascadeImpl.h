/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CascadeImpl.h,v 1.2 2004/04/22 15:55:44 pretz Exp $
 *
 * @file I3CascadeImpl.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3CASCADEIMPL_H
#define I3CASCADEIMPL_H

#include <TObject.h>
#include "dataclasses/I3Cascade.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * A class which modularizes how the I3Cascade interface is implemented.
 * To pick a particular I3Cascade implementation, you need to first select
 * a DirectionalType, a LocalizableType, and an  EnergeticType.  
 * 
 */
template <class DirectionalType,
          class LocalizableType,
          class EnergeticType>
class I3CascadeImpl : public I3Cascade,
                      public DirectionalType,
                      public LocalizableType,
                      public EnergeticType
{
 public:
  /**
   * constructor
   */
  I3CascadeImpl() {};

  /**
   * destructor
   */
  virtual ~I3CascadeImpl() {};

  /**
   * indicates whether the cascade has an energy, and whether the Energy() 
   * method  will work
   */ 
  virtual Bool_t IsEnergetic() const {return EnergeticType::IsEnergetic();}

  /**
   * indicates whether the cascade has a direction, and whether Zenith()and 
   * Azimuth() are legimitate to call.
   */
  virtual Bool_t IsDirectional() const 
    {
      return DirectionalType::IsDirectional();
    }

  /**
   * indicates whether the particle is localized within the detector, and 
   * whether X(), Y(), Z() and T() are legitimate to call
   */
  virtual Bool_t IsLocalized() const {return LocalizableType::IsLocalized();}

  /**
   * the zenith of the cascade
   */
  virtual Double_t Zenith() const {return DirectionalType::Zenith();}
  using DirectionalType::Zenith;

  /**
   * the azimuth of the cascade
   */
  virtual Double_t Azimuth() const {return DirectionalType::Azimuth();}
  using DirectionalType::Azimuth;

  /**
   * the X position of the cascade
   */
  virtual Double_t X() const {return LocalizableType::X();}
  using LocalizableType::X;

  /**
   * the Y position of the cascade
   */
  virtual Double_t Y() const {return LocalizableType::Y();}
  using LocalizableType::Y;

  /**
   * the Z position of the cascade
   */
  virtual Double_t Z() const {return LocalizableType::Z();}
  using LocalizableType::Z;

  /**
   * the time of the cascade
   */
  virtual Double_t T() const {return LocalizableType::T();}
  using LocalizableType::T;

  /**
   * the position of the cascade as an I3Position object
   */
  virtual I3Position Pos() const {return I3Position(X(),Y(),Z());}

  /**
   * the energy of the cascade
   */
  virtual Double_t Energy() const {return EnergeticType::Energy();}
  using EnergeticType::Energy;

  virtual void CopyTo(I3Particle& destination) const
    {
      I3Cascade::CopyTo(destination);
      DirectionalType::CopyTo(destination);
      LocalizableType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
    }

  virtual void CopyFrom(const I3Particle& source)
    {
      source.CopyTo(*this);
    }

 private:
  // ROOT macro
  ClassDef(I3CascadeImpl,1);
};

#endif
