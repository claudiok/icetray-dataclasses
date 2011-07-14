#!/usr/bin/env python

from icecube import dataio, dataclasses
from os.path import expandvars

from I3Tray import I3Units
from icecube.icetray.I3Test import *

def test_tree(tree):
    tree.Dump()
    tree.Dump("+locationType-majorID")
    print tree
    
    print tree.GetMostEnergeticPrimary()
    print tree.GetMostEnergeticPrimary()
    print tree.GetMostEnergeticCascade()
    print tree.GetMostEnergeticInIce()
    print tree.GetMostEnergetic(dataclasses.I3Particle.ParticleType.MuMinus)
    print tree.GetMostEnergeticTrack()
    print tree.GetMostEnergeticStochastic()
    print tree.GetNumberOfStochastics(10*I3Units.GeV)
    print tree.GetNumberOfAtmosphericMuons()
    print tree.GetInIce()
    print tree.GetPrimaries()
    print tree.NCascades()
    print tree.GetNeutrinoEventType() 
    print tree.IsNeutralCurrent() 
    print tree.IsChargedCurrent() 
    print tree.IsGlashowResonance() 
    print tree.CheckNeutrino() 

    p = dataclasses.I3Particle()
    tree.AddPrimary(p)
    d = dataclasses.I3Particle()
    tree.AppendChild(p,d)

    print d.MajorID
    print d.MinorID
    hit = dataclasses.I3MCHit(d.MajorID,d.MinorID)

    light_generator = tree.GetParticleFromHit(hit)
    ENSURE(light_generator.MajorID == d.MajorID, "this is not the particle you're looking for" )
    ENSURE(light_generator.MinorID == d.MinorID, "this is not the particle you're looking for" )

    primaries = tree.GetPrimaries()
    for p in primaries:
        daughters = tree.GetDaughters(p)
        ENSURE( tree.depth(p) == 0 , "depth of primary is wrong")
        for d in daughters:
            ENSURE( tree.depth(d) == 1 , "depth of children is wrong")
            ENSURE( tree.HasParent(d) , "this child needs a parent")

# test an empty tree first
test_tree(dataclasses.I3MCTree())

f = dataio.I3File(expandvars("$I3_PORTS/test-data/nugen_numu_ic80_dc6.002488.000000.processed.i3.gz") )

fr = f.pop_physics()

mctree = fr.Get("I3MCTree")

test_tree(mctree)
