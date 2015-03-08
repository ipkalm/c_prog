#include <stdio.h>

main()
{
  float far, cel;
  int lower, upper, step;
  upper=300;
  step=20;
  far=lower=0;
  
  printf("Программа перевода градусов из цельсия в фаренгейты\n");

  while(far<=upper)
    {
      cel = (5.0/9.0)*(far-32.0);
      printf("%3.0f\t%6.2f\n",far,cel);
      far=far+step;
    }
}
