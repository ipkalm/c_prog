/**
   Пример запуска:
   $ make
   $ ./main 2 5 /path/to/libdir funcname
 */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[]) {

  void *dynlib;
  double (*dynfunc)(double a, double b);
  double a, b;

  if (argc != 5) {
    fprintf(stderr, "incorrent launch\n");
    exit(-1);
  }

  a = atof(argv[1]);
  b = atof(argv[2]);
  dynlib = dlopen(argv[3], RTLD_LAZY);
  if (!dynlib) {
    fprintf(stderr, "dlopen(): %s\n", dlerror());
    exit(-2);
  }
  dynfunc = dlsym(dynlib, argv[4]);

  printf("expression a * b = %.2F\n", (*dynfunc)(a, b));

  dlclose(dynlib);

  return 0;
}
