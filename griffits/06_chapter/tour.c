#include <stdio.h>
#include "tour.h"

int main() {

  island amity = {"Остров Дружбы", "09:00", "17:00", NULL};
  island craggy = {"Скалистый", "09:00", "17:00", NULL};
  island isla_nublar = {"Туманный", "09:00", "17:00", NULL};
  island shutter = {"Остров Проклятых", "09:00", "17:00", NULL};

  amity.next = &craggy;
  craggy.next = &isla_nublar;
  isla_nublar.next = &shutter;

  island skull = {"Остров Черепа", "09:00", "17:00", NULL};
  isla_nublar.next = &skull;
  skull.next = &shutter;

  display(&amity);

  return 0;
}

void display(island *start) {
  island *i = start;

  for (;i != NULL; i = i->next)
    printf("Название: %s\nоткрыт: %s-%s\n", i->name, i->opens, i->closes);
}
