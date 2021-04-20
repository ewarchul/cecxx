#include "cec2017.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define REP 1

int main() {
  int dims[1] = {100};
  for (int d = 0; d < 1; ++d) {
    for (int fn = 1; fn < 31; ++fn) {
      for (int i = 0; i < REP; i++) {
        double *output = malloc(dims[d] * sizeof(double));
        double *input = malloc(dims[d] * sizeof(double));
        for (int i = 0; i < dims[d]; ++i) {
          input[i] = 0.1;
        }
        cec17_test_func(input, output, dims[d], 1, fn);
        free(output);
        free(input);
      }
    }
  }
  return 0;
}
