/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonComposite.h,v 1.10 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3NonComposite.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3NONCOMPOSITE_H
#define I3NONCOMPOSITE_H

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
  /**
   * constructor
   */
  I3NonComposite(){}

  /**
   * destructor
   */
  virtual ~I3NonComposite(){}

  /**
   * indicates that this track is not a composite track
   */
  bool IsComposite() const {return kFALSE;}

  /**
   * Doesn't do anything since there's no data to copy.
   */
  void CopyTo(I3Particle& destination) const {}

  virtual void ToStream(ostream& o) const
    {
      o<<"Constituent particles: NonComposite\n";
    }

 private:
  //ROOT macro
  ClassDef(I3NonComposite,1);
};

#endif

