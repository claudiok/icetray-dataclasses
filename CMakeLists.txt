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

  USE_TOOLS log4cplus boost python root

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

if(NOT USE_ROOT)
  i3_test_executable(test 
    private/test/*.cxx
    USE_PROJECTS dataclasses
    )
else(NOT USE_ROOT)
  configure_file(${CMAKE_SRC_DIR}/${PROJECT_NAME}/private/test/I3DirectionTest.cxx.in
    ${CMAKE_SRC_DIR}/${PROJECT_NAME}/private/test/I3DirectionTest.cxx
    @ONLY)
  i3_test_executable(test 
    AsXMLTest.cxx
    DOMFunctions.cxx
    DeltaCompressTest.cxx
    I3CalibrationTest.cxx
    I3DOMLaunchTest.cxx
    I3DOMStatusTest.cxx
    I3FlasherInfoTest.cxx
    I3MCHitTest.cxx
    I3MCTreeTest.cxx
    I3MapMaskTest.cxx
    I3MapTest.cxx
    I3MapTests.cxx
    I3ParticleTest.cxx
    I3TimeTest.cxx
    I3TreeTest.cxx
    I3TreeUtilsTest.cxx
    I3TriggerHierarchyTest.cxx
    I3TriggerStatusTest.cxx
    I3TriggerTest.cxx
    I3VectorTest.cxx
    I3WaveformTest.cxx
    OMKeyTest.cxx
    OldScriptsTest.cxx
    main.cxx
    USE_PROJECTS dataclasses
    )
endif(NOT USE_ROOT)

i3_test_scripts(resources/test/*.py)

add_subdirectory(private/pybindings)
