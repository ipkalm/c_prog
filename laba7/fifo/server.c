// Copyright 2015 <Astro>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

// #include "error.c"
#include "mine_init.c"

#define FIFO1 "/tmp/fi1"
#define FIFO2 "/tmp/fi2"
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define WORKERS 5

void super_exit(int, int);

int main(int argc, char *argv[]) {
  int gold, need_gold, i, readfd, writefd, stat, fd[2], workers;
  pid_t worker[WORKERS];
  char line[50];
  ssize_t n;

  // инициализация шахты
  mine_init();

  // инициализация pipe
  if (pipe(fd) < 0)
    error("не могу создать канал\n");

  // создание fifo
  if ((mkfifo(FIFO1, FILE_MODE) < 0) && (errno != EEXIST)) {
    error("не создал FIFO1");
  }
  if ((mkfifo(FIFO2, FILE_MODE) < 0) && (errno != EEXIST)) {
    unlink(FIFO1);
    error("не создал FIFO2");
  }

  readfd = open(FIFO1, O_RDONLY, 0);
  writefd = open(FIFO2, O_WRONLY, 0);

  // читаем из fifo сколько золота надо наносить, и делим на рабочих
  if (read(readfd, &gold, sizeof(gold)) == 0)
    error("неожиданный конец файла");

  // проверки корректного ввода голда
  if ((gold % 10) != 0) {
    snprintf (line, sizeof(line), "рабочие носят по 10 золота\n");
    n = strlen(line);
    write(writefd, line, n);
    super_exit(writefd, readfd);
    error("рабочие носят по 10 золота");
  }

  // магические вычисление сколько рабочих надо запустить
  workers = gold / 10;
  if (workers > 5)
    workers = 5;
  need_gold = gold / workers;

  // логгирование на сервере
  printf("было передано от клиента %d\n", gold);

  // магия перевода золота в агрумент для рабочего
  char a[5];
  snprintf(a, sizeof(a), "%d", need_gold);

  // создаем рабочих
  for (i = 0; i < workers; i++) {
    if (!(worker[i] = fork())) {
      // перенаправление stdout в fd[1]
      dup2(fd[1], 1);
      close(fd[0]);

      // запускаем рабочих
      if (execl("./worker", "worker", a, NULL) < 0) {
        error("ошибка во время запуска рабочего");
      }
    } else if (worker[i] < 0) {
      error("ошибка при создании процесса");
    }
  }

  // перенаправление fd[0] в stdin
  dup2(fd[0], 0);
  close(fd[1]);

  // ждем пока рабочие выполят работу
  for (i = 0; i < workers; i++)
    if (worker[i] == waitpid(worker[i], NULL, 0))
      printf("рабочий №%d - всё (pid=%d)\n", i+1, worker[i]);

  // передать клиенту результаты
  while (fgets(line, 50, stdin))
    write(writefd, line, 50);
  //    printf("%s", line);

  // закрыть каналы, удалить и выйти
  super_exit(writefd, readfd);

  return 0;
}

void super_exit(int writefd, int readfd) {
  close(writefd);
  close(readfd);
  unlink(FIFO1);
  unlink(FIFO2);
}
