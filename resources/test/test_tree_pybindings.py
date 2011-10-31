#!/usr/bin/env python

from icecube import dataio, dataclasses
from os.path import expandvars

from I3Tray import I3Units
from icecube.icetray.I3Test import *

def test_tree(tree):
    tree.dump()
    tree.dump("+locationType-majorID")
    print tree

    # these are properties
    print tree.most_energetic_primary
    print tree.most_energetic_primary
    print tree.most_energetic_cascade
    print tree.most_energetic_in_ice
    print tree.most_energetic_track
    print tree.most_energetic_stochastic
    print tree.number_of_atmospheric_muons
    print tree.in_ice
    print tree.primaries
    print tree.n_cascades
    print tree.neutrino_event_type 
    print tree.is_neutral_current 
    print tree.is_charged_current 
    print tree.is_glashow_resonance 
    print tree.check_neutrino
    print tree.most_energetic_muon
    print tree.most_energetic_nucleus
    print tree.most_energetic_neutrino
    
    # these have to remain functions since they
    # have multiple solutions for a single tree and
    # require input
    print tree.get_most_energetic(dataclasses.I3Particle.ParticleType.MuMinus)
    print tree.get_number_of_stochastics(10*I3Units.GeV)

    p = dataclasses.I3Particle()
    tree.add_primary(p)
    d = dataclasses.I3Particle()
    tree.append_child(p,d)

    print d.major_id
    print d.minor_id
    hit = dataclasses.I3MCHit(d.major_id,d.minor_id)

    light_generator = tree.get_particle_from_hit(hit)
    ENSURE(light_generator.major_id == d.major_id, "this is not the particle you're looking for" )
    ENSURE(light_generator.minor_id == d.minor_id, "this is not the particle you're looking for" )

    primaries = tree.primaries
    for p in primaries:
        daughters = tree.get_daughters(p)
        ENSURE( tree.depth(p) == 0 , "depth of primary is wrong")
        for d in daughters:
            ENSURE( tree.depth(d) == 1 , "depth of children is wrong")
            ENSURE( tree.has_parent(d) , "this child needs a parent")

# test an empty tree first
test_tree(dataclasses.I3MCTree())

f = dataio.I3File(expandvars("$I3_PORTS/test-data/nugen_numu_ic80_dc6.002488.000000.processed.i3.gz") )

fr = f.pop_physics()

mctree = fr.Get("I3MCTree")

test_tree(mctree)
