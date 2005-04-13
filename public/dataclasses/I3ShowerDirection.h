/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * $Id: I3ShowerDirection.h,v 1.3.14.1 2005/04/13 20:21:15 niessen Exp $
 *
 * @file I3ShowerDirection.h
 * @version $Revision: 1.3.14.1 $
 * @date $Date: 2005/04/13 20:21:15 $
 * @author Peter Niessen
 */

#ifndef __I3SHOWERPLANE_H_
#define __I3SHOWERPLANE_H_

#include "dataclasses/StoragePolicy.h"
#include "I3TopShowerImpl.h"

#include "I3Directional.h"
#include "I3NonLocalized.h"
#include "I3NonEnergetic.h"

/**
 * @brief This is a representation of the shower front by a
 * plane. Intention is to use it as a first guess.
 */
class I3ShowerDirection
: public I3TopShowerImpl<I3Directional, I3NonLocalized, I3NonEnergetic>
{

  /**
   * the t0 of the track
   */
  Float_t T0;
  
  /**
   * The chi2
   */
  Float_t Chi2;


 public:

  /**
   * Set the t_0
   */
  void SetT0 (Float_t t0) {T0 = t0;}

  /**
   * Get the t_0
   */
  Float_t GetT0 () {return T0;}

  /**
   * Set the chi2
   */
  void SetChi2 (Float_t chi2) {Chi2 = chi2;}

  /**
   * Get the chi2
   */
  Float_t GetChi2 () {return Chi2;}

 private:

  ClassDef (I3ShowerDirection, 1);
};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef PtrPolicy<I3ShowerDirection>::ThePolicy I3ShowerDirectionPtr;

#endif
