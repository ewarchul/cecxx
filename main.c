#include "cec.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int year = 2014;
  int fn_max = 30;
  char dataPath[50];
  sprintf(dataPath, "../data/cec%d", year);
  int dims[4] = {10, 30, 50, 100};
  for (int d = 0; d < 4; ++d) {
    for (int fn = 1; fn < fn_max + 1; ++fn) {
      double *output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for (int i = 0; i < dims[d]; ++i) {
        output[i] = 0;
      }
      for (int i = 0; i < dims[d]; ++i) {
        input[i] = 0.1;
      }
      cec(dataPath, year, fn, input, dims[d], 1, output, "");
      printf("[CEC%d]\tfn = %d\tinput = (0.1)^%d\t->\toutput = %.3f\n", year, fn,
             dims[d], output[0]);
      free(output);
      free(input);
    }
  }
  return 0;
}
