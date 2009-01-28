#!/usr/bin/python

from icecube import icetray, dataclasses, dataio
from os.path import expandvars

tools = expandvars("$I3_PORTS")
runfile = tools + "/test-data/amanda/amanda_malfunction_not_cascade.i3"

i3f = dataio.I3File(runfile)

phys = i3f.pop_physics()

print phys

dt = phys['DrivingTime']
print dt
assert type(dt) == dataclasses.I3Time

md = phys['F2kMuonDAQ']
print md
print len(md)
assert len(md) == 480

amps = [e.data().Amplitude for e in md]
print "\n\nAmplitudes:", len(amps), "\n", amps

adcs = [e.data().ADC for e in md]
print "\n\nADCs:", len(adcs), "\n", adcs





