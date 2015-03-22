#include <stdio.h>

int main()
{
  printf("размер double: %lu байт\n", sizeof(double));
  printf("размер float: %lu байт\n", sizeof(float));
  printf("размер int: %lu байт\n", sizeof(int));
  printf("размер char: %lu байт\n", sizeof(char));
  printf("размер long int: %lu байт\n", sizeof(long int));
  printf("размер long double: %lu байт\n", sizeof(long double));
  return 0;
}
