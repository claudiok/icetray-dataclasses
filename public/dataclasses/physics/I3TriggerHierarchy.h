/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerHierarchy.h 13215 2005-12-06 15:10:33Z blaufuss $
 *
 * @file I3TriggerHierarchy.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005-12-06 16:10:33 +0100 (Tue, 06 Dec 2005) $
 * @author tschmidt
 */
#ifndef I3_TRIGGER_HIERARCHY_H_INCLUDED
#define I3_TRIGGER_HIERARCHY_H_INCLUDED

#include "dataclasses/I3Tree.h"
#include "dataclasses/I3Trigger.h"

typedef I3Tree<I3Trigger> I3TriggerHierarchy;

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
I3_POINTER_TYPEDEFS(I3TriggerHierarchy);

#endif


