#include <stdio.h>

int main()
{
  int cel;

  printf("Преобр шкалы Цельсия в Фаренгейты\n");
  printf("cel\t   far\n\n");
  
  for (cel = 300; cel >= 0; cel = cel - 20)
    {
      printf("%3d\t%6d\n", cel, (cel * 9 / 5 + 32));
    }
  return 0;
}
