/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3Particle.h
 * @date $Date$
 */

#ifndef I3PARTICLE_H_INCLUDED
#define I3PARTICLE_H_INCLUDED

#include "TObject.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/StoragePolicy.h"
#include "TClass.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class I3Particle
{
 public:
  /**
   * enumerated type of the different paricles.
   * follows the f2k convention for numbering
   */
 enum ParticleType {
    Unknown = -100,
    Null = 0,
    Gamma = 1,
    EPlus = 2,
    EMinus = 3,
    Nu = 4,
    MuPlus = 5,
    MuMinus = 6,
    Pi0 = 7,
    PiPlus = 8,
    PiMinus = 9,
    PPlus = 14,
    PMinus = 15,
    TauPlus = 33,
    TauMinus = 34,
    Monopole = 41,
    NuE = 201,
    NuMu = 202,
    NuTau = 203,
    NuEBar = 204,
    NuMuBar = 205,
    NuTauBar = 206,
    Brems = 1001,
    DeltaE = 1002,
    PairProd = 1003,
    NuclInt = 1004,
    MuPair = 1005,
    Hadrons = 1006,
    FiberLaser = 2100,
    N2Laser = 2101,
    YAGLaser = 2201,
    ZPrimary = 3000,
    APrimary = 3500,
    Elph = 9999
  };

 static string Stringize(I3Particle::ParticleType);

};

#endif //I3PARTICLE_H_INCLUDED
