#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

int scores[] = {543,323,32,554,11,3,112};

int main() {

  int i;

  qsort(scores, 7, sizeof(int), compare_scores);

  puts("Это упорядоченные числа");

  for (i = 0; i < 7; i++)
    printf("Оценка = %i\n", scores[i]);

  char *names[] = {"Карен", "Марк", "Бретт", "Молли"};
  qsort(names, 4, sizeof(char*), compare_names);
  puts("Это упорядоченные имена");

  for (i = 0; i < 4; i++)
    printf("%s\n", names[i]);

  return 0;
}

int compare_scores(const void * score_a, const void * score_b) {
  int a = *(int*)score_a;
  int b = *(int*)score_b;
  return a - b;
}

int compare_scores_desc(const void * score_a, const void * score_b) {
  int a = *(int*)score_a;
  int b = *(int*)score_b;
  return b - a;
}

int compare_rectangles(const void * first, const void * second) {
  rectangle * a = (rectangle*)first;
  rectangle * b = (rectangle*)second;

  return a->width * a->heigth - b->width * b->heigth;
}

int compare_names(const void * a, const void * b) {
  char ** first = (char**)a;
  char ** second = (char**)b;

  return strcmp(*first, *second);
}

int compare_areas_desc(const void * a, const void * b) {
  return compare_rectangles(b, a);
}

int compare_names_desc(const void * a, const void * b) {
  return compare_names(b, a);
}
