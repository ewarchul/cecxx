set(TEST_TARGET "cecxx_unit_tests")
set(TEST_SOURCES
  evaluator.test.cpp
)

enable_testing()


add_executable(${TEST_TARGET} ${TEST_SOURCES})
set_target_properties(${TEST_TARGET}
  PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 23
)
target_include_directories(${TEST_TARGET} PUBLIC .)
target_link_libraries(${TEST_TARGET} GTest::gtest_main cecxx)
gtest_discover_tests(${TEST_TARGET})

add_test(NAME ${TEST_TARGET} COMMAND $<TARGET_FILE:${TEST_TARGET}>)
