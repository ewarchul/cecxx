#define UNIT_TESTING 1

#include "cec.h"
#include "interfaces.h"
#include "cecs/cec2021.h"
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include <cmocka.h>

#define REPEATS 100

CecData cd = {
  .prevDimension = 0,
  .prevFunction = 0,
  .dataLoaded = 0,
};


inline static void fillRandomArray(size_t n, double* input) {
  for(size_t i = 0; i < n; ++i) {
    input[i] = rand();
  }
}

static void test_cec2021_basic_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "basic");  
      cec21_basic_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_bias_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "bias");  
      cec21_bias_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_rot_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "rot");  
      cec21_rot_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_shift_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "shift");  
      cec21_shift_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_shift_rot_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "shift_rot");  
      cec21_shift_rot_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_bias_shift_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "bias_shift");  
      cec21_bias_shift_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_bias_rot_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "bias_rot");  
      cec21_bias_rot_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

static void test_cec2021_bias_shift_rot_equiv(void **state) {
  (void)state;
  int dims[2] = {10, 20};
  int fnNum = 10;
  char *dataPath = "../data/cec2021";
  int row = 1;
  for (int d = 0; d < 2; ++d) {
    for (int f = 1; f < fnNum+1; ++f) {
      double *original_output = malloc(dims[d] * sizeof(double));
      double *rewritten_output = malloc(dims[d] * sizeof(double));
      double *input = malloc(dims[d] * sizeof(double));
      for(int i = 0; i < REPEATS; ++i) {
      fillRandomArray(dims[d], input);
      cec2021_interface(dataPath, input, rewritten_output, dims[d], row, f, "bias_shift_rot");  
      cec21_bias_shift_rot_func(input, original_output, dims[d], row, f);
      assert_true(original_output[0] == rewritten_output[0]);
      }

      free(rewritten_output);
      free(original_output);
      free(input);
    }
  }
}

int main() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_cec2021_basic_equiv),
      cmocka_unit_test(test_cec2021_bias_equiv),
      cmocka_unit_test(test_cec2021_rot_equiv),
      cmocka_unit_test(test_cec2021_shift_equiv),
      cmocka_unit_test(test_cec2021_shift_rot_equiv),
      cmocka_unit_test(test_cec2021_bias_shift_equiv),
      cmocka_unit_test(test_cec2021_bias_rot_equiv),
      cmocka_unit_test(test_cec2021_bias_shift_rot_equiv)
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
