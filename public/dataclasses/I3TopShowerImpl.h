/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopShowerImpl.h,v 1.1.4.2 2005/02/04 06:11:43 troy Exp $
 *
 * @file I3TopShowerImpl.h
 * @version $Revision: 1.1.4.2 $
 * @date $Date: 2005/02/04 06:11:43 $
 * @author blaufuss
 *
 */
#ifndef I3TOPSHOWERIMPL_H
#define I3TOPSHOWERIMPL_H

#include "dataclasses/I3TopShower.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * @brief A class for modularizing how the I3TopShower interface is implemented.
 *
 * All you need to do is specify the a DirectionalType, a CoreType, and an
 * EnergeticType which satisfy the interface, and you've got a new I3TopShower
 * implementation
 */
template <class DirectionalType,
          class CoreType,
          class EnergeticType>
class I3TopShowerImpl : public I3TopShower,
                        public DirectionalType,
                        public CoreType,
                        public EnergeticType
{
 public:
  /**
   * constructor
   */
  I3TopShowerImpl() {};

  /**
   * destructor
   */
  virtual ~I3TopShowerImpl() {};

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
  virtual Bool_t IsCoreLocalized() const {return CoreType::IsCoreLocalized();}

  /**
   * 
   */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Particle::CopyTo(destination);
      DirectionalType::CopyTo(destination);
      EnergeticType::CopyTo(destination);
      CoreType::CopyTo(destination);
    }

 private:
  //ROOT macro
  ClassDef(I3TopShowerImpl,1);
};

#endif
