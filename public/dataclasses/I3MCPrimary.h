#ifndef I3MCPRIMARY_H
#define I3MCPRIMARY_H

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3Directional.h"
#include "I3CoreLocalized.h"
#include "I3Energetic.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPrimary.h,v 1.3 2004/04/23 20:30:06 ehrlich Exp $
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/23 20:30:06 $
 * @author pretz
 *
 * @todo copy and assignment private??
 *
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
