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

  virtual Bool_t IsIdentifiable() const 
    {
      return IdentifiableType::IsIdentifiable();
    }

  virtual Bool_t IsEnergetic() const {return EnergeticType::IsEnergetic();}

  virtual Bool_t IsDirectional() const {return DirectionalType::IsDirectional();}

  virtual Bool_t IsLocalized() const {return LocalizableType::IsLocalized();}

  virtual ParticleType Type() const {return IdentifiableType::Type();}

  virtual Double_t Theta() const {return DirectionalType::Theta();}

  virtual Double_t Phi() const {return DirectionalType::Phi();}

  virtual Double_t X() const {return LocalizableType::X();}

  virtual Double_t Y() const {return LocalizableType::Y();}

  virtual Double_t Z() const {return LocalizableType::Z();}

  virtual Double_t T() const {return LocalizableType::T();}

  virtual I3Position Pos() const {return I3Position(X(),Y(),Z(),T());}

  virtual Double_t Energy() const {return EnergeticType::Energy();}

  ClassDef(I3CascadeImpl,1);
};

#endif
