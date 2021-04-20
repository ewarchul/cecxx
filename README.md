

# CEC

faster & safer.

# About 

This repository contains a tidied up codebase of CEC, i.e. set of optimization benchmark problems.

During working with the official code of the benchmark I had encountered issues with memory management, variable scoping, and code readability so I decided to tidy up the code and fix those issues.
Modified code is equivalent to the official one - you can run tests and check it by yourself. 

Currently, the repository contains the modified implementation and their technical specifications (check `doc/` directory) of the following editions: 

- CEC 2021 Special Session and Competition on Single Objective Bound Constrained Numerical Optimization
- CEC 2019 Special Session and Competition on Single Objective Bound Constrained Numerical Optimization
- CEC 2017 Special Session and Competition on Single Objective Bound Constrained Numerical Optimization
- CEC 2015 Learning-based Real-Parameter Single Objective Optimization
- CEC 2014 Special Session and Competition on Single Objective Bound Constrained Numerical Optimization

For more information about the benchmark check the official repository of the CEC availabled under the
following link:

[https://github.com/P-N-Suganthan?tab=repositories](https://github.com/P-N-Suganthan?tab=repositories).

Simple example of how to use given interface is in the `main.c` file. 

# Tests

To run test you need [CMocka](https://cmocka.org/) unit test framework and [CMake](https://cmake.org/) (3.16.3v). 
If you meet the requirements then execute `test.sh` script.

## Nix 

If you use [Nix package manager](https://nixos.org/) type commands written below:

```Nix
nix-shell --command "bash test.sh"
```


