/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonComposite.h,v 1.5 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3NonComposite.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 */
#ifndef I3NONCOMPOSITE_H
#define I3NONCOMPOSITE_H

#include <vector>
#include "I3Particle.h"
#include "NanPolicy.h"

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
  Bool_t IsComposite() const {return false;}

  /**
   * Shouldn't be used. Calls Fatal.
   */ 
  int GetNumConstituents() const 
    {
      NanPolicy::Fatal();
      return 0;
    }

  /**
   * Shouldn't be used.  Calls Fatal().
   */
  const I3Particle& GetConstituent(int i) const 
    {
      NanPolicy::Fatal();
      return *(I3Particle*)0;
    }

  /**
   * Doesn't do anything since there's no data to copy.
   */
  void CopyTo(I3Particle& destination) const {}

 private:
  //ROOT macro
  ClassDef(I3NonComposite,1);
};

#endif

