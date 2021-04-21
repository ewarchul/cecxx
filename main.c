#include "cec.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define REP 10000

CecData cd = {
    .prevDimension = 0,
    .prevFunction = 0,
    .dataLoaded = 0,
};

int main() {
  int year[] = { 2014, 2015, 2017, 2019, 2021 };
  char dataPath[50];
  int fn_max[] = { 30, 15, 30, 10, 10 };
  int dims[1] = {10};
  double input[10] = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 };
  for (int y = 0; y < 5; ++y) {
    for (int d = 0; d < 1; ++d) {
      sprintf(dataPath, "../data/cec%d", year[y]);
      for (int fn = 1; fn < fn_max[y] + 1; ++fn) {
        for (int i = 0; i < REP; i++) {
          double *output = malloc(dims[d] * sizeof(double));
          switch (year[y]) {
          case 2014:
            cec2014_interface(dataPath, input, output, dims[d], 1, fn);
            break;
          case 2015:
            cec2015_interface(dataPath, input, output, dims[d], 1, fn);
            break;
          case 2017:
            cec2017_interface(dataPath, input, output, dims[d], 1, fn);
            break;
          case 2019:
            cec2019_interface(dataPath, input, output, dims[d], 1, fn);
            break;
          case 2021:
            cec2021_interface(dataPath, input, output, dims[d], 1, fn,
                              "bias_shift_rot");
            break;
          }
          free(output);
        }
      }
    }
  }
  free(cd.M);
  free(cd.OShift);
  free(cd.SS);
  free(cd.bias);
  return 0;
}
