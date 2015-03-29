#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dlfcn.h>


double atof(const char *arg);
int isinf(double q);
/*extern double umn(double x, double y);
  extern double del(double x, double y); */


/* void *dlopen (const char *filename, int flag); открываем файл библиотеки */
/* void *dlsym(void *handle, char *symbol); получаем адресс функции */



int main(int argc, char * argv[])
{
  double x1, y1;
  void *my_ext_library;
  double (*del_func)(double x1, double y1);
  double (*umn_func)(double x1, double y1);
  
  my_ext_library = dlopen("./libdudyn.so", RTLD_LAZY);

  if(!my_ext_library)
    {
      fprintf(stderr, "dlopen() error: %s\n", dlerror());
      exit(1);
    }
  
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

  umn_func = dlsym(my_ext_library, "umn");
  del_func = dlsym(my_ext_library, "del");
      
  if (*argv[2] == '/' || *argv[2] == 'd')
    printf("%.2lf\n", (*del_func)(x1, y1));
  else if (*argv[2] == 'u' || *argv[2] == 'x')
    printf("%.2lf\n", (*umn_func)(x1, y1));
  else
    {
      printf("Некорректные параметры\n");
      printf("Необходимо ввести параметры следующим образом:\n");
      printf("var1 x var2, где var1 и var2 - числа типа double, а x - операция.\n");
      printf("для умножения - u или x, для деления - d или /\n");
    }
  
  return 0;
}
