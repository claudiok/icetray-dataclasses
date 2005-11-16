/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3TopShowerImpl.h
 * @version $Revision: 1.3 $
 * @date $Date$
 * @author blaufuss
 *
 */
#ifndef I3TOPSHOWERIMPL_H
#define I3TOPSHOWERIMPL_H

#include <TObject.h>
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
  virtual bool HasEnergy() const {return EnergeticType::HasEnergy();}

  /**
   * indicates whether or not the particle has a valid direction
   */
  virtual bool HasDirection() const {return DirectionalType::HasDirection();}

  /**
   * indicates whether or not the primary has a valid core position
   */
  virtual bool IsCoreLocalized() const {return CoreType::IsCoreLocalized();}

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

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3TopShower", base_object<I3TopShower>(*this));
    ar & make_nvp("DirectionalType", base_object<DirectionalType>(*this));
    ar & make_nvp("CoreType", base_object<CoreType>(*this));
    ar & make_nvp("EnergeticType", base_object<EnergeticType>(*this));
  }

  //ROOT macro
  //ClassDef(I3TopShowerImpl,1);
};

#endif
