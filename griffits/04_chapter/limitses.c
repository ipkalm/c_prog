#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

  printf("Значение INT_MAX = %i\n", INT_MAX);
  printf("Значение INT_MIN = %i\n", INT_MIN);
  printf("int занимет %li байт\n\n", sizeof(int));

  printf("Значение FLT_MAX = %f\n", FLT_MAX);
  printf("Значение FLT_MIN = %f\n", FLT_MIN);
  printf("float занимает %li байт\n\n", sizeof(float));
  
  printf("Значение CHAR_MAX = %c\n", CHAR_MAX);
  printf("Значение CHAR_MIN = %c\n", CHAR_MIN);
  printf("char занимает %li байт\n\n", sizeof(char));
  
  printf("Значение DBL_MAX = %f\n", DBL_MAX);
  printf("Значение DBL_MIN = %f\n", DBL_MIN);
  printf("double занимает %li байт\n\n", sizeof(double));
  
  printf("Значение SHRT_MAX = %i\n", SHRT_MAX);
  printf("Значение SHRT_MIN = %i\n", SHRT_MIN);
  printf("short занимает %li байт\n\n", sizeof(short));

  return 0;
}
