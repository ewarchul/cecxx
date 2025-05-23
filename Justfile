set dotenv-load

alias i := init
alias b := build
alias tu := run_unit_tests
alias tc := run_compliance_tests
alias c := clean

cxx_compiler := "${CXX}"
c_compiler := "${CC}"
cmake_build_type := "${BUILD_TYPE}"
cmake_generator := "${GENERATOR}"
build_dir := "build-" + cxx_compiler
ncores := `nproc`

default:
  @just --list

init:
  git submodule update --init
  mkdir -p {{build_dir}}
  CXX={{cxx_compiler}} cmake \
    -B {{build_dir}} \
    -S . \
    -G "{{cmake_generator}}" \
    -DCMAKE_BUILD_TYPE={{cmake_build_type}} \
    -DWITH_UNIT_TESTS=on \
    -DWITH_COMPLIANCE_TESTS=on \
    -DWITH_EXAMPLES=on
  ln -fs {{build_dir}}/compile_commands.json compile_commands.json

build: 
  cmake --build {{build_dir}} --parallel {{ncores}}

run_unit_tests:
  unzip -f data/cec2017.zip -d data
  unzip -f data/cec2014.zip -d data
  ctest --test-dir {{build_dir}}/test/unit

run_compliance_tests: 
  unzip -f data/cec2017.zip -d data
  unzip -f data/cec2014.zip -d data
  ASAN_OPTIONS=detect_leaks=0 ./{{build_dir}}/test/compliance/cecxx-compliance-tests

clean: 
  rm -rf {{build_dir}}

fmt: 
  find src -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
  find include -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
