#include <stdio.h>

#define MAX_WORD_LENGTH 256
#define HYSTOGRAM_HEIGHT 80

unsigned int range_line(unsigned int count, unsigned int all);

int main(int argc, char *argv[]) {

  int j;
  int i;
  int symbol;
  unsigned int max_word_count;
  unsigned int all;
  unsigned int counter;
  unsigned int word_length[MAX_WORD_LENGTH] = { 0 };

  max_word_count = counter = all = 0;

  /* считаем слова */
  while ((symbol = getchar()) != EOF) {
    if (symbol == ' ' || symbol == '\n' || symbol == '\t') {
      if (counter > 0) {
        ++all;
        ++word_length[counter - 1];
        counter = 0;
      }
    } else {
      ++counter;
    }
  }

  /* определяем максимальное число повторений слова */
  for (i = 0 ; i < MAX_WORD_LENGTH; ++i)
    if (max_word_count < word_length[i])
      max_word_count = word_length[i];

  /* for (i = 0; i < MAX_WORD_LENGTH; ++i) */
  /*   printf("%3d : %6u\n", i + 1, word_length[i]); */

  putchar('\n');
  for (i = max_word_count; i >= 0; --i) {
    if (i > 0)
      printf("%2d ", i);
    else if (i == 0)
      printf("   ");

    for (j = 1; j < max_word_count + 1; ++j) {
      if (i > word_length[j])
        printf("   ");
      else if (i == 0)
        printf("%3d", j);
      else
        printf("+++");
    }
    putchar('\n');
  }


  return 0;
}

unsigned int range_line(unsigned int count, unsigned int all) {
  return count * HYSTOGRAM_HEIGHT / all;
}
