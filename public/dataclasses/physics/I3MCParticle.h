/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3Particle.h 18608 2006-04-20 13:20:57Z dule $
    @file I3Particle.h
    @date $Date: 2006-04-20 09:20:57 -0400 (Thu, 20 Apr 2006) $
*/

#ifndef I3MCPARTICLE_H_INCLUDED
#define I3MCPARTICLE_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"

/**
 * @brief Simulation particle class
 */
template<class MCInfo>
struct I3MCParticle
{    
  I3Particle particle;
  MCInfo     mc;
};

#endif 


