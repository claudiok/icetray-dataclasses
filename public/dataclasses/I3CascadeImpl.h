#ifndef I3CASCADEIMPL_H
#define I3CASCADEIMPL_H

#include <TObject.h>
#include "dataclasses/I3Cascade.h"
#include <vector>
#include <cmath>

#include <iostream>

template <class DirectionalType,
	  class IdentifiableType,
          class LocalizableType,
          class EnergeticType>
class I3CascadeImpl : public I3Cascade,
                      public DirectionalType,
                      public IdentifiableType,
                      public LocalizableType,
                      public EnergeticType
{
 public:
  I3CascadeImpl() {};

  virtual ~I3CascadeImpl() {};

  virtual bool IsIdentifiable() const 
    {
      return IdentifiableType::IsIdentifiable();
    }

  virtual bool IsEnergetic() const {return EnergeticType::IsEnergetic();}

  virtual bool IsDirectional() const {return DirectionalType::IsDirectional();}

  virtual bool IsLocalized() const {return LocalizableType::IsLocalized();}

  virtual ParticleType Type() const {return IdentifiableType::Type();}

  virtual double Theta() const {return DirectionalType::Theta();}

  virtual double Phi() const {return DirectionalType::Phi();}

  virtual double X() const {return LocalizableType::X();}

  virtual double Y() const {return LocalizableType::Y();}

  virtual double Z() const {return LocalizableType::Z();}

  virtual double T() const {return LocalizableType::T();}

  virtual double Energy() const {return EnergeticType::Energy();}

  ClassDef(I3CascadeImpl,1);
};

#endif
