#ifndef I3CASCADEIMPL_H
#define I3CASCADEIMPL_H

#include <TObject.h>
#include "dataclasses/I3Cascade.h"
#include <vector>
#include <cmath>

#include <iostream>

template <class DirectionalType,
          class LocalizableType,
          class EnergeticType>
class I3CascadeImpl : public I3Cascade,
                      public DirectionalType,
                      public LocalizableType,
                      public EnergeticType
{
 public:
  I3CascadeImpl() {};

  virtual ~I3CascadeImpl() {};

  virtual Bool_t IsEnergetic() const {return EnergeticType::IsEnergetic();}

  virtual Bool_t IsDirectional() const {return DirectionalType::IsDirectional();}

  virtual Bool_t IsLocalized() const {return LocalizableType::IsLocalized();}

  virtual Double_t Zenith() const {return DirectionalType::Zenith();}

  virtual Double_t Azimuth() const {return DirectionalType::Azimuth();}

  virtual Double_t X() const {return LocalizableType::X();}

  virtual Double_t Y() const {return LocalizableType::Y();}

  virtual Double_t Z() const {return LocalizableType::Z();}

  virtual Double_t T() const {return LocalizableType::T();}

  virtual I3Position Pos() const {return I3Position(X(),Y(),Z());}

  virtual Double_t Energy() const {return EnergeticType::Energy();}

  ClassDef(I3CascadeImpl,1);
};

#endif
