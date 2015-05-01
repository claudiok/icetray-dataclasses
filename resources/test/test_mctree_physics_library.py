#!/usr/bin/env python

from I3Tray import I3Units
from icecube import dataclasses as dc

from icecube.icetray import I3Test


from icecube.dataclasses import get_most_energetic_primary
from icecube.dataclasses import get_most_energetic_cascade
from icecube.dataclasses import get_most_energetic_inice
from icecube.dataclasses import get_most_energetic
from icecube.dataclasses import get_most_energetic_track
from icecube.dataclasses import get_most_energetic_cascade
from icecube.dataclasses import get_most_energetic_neutrino
from icecube.dataclasses import get_most_energetic_muon
from icecube.dataclasses import get_most_energetic_nucleus
from icecube.dataclasses import is_cosmic_ray_event
from icecube.dataclasses import is_neutrino_event
from icecube.dataclasses import is_gamma_event

primary = dc.I3Particle()
primary.energy = 10 * I3Units.TeV
tree = dc.I3MCTree()
tree.add_primary(primary)


mep = get_most_energetic_primary(tree)
I3Test.ENSURE(mep.id == primary.id, "got the wrong particle.")

I3Test.ENSURE(not get_most_energetic_cascade(tree), "got a particle, but shouldn't.")
I3Test.ENSURE(not get_most_energetic_inice(tree), "got a particle, but shouldn't.")
I3Test.ENSURE(not get_most_energetic_track(tree), "got a particle, but shouldn't.")
I3Test.ENSURE(not get_most_energetic_neutrino(tree), "got a particle, but shouldn't.")
I3Test.ENSURE(not get_most_energetic_muon(tree), "got a particle, but shouldn't.")
I3Test.ENSURE(not get_most_energetic_nucleus(tree), "got a particle, but shouldn't.")


primary2 = dc.I3Particle()
primary2.energy = 9 * I3Units.TeV

cascade = dc.I3Particle()
cascade.type = dc.I3Particle.EMinus

inice = dc.I3Particle()
inice.location_type = dc.I3Particle.InIce

track = dc.I3Particle()
track.energy = 10 * I3Units.TeV
track.type = dc.I3Particle.TauMinus

muon = dc.I3Particle()
muon.energy = 9 * I3Units.TeV
muon.type = dc.I3Particle.MuMinus

neutrino = dc.I3Particle()
neutrino.type = dc.I3Particle.NuTau

nucleus = dc.I3Particle()
nucleus.energy = 8 * I3Units.TeV
nucleus.type = dc.I3Particle.He3Nucleus

tree = dc.I3MCTree()
tree.add_primary(nucleus)
tree.add_primary(primary)
tree.append_child(primary, cascade)
tree.append_child(primary, neutrino)
tree.append_child(primary, muon)
tree.add_primary(primary2)
tree.append_child(primary2, inice)
tree.append_child(primary2, track)

mep = get_most_energetic_primary(tree)
I3Test.ENSURE(mep.id == primary.id, "got the wrong particle.")

I3Test.ENSURE(cascade.id == get_most_energetic_cascade(tree).id, "didn't get the cascade")
I3Test.ENSURE(inice.id == get_most_energetic_inice(tree).id, "didn't get the inice")
I3Test.ENSURE(track.id == get_most_energetic_track(tree).id, "didn't get the track")
I3Test.ENSURE(neutrino.id == get_most_energetic_neutrino(tree).id, "didn't get the neutrino")
I3Test.ENSURE(muon.id == get_most_energetic_muon(tree).id, "didn't get the muon")
I3Test.ENSURE(nucleus.id == get_most_energetic_nucleus(tree).id, "didn't get the nucleus")

for ptype in (dc.I3Particle.PPlus,
              dc.I3Particle.Neutron,
              dc.I3Particle.He3Nucleus):
    tree = dc.I3MCTree()
    primary = dc.I3Particle()
    primary.energy = 100 * I3Units.TeV
    primary.type = ptype
    tree.add_primary(primary)
    tree.add_primary(nucleus)
    tree.append_child(primary, cascade)
    tree.append_child(primary, neutrino)
    tree.append_child(primary, muon)

    I3Test.ENSURE(is_cosmic_ray_event(tree), "event not classified as CR event")
    I3Test.ENSURE(not is_neutrino_event(tree), "event mis-classified as neutrino event")
    I3Test.ENSURE(not is_gamma_event(tree), "event mis-classified as gamma event")

for ptype in (dc.I3Particle.NuE,
              dc.I3Particle.NuMu,
              dc.I3Particle.NuTau):
    tree = dc.I3MCTree()
    primary = dc.I3Particle()
    primary.energy = 100 * I3Units.TeV
    primary.type = ptype
    tree.add_primary(primary)
    tree.add_primary(nucleus)
    tree.append_child(primary, cascade)
    tree.append_child(primary, neutrino)
    tree.append_child(primary, muon)

    I3Test.ENSURE(not is_cosmic_ray_event(tree), "event mis-classified as CR event")
    I3Test.ENSURE(is_neutrino_event(tree), "event not classified as neutrino event")
    I3Test.ENSURE(not is_gamma_event(tree), "event mis-classified as gamma event")

tree = dc.I3MCTree()
primary = dc.I3Particle()
primary.energy = 100 * I3Units.TeV
primary.type = dc.I3Particle.Gamma
tree.add_primary(primary)
tree.add_primary(nucleus)
tree.append_child(primary, cascade)
tree.append_child(primary, neutrino)
tree.append_child(primary, muon)

I3Test.ENSURE(not is_cosmic_ray_event(tree), "event mis-classified as CR event")
I3Test.ENSURE(not is_neutrino_event(tree), "event mis-classified as neutrino event")
I3Test.ENSURE(is_gamma_event(tree), "event not classified as gamma event")
