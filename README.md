# cecxx

[![gnu](https://github.com/ewarchul/cecxx/actions/workflows/gnu.yml/badge.svg?branch=main)](https://github.com/ewarchul/cecxx/actions/workflows/gnu.yml)
[![llvm](https://github.com/ewarchul/cecxx/actions/workflows/llvm.yml/badge.svg?branch=main)](https://github.com/ewarchul/cecxx/actions/workflows/llvm.yml)

Implementation of IEEE Congress of Evolutionary (CEC) Bound-constrained Single Objective Numerical Optimization benchmarks in
C++23.


> [!IMPORTANT]
> This is pre-alpha stage software. Only CEC BC-SOP 2017 is supported. See [below table](#supported-benchmarks) for supported
> benchmarks.


---

[About](#about)

[Build and installation](#build-and-installation)

[Usage](#usage)

[Supported benchmarks](#supported-benchmarks)

[Contact](#contact)

## About

The `{cecxx}` is a novel implementation of IEEE CEC BC-SOP [^1] benchmarks in C++23, which compared to the [official implementation
](https://github.com/P-N-Suganthan?tab=repositories) does not:
- leak memory 
- involves multiple IO operations during each objective function call.

Solving the above problems results in reliable and fast implementation that is ready to be used in your numerical experiments.

> [!NOTE]
> This **is not** official implementation of CEC BC-SOP benchmarks. However, it can be used as a drop-in replacement. The
> `{cecxx}` is extensively tested to be compliant with the official implementations by emplyoing property-based testing. See
> [test/compliance](https://github.com/ewarchul/cecxx/tree/main/test/compliance) for details.


[^1]: Bound-constrained single objective problem.


## Build and installation

### Requirements

To build and install the `{cecxx}` library, the following dependencies are required:

* LLVM clang++ (>=v19) or GNU g++ (>=v14)
* cmake (>=v3.19)

To build and run tests, you need [googletest](https://github.com/google/googletest).
Note that only LLVM's compiler can be used to build compliance tests. 

#### Supported platforms

| Operating system | Status |
|:----------------:|:------:|
| Linux | :heavy_check_mark: |
| macOS [^2] | :heavy_check_mark: |
| Windows | :soon: |


[^2]: Only LLVM and GNU toolchain are supported. The Apple Clang won't be supported.

### Build

To build the `{cecxx}` library, run the following commands:

```sh
mkdir build 
cmake -B build -S . 
cmake --build build
```

#### Justfile

If you are using `Justfile`, then you can type:

```sh
just init build
```

See [Justfile](https://github.com/ewarchul/cecxx/blob/main/Justfile) recipes for details.

### Tests

To build unit or compliance tests, run `cmake` with `-DWITH_UNIT_TESTS` and `-DWITH_COMPLIANCE_TESTS` options.

### Usage

#### Set up a CMake project 

To set up your CMake project with the `{cecxx}`, add the following lines to the CMakeLists.txt:

```cmake
# {cecxx} requires at least C++23 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cecxx REQUIRED)
...
target_link_libraries(<your-target> cecxx::cecxx)

```

#### Usage example 

<details closed>

```cpp
#include <print>
#include <ranges>
#include <vector>

#include <cecxx/mdspan.hpp>
#include <cecxx/benchmark/evaluator.hpp>

namespace rn = std::ranges;
namespace rv = std::ranges::views;
using namespace cecxx::benchmark;

auto main() -> int {
    const auto dimensions = std::vector{10uz, 30uz, 50uz, 100uz};
    // Create an evaluator object for the CEC2017 benchmark
    auto cec_2017 = evaluator(cec_edition_t::cec2017, dimensions, DATA_STORAGE_PATH);
    // Create a problem grid [problem_number X dimension]
    const auto problem_grid = rv::cartesian_product(dimensions, rv::iota(1, 30));
    // Evaluate given input on each optimization problem from CEC2017/D{10, 30, 50, 100}
    for (const auto &[dim, fn] : problem_grid) {
        // Prepare an input, i.e., matrix [dim x 2]
        const auto input = rv::repeat(0.0) | rv::take(2 * dim) | rn::to<std::vector<double>>();
        const auto output = cec_2017(fn, cecxx::mdspan{input.data(), dim, 2});
        std::println("dim = {}, fn = {}, output[0] = {}, output[1] = {}", dim, fn, output[0], output[1]);
    }
}
```
</details>

You can find other examples in [example](https://github.com/ewarchul/cecxx/tree/main/example) directory. 

## Supported benchmarks

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

## Contact

If you encounter any bugs, feel encouraged to create an issue or raise a PR with the fix.

If you are using `{cecxx}` as a part of your academic research or other activities,
please star the repository.

