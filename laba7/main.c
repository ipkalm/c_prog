// Copyright 2015 <Astro>

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "error.c"

#define WORKERS 5
#define GOLD 15000
#define MINE "mine"

void mine_init(void);

int main() {
  int i, stat;
  pid_t pid[WORKERS];
  int fd[2];
  char line[50];

  // инициализации шахты
  mine_init();
  if (pipe(fd) < 0)
    error("не могу создать канал\n");

  // создаем процессы рабочих
  for (i = 0; i < WORKERS; i++) {
    if (!(pid[i] = fork())) {
      // перенаправляем стандарнтый вывод в канал pipe
      dup2(fd[1], 1);
      close(fd[0]);

      // запускаем рабочих
      if (execl("./worker", "worker", NULL) < 0)
        error("Ошибка во время запуска файла/процееса\n");

    } else if (pid[i] < 0) {
      error("ошибка при создании процесса\n");
    }
  }

  dup2(fd[0], 0);
  close(fd[1]);

  // ждем пока рабоче закончат работу
  for (i = 0; i < WORKERS; i++)
    if (pid[i] == waitpid(pid[i], &stat, 0))
      printf("рабочий номер %d - всё (pid=%d)\n", i+1, pid[i]);

  while (fgets(line, 50, stdin))
    printf("%s", line);


  return 0;
}

// инициализация шахты
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
