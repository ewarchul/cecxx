option(WITH_TESTS "Build tests" OFF)
option(WITH_EXAMPLES "Build examples" OFF)
option(WITH_BENCHMARKS "Build benchmarks" OFF)

set(BENCHMARK_DATA_STORAGE "${CMAKE_INSTALL_PREFIX}/share/cecxx")

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(COMPILE_FLAGS -Wall -Wpedantic -Wextra -Wconversion -Wimplicit-fallthrough -Wundef)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(COMPILE_FLAGS -Wall -Wextra -pedantic -Wconversion -Wundef
      -Wdeprecated -Wshadow)
endif()
