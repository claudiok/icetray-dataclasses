/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPrimary.h,v 1.4 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3MCPrimary.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 */
#ifndef I3MCPRIMARY_H
#define I3MCPRIMARY_H

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3Directional.h"
#include "I3CoreLocalized.h"
#include "I3Energetic.h"

/**
 * @brief The basic class for a Monte Carlo primary, where all the data is 
 * known
 *
 * @todo copy and assignment private??
 */
class I3MCPrimary : public I3PrimaryImpl<I3Directional,
	                                 I3CoreLocalized,
	                                 I3Energetic> 
{
  ClassDef(I3MCPrimary,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCPrimary>::ThePolicy I3MCPrimaryPtr;

#endif
