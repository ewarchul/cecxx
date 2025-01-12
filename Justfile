set dotenv-load

alias i := init_build
alias b := build
alias p := package
alias e := exe
alias t := test
alias c := clean

cxx_compiler := "${CXX}"
c_compiler := "${CC}"
build_dir := "build-" + cxx_compiler
ncores := `nproc`


default:
  @just --list

init_build: clean
  mkdir -p {{build_dir}}
  cd {{build_dir}} && CC={{c_compiler}} CXX={{cxx_compiler}} cmake -DWITH_TESTS=on -DWITH_EXAMPLES=on .. 
  ln -fs {{build_dir}}/compile_commands.json compile_commands.json

build: 
  cd {{build_dir}} && make -j {{ncores}}

exe:
  ./{{build_dir}}/example/evaluator/evaluator_example


test $fuzz_duration: 
  #!/usr/bin/env bash
  set -euo pipefail
  dimensions=(10 30 50 100)
  GREEN='\033[0;32m'
  NO_COLOR='\033[0m'
  for dim in ${dimensions[@]}; do
    echo -e "${GREEN} Running compliance tests for dimension ${dim}. Duration: ${fuzz_duration} ${NO_COLOR}"
    unzip -o "${PWD}/data/cec2017.zip" -d "${PWD}/data"
    ASAN_OPTIONS=detect_leaks=0 ./{{build_dir}}/test/cecxx-fuzz --fuzz="Cec2017ComplianceTest.Cec2017D${dim}ImplsAreEquiv" --fuzz_for={{fuzz_duration}} || true
  done

package:
  cd {{build_dir}} && cpack 

clean: 
  rm -rf {{build_dir}}

fmt: 
  find src -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
  find include -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
