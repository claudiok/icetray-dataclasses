#!/usr/bin/env python

from icecube import icetray, dataio, dataclasses
from os.path import expandvars

from I3Tray import I3Units
from icecube.icetray.I3Test import *

def is_nucleus(p):
    return p.type == dataclasses.I3Particle.PPlus or \
           p.type == dataclasses.I3Particle.PMinus or \
           p.type == dataclasses.I3Particle.He4Nucleus or \
           p.type == dataclasses.I3Particle.Li7Nucleus or \
           p.type == dataclasses.I3Particle.Be9Nucleus or \
           p.type == dataclasses.I3Particle.B11Nucleus or \
           p.type == dataclasses.I3Particle.C12Nucleus or \
           p.type == dataclasses.I3Particle.N14Nucleus or \
           p.type == dataclasses.I3Particle.O16Nucleus or \
           p.type == dataclasses.I3Particle.F19Nucleus or \
           p.type == dataclasses.I3Particle.Ne20Nucleus or \
           p.type == dataclasses.I3Particle.Na23Nucleus or \
           p.type == dataclasses.I3Particle.Mg24Nucleus or \
           p.type == dataclasses.I3Particle.Al27Nucleus or \
           p.type == dataclasses.I3Particle.Si28Nucleus or \
           p.type == dataclasses.I3Particle.P31Nucleus or \
           p.type == dataclasses.I3Particle.S32Nucleus or \
           p.type == dataclasses.I3Particle.Cl35Nucleus or \
           p.type == dataclasses.I3Particle.Ar40Nucleus or \
           p.type == dataclasses.I3Particle.K39Nucleus or \
           p.type == dataclasses.I3Particle.Ca40Nucleus or \
           p.type == dataclasses.I3Particle.Sc45Nucleus or \
           p.type == dataclasses.I3Particle.Ti48Nucleus or \
           p.type == dataclasses.I3Particle.V51Nucleus or \
           p.type == dataclasses.I3Particle.Cr52Nucleus or \
           p.type == dataclasses.I3Particle.Mn55Nucleus or \
           p.type == dataclasses.I3Particle.Fe56Nucleus 

def test_tree(tree):
    tree.dump("+locationType-majorID")

    # these are properties
    print("*** most energetic primary ***")
    print(tree.most_energetic_primary)
    print("***  most energetic cascade ***")
    print(tree.most_energetic_cascade)
    print("***  most energetic inice ***")
    print(tree.most_energetic_in_ice)
    print("***  most energetic track ***")
    print(tree.most_energetic_track)
    print("***  most energetic stochastic ***")
    print(tree.most_energetic_stochastic)
    print("***  most energetic muon ***")
    print(tree.most_energetic_muon)
    print("***  most energetic nucleus ***")
    print(tree.most_energetic_nucleus)
    print("***  most energetic neutrino ***")
    print(tree.most_energetic_neutrino)
    print("*** number of atmospheric muons = ", tree.number_of_atmospheric_muons)
    print("***  InIce particle list ***")
    print(tree.in_ice)
    print("***  primary list ***")
    print(tree.primaries)
    print("*** number of cascades = ", tree.n_cascades)
    print("***  neurtino event type = ", tree.neutrino_event_type) 
    print("*** is neutral current = ",tree.is_neutral_current) 
    print("*** is charged current = ",tree.is_charged_current) 
    print("*** is glashow resonance = ", tree.is_glashow_resonance) 
    print("*** check neutrino = ", tree.check_neutrino)
    
    # these have to remain functions since they
    # have multiple solutions for a single tree and
    # require input
    print(tree.get_most_energetic(dataclasses.I3Particle.ParticleType.MuMinus))
    print(tree.get_number_of_stochastics(10*I3Units.GeV))

    p = dataclasses.I3Particle()
    tree.add_primary(p)
    d = dataclasses.I3Particle()
    tree.append_child(p,d)

    print(d.major_id)
    print(d.minor_id)
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


    if len(tree) > 0 :
        print(tree)
        print([pi.energy for pi in tree])
        if tree.most_energetic_muon :
            muon_energies = [p.energy for p in tree \
                             if p.type == dataclasses.I3Particle.MuMinus or \
                             p.type == dataclasses.I3Particle.MuPlus]
            if len(muon_energies) > 0 :
                ENSURE( tree.most_energetic_muon.energy == max(muon_energies) , "most energetic muon")

        neutrino_energies = [p.energy for p in tree if p.is_neutrino]
        if len( neutrino_energies ) > 0 :
            if tree.most_energetic_neutrino :
                ENSURE( tree.most_energetic_neutrino.energy == max(neutrino_energies), "most energetic neutrino" )

        nucleon_energies = [p.energy for p in tree if is_nucleus(p)]
        if len(nucleon_energies) > 0 :
            if tree.most_energetic_nucleus :
                ENSURE( tree.most_energetic_nucleus.energy == max(nucleon_energies), "most energetic nucleus" )
                                                   
        

# test an empty tree first
test_tree(dataclasses.I3MCTree())

f = dataio.I3File(expandvars("$I3_TESTDATA/nugen_numu_ic80_dc6.002488.000000.processed.i3.gz") )

while f.more():
    fr = f.pop_physics()
    
    mctree = fr.Get("I3MCTree")

    test_tree(mctree)

f = dataio.I3File(expandvars("$I3_TESTDATA/sim/corsika.F2K010001_IC59_slim.i3.gz") )

ev_counter = 0
while f.more()  :
    ev_counter += 1
    fr = f.pop_frame()
    if fr.Stop != icetray.I3Frame.DAQ : continue
    
    mctree = fr.Get("I3MCTree")

    test_tree(mctree)
