/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * $Id: I3ShowerDirection.h,v 1.2.4.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3ShowerDirection.h
 * @version $Revision: 1.2.4.2 $
 * @date $Date: 2005/02/04 21:49:05 $
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

};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef PtrPolicy<I3ShowerDirection>::ThePolicy I3ShowerDirectionPtr;

#endif
