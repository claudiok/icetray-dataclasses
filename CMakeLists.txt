
i3_project(dataclasses
  PYTHON_DIR python
  DOCS_DIR resources/docs)

if(ROOT_FOUND)
  set(OPTIONAL_TOOLS root)
endif(ROOT_FOUND)

i3_add_library(dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx
  private/dataclasses/*/*/*.cxx
  private/dataclasses/stream_overloads.cpp

  USE_TOOLS boost python ${OPTIONAL_TOOLS}

  USE_PROJECTS icetray
  )


i3_test_executable(test 
  private/test/*.cxx
  USE_PROJECTS dataclasses dataio
  USE_PYBINDINGS dataio
  USE_TOOLS ${USE_TOOL_ROOT}
  )

i3_add_pybindings(dataclasses
  private/pybindings/I3Calibration/*.cxx
  private/pybindings/I3Constants.cxx
  private/pybindings/I3DOMLaunch/*.cxx
  private/pybindings/I3DetectorStatus/*.cxx
  private/pybindings/I3DOMFunctions.cxx
  private/pybindings/I3Direction.cxx
  private/pybindings/I3Double.cxx
  private/pybindings/I3EventHeader.cxx
  private/pybindings/I3FlasherInfo.cxx
  private/pybindings/I3FilterResult.cxx
  private/pybindings/I3Geometry.cxx
  private/pybindings/I3OMGeo.cxx
  private/pybindings/I3TankGeo.cxx
  private/pybindings/I3MCHit/*.cxx
  private/pybindings/I3MCList.cxx
  private/pybindings/I3MCTree.cxx
  private/pybindings/I3LinearizedMCTree.cxx
  private/pybindings/I3ParticleID.cxx
  private/pybindings/I3Particle.cxx
  private/pybindings/I3Position.cxx
  private/pybindings/I3RecoHit.cxx
  private/pybindings/I3RecoPulse.cxx
  private/pybindings/I3String.cxx
  private/pybindings/I3Matrix.cxx
  private/pybindings/I3Time.cxx
  private/pybindings/I3TimeWindow.cxx
  private/pybindings/I3Trigger.cxx
  private/pybindings/I3Waveform/*.cxx
  private/pybindings/I3Vectors/*.cxx
  private/pybindings/I3Maps/*.cxx
  private/pybindings/I3Orientation.cxx
  private/pybindings/I3SuperDST.cxx
  private/pybindings/I3ModuleGeo.cxx
  private/pybindings/I3MCTreePhysicsLibrary.cxx
  private/pybindings/ModuleKey.cxx
  private/pybindings/module.cxx
  private/pybindings/TankKey.cxx
  private/pybindings/TriggerKey.cxx
  private/pybindings/test_utils/I3VectorUtils.cxx
  USE_TOOLS boost python
  USE_PROJECTS icetray dataclasses
  )

set(TEST_SCRIPTS
  resources/test/filtermasks_pybindings.py
  resources/test/i3eventheader_version_test.py
  resources/test/loads.py
  resources/test/test_launch_serialization.py
  resources/test/Fix_Cals_In_GCD.py
  resources/test/i3frame_subterfuge.py
  resources/test/readwrite_i3vectors.py
  resources/test/test_linear_tree.py
  resources/test/Fix_Trigger_In_GCD.py
  resources/test/i3geometry_version_test.py
  resources/test/std_map_indexing_suite_dict_interface_test.py
  resources/test/test_particle_masses.py
  resources/test/i3calibration_version_test.py
  resources/test/i3matrix_test.py
  resources/test/std_map_indexing_suite_test.py
  resources/test/i3detectorstatus_version_test.py
  resources/test/i3string_compare.py
  resources/test/test_disabling_of_python_dynamism.py
  resources/test/workout_pybindings.py
  resources/test/i3double_compare.py
  resources/test/leap_second_test.py
  resources/test/test_I3RecoPulseSeriesMapMask_pybindings.py
  resources/test/test_i3particlevect.py
  resources/test/test_mctree_physics_library.py
  resources/test/test_I3Vectors.py
  resources/test/test_I3Calibration.py
  resources/test/test_I3DOMStatus.py
  resources/test/test_I3DetectorStatus.py
  resources/test/test_I3Geometry.py
  resources/test/test_I3ModuleGeo.py
  resources/test/test_I3OMGeo.py
  resources/test/test_I3TankGeo.py
  resources/test/test_I3VEMCalibration.py
  resources/test/test_I3WaveformIsEqualOperator.py
  resources/test/test_I3Trigger.py
  resources/test/test_TriggerKey.py
)

# For whatever reason this test doesn't play well with old versions
# of ROOT on Ubuntu 10.04 even though it doesn't use ROOT at all.  
# It seg faults when using i3-tools-v4, which uses ROOT 5.34.18.  
# Works just fine with i3-tools-v5.
# 
# I'm not *necessarily* saying this is ROOT's fault...I'm just sayin'.  
# Using the same toolset but building w/o ROOT this test passes.  
# When we retire 10.04 for good (soon, likely) we can re-enable this 
# test and see what happens.
if(NOT ROOT_FOUND)
  LIST(APPEND TEST_SCRIPTS resources/test/test_tree_pybindings.py)
endif()

i3_test_scripts("${TEST_SCRIPTS}")
set_tests_properties(dataclasses::test PROPERTIES LABELS RUN_LONG)
