#include <stdio.h>

extern int f1();
extern int f2();

int main()
{
  int n1, n2;
  n1 = f1(); n2 = f2();
  printf("%d\n",n1+n2);
  return 0;
}
