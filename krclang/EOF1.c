#include <stdio.h>

int main()
{
  int c;
  printf("input symbol pls: ");
  c = (getchar() != EOF);
  printf("getchar() != EOF return is \"%d\"\ngood night, bro\n", c);
  return 0;
}
