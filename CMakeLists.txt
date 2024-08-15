cmake_minimum_required(VERSION 3.19)
set(PROJECT_VER 0.2.1)

project(cecxx
  VERSION ${PROJECT_VER}
  DESCRIPTION "An implementation of CECs benchmarks in C++20"
  LANGUAGES CXX
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(Package)
include(ProjectConfig)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)
include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(HEADER_DIR ${ROOT_DIR}/include)
set(SOURCE_DIR ${ROOT_DIR}/src)

file(
  GLOB_RECURSE
  HEADERS
  CONFIGURE_DEPENDS
  ${HEADER_DIR}/*.hpp
  ${HEADER_DIR}/**/*.hpp
)

file(
  GLOB_RECURSE
  SOURCES
  CONFIGURE_DEPENDS
  ${SOURCE_DIR}/*.cpp
  ${SOURCE_DIR}/**/*.cpp
  ${SOURCE_DIR}/*.hpp
  ${SOURCE_DIR}/**/*.hpp
)

if (BUILD_SHARED_LIBS)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

FetchContent_Declare(concurrencpp 
  GIT_REPOSITORY https://github.com/David-Haim/concurrencpp.git
  GIT_TAG        7a88f5401e15e1b64acae70077e40df1a5a9f6bf # release: 0.1.7
)
FetchContent_MakeAvailable(concurrencpp)


add_library(cecxx)
target_sources(cecxx PRIVATE ${SOURCES})
target_sources(cecxx PUBLIC FILE_SET HEADERS BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include" FILES ${HEADERS})
target_link_libraries(cecxx PRIVATE concurrencpp::concurrencpp)
target_compile_options(cecxx PRIVATE ${COMPILE_FLAGS})
target_compile_features(cecxx PRIVATE cxx_std_23)

message(STATUS "The cecxx library is going to be compiled with the following additional flags: ${COMPILE_FLAGS}")

configure_file(defaults.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/include/cecxx/benchmark/defaults.hpp) 
generate_export_header(cecxx)

write_basic_package_version_file("${PROJECT_BINARY_DIR}/cecxxConfigVersion.cmake"
  VERSION ${PROJECT_VER}
  COMPATIBILITY AnyNewerVersion
)

include(CPack)

install(TARGETS cecxx EXPORT cecxxTargets FILE_SET HEADERS)
install(EXPORT cecxxTargets NAMESPACE cecxx:: DESTINATION lib/cmake/cecxx)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION "${BENCHMARK_DATA_STORAGE}")

if (WITH_EXAMPLES)
  add_subdirectory(example)
endif()

if (WITH_BENCHMARKS)
  add_subdirectory(benchmark)
endif()

if (WITH_TESTS)
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_subdirectory(test)
  else()
    message(WARNING "To build tests, use clang compiler. Current CXX compiler: ${CMAKE_CXX_COMPILER}")
  endif()
endif(WITH_TESTS)
