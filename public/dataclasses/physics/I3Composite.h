/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3Particle.h 20090 2006-05-25 15:06:56Z olivas $
    @file I3Particle.h
    @date $Date: 2006-05-25 10:06:56 -0500 (Thu, 25 May 2006) $
*/

#ifndef I3COMPOSITE_H_INCLUDED
#define I3COMPOSITE_H_INCLUDED

#include <vector>
#include "dataclasses/physics/I3Particle.h"

/**
 * @brief I3Composite is a very simple representation
 * of a collection of particles
 */
struct I3Composite
{
  /**
   *This is the top level particle which has the
   *properties of the whole group.
   */
  I3Particle particle;  
  /**
   *This is the set of particles that make up the
   *the "meta-particle"
   */
  vector<I3Particle> composite;
};

I3_POINTER_TYPEDEFS(I3Particle);

#endif 


