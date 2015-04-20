// Copyright 2015 <Astro>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
  int gold;
  FILE *mine = fopen("mine", "r");

  fread(&gold, sizeof(int), 1, mine);
  printf("золота в шахте = %d\n", gold);
  return 0;
}
