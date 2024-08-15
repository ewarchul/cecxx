find_package(fmt REQUIRED)

add_compile_definitions(DATA_STORAGE_PATH="${CMAKE_SOURCE_DIR}/data")

add_executable(main main.cpp)
target_link_libraries(main PRIVATE cecxx fmt::fmt concurrencpp::concurrencpp)
set_target_properties(main PROPERTIES CXX_STANDARD 23)
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic -O3)

