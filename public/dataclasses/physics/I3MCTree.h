/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id$
    @file I3MCTree.h
    @date $Date$
*/

#ifndef I3MCTREE_H_INCLUDED
#define I3MCTREE_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/I3Tree.h"
#include "icetray/I3DefaultName.h"

/**
 *I3MCTree - This goes into the frame and everyone can see it
 */
typedef I3Tree<I3Particle> I3MCTree;

I3_POINTER_TYPEDEFS(I3MCTree);
I3_DEFAULT_NAME(I3MCTree);

#endif 


