/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * $Id: I3ShowerCore.h,v 1.1 2004/07/13 15:37:53 niessen Exp $
 *
 * @file I3ShowerCore.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/13 15:37:53 $
 * @author Peter Niessen
 */

#ifndef __I3SHOWERCORE_H_
#define __I3SHOWERCORE_H_

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3NonDirectional.h"
#include "I3CoreLocalized.h"
#include "I3NonEnergetic.h"

/**
 * @brief This is a Shower core which is to be reconstructed by icetop
 * stations.
 */
class I3ShowerCore
: public I3PrimaryImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>
{
  ClassDef (I3ShowerCore, 1);
};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef PtrPolicy<I3ShowerCore>::ThePolicy I3ShowerCorePtr;

#endif
