/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * $Id: I3ShowerDirection.h,v 1.1.2.1 2004/07/19 22:24:20 ehrlich Exp $
 *
 * @file I3ShowerDirection.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2004/07/19 22:24:20 $
 * @author Peter Niessen
 */

#ifndef __I3SHOWERPLANE_H_
#define __I3SHOWERPLANE_H_

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3Directional.h"
#include "I3NonCoreLocalized.h"
#include "I3NonEnergetic.h"

/**
 * @brief This is a representation of the shower front by a
 * plane. Intention is to use it as a first guess.
 */
class I3ShowerDirection
: public I3PrimaryImpl<I3Directional, I3NonCoreLocalized, I3NonEnergetic>
{
  ClassDef (I3ShowerDirection, 1);
};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef PtrPolicy<I3ShowerDirection>::ThePolicy I3ShowerDirectionPtr;

#endif
