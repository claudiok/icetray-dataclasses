/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Primary.h
 * @version $Revision: 1.11 $
 * @date $Date$
 * @author pretz
  */

#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * @brief Represents a particle which induces an event in the detector.
 */
class I3Primary : public I3Particle{
 public:
  virtual ~I3Primary();
  /**
   * indicates that the particle is not an observable particle
   */
  virtual bool IsObservable() const {return false;}
   
  /**
   * indicates whether the particle has a core position, and so
   * asking CoreX, and CoreY and CoreT is legit.
   */
  virtual bool IsCoreLocalized() const = 0;

  /**
   * indicates whether the particle has a inice position, and so
   * asking X, Y, Z and T is legit.
   */
  virtual bool IsLocalized() const = 0;

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
    ar & make_nvp("I3Primary", base_object<I3Particle>(*this));
  }

  // ROOT macro
  //ClassDef(I3Primary,1);
};


#endif
