#include <stdio.h>

int main() {
  int c;

  while (c = getchar()) {
    if (c != EOF) {
      putchar(c);
    } else {
      printf("%d\n", c);
      break;
    }
  }

  return 0;
}
