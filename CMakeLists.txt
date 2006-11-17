I3_PROJECT (dataclasses)
USE_PROJECT(icetray)

FILE(GLOB dataclasses_lib_source "private/dataclasses/*.cxx")

ROOTCINT()
ADD_LIBRARY(dataclasses ${dataclasses_lib_source} ${PROJECT_BINARY_DIR}/___Dict.cxx)

FILE(GLOB dataclasses_test_source "private/test/*.cxx")
ADD_TEST(dataclasses-test ${dataclasses_test_source})


