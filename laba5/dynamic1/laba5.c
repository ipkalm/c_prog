#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double atof(const char *arg);
int isinf(double q);
extern double umn(double x, double y);
extern double del(double x, double y);

int main(int argc, char * argv[])
{
  double x1, y1;

  if (argc < 4)
    {
      printf("Некорректные параметры\n");
      printf("Необходимо ввести параметры следующим образом:\n");
      printf("var1 x var2, где var1 и var2 - числа типа double, а x - операция.\n");
      printf("для умножения - u или x, для деления - d или /\n");
      exit(1);
    }

  x1 = atof(argv[1]);
  y1 = atof(argv[3]);
  
  if (isinf(x1) || isinf(y1))
    {
      printf("Введенные первый или третий агрумент не есть числа\n");
      exit(1);
    }
      
      
  if (*argv[2] == '/' || *argv[2] == 'd')
    printf("%.2lf\n", del(x1, y1));
  else if (*argv[2] == 'u' || *argv[2] == 'x')
    printf("%.2lf\n", umn(x1, y1));
  else
    {
      printf("Некорректные параметры\n");
      printf("Необходимо ввести параметры следующим образом:\n");
      printf("var1 x var2, где var1 и var2 - числа типа double, а x - операция.\n");
      printf("для умножения - u или x, для деления - d или /\n");
    }
  
  return 0;
}
