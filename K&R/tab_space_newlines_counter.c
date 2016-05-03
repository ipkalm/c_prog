#include <stdio.h>


int main(int argc, char *argv[]) {

  long spaces;
  int tabs;
  int lines;

  int symbol;

  spaces = tabs = lines = 0;

  while ((symbol = getchar()) != EOF) {
    if (symbol == '\n')
      ++lines;
    else if (symbol == '\t')
      ++tabs;
    else if (symbol == ' ')
      ++spaces;
  }

  printf("\n%ld spaces\n%d tabs\n%d lines\n", spaces, tabs, lines);

  return 0;
}
