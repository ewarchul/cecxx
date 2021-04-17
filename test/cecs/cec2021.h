#ifndef CEC2021_H
#define CEC2021_H

void cec21_basic_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_bias_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_bias_rot_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_bias_shift_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_rot_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_shift_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_shift_rot_func(double *x, double *f, int nx, int mx, int func_num);

void cec21_bias_shift_rot_func(double *x, double *f, int nx, int mx,
                               int func_num);

#endif
