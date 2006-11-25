PROJECT(dataclasses)

LIB (private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx)

USE_TOOLS(log4cplus boost root)

USE_PROJECTS(icetray)

ROOTCINT(dataclasses/I3Position.h 
  dataclasses/I3Direction.h 
  dataclasses/I3Double.h 
  dataclasses/I3Time.h 
  dataclasses/physics/I3Particle.h)

TEST_EXECUTABLE(test private/test/*.cxx)

