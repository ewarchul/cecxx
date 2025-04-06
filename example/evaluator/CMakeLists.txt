add_compile_definitions(DATA_STORAGE_PATH="${CMAKE_SOURCE_DIR}/data")

add_executable(evaluate_each_problem evaluate_each_problem.cpp)
target_link_libraries(evaluate_each_problem PRIVATE cecxx)
set_target_properties(evaluate_each_problem PROPERTIES CXX_STANDARD 23)
target_compile_options(evaluate_each_problem PRIVATE -Wall -Wextra -Wpedantic -O3)


add_executable(evaluate_separate_problem evaluate_separate_problem.cpp)
target_link_libraries(evaluate_separate_problem PRIVATE cecxx)
set_target_properties(evaluate_separate_problem PROPERTIES CXX_STANDARD 23)
target_compile_options(evaluate_separate_problem PRIVATE -Wall -Wextra -Wpedantic -O3)

