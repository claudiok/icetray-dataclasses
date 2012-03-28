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

tr = dataclasses.I3Trigger()
tr.key = tkey

th.insert( tr )

ENSURE( len(find_triggers(th,tkey)) == 1, "there should be 1 trigger found" )

ENSURE( n_triggers(th, sourceID = sid) == 1, "expected 1 source %s, found %d" \
            % (str(sid), n_triggers(th,sourceID = sid) ) )
ENSURE( n_triggers(th, typeID = tid) == 1, "expected 1 type %s found %d" \
            % (str(tid), n_triggers(th,typeID = tid) ) )
ENSURE( n_triggers(th, configID = cid) == 1, "expected 1 config %s found %d" \
            % (str(cid), n_triggers(th,configID = cid) ) )

ENSURE( len(trigger_lengths(th, sourceID = sid)) == 1, "expected 1 source %s, found %d" \
            % (str(sid), len(trigger_lengths(th,sourceID = sid) ) ) )
ENSURE( len(trigger_lengths(th, typeID = tid)) == 1, "expected 1 type %s found %d" \
            % (str(tid), len(trigger_lengths(th,typeID = tid) ) ) )
ENSURE( len(trigger_lengths(th, configID = cid)) == 1, "expected 1 config %s found %d" \
            % (str(cid), len(trigger_lengths(th,configID = cid) ) ) )



