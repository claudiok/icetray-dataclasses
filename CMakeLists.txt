#
#   
#
i3_project(dataclasses
  DOCS_DIR resources/docs)

if (USE_ROOT)
  set(ROOT_TOOL root)
endif (USE_ROOT)

i3_add_library(dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx

  USE_TOOLS log4cplus boost python ${ROOT_TOOL}

  USE_PROJECTS icetray

  ROOTCINT public/dataclasses/I3Position.h 
  public/dataclasses/I3Direction.h 
  public/dataclasses/I3Double.h 
  public/dataclasses/I3Time.h 
  public/dataclasses/I3Bool.h 
  public/dataclasses/physics/I3Particle.h
  public/dataclasses/physics/I3Trigger.h
  public/dataclasses/TriggerKey.h
  )

i3_test_executable(test 
  private/test/*.cxx
  USE_PROJECTS dataclasses
  )

i3_test_scripts(resources/scripts/*.py)

add_subdirectory(private/pybindings)
