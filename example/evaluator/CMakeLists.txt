find_package(fmt REQUIRED)

add_compile_definitions(DATA_STORAGE_PATH="${CMAKE_SOURCE_DIR}/data")

add_executable(evaluator_example main.cpp)
target_link_libraries(evaluator_example PRIVATE cecxx range-v3)
set_target_properties(evaluator_example PROPERTIES CXX_STANDARD 23)
target_compile_options(evaluator_example PRIVATE -Wall -Wextra -Wpedantic -O3)

