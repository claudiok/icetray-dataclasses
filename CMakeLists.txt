#
# Co
#
i3_project(dataclasses
  PYTHON_DIR python
  DOCS_DIR resources/docs)

if(USE_ROOT)
  set(OPTIONAL_TOOLS root)
endif(USE_ROOT)

i3_add_library(dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx
  private/dataclasses/stream_overloads.cpp

  USE_TOOLS boost python ${OPTIONAL_TOOLS}

  USE_PROJECTS icetray

  ROOTCINT public/dataclasses/I3Position.h 
  public/dataclasses/I3Direction.h 
  public/dataclasses/I3Double.h 
  public/dataclasses/I3Time.h 
  public/dataclasses/physics/I3Particle.h
  public/dataclasses/physics/I3TopRecoPlaneFitParams.h
  public/dataclasses/physics/I3TopLateralFitParams.h
  )


if(USE_CINT)
  set(CINT_ENABLED_TEST "TEST")
  set(USE_TOOL_ROOT root)
endif(USE_CINT)

i3_test_executable(test 
  private/test/*.cxx
  USE_PROJECTS dataclasses dataio
  USE_TOOLS ${USE_TOOL_ROOT}
  )

i3_test_scripts(resources/test/*.py)

add_subdirectory(private/pybindings)
