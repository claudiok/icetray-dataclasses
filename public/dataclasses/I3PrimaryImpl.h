#ifndef I3PRIMARYIMPL_H
#define I3PRIMARYIMPL_H

#include <TObject.h>
#include "dataclasses/I3Primary.h"
#include <vector>
#include <cmath>

#include <iostream>

template <class DirectionalType,
          class CoreType,
          class EnergeticType>
class I3PrimaryImpl : public I3Primary,
                      public DirectionalType,
                      public CoreType,
                      public EnergeticType
{
 public:
  I3PrimaryImpl() {};

  virtual ~I3PrimaryImpl() {};

  virtual Bool_t IsEnergetic() const {return EnergeticType::IsEnergetic();}

  virtual Bool_t IsDirectional() const {return DirectionalType::IsDirectional();}

  virtual Bool_t HasCorePosition() const {return CoreType::HasCorePosition();}

  virtual Double_t Zenith() const {return DirectionalType::Zenith();}

  virtual Double_t Azimuth() const {return DirectionalType::Azimuth();}

  virtual Double_t CoreX() const {return CoreType::CoreX();}

  virtual Double_t CoreY() const {return CoreType::CoreY();}

  virtual Double_t CoreT() const {return CoreType::CoreT();}

  virtual Double_t Energy() const {return EnergeticType::Energy();}

  ClassDef(I3PrimaryImpl,1);
};

#endif
