#include "cec.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define REP 1

CecData cd = {
  .prevDimension = 0,
  .prevFunction = 0,
  .dataLoaded = 0,
};

int main() {
  int year = 2015;
  char dataPath[50];
  sprintf(dataPath, "../data/cec%d", year);
  int fn_max = 15;
  int dims[1] = {10};
  for (int d = 0; d < 1; ++d) {
    for (int fn = 1; fn < fn_max + 1; ++fn) {
      for (int i = 0; i < REP; i++) {
        double *output = malloc(dims[d] * sizeof(double));
        double *input = malloc(dims[d] * sizeof(double));
        for (int i = 0; i < dims[d]; ++i) {
          input[i] = 0.1;
        }
        cec2015_interface(dataPath, input, output, dims[d], 1, fn);
       // printf("<f=%d|d=%d\toutput[0] = %0.3f\n",fn, dims[d], output[0]);
        free(output);
        free(input);
      }
    }
  }
  free(cd.M);
  free(cd.OShift);
  free(cd.SS);
  free(cd.bias);
  return 0;
}
