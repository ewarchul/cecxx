set(TEST_TARGET "cecxx_unit_tests")
set(TEST_SOURCES
  evaluator.test.cpp
)

enable_testing()

add_executable(${TEST_TARGET} ${TEST_SOURCES})
target_link_libraries(${TEST_TARGET} GTest::gtest_main)
gtest_discover_tests(${TEST_TARGET})

add_test(NAME ${TEST_TARGET} COMMAND $<TARGET_FILE:${TEST_TARGET}>)
