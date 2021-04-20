#ifndef UTILS_H
#define UTILS_H

/*
 * Helper function for getting right value of bias in CEC 2021 benchmark.
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct CecData CecData;
struct CecData {
  int dataLoaded;
  int prevFunction;
  int prevDimension;
  double *M;
  double *OShift;
//  double *bias;
  int *SS;
};

double getFunctionBias(const int, const int);

void loadMatrixData(CecData *, int, int);
void loadOShiftData(CecData *, int, int, int);
void loadShuffleData(CecData *, int, int, int);

#endif 
