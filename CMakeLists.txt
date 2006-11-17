# PROJECT (dataclasses)

include_directories(public private ${CMAKE_SOURCE_DIR}/icetray/public)

FILE(GLOB dataclasses_lib_source "private/dataclasses/*.cxx")
MESSAGE(foo)
ADD_LIBRARY(dataclasses ${dataclasses_lib_source})

FILE(GLOB dataclasses_test_source "private/test/*.cxx")
ADD_TEST(dataclasses-test ${dataclasses_test_source})

