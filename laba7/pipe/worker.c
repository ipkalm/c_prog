// Copyright 2015 <Astronaut>

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.c"

#define CARGO 10
#define MINE "mine"

int main(int argc, char *argv[]) {
  int gold;
  int kpd = 0;
  int mine_fd;
  pid_t pid = getpid();
  struct flock lck;

  mine_fd = open(MINE, O_RDWR);
  if (mine_fd < 0) {
    error("Не могу открыть файл\n");
  }

  // блокировка
  lck.l_whence = 0;  // смещение от начала
  lck.l_len = 0L;    // начало блокировки с позии 0
  lck.l_start = 0L;  // и до конца

  for (;;) {
    lseek(mine_fd, 0L, 0);
    lck.l_type = F_WRLCK;
    fcntl(mine_fd, F_SETLKW, &lck);

    read(mine_fd, &gold, sizeof(gold));

    if (gold > 9) {
      gold = gold - CARGO;
      kpd = kpd + CARGO;

      lseek(mine_fd, 0L, 0);
      write(mine_fd, &gold, sizeof(gold));

      lck.l_type = F_UNLCK;
      fcntl(mine_fd, F_SETLK, &lck);
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
