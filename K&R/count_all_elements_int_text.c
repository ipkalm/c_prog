#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]) {

  unsigned int symbol, nl, nw, nc;
  unsigned char state;

  state = OUT;

  nl = nw = nc = 0;

  while ((symbol = getchar()) != EOF) {
    ++nc;
    if (symbol == '\n')
      ++nl;

    if (symbol == ' ' || symbol == '\n' || symbol == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
