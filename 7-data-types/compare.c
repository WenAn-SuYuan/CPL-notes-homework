//
// Created by weslie on 2023/12/7.
//
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define EPSILON 1e-5

bool IsEqual(double x, double y);

int main() {
  printf("%d\n", IsEqual(DBL_MAX, DBL_MAX - 100));

  printf("%.50f\n", DBL_MAX - (DBL_MAX - 100));

  return 0;
}

bool IsEqual(double x, double y) {
  return fabs(x - y) <= EPSILON;
}