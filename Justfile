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


# cd {{build_dir}} && CC={{c_compiler}} CXX={{cxx_compiler}} cmake -DWITH_TESTS=off .. 

init_build: clean
  mkdir -p {{build_dir}}
  cd {{build_dir}} && CC={{c_compiler}} CXX={{cxx_compiler}} cmake -DFUZZTEST_FUZZING_MODE=on -DWITH_TESTS=on -DWITH_EXAMPLES=on .. 
  ln -fs {{build_dir}}/compile_commands.json compile_commands.json

build: 
  cd {{build_dir}} && make -j {{ncores}}

exe:
  ./{{build_dir}}/main

fuzz_duration := "15s"
test: 
  #!/usr/bin/env bash
  set -euxo pipefail
  dimensions=(10 30 50 100)
  for dim in ${dimensions[@]}; do
    ./{{build_dir}}/test/cecxx-fuzz --fuzz="CecFuzzTest${dim}D.Cec2017ImplsAreEquiv" --fuzz_for={{fuzz_duration}} || true
  done

package:
  cd {{build_dir}} && cpack 

clean: 
  rm -rf {{build_dir}}

fmt: 
  find src -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
  find include -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i


default:
  @just --list
