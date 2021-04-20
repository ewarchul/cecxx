#include "utils.h"

double getFunctionBias(const int biasFlag, const int fnNumber) {
  double bias = 0.0;
  double fnBiasDict[10] = {100.0,  1100.0, 700.0,  1900.0, 1700.0,
                           1600.0, 2100.0, 2200.0, 2400.0, 2500.0};
  if (biasFlag) {
    bias = fnBiasDict[fnNumber - 1];
  } else {
    bias = 0.0;
  }
  return bias;
}

void loadMatrixData(CecData *cd, int dim, int fn) {
  char FileName[256];
  sprintf(FileName, "../data/cec2017/M_%d_D%d.txt", fn, dim);
  FILE *fptMData = fopen(FileName, "r");
  if (fptMData == NULL) {
    perror("Error: Cannot open input file for reading");
  }
  int MatrixSize = fn < 20 ? dim * dim : dim * dim * 10;
  cd->M = malloc(MatrixSize * sizeof(double));
  if (cd->M == NULL) {
    perror("Error: there is insufficient memory available!");
  } else {
    for (int i = 0; i < MatrixSize; ++i) {
      if (fscanf(fptMData, "%lf", &cd->M[i]) == -1) {
        break;
      }
    }
  }
  fclose(fptMData);
}

void loadOShiftData(CecData *cd, int dim, int fn, int cecVersion) {
  char FileName[256];
  int funcTreshold, coeff = 0;
  if (cecVersion == 2017) {
    funcTreshold = 20;
    coeff = 10;
  }
  sprintf(FileName, "../data/cec2017/shift_data_%d.txt", fn);
  FILE *fptOShiftData = fopen(FileName, "r");
  if (fptOShiftData == NULL) {
    perror("Error: Cannot open input file for reading");
  }
  int OShiftSize = fn < funcTreshold ? dim : coeff * dim;
  cd->OShift = malloc(OShiftSize * sizeof(double));
  if (cd->OShift == NULL) {
    perror("Error: there is insufficient memory available!");
  }
  if (fn < funcTreshold) {
    for (int i = 0; i < OShiftSize; ++i) {
      if (fscanf(fptOShiftData, "%lf", &cd->OShift[i]) == -1) {
        break;
      }
    }
  } else {
    for (int i = 0; i < coeff - 1; i++) {
      for (int j = 0; j < dim; j++) {
        int count = fscanf(fptOShiftData, "%lf", &cd->OShift[i * dim + j]);
        if (count == -1) {
          break;
        }
      }
      int count = fscanf(fptOShiftData, "%*[^\n]%*c");
      if (count == -1) {
        break;
      }
    }
    for (int j = 0; j < dim; j++) {
      if (fscanf(fptOShiftData, "%lf", &cd->OShift[(coeff - 1) * dim + j]) ==
          -1) {
        break;
      }
    }
  }
  fclose(fptOShiftData);
}

void loadShuffleData(CecData *cd, int dim, int fn, int cecVersion) {
  int funcTreshold, coeff = 0;
  if (cecVersion == 2017) {
    coeff = 10;
  }
  char FileName[256];
  sprintf(FileName, "../data/cec2017/shuffle_data_%d_D%d.txt", fn, dim);
  FILE *fptShuffleData = fopen(FileName, "r");
  if (fptShuffleData == NULL) {
    perror("Error: Cannot open input file for reading");
  }
  int ShuffleSize = (fn >= 11 && fn <= 20) ? dim : coeff * dim;
  cd->SS = malloc(ShuffleSize * sizeof(int));
  for (int i = 0; i < ShuffleSize; ++i) {
    if (fscanf(fptShuffleData, "%d", &cd->SS[i]) == -1) {
      break;
    }
  }
  fclose(fptShuffleData);
}
