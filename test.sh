#!/usr/bin/env bash
set -euo pipefail

mkdir -p build && cd build
cmake ..
versions=(
  2014
  2015
  2017
  2019
  2021
)
for v in "${versions[@]}"; do
  make test_cec${v}
done
ctest



