#
# C   
#
i3_project(dataclasses
  PYTHON_DIR python
  DOCS_DIR resources/docs)

i3_add_library(dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx
  private/dataclasses/stream_overloads.cpp

  USE_TOOLS log4cplus boost python root

  USE_PROJECTS icetray

  ROOTCINT public/dataclasses/I3Position.h 
  public/dataclasses/I3Direction.h 
  public/dataclasses/I3Double.h 
  public/dataclasses/I3Time.h 
  public/dataclasses/physics/I3Particle.h
  )


if(USE_CINT)
  set(CINT_ENABLED_TEST "TEST")
  set(USE_TOOL_ROOT root)
endif(USE_CINT)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/private/test/I3DirectionTest.cxx.in
  ${CMAKE_CURRENT_BINARY_DIR}/private/test/I3DirectionTest.cxx
  @ONLY)

i3_test_executable(test 
  private/test/*.cxx
  ${CMAKE_CURRENT_BINARY_DIR}/private/test/I3DirectionTest.cxx
  USE_PROJECTS dataclasses
  USE_TOOLS ${USE_TOOL_ROOT}
  )

i3_test_scripts(resources/test/*.py)

add_subdirectory(private/pybindings)
