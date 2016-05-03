#include <stdio.h>
#include <string.h>

#define SIZE 2
#define BUF 80

struct DB {
  char lastname[BUF];
  unsigned short int birthyear;
  char department[BUF];
  int pay;
};

void display(struct DB st);
void create_record(struct DB *st);

int main(int argc, char *argv[])
{
  unsigned int i;
  struct DB mybase[SIZE] = { 0 };

  for(i = 0; i < SIZE; i++)
    create_record(&mybase[i]);

  for (i = 0; i < SIZE; i++)
    display(mybase[i]);

  return 0;
}

void display(struct DB st)
{
  printf("Lastname: %s\n", st.lastname);
  printf("Year of the birth: %hu\n", st.birthyear);
  printf("Department: %s\n", st.department);
  printf("Payment: %i\n\n", st.pay);
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
