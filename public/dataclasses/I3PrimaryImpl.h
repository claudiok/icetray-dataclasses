/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3PrimaryImpl.h,v 1.10.4.3 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3PrimaryImpl.h
 * @version $Revision: 1.10.4.3 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author pretz
 *
 */
#ifndef I3PRIMARYIMPL_H
#define I3PRIMARYIMPL_H

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
  virtual Bool_t HasEnergy() const {return EnergeticType::HasEnergy();}

  /**
   * indicates whether or not the particle has a valid direction
   */
  virtual Bool_t HasDirection() const {return DirectionalType::HasDirection();}

  /**
   * indicates whether or not the primary has a valid core position
   */
  virtual Bool_t IsCoreLocalized() const {return LocalizableType::IsCoreLocalized();}

  /**
   * indicates whether or not the primary has a valid inice position
   */
  virtual Bool_t IsLocalized() const {return LocalizableType::IsLocalized();}

  /**
   * indicates that this is not an in ice partcile
   */
  virtual Bool_t IsInIce() const { return kFALSE;}

  /** 
   * indicates taht this is not an ice top particle
   */ 
  virtual Bool_t IsIceTop() const { return kFALSE;}

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

};

#endif
