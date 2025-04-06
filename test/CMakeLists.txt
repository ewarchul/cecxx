find_package(GTest REQUIRED)
include(GoogleTest)

add_compile_definitions(DATA_STORAGE_PATH="${CMAKE_SOURCE_DIR}/data")

if(WITH_COMPLIANCE_TESTS)
  if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(WARNING
      "To build compliance tests, clang compiler is required.\
      Current compiler: ${CMAKE_CXX_COMPILER_ID}. Skipping building compliance tests..."
    )
  else()
    add_subdirectory(compliance)
  endif()
endif(WITH_COMPLIANCE_TESTS)

if (WITH_UNIT_TESTS)
  add_subdirectory(unit)
endif(WITH_UNIT_TESTS)


