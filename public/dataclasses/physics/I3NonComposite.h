/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3NonComposite.h
 * @date $Date$
 */

#ifndef I3NONCOMPOSITE_H_INCLUDED
#define I3NONCOMPOSITE_H_INCLUDED

#include <vector>
#include "I3Particle.h"

/**
 * @brief This class satisfies the 'Composite' part of an I3Track 
 * implementation ; it has no constiuents.
 * @todo implement fatal call if out of bounds
 * @todo implement I3ParticlePtr stuff
 */
class I3NonComposite
{
 public:

  I3NonComposite(){}

  virtual ~I3NonComposite();

  /**
   * indicates that this track is not a composite track
   */
  bool IsComposite() const {return false;}

  /**
   * Doesn't do anything since there's no data to copy.
   */
  void CopyTo(I3Particle& destination) const {}

  virtual void ToStream(ostream& o) const
    {
      o<<"Constituent particles: NonComposite\n";
    }

 private:
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  //ClassDef(I3NonComposite,1);
};

#endif //I3NONCOMPOSITE_H_INCLUDED


