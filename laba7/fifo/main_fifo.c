// Copyright 2015 <Astro>

#include <stdio.h>

#include "mine_init.c"  // тут же include "error.c"

#define WORKERS 5
#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void client(void);

int main(int argc, char *argv[]) {
  int read_fd, write_fd;
  pid_t worker[WORKERS];

  // создание FIFO
  if ((mkfifo(FIFO1, FILE_MODE) < 0) && (errno != EEXIST)) {
    error("не могу создать %s\n", FIFO1);
  }
  if ((mkfifo(FIFO2, FILE_MODE) < 0) && (errno != EEXIST)) {
    unlink(FIFO1);
    error("не могу создать %s\n", FIFO2);
  }

  // дочерние процессы, а-ля сервер должен запустить 5 работяг
  for (i = 0; i < WORKERS; i++) {
    if (!(worker[i] = fork())) {
      read_fd = open(FIFO1, O_RDONLY, 0);
      write_fd = open(FIFO2, O_WRONLY, 0);

      if (execl("./worker", "worker", NULL) < 0) {
        error("ошибка во время запуска рабочего\n");
      }
    } else if (worker[i] < 0) {
      error("ошибка при создании процесса\n");
    }
  }

  // родительский процесс, который передаст сколько голд надо рабочим наносить
  write_fd = open(FIFO1, O_WRONLY, 0);
  read_fd = open(FIFO2, O_RDONLY, 0);
  client();

  for (i = 0; i < WORKERS; i++) {
    waitpid(worker[i], NULL, 0);
  }

  close(read_fd);
  close(write_fd);
  unlink(FIFO1);
  unlink(FIFO2);
  return 0;
}
