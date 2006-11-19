PROJECT(dataclasses)

LIB (dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx)

USE_TOOL(log4cplus)
USE_TOOL(boost)
USE_TOOL(root)

USE_PROJECTS(icetray)

ROOTCINT(dataclasses/I3Position.h 
  dataclasses/I3Direction.h 
  dataclasses/I3Double.h 
  dataclasses/I3Time.h 
  dataclasses/physics/I3Particle.h)


FILE(GLOB dataclasses_test_source "private/test/*.cxx")
ADD_TEST(dataclasses-test ${dataclasses_test_source})

