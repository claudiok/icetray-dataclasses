/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonCoreLocalized.h,v 1.2 2004/07/13 18:48:04 niessen Exp $
 *
 * @file I3NonCoreLocalized.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/13 18:48:04 $
 * @author Peter Niessen
 */
#ifndef I3NONCORELOCALIZED_H
#define I3NONCORELOCALIZED_H

#include "NanPolicy.h"

/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is unknown.
 */
class I3NonCoreLocalized 
{
 public:
  /**
   * indicates that the core position is known
   */
  Bool_t HasCorePosition() const { return kFALSE;}

  /**
   * gives the x position of the core
   */
  Double_t GetCoreX() const {
    NanPolicy::Fatal ();
    return NAN;
  }

  /**
   * gives the y position of the core
   */
  Double_t GetCoreY() const {
    NanPolicy::Fatal ();
    return NAN;
  }

  /**
   * gives the time of the core arrival
   */
  Double_t GetCoreT() const {
    NanPolicy::Fatal ();
    return NAN;
  }

  /**
   * nothing to copy. does nothing.
   */
  void CopyTo(I3Particle& destination) const {}

 private:
  //ROOT macro
  ClassDef(I3NonCoreLocalized,1);
};

#endif
