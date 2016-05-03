#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tour.h"

int main () {

  char name[80];

  fgets(name, 80, stdin);
  island *p_island0 = create(name);

  fgets(name, 80, stdin);
  island *p_island1 = create(name);

  p_island0->next = p_island1;

  display(p_island0);

  return 0;
}

island * create(char *name) {
  island * i = malloc(sizeof(island));
  
  i->name = strdup(name);
  i->opens = "09:00";
  i->closes = "17:00";
  i->next = NULL;

  return i;
}

void display(island * start) {
  island * i = start;
  for (;i != NULL; i = i->next)
    printf("Название: %s\tоткрыт: %s-%s\n", i->name, i->opens, i->closes);
}
