// Copyright 2015

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char *w = getenv("EXTRA");
  if (!w)
    w = getenv("FOOD");

  if (!w)
    w = argv[argc - 1];

  char *c = getenv("EXTRA");
  if (!c)
    c = argv[argc - 1];

  printf("%s c %s\n", c, w);
  return 0;
}
