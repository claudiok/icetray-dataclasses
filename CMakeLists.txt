PROJECT(dataclasses)

LIB (private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx)

USE_TOOLS(log4cplus boost root)

USE_PROJECTS(icetray)

ROOTCINT(public/dataclasses/I3Position.h 
  public/dataclasses/I3Direction.h 
  public/dataclasses/I3Double.h 
  public/dataclasses/I3Time.h 
  public/dataclasses/I3Bool.h 
  public/dataclasses/physics/I3Particle.h)

TEST_EXECUTABLE(test private/test/*.cxx)

