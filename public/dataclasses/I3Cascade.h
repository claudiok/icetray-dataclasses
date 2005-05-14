/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Cascade.h
 * @version $Revision: 1.16 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3CASCADE_H
#define I3CASCADE_H

#include "Rtypes.h"
#include "I3InIceParticle.h"

/**
 * @brief The cascade interface.  
 *
 * If 'IsLocalized' is true, then you should
 * be able to get X,Y,Z and T out.  If HasEnergy is true, then you should
 * expect to be able to get an Energy out. 
 *
 *
 */
class I3Cascade : public I3InIceParticle{
 public:
  /**
   * indicates that this is not a track
   */
  virtual bool IsTrack() {return false;}

  /**
   * indicates that this particle is a Cascade.
   */
  virtual bool IsCascade() {return true;}

  /**
   * indicates whether the particle is localized within the detector, and
   * whether X(), Y(), Z() and T() are legitimate to call
   */
  virtual bool IsLocalized() const =0;

  /**
   * indicates that the track is a composite track
   */
  virtual bool IsComposite() const =0;

  /**
   * the time of the cascade
   */
  virtual double GetT() const =0;

  /**
   * the position of the cascade as an I3Position object
   */
  virtual I3Position GetPos() const =0;

 /**
  * Copies the data from the source particle into this particle
  * Only copies the data which the two have in commmon
  */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Particle::CopyTo(destination);
    }

  virtual void ToStream(ostream& o) const
    {
      I3Particle::ToStream(o);
    }

 private:
  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3InIceParticle", base_object<I3InIceParticle>(*this));
  }
  //ROOT macro
  ClassDef(I3Cascade,1);
};

BOOST_IS_ABSTRACT(I3Cascade);

/** 
 * pointer type to insulate users from memory management issues
 */
typedef shared_ptr<I3Cascade>  I3CascadePtr;

#endif
