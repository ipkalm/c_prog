// Copyright 2015

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * now() {
  time_t t;
  time(&t);
  return asctime(localtime(&t));
}

int main(void) {
  char comment[80];
  char cmd[120];

  fgets(comment, 80, stdin);

  snprintf(cmd, sizeof(cmd), "echo '%s %s' >> report.log", comment, now());

  system(cmd);
  return 0;
}
