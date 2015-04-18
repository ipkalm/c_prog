// Copyright 2015 <Astro>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WORKERS 5
#define GOLD 15000
#define MINE "mine"

void mine_init(void);

int main(void) {
  int i, pid[WORKERS], stat, status;

  // инициализации шахты
  mine_init();

  // создаем процессы рабочих
  for (i = 0; i < 5; i++) {
    // порождаем дочерний процесс
    pid[i] = fork();

    if (pid[i] == 0) {
      // запускаем рабочих
      if (execl("./worker", "worker", NULL) < 0) {
        printf("Ошибка во время запуска файла/процееса\n");
        exit(-2);
      } else {
        printf("Процесс-файл запущен pid=%d\n", pid[i]);
      }
    }
  }

  for (i = 0; i < 5; i++) {
    // ждем пока процессы закончат работу
    status = waitpid(pid[i], &stat, WUNTRACED);
    if (pid[i] == status)
      printf("рабочий №%d(pid:%d) закончил работу\n", i + 1, pid[i]);
  }

  // проверяем сколько голд в шахте осталось
  int q;
  FILE *fp = fopen(MINE, "r");
  fread(&q, sizeof(int), 1, fp);
  printf("золота в шахте осталось %d\n", q);
  fclose(fp);

  return 0;
}

// инициализация шахты

void mine_init(void) {
  int gold = GOLD;
  int x;
  int fd_mine;

  // открываем файл если есть, если нет то создаем с обычными правами
  fd_mine = open(MINE, O_RDWR|O_CREAT|O_TRUNC,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd_mine < 0) {
    fprintf(stderr, "Can't open/create file");
    exit(1);
  }

  // устанавливаем каретку на начало
  lseek(fd_mine, 0L, 0);
  // пишем золото в шахту
  write(fd_mine, &gold, sizeof(int));

  // устанавливаем каретку на начало
  lseek(fd_mine, 0L, 0);
  read(fd_mine, &x, sizeof(int));
  printf("стало - %d\n", x);

  close(fd_mine);
}
