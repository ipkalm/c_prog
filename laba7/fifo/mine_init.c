// инициализация шахты
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "error.c"

#define MINE "mine"
#define GOLD 15000

void mine_init(void) {
  int gold = GOLD;
  int fd_mine;

  // открываем файл если есть, если нет то создаем с обычными правами
  fd_mine = open(MINE, O_RDWR|O_CREAT|O_TRUNC,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd_mine < 0) {
    error("не могу создать шахту\n");
  }

  // устанавливаем каретку на начало
  lseek(fd_mine, 0L, 0);
  write(fd_mine, &gold, sizeof(gold));
  close(fd_mine);
}
