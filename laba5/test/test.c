#include <stdio.h>
#include <stdlib.h>


double atof(const char *arg);
double um(double x, double y);

int main(int argc, char * argv[])
{
  printf("%d\n", argc);
  if (argc < 4)
    {
      return 1;
      exit(1);
    }
  
  printf("%.2lf\n", um(atof(argv[1]), atof(argv[2])));
  printf("%c\n", *argv[3]);
  printf("\n\n#####\n");
  char x = *argv[3];
  printf("%c\n", x);
  if(x == 't')
    printf("pobeda\n");
  else if (x == '/')
    printf("pew pew\n");
  return 0;
}

double um(double x, double y)
{
  return x * y;
}
