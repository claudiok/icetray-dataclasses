/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3MCPrimary.h
 * @version $Revision: 1.6 $
 * @date $Date$
 * @author ehrlich
 * @author pretz
 */
#ifndef I3MCPRIMARY_H
#define I3MCPRIMARY_H

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"

/**
 * @brief The basic class for a Monte Carlo primary, where all the data is 
 * known
 *
 * @todo copy and assignment private??
 */
class I3MCPrimary : public I3PrimaryImpl<I3Directional,
	                                 I3Localized,
	                                 I3Energetic> 
{
  ClassDef(I3MCPrimary,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCPrimary>  I3MCPrimaryPtr;

#endif
