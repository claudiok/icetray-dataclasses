/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CascadeImpl.h,v 1.13 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3CascadeImpl.h
 * @version $Revision: 1.13 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3CASCADEIMPL_H
#define I3CASCADEIMPL_H

#include <TObject.h>
#include "dataclasses/I3Cascade.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * @brief A class which modularizes how the I3Cascade interface is implemented.
 *
 * To pick a particular I3Cascade implementation, you need to first select
 * a DirectionalType, a LocalizableType, and an  EnergeticType.  
 * 
 */
template <class DirectionalType,
          class LocalizableType,
          class EnergeticType,
          class CompositeType>
class I3CascadeImpl : public I3Cascade,
                      public DirectionalType,
                      public LocalizableType,
                      public EnergeticType,
                      public CompositeType
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
  virtual bool HasEnergy() const {return EnergeticType::HasEnergy();}

  /**
   * indicates whether the cascade has a direction, and whether Zenith()and 
   * Azimuth() are legimitate to call.
   */
  virtual bool HasDirection() const 
    {
      return DirectionalType::HasDirection();
    }

  /**
   * indicates whether the particle is localized within the detector, and 
   * whether X(), Y(), Z() and T() are legitimate to call
   */
  virtual bool IsLocalized() const {return LocalizableType::IsLocalized();}

  /**
   * indicates whether the cascade is a composite cascade
   */
  virtual bool IsComposite() const {return CompositeType::IsComposite();}

  /**
   * the time of the cascade
   */
  virtual double GetT() const {return LocalizableType::GetT();}

  /**
   * the position of the cascade as an I3Position object
   */
  virtual I3Position GetPos() const {return LocalizableType::GetPos();}

  virtual void CopyTo(I3Particle& destination) const
    {
      I3Cascade::CopyTo(destination);
      DirectionalType::CopyTo(destination);
      LocalizableType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
      CompositeType::CopyTo(destination);
    }

  virtual void CopyFrom(const I3Particle& source)
    {
      source.CopyTo(*this);
    }

  virtual void ToStream(ostream& o) const
    {
      I3Cascade::ToStream(o);
      DirectionalType::ToStream(o);
      LocalizableType::ToStream(o);
      EnergeticType::ToStream(o);
      CompositeType::ToStream(o);
    }

 private:
  // ROOT macro
  ClassDef(I3CascadeImpl,1);
};

#endif
