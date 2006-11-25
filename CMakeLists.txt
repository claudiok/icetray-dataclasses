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


FILE(GLOB dataclasses_test_source "private/test/*.cxx")
ADD_TEST(dataclasses-test ${dataclasses_test_source})

