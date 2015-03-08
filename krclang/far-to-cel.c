#include <stdio.h>

int main()
{
  int cel, far, step, low, up;
  
  cel = low = 0;
  step = 20;
  up = 300;
  printf("Программа конвертер из фаренгейта в цельсии\n");
  printf("cel\t   far\n");
  while (far < up)
    {
      far = (cel * 9.0)/5.0 + 32.0;
      printf("%3d\t%6d\n", cel, far);
      cel = cel + step;
    }
  return 0;
}
