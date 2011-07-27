#!/usr/bin/env python

from icecube import icetray, dataclasses
from icecube.icetray.I3Test import *

#
#  This file is not a hard test per-say, but just exercises some of the 
#        python bindings for dataclasses.  Might be useful for example usage.
#  Is there an interface you see missing?  Add it, and if it doesn't work
#   properly, report it via Trac:  http://code.icecube.wisc.edu/projects/icecube
#
#    No attempt to use all interfaces for each class has been made


print 'Testing TriggerKey pybindings'
tk = dataclasses.TriggerKey()
tk.config_id = 1002
ENSURE(tk.check_config_id() == True, "CheckConfigID fail")
ENSURE(tk.config_id == 1002, "Wrong ConfigID")

tk.Source = dataclasses.I3Trigger.IN_ICE
ENSURE(tk.Source == dataclasses.I3Trigger.IN_ICE, "Wrong Trigger Source")

tk.Type = dataclasses.I3Trigger.SIMPLE_MULTIPLICITY
ENSURE(tk.Type == dataclasses.I3Trigger.SIMPLE_MULTIPLICITY, "Wrong Trigger Type")
print tk
tk.reset_config_id() 
ENSURE(tk.check_config_id() == False, "CheckConfigID fail")


mytrig = dataclasses.I3Trigger()
mytrig.fired = True
mytrig.time = 5.0 * icetray.I3Units.microsecond
mytrig.length = 1.0 * icetray.I3Units.microsecond
mytrig.key.config_id = 1002
mytrig.key.Source = dataclasses.I3Trigger.IN_ICE

print mytrig

my_th = dataclasses.I3TriggerHierarchy()
## TriggerHierarchy is RO right now from the python side.

print 'Testing I3Constants'
print 'NA',dataclasses.I3Constants.NA
print 'Coordinate_shift_x',dataclasses.I3Constants.Coordinate_shift_x
print 'Coordinate_shift_y',dataclasses.I3Constants.Coordinate_shift_y
print 'Coordinate_shift_z',dataclasses.I3Constants.Coordinate_shift_z
print 'OriginElev',dataclasses.I3Constants.OriginElev
print 'SurfaceElev',dataclasses.I3Constants.SurfaceElev
print 'c',dataclasses.I3Constants.c

print 'Testing I3Direction'
dir = dataclasses.I3Direction(1.0, 1.0, 1.0)
print "Directions!", dir.theta, dir.phi, dir.azimuth, dir.zenith

dir2 = dataclasses.I3Direction(1.0, 0.0, 0.0)
print dir2

dir2.rotate_z(90*icetray.I3Units.deg)
print dir2

dir3 = dataclasses.I3Direction()
dir3.set_direction(dir2)
print dir3

# Testing DOMFunctions
print 'Testing I3DOMFunctions'
ds = dataclasses.I3DOMStatus()
dc = dataclasses.I3DOMCalibration()

transittime = dataclasses.transit_time(ds, dc)

#I3Double
print 'Testing I3Double'
doub = dataclasses.I3Double(99.9)
doub2 = dataclasses.I3Double(99.9)

doub3 = dataclasses.I3Double(doub.value + doub2.value)
print doub3

#I3Maps
print 'Testing I3Maps, in this case, I3MapStringInt'
mapy = dataclasses.I3MapStringInt()
mapy["foo"] = 1
mapy["bar"] = 2

ENSURE(mapy.has_key("foo") == True, "Failed to search the I3Map")
ENSURE(mapy.get("bar") == 2, "Failed to get from I3Map")

print mapy

#I3Vector
print 'Testing I3Vector'
vecy = dataclasses.I3VectorInt([1,2,3,4,5,6,7,8,9,10])
vecy.append(11)

print vecy

#I3Postion
print 'Testing I3Position'
pos = dataclasses.I3Position(1.1, 2.2, 3.3)
print pos
pos2 = dataclasses.I3Position(0, 0, 0)
distance = pos.calc_distance(pos2)
ENSURE(pos.r == distance, "Distances don't match")

#I3Time
print 'Testing I3Time'
time = dataclasses.I3Time()
time.set_daq_time(2010,111111111123456789)
print time
print time.mod_julian_day_double
print time.mod_julian_day, time.mod_julian_sec, time.mod_julian_nano_sec

time2 = dataclasses.I3Time(2009,111111111123456789)

ENSURE(time>time2,'Time order not correct')


