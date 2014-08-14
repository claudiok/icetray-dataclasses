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

i3_add_pybindings(dataclasses
  private/pybindings/I3Calibration.cxx
  private/pybindings/I3Constants.cxx
  private/pybindings/I3DOMLaunch.cxx
  private/pybindings/I3DetectorStatus.cxx
  private/pybindings/I3DOMFunctions.cxx
  private/pybindings/I3Direction.cxx
  private/pybindings/I3Double.cxx
  private/pybindings/I3EventHeader.cxx
  private/pybindings/I3FlasherInfo.cxx
  private/pybindings/I3FilterResult.cxx
  private/pybindings/I3Geometry.cxx
  private/pybindings/I3OMGeo.cxx
  private/pybindings/I3TankGeo.cxx
  private/pybindings/I3MCHit.cxx
  private/pybindings/I3MCList.cxx
  private/pybindings/I3MCTree.cxx
  private/pybindings/I3LinearizedMCTree.cxx
  private/pybindings/I3ParticleID.cxx
  private/pybindings/I3Particle.cxx
  private/pybindings/I3Position.cxx
  private/pybindings/I3RecoHit.cxx
  private/pybindings/I3RecoPulse.cxx
  private/pybindings/I3String.cxx
  private/pybindings/I3MapOMKeyMask.cxx
  private/pybindings/I3MapOMKeyUnion.cxx
  private/pybindings/I3Matrix.cxx
  private/pybindings/I3Time.cxx
  private/pybindings/I3TimeWindow.cxx
  private/pybindings/I3Trigger.cxx
  private/pybindings/I3Waveform.cxx
  private/pybindings/I3Vectors/*.cxx
  private/pybindings/I3MapString.cxx
  private/pybindings/I3MapInt.cxx
  private/pybindings/I3MapKey.cxx
  private/pybindings/I3MapI3ParticleID.cxx
  private/pybindings/I3Orientation.cxx
  private/pybindings/I3SuperDST.cxx
  private/pybindings/ModuleKey.cxx
  private/pybindings/I3ModuleGeo.cxx
  private/pybindings/TankKey.cxx
  private/pybindings/mctree/I3MCTreeTools.cxx
  private/pybindings/module.cxx
  USE_TOOLS boost python
  USE_PROJECTS icetray dataclasses
  )
