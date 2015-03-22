#include <stdio.h>

int fact(int n)
{
  return (n < 2) ? 1 : n * fact(n - 1);
}

int main(void)
{
  int n;
  while (scanf("%d", &n) == 1)
    {
      printf("%d\n", fact(n));
    }
}
