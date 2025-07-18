set(TEST_TARGET "cecxx-compliance-tests")
set(TEST_SOURCES
  # cec2017.test.cpp
   cec2014.test.cpp
  cec2013.test.cpp
  # oracle/cec2017.cpp
   oracle/cec2014.cpp
  oracle/cec2013.cpp
)
set(FUZZTEST_FUZZING_MODE ON)

enable_testing()
fuzztest_setup_fuzzing_flags()

add_executable(${TEST_TARGET} ${TEST_SOURCES})
target_include_directories(${TEST_TARGET} PUBLIC .)
target_link_libraries(${TEST_TARGET} PRIVATE cecxx)
set_target_properties(${TEST_TARGET}
  PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 23
)
link_fuzztest(${TEST_TARGET})
gtest_discover_tests(${TEST_TARGET})

add_test(NAME ${TEST_TARGET} COMMAND $<TARGET_FILE:${TEST_TARGET}>)
