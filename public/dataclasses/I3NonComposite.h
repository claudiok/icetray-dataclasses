/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonComposite.h,v 1.7 2004/07/06 16:41:45 pretz Exp $
 *
 * @file I3NonComposite.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/07/06 16:41:45 $
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
  Bool_t IsComposite() const {return kFALSE;}

  /**
   * Shouldn't be used.  Calls Fatal();
   */
  const vector<I3ParticlePtr>& GetConstituents() const
    {
      NanPolicy::Fatal();
      return *(vector<I3ParticlePtr>*)0;
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

