#include <dataclasses/physics/I3ParticleID.h>
#include <dataclasses/I3Map.h>

typedef I3Map<I3ParticleID, double> I3MapI3ParticleIDDouble;
I3_SERIALIZABLE(I3MapI3ParticleIDDouble);
