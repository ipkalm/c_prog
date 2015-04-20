// Copyright 2015 <Astronaut>
// имзененная версия рабочего, который в аргумент принимает
// сколько голд надо принести из шахты

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.c"

#define CARGO 10
#define MINE "mine"

int atoi(const char *nptr);

int main(int argc, char *argv[]) {
  int gold;
  int kpd = 0;
  int need_gold = atoi(argv[1]);
  int mine_fd;
  pid_t pid = getpid();
  struct flock lck;

  // в аргументе командной строки должно быть указано количество голда
  if (argc < 2)
    error("не задано количество голда в аргументе");
  else if (argc > 2)
    error("что-то многовато аргументов!");

  if ((need_gold % 10) != 0)
    error("рабочий носит по 10 золота");

  mine_fd = open(MINE, O_RDWR);
  if (mine_fd < 0)
    error("Не могу открыть файл");

  // блокировка
  lck.l_whence = 0;  // смещение от начала
  lck.l_len = 0L;    // начало блокировки с позии 0
  lck.l_start = 0L;  // и до конца

  for (;;) {
    lseek(mine_fd, 0L, 0);
    lck.l_type = F_WRLCK;
    fcntl(mine_fd, F_SETLKW, &lck);

    read(mine_fd, &gold, sizeof(gold));
    if (need_gold > gold) {
      printf("в шахте %d\n", gold);
      error("увы, но столько золота в шахте нет");
    }

    if (gold > 9 && kpd <= need_gold-10) {
      gold = gold - CARGO;
      kpd = kpd + CARGO;

      lseek(mine_fd, 0L, 0);
      write(mine_fd, &gold, sizeof(gold));

      lck.l_type = F_UNLCK;
      fcntl(mine_fd, F_SETLK, &lck);

      sleep(1);  // типа несет голду
    } else {
      lck.l_type = F_UNLCK;
      fcntl(mine_fd, F_SETLK, &lck);
      printf("наносил %d золота (pid=%d)\n", kpd, pid);
      close(mine_fd);
      break;
    }
  }
  return 0;
}
