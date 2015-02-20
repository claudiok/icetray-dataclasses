#!/usr/bin/env python

# The I3FrameObject base was missing in the python bindings.
# Now the I3ParticleVect inherits from I3FrameObject in python.
# just as it does in C++, so you can create them and add them
# to frames...just like in C++.

from icecube import icetray
from icecube import dataclasses

particle_vect = dataclasses.I3VectorI3Particle()

particle_vect.append(dataclasses.I3Particle())

frame = icetray.I3Frame()
frame['pv'] = particle_vect


