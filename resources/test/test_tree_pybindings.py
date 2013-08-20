#!/usr/bin/env python

from icecube import icetray, dataio, dataclasses
from os.path import expandvars

from I3Tray import I3Units
from icecube.icetray.I3Test import *

def test_tree(tree):

    # these are properties
    
    # these have to remain functions since they
    # have multiple solutions for a single tree and
    # require input

    p = dataclasses.I3Particle()
    tree.add_primary(p)
    d = dataclasses.I3Particle()
    tree.append_child(p,d)

    print(d.major_id)
    print(d.minor_id)
    hit = dataclasses.I3MCHit(d.major_id,d.minor_id)

    light_generator = tree[hit]
    ENSURE(light_generator.major_id == d.major_id, "this is not the particle you're looking for" )
    ENSURE(light_generator.minor_id == d.minor_id, "this is not the particle you're looking for" )

    primaries = tree.primaries
    for p in primaries:
        daughters = tree.get_daughters(p)
        ENSURE( tree.depth(p) == 0 , "depth of primary is wrong")
        for d in daughters:
            ENSURE( tree.depth(d) == 1 , "depth of children is wrong")
            ENSURE( tree.has_parent(d) , "this child needs a parent")


    if len(tree) > 0:
        print(tree)
        print([pi.energy for pi in tree])
        

# test an empty tree first
test_tree(dataclasses.I3MCTree())

#f = dataio.I3File(expandvars("$I3_PORTS/test-data/nugen_numu_ic80_dc6.002488.000000.processed.i3.gz") )
#while f.more():
#    fr = f.pop_physics()
#    mctree = fr.Get("I3MCTree")
#    test_tree(mctree)

#f = dataio.I3File(expandvars("$I3_PORTS/test-data/sim/corsika.F2K010001_IC59_slim.i3.gz") )
#ev_counter = 0
#while f.more():
#    ev_counter += 1
#    fr = f.pop_frame()
#    if fr.Stop != icetray.I3Frame.DAQ : continue
    
#    mctree = fr.Get("I3MCTree")
#    test_tree(mctree)

