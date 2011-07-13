from icecube.load_pybindings import load_pybindings
import icecube.icetray # be nice and pull in our dependencies

load_pybindings(__name__,__path__)


# Add some aliases for naming consistency
I3RecoPulseSeries = vector_I3RecoPulse
I3RecoHitSeries = vector_I3RecoHit
I3MCHitSeries = vector_I3MCHit

del icecube
