CXX_BIN_SRCDIR_NAMES := 
TEST_SRCDIR_NAMES := test 

USES_PROJECTS := icetray 
USES_TOOLS := root log4cplus boost boost

ROOT_DICTIONARY_HEADERS := \
dataclasses/I3Position.h \
dataclasses/I3Direction.h \
dataclasses/I3Double.h \
dataclasses/I3Time.h \
dataclasses/physics/I3Particle.h

GIMP = dataclasses/I3Time.h \
dataclasses/OMKey.h \
dataclasses/TriggerKey.h \
dataclasses/geometry/I3OMGeo.h \
dataclasses/status/I3TriggerStatus.h \
dataclasses/physics/I3AMANDAAnalogReadout.h \
dataclasses/physics/I3DOMLaunch.h \
dataclasses/physics/I3FlasherInfo.h \
dataclasses/physics/I3MCHit.h \
dataclasses/physics/I3MCPMTResponse.h \
dataclasses/physics/I3PMTPulse.h \
dataclasses/physics/I3RecoHit.h \
dataclasses/physics/I3RecoPulse.h \
dataclasses/physics/I3TWRFrag.h \
dataclasses/physics/I3TWRLaunch.h \
dataclasses/physics/I3TankHit.h \
dataclasses/physics/I3Trigger.h \
dataclasses/I3Constants.h \
dataclasses/I3Units.h
