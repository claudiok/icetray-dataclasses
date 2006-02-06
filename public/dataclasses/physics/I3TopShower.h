/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3TopShower.h
 * @date $Date$
  */

#ifndef I3TOPSHOWER_H_INCLUDED
#define I3TOPSHOWER_H_INCLUDED

#include "Rtypes.h"
#include "I3IceTopParticle.h"

/**
 * @brief Represents a particle which can appear in the IceTop array
 */
class I3TopShower : public I3IceTopParticle{
 public:
   
  virtual ~I3TopShower();

  /**
   * indicatess that the particle has a core position, and so
   * asking CoreX, and CoreY and CoreT is legit.
   */
  virtual bool IsCoreLocalized() const = 0;

  /**
   * Copies over data from the source particle to this particle.
   * Only copies that data which the two have in common.
   */
  virtual void CopyFrom(const I3Particle& source)
    {
      source.CopyTo(*this);
    } 
  
 private:

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TopShower",base_object<I3IceTopParticle>(*this));
  }

  // ROOT macro
  //ClassDef(I3TopShower,1);
};

I3_POINTER_TYPEDEFS(I3TopShower);

#endif //I3TOPSHOWER_H_INCLUDED
