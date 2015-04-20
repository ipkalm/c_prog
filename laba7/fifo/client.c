// Copyright 2015 <Astro>

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "error.c"

#define FIFO1 "/tmp/fi1"
#define FIFO2 "/tmp/fi2"
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define MAXLINE 80


int main(int argc, char *argv[]) {
  int readfd, writefd, input_gold;
  size_t len;
  ssize_t n;
  char answer[MAXLINE];

  writefd = open(FIFO1, O_WRONLY, 0);
  readfd = open(FIFO2, O_RDONLY, 0);

  printf("введите количество золота которое надо добыть\n");
  scanf("%d", &input_gold);

  // передать в канал задание
  write(writefd, &input_gold, sizeof(input_gold));

  // читаем ответ в stdout
  while ((n = read(readfd, answer, MAXLINE)) > 0)
    write(STDOUT_FILENO, answer, n);

  return 0;
}
