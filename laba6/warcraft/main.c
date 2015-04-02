#include <stdio.h> // стандарнтый ввод вывод
#include <unistd.h> // доступ к POSIX API. различные основные ф-ии и константы
#include <sys/types.h> // C POSIX с различными типами данных
#include <stdlib.h> // для exit

int main(int argc, char *argv[])
{
  FILE *mine = fopen("mine", "w+");
  int gold_m = 15000;

  /* pid_t pid;
  pid = fork();
  if (pid == 0)
    {
      printf("дочерний процесс\n");
      sleep(10);
    }
  printf("родитель\n"); */

  if (mine == NULL)
    {
      printf("error open file\n");
      exit(1);
    }

  fprintf(mine, "%d", gold_m);
  fclose(mine);
  

  return 0;
}
