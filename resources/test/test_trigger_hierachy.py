#!/usr/bin/env python

from icecube.dataclasses.trigger_hierarchy_recipes import *
from icecube import dataio, dataclasses
from os.path import expandvars

from I3Tray import I3Units
from icecube.icetray.I3Test import *

th = dataclasses.I3TriggerHierarchy()



sid = dataclasses.I3Trigger.IN_ICE
tid = dataclasses.I3Trigger.SIMPLE_MULTIPLICITY
cid = 1008
tkey = dataclasses.TriggerKey(sid, tid, cid)
print find_triggers(th,tkey)

print n_triggers(th, sourceID = sid)
print n_triggers(th, typeID = tid)
print n_triggers(th, configID = cid)

print trigger_lengths(th, sourceID = sid)
print trigger_lengths(th, typeID = tid)
print trigger_lengths(th, configID = cid)

