from icecube import dataclasses
from icecube.dataclasses import I3TriggerHierarchy
from icecube.dataclasses import I3Trigger
from icecube.dataclasses import TriggerKey

def find_triggers(th, key):
    return_list = list()
    for t in th:
        if t.trigger_key == key:
            return_list.append(t)
    return return_list

def n_triggers( th, sourceID = None, typeID = None, configID = None):
    if not ( sourceID or typeID or configID) : return 0
    return_value = 0
    for t in th:
        if ( not sourceID or t.source_id == sourceID ) and \
        ( not typeID or t.type_id == typeID ) and \
        ( not configID or t.config_id == configID ) :
            return_value += 1
    return return_value      

def trigger_lengths( th, sourceID = None, typeID = None, configID = None):
    return_list = list()
    if not ( sourceID or typeID or configID) : return return_list
    for t in th:
        if ( not sourceID or t.source_id == sourceID ) and \
        ( not typeID or t.type_id == typeID ) and \
        ( not configID or t.config_id == configID ) :
            return_list.append( t.trigger_length )
    return return_list
