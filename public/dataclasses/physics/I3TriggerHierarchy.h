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
#include "dataclasses/physics/I3Trigger.h"

/**
 * Type definition for a n-ary tree of I3Trigger.
 * 
 * In contrast to AMANDA, there is no "flat" structure of coincident triggers
 * in IceCube anymore. DAQ provides a more complicated n-ary tree-like hierarchy
 * of triggers instead. So called "global triggers" hold "subdetector triggers"
 * (child nodes of the corresponding node within the tree).
 * "Global triggers" might be assigned as childs to an additional "global trigger"
 * of type "MERGED", if two or more of these overlap in time.
 * 
 * Triggering at "string processor" level will add one additional level of
 * siblings in future.
 * 
 * A n-ary tree of I3Trigger describes both scenarios very well.
 * One might only use top level siblings for triggers in AMANDA and a full
 * tree-like hierarchy for triggers in IceCube.
 */
typedef I3Tree<I3Trigger> I3TriggerHierarchy;

/**
 * pointer type to insulate users from memory management
 */
I3_POINTER_TYPEDEFS(I3TriggerHierarchy);

#endif


