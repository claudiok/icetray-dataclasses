/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3PrimaryImpl.h,v 1.6 2004/05/04 17:56:38 pretz Exp $
 *
 * @file I3PrimaryImpl.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/05/04 17:56:38 $
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
 * All you need to do is specify the a DirectionalType, a CoreType, and an
 * EnergeticType which satisfy the interface, and you've got a new I3Primary
 * implementation
 */
template <class DirectionalType,
          class CoreType,
          class EnergeticType>
class I3PrimaryImpl : public I3Primary,
                      public DirectionalType,
                      public CoreType,
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
  virtual Bool_t HasCorePosition() const {return CoreType::HasCorePosition();}

  /**
   * gives the zenith of the primary
   */
  virtual Double_t Zenith() const {return DirectionalType::Zenith();}

  /**
   * gives the azimuth of the primary
   */
  virtual Double_t Azimuth() const {return DirectionalType::Azimuth();}

  /**
   * gives the X coordinate of the core
   */
  virtual Double_t CoreX() const {return CoreType::CoreX();}

  /**
   * gives the y position of the core
   */
  virtual Double_t CoreY() const {return CoreType::CoreY();}

  /**
   * gives the T position of the core
   */
  virtual Double_t CoreT() const {return CoreType::CoreT();}

  /**
   * gives the energy of the particle
   */
  virtual Double_t Energy() const {return EnergeticType::Energy();}

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
  ClassDef(I3PrimaryImpl,1);
};

#endif
