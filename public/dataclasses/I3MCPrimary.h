/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPrimary.h,v 1.4.6.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3MCPrimary.h
 * @version $Revision: 1.4.6.2 $
 * @date $Date: 2005/02/04 21:51:03 $
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

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCPrimary>::ThePolicy I3MCPrimaryPtr;

#endif
