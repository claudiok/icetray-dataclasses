from icecube.load_pybindings import load_pybindings
load_pybindings(__name__,__path__)

# Add some aliases for naming consistency
I3RecoPulseSeries = vector_I3RecoPulse
I3RecoHitSeries = vector_I3RecoHit
I3TWRLaunchSeries = Vector_I3TWRLaunch
I3MCHitSeries = vector_I3MCHit
