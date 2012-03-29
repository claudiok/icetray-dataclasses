from icecube import dataclasses
from icecube.dataclasses import I3TriggerHierarchy
from icecube.dataclasses import I3Trigger
from icecube.dataclasses import TriggerKey

def find_triggers(th, key):
    return_list = list()
    for t in th:
        if t.key == key:
            return_list.append(t)
    return return_list

def n_triggers(th, sourceID = None, typeID = None, configID = None):
    if sourceID == None and \
            typeID == None and \
            configID == None : return 0
    return_value = 0
    for t in th:
        if ( sourceID == None or t.key.source == sourceID ) and \
        ( typeID == None or t.key.type == typeID ) and \
        ( configID == None or t.key.config_id == configID ) :
            return_value += 1
    return return_value      

def trigger_lengths(th, sourceID = None, typeID = None, configID = None):
    return_list = list() 
    if sourceID == None and \
            typeID == None and \
            configID == None : return return_list
    for t in th:
        if ( sourceID == None or t.key.source == sourceID ) and \
        ( typeID == None or t.key.type == typeID ) and \
        ( configID == None or t.key.config_id == configID ) :
            return_list.append( t.length )
    return return_list
