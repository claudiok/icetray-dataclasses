I3_PROJECT (dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx)

USE_PROJECT(icetray)

FILE(GLOB dataclasses_test_source "private/test/*.cxx")
ADD_TEST(dataclasses-test ${dataclasses_test_source})


