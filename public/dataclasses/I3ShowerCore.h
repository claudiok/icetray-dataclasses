/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * $Id: I3ShowerCore.h,v 1.3 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3ShowerCore.h
 * @version $Revision: 1.3 $
 * @date $Date: 2005/04/09 03:02:10 $
 * @author Peter Niessen
 */

#ifndef __I3SHOWERCORE_H_
#define __I3SHOWERCORE_H_

#include "dataclasses/StoragePolicy.h"
#include "I3TopShowerImpl.h"

#include "I3NonDirectional.h"
#include "I3CoreLocalized.h"
#include "I3NonEnergetic.h"

/**
 * @brief This is a Shower core which is to be reconstructed by icetop
 * stations.
 */
class I3ShowerCore
: public I3TopShowerImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>
{
  ClassDef (I3ShowerCore, 1);
};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef shared_ptr<I3ShowerCore>  I3ShowerCorePtr;

#endif
