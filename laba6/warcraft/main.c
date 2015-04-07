#include <stdio.h> // стандарнтый ввод вывод
#include <stdlib.h>
#include <unistd.h> // доступ к POSIX различные основные ф-ии конс-ты
#include <sys/types.h> // C POSIX с различными типами данных
#include <sys/wait.h>

#define WORKERS 5

void mine_init(void);
void warehouse_init(void);

int main(int argc, char *argv[])
{
  int i, pid[WORKERS], stat, status;
  
  // инициализации шахты и склада
  mine_init();
  
  for (i = 0; i < 5; i++) // создаем процессы рабочих
    {
      pid[i] = fork(); // порождаем дочерний процесс

      if (pid[i] == 0)
	{
	  if (execl("./worker.c.out", "worker.c.out", NULL) < 0) // запускаем файл рабочего
	    {
	      printf("Ошибка во время запуска файла/процееса\n");
	      exit(-2);
	    }
	  else
	    {
	      printf("Процесс-файл запущен pid=%d\n", pid[i]);
	    }
	  // выход из процесса
	}
    }
  
  sleep(1);

  for (i = 0; i < 5; i++)
    {
      status = waitpid(pid[i], &stat, WNOHANG);
      if (pid[i] == status)
	{
	  printf("процесс %d завершился\n", pid[i]);
	}
    }

  int q;
  FILE *mine = fopen("mine", "r");
  if(mine == NULL)
    {
      printf("ошибка открытия файла\n");
      exit(1);
    }
  
  fread(&q, sizeof(int), 1,mine);
  printf("золота осталось %d\n", q);
  fclose(mine);
  
  return 0;
}


// инициализация шахты
void mine_init(void)
{
  int gold = 15000;
  int x;
  
  FILE *mine = fopen("mine", "w+");
  if (mine == NULL)
    {
      printf ("ошбка открытия mine\n");
      exit(1);
    }
  fwrite(&gold, sizeof(int), 1, mine);
  printf("шахта инициализирована\n");

  rewind(mine);
  
  fread(&x, sizeof(int), 1, mine);
  printf("в шахте %d золота\n", x);

  fclose(mine);
}