#I3DetectorStatus
print 'Testing I3DectorStatus'
ds = dataclasses.I3DetectorStatus()
dmstat = ds.dom_status
adom = dataclasses.I3DOMStatus()
adom.pmt_hv = 1500*icetray.I3Units.V
dmstat[icetray.OMKey(1,1)] = adom
mykey = icetray.OMKey(1,1)
ENSURE(dmstat.has_key(mykey),'Can not find my new dom status')

#Also...see Fix_Trigger_In_GCD.py test


# I3Geometry example? (olivas have one?)
print "Testing I3Geometry"
omg = dataclasses.I3OMGeo()
omg.position.x=100.0
omg.position.y=101.0
omg.position.z=102.0
i3g = dataclasses.I3Geometry()
i3g.omgeo[icetray.OMKey(1,1)] = omg
ENSURE(i3g.omgeo.has_key(icetray.OMKey(1,1)), 'can not find my omkey in i3geo')
ENSURE( (not i3g.omgeo.has_key(icetray.OMKey(1,2))), 'found a bad omkey in i3geo')
newom = i3g.omgeo[icetray.OMKey(1,1)]
ENSURE(newom.position.x > 99.0, 'Failed to get the right OMGeo position back')

# I3Calibratoim example? (olivas have one?)
## See the Fix_Cals_in_GCD.py script for full example

#I3DOMLaunch
print 'Testing I3DOMLaunch'
dl = dataclasses.I3DOMLaunch()
fadc = icetray.vector_int()
[fadc.append(i) for i in range(10)]
dl.RawFADC = fadc
atwd0 = icetray.vector_int()
[atwd0.append(i) for i in range(100)]
dl.raw_atwd[0] = atwd0
dl.lc_bit = True
ENSURE(dl.lc_bit == True, 'Got wrong LCBit')
dl.TriggerType = dataclasses.I3DOMLaunch.SPE_DISCRIMINATOR_TRIGGER
dl.TriggerMode = dataclasses.I3DOMLaunch.LC_UPPER
dl.WhichATWD = dataclasses.I3DOMLaunch.ATWDb

print dl


#I3EventHeader
header_t = dataclasses.I3Time(2008, 87695866111263130)
header = dataclasses.I3EventHeader()
header.run_id = 110811
header.event_id = 0
header.start_time = header_t
header.end_time = header_t+10*icetray.I3Units.microsecond
header.sub_event_stream = 'MyFirstSplit'
print header

#I3Particle
print 'Testing I3Particle'
mypart = dataclasses.I3Particle()
mypart.dir = dataclasses.I3Direction(90.0*icetray.I3Units.deg,180*icetray.I3Units.deg)
mypart.pos = dataclasses.I3Position(10.0*icetray.I3Units.m, 10.0*icetray.I3Units.m, 10.0*icetray.I3Units.m)
mypart.time = 0.0 * icetray.I3Units.ns
mypart.energy = 1000.0 * icetray.I3Units.GeV
mypart.shape = dataclasses.I3Particle.InfiniteTrack
mypart.fit_status = dataclasses.I3Particle.OK


print mypart

mypartvec = dataclasses.I3ParticleVect()
mypartvec.append(mypart)

for party in mypartvec:
    print party


#I3RecoPulse
print 'Testing I3RecoPulse'
rp = dataclasses.I3RecoPulse()
rp.charge = 1.5   ## PEs
rp.time = 100.0 * icetray.I3Units.ns
rp.flags = dataclasses.I3RecoPulse.PulseFlags.ATWD

print rp

rps = dataclasses.I3RecoPulseSeries()
rps.append(rp)

for pulse in rps:
    print pulse

rpsm = dataclasses.I3RecoPulseSeriesMap()
rpsm[icetray.OMKey(1,1)] = rps

for key,pseries in rpsm:
    print key
    for pulse in pseries:
        print pulse


#I3Waveform
print 'Testing I3Waveform'
my_wf = dataclasses.I3Waveform()
my_wf.time = 100.0 * icetray.I3Units.ns
my_wf.bin_width = 3.3 * icetray.I3Units.ns
awave = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0]
my_wf.waveform = awave
my_wf.digitizer = dataclasses.I3Waveform.Source.FADC
my_wf.hlc = True

wv_series = dataclasses.I3WaveformSeries()
wv_series.append(my_wf)
for wv in wv_series:
    print wv.time

wv_ser_map = dataclasses.I3WaveformSeriesMap()
wv_ser_map[icetray.OMKey(2,2)] = wv_series

ENSURE(wv_ser_map.has_key(icetray.OMKey(2,2)), 'I3Waveform not present in map!')
ENSURE(not wv_ser_map.has_key(icetray.OMKey(2,3)), 'mystery I3waveform in map!')

print my_wf
