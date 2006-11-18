PROJECT(dataclasses)

LIB (dataclasses
  private/dataclasses/*.cxx
  private/dataclasses/*.c
  private/dataclasses/*/*.cxx)

USE_TOOL(log4cplus)
USE_TOOL(boost)
USE_TOOL(root)

USE_PROJECT(icetray)

FILE(GLOB dataclasses_test_source "private/test/*.cxx")
ADD_TEST(dataclasses-test ${dataclasses_test_source})

