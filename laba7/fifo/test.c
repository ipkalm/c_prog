// Copyright 2015 <astro>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#include "error.c"

int main(int argc, char *argv[]) {
  pid_t pid;
  int q = 20;
  char a[5];
  snprintf(a, sizeof(a), "%d", q);
  if (!(pid = fork()))
    if (execl("./worker", "worker", a, NULL) < 0)
      error("error while runnning worker");

  if (pid == waitpid(pid, NULL, 0))
    printf("pid over %d\n", pid);

  return 0;
}
