include(FetchContent)
FetchContent_Declare(
  fuzztest
  GIT_REPOSITORY https://github.com/google/fuzztest.git
  GIT_TAG "main"
)
FetchContent_MakeAvailable(fuzztest)

enable_testing()
include(GoogleTest)

fuzztest_setup_fuzzing_flags()

add_compile_definitions(DATA_STORAGE_PATH="${CMAKE_SOURCE_DIR}/data")

add_executable(cecxx-fuzz gtest/cec2017_oracle_compliance_test.cpp oracle/cec2017.cpp)
target_include_directories(cecxx-fuzz PUBLIC .)
target_link_libraries(cecxx-fuzz PRIVATE cecxx)

set_target_properties(cecxx-fuzz PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 20)

link_fuzztest(cecxx-fuzz)
gtest_discover_tests(cecxx-fuzz)
