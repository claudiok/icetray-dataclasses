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
tk.ConfigID = 1002
ENSURE(tk.check_config_id() == True, "CheckConfigID fail")
ENSURE(tk.ConfigID == 1002, "Wrong ConfigID")

tk.Source = dataclasses.I3Trigger.IN_ICE
ENSURE(tk.Source == dataclasses.I3Trigger.IN_ICE, "Wrong Trigger Source")

tk.Type = dataclasses.I3Trigger.SIMPLE_MULTIPLICITY
ENSURE(tk.Type == dataclasses.I3Trigger.SIMPLE_MULTIPLICITY, "Wrong Trigger Type")

#pretty print works
print tk

tk.ResetConfigID() 
ENSURE(tk.CheckConfigID() == False, "CheckConfigID fail")

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
# TODO: This needs pretty print
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

transittime = dataclasses.TransitTime(ds, dc)

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

## TODO:  needs a pretty print.  Can we use items() for I3Maps?
print mapy

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

#I3Tree -> triggers for example....see Fix_Trigger_In_GCD.py test

#I3DetectorStatus
print 'Testing I3DectorStatus'
ds = dataclasses.I3DetectorStatus()
dmstat = ds.DOMStatus
adom = dataclasses.I3DOMStatus()
adom.PMTHV = 1500*icetray.I3Units.V
dmstat[icetray.OMKey(1,1)] = adom
mykey = icetray.OMKey(1,1)
ENSURE(dmstat.has_key(mykey),'Can not find my new dom status')

# I3Geometry example? (olivas have one?)

# I3Calibratopm example? (olivas have one?)

#I3DOMLaunch
print 'Testing I3DOMLaunch'
dl = dataclasses.I3DOMLaunch()
fadc = icetray.vector_int()
[fadc.append(i) for i in range(10)]
## TODO:  fixme
##dl.RawFADC = fadc

dl.LCBit = True
ENSURE(dl.LCBit == True, 'Got wrong LCBit')
dl.TriggerType = dataclasses.I3DOMLaunch.SPE_DISCRIMINATOR_TRIGGER
dl.TriggerMode = dataclasses.I3DOMLaunch.LC_UPPER
dl.WhichATWD = dataclasses.I3DOMLaunch.ATWDb


#TODO This needs some better pretty print
print dl


#I3EventHeader

#I3FlasherInfo

#I3MCHits

#I3MCTree

#I3Particle

#I3RecoPulse

#I3Trigger

#I3Waveform
