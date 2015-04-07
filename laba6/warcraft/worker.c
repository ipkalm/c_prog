// код рабочего, кторый должен заблокировать файл шахты
// отнять 10 голда
// разблокировать файл шахты

#include <sys/file.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

#define CARGO 10
#define MAX_TRY 2000

int fileno(FILE * stream);
int lockf(int fd, int cmd, off_t len);
void exit(int exit_code);

int main(int argc, char *argv[])
{
  int gold_mine;
  
  //открываем файл
  FILE *mine = fopen("mine", "r+");

  // читаем содержимое шахты
  fread(&gold_mine, sizeof(int), 1, mine);

  // в начало файла
  lseek(fileno(mine), 0L, 0);
  while ()
    {
  
      while (gold_mine > 9)
	{
	  gold_mine = gold_mine - CARGO; // уносим 10 золота
	  rewind(mine);
	  fwrite(&gold_mine, sizeof(int), 1, mine); // записываем остаток в шахту
	}

    }
  
  // lockf(fileno(mine), F_ULOCK, 0L); // снимаем блокировку с шахты
  
  return 0;
}
