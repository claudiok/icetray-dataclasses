/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCCorePrimary.h,v 1.2 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3MCCorePrimary.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005/04/09 03:02:10 $
 * @author ehrlich
 * @author pretz
 */
#ifndef I3MCCOREPRIMARY_H
#define I3MCCOREPRIMARY_H

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3Directional.h"
#include "I3CoreLocalized.h"
#include "I3Energetic.h"

/**
 * @brief The basic class for a Monte Carlo primary, where all the data is 
 * known
 */
class I3MCCorePrimary : public I3PrimaryImpl<I3Directional,
	                                 I3CoreLocalized,
	                                 I3Energetic> 
{
  ClassDef(I3MCCorePrimary,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCCorePrimary>  I3MCCorePrimaryPtr;

#endif
