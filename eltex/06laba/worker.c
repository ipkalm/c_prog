#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define CARGO 10

int main() {

  /* дескрипторы шахты и базы */
  int base, mine;
  unsigned int gold;
  unsigned int *buf = &gold; 
  
  /* флаги для файлов */
  mode_t flags = O_RDWR;

  /* структура блокировки файлов */
  struct flock lock;
  lock.l_type = F_WRLCK;      /* тип блокировки */
  lock.l_whence = SEEK_SET;   /* абсолютное положение */
  lock.l_start = 0;           /* начало блокируемого участка */
  lock.l_len = 0;             /* весь файл */
 
  /* PID процесса */
  pid_t pid = getpid(); 

  /* типа идём от базы к шахте */
  printf("рабочий PID = %i, идёт от базы к шахте\n", pid);
//  sleep(rand()%20);

  /* открытие файла шахты */
  while ((mine = open("mine.bin", flags)) < 0)
    perror("ошибка при открытии файла шахты");
  
  /* блокировка файла */
  while (fcntl(mine, F_SETLKW, &lock) < 0)
    perror("блокировка файла шахты");
      
  /* читаем кол-во голда в шахте и пишем новое значение */
  read(mine, buf, sizeof(gold));
  if (gold >= CARGO) {
    gold -= CARGO;
  } else {
    fprintf(stderr, "в шахте %i золота\n", gold);
    lock.l_type = F_UNLCK;
    while (fcntl(mine, F_SETLK, &lock) < 0)
      perror("снятие блокировки с шахты, в шахте кончилось золото");
    close(mine);

    return 0;
  }
  lseek(mine, 0, SEEK_SET);
  write(mine, buf, sizeof(gold));
  
  /* снятие блокировки */
  lock.l_type = F_UNLCK;
  if (fcntl(mine, F_SETLK, &lock) < 0)
    perror("ошибка при снятии блокировки с шахты"); 
  close(mine);

  /* идём от шахты к базе */
  printf("рабочий PID = %i, идёт от шахты к базе\n", pid);
//  sleep(rand()%5);

  /* открытие файла базы */
  while ((base = open("base.bin", flags)) < 0)
    perror("ошибка при открытии файла базы");
 
  /* блокировка */
  lock.l_type = F_WRLCK;
  while (fcntl(base, F_SETLKW, &lock) < 0) 
    perror("блокировка файла базы");
  
  /* чтение и запись нового значения */
  read(base, buf, sizeof(gold));
  gold += CARGO;
  lseek(base, 0, SEEK_SET);
  write(base, buf, sizeof(gold));
  
  /* снятие блокировки */
  lock.l_type = F_UNLCK;
  if (fcntl(base, F_SETLK, &lock) < 0)
    perror("ошибка при снятии блокировки с базы");
  close(base);
  
  /* возвращаем 1, т.к. в шахте еще есть золото, и родительский процесс вызовет
   * дочерний еще раз */
  return 1;
}
