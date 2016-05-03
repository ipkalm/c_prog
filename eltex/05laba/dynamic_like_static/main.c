#include <stdio.h>
#include <stdlib.h>
// #include "math.h"

extern double mMul(double a, double b);

int main(int argc, char *argv[]) {
  double a, b;

  if (argc != 3)
    exit(-1);

  a = atof(argv[1]);
  b = atof(argv[2]);

  printf("expression a * b = %.2F\n", mMul(a, b));
  return 0;
}
