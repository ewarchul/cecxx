find_package(fmt REQUIRED)

add_compile_definitions(DATA_STORAGE_PATH="${CMAKE_SOURCE_DIR}/data")

add_executable(runner_example main.cpp)
target_link_libraries(runner_example PRIVATE cecxx concurrencpp::concurrencpp)
set_target_properties(runner_example PROPERTIES CXX_STANDARD 23)
target_compile_options(runner_example PRIVATE -g -Wall -Wextra -Wpedantic -O0)

