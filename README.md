# cecxx

An implementation of IEEE Congress of Evolutionary (CEC) Bound Constrained Single Objective Numerical Optimization benchmarks in
C++23.

[![gnu](https://github.com/ewarchul/cecxx/actions/workflows/gnu.yml/badge.svg?branch=main)](https://github.com/ewarchul/cecxx/actions/workflows/gnu.yml)
[![llvm](https://github.com/ewarchul/cecxx/actions/workflows/llvm.yml/badge.svg?branch=main)](https://github.com/ewarchul/cecxx/actions/workflows/llvm.yml)


[About](#about)

[Benchmarks](#benchmarks)

[Installation and usage](#installation-and-usage)

[Examples](#examples)

[Supported benchmarks](#supported-benchmarks)

## About

TODO

## Benchmarks

TODO

## Installation and usage

### Requirements

To build and install the `{cecxx}` library, following programs are required:

* LLVM clang++-19 or GNU gcc-14
* cmake (at least 3.19)

To build and run compliance tests, only LLVM's compiler can be used. 

#### Supported platforms

| Operating system | Status |
|:----------------:|:------:|
| Linux | :heavy_check_mark: |
| macOS | :soon: |
| Windows | :soon: |


### Build and installation

To build and install the `{cecxx}` library, run the following commands:

```sh
mkdir build 
cmake -B build -S . 
cmake --build build
cmake --install build
```

#### Justfile

or if you are using `Justfile` simply type:

```sh
just init build install
```

### Running tests

TODO

#### Justfile

TODO

### Usage

TODO

### Examples

TODO

All examples can be found in [example](https://github.com/ewarchul/cecxx/tree/main/example) directory. 

## Supported benchmarks

TODO


| CEC editiion | Status |
|:-------------|:------:|
| 2013 | :soon: |  
| 2014 | :soon: |  
| 2015 | :soon: |  
| 2017 | :heavy_check_mark: |  
| 2019 | :soon: |  
| 2021 | :soon: |  
| 2022 | :soon: |  
| 2023 | :soon: |  
| 2024 | :soon: |  
| 2025 | :soon: |  

