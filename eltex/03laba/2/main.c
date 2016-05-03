#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 80

const unsigned short int SIZE = 2;

struct DB {
  char lastname[BUF];
  unsigned short int birthyear;
  char department[BUF];
  int pay;
};

void display(struct DB *st);
void create_record(struct DB *st);
void sortall(struct DB *st, int size);
void swap(struct DB *st1, struct DB *st2);

int main(int argc, char *argv[])
{
  register unsigned short int i;
  struct DB *p;

  p = malloc(SIZE * sizeof(struct DB));

  for (i = 0; i < SIZE; i++)
    create_record(p+i);

  sortall(p, SIZE);

  for (i = 0; i < SIZE; i++)
    display(p+i);

  free(p);

  return 0;
}

void display(struct DB *st)
{
  printf("Lastname: %s\n", st->lastname);
  printf("Year of the birth: %hu\n", st->birthyear);
  printf("Department: %s\n", st->department);
  printf("Payment: %i\n\n", st->pay);
}

void create_record(struct DB *st)
{
  char buff[BUF];

  printf("Введите данные:\n");

  printf("Фамилия: ");
  scanf("%s", buff);
  strcpy(st->lastname, buff);

  printf("Год рождения: ");
  scanf("%hu", &st->birthyear);

  printf("Отдел: ");
  scanf("%s", buff);
  strcpy(st->department, buff);

  printf("Зарплата: ");
  scanf("%i", &st->pay);

  puts("\n");
}


void sortall(struct DB *st, int size)
{
  register unsigned short int i;
  for (i = 0; i < size - 1; i++) {
    if ((st + i)->birthyear > (st + i + 1)->birthyear) {
      printf("delay swap\n");
      swap((st+i), (st+i+1));
    }
  }
}

void swap(struct DB *st1, struct DB *st2)
{
  struct DB tmp;

  // st2 to tmp
  strcpy (tmp.lastname, st2->lastname);
  tmp.birthyear = st2->birthyear;
  strcpy (tmp.department,st2->department);
  tmp.pay = st2->pay;

  // st1 to st2
  strcpy(st2->lastname, st1->lastname);
  st2->birthyear = st1->birthyear;
  strcpy(st2->department, st1->department);
  st2->pay = st2->pay;

  // tmp to st1
  strcpy(st1->lastname, tmp.lastname);
  st1->birthyear = tmp.birthyear;
  strcpy(st1->department, tmp.department);
  st1->pay = tmp.pay;
}
