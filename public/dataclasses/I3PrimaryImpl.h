/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3PrimaryImpl.h
 * @version $Revision: 1.13 $
 * @date $Date$
 * @author pretz
 *
 */
#ifndef I3PRIMARYIMPL_H
#define I3PRIMARYIMPL_H

#include <TObject.h>
#include "dataclasses/I3Primary.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * @brief A class for modularizing how the I3Primary interface is implemented.
 *
 * All you need to do is specify the a DirectionalType, a LocalizableType, and an
 * EnergeticType which satisfy the interface, and you've got a new I3Primary
 * implementation
 */
template <class DirectionalType,
          class LocalizableType,
          class EnergeticType>
class I3PrimaryImpl : public I3Primary,
                      public DirectionalType,
                      public LocalizableType,
                      public EnergeticType
{
 public:
  /**
   * constructor
   */
  I3PrimaryImpl() {};

  /**
   * destructor
   */
  virtual ~I3PrimaryImpl() {};

  /**
   * indicates whether or not the particle has a valid energy
   */
  virtual bool HasEnergy() const {return EnergeticType::HasEnergy();}

  /**
   * indicates whether or not the particle has a valid direction
   */
  virtual bool HasDirection() const {return DirectionalType::HasDirection();}

  /**
   * indicates whether or not the primary has a valid core position
   */
  virtual bool IsCoreLocalized() const {return LocalizableType::IsCoreLocalized();}

  /**
   * indicates whether or not the primary has a valid inice position
   */
  virtual bool IsLocalized() const {return LocalizableType::IsLocalized();}

  /**
   * indicates that this is not an in ice partcile
   */
  virtual bool IsInIce() const { return false;}

  /** 
   * indicates taht this is not an ice top particle
   */ 
  virtual bool IsIceTop() const { return false;}

  /**
   * 
   */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Particle::CopyTo(destination);
      DirectionalType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
      LocalizableType::CopyTo(destination);
    }

 private:
  //ROOT macro
  ClassDef(I3PrimaryImpl,1);
};

#endif
