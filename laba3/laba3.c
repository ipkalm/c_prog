/*
Написать программу, работающую с базой данных в виде массива структур
и выполняющую последовательный ввод данных в массив и последующую 
распечатку его содержимого. Состав структуры:

Название книги
Год издания
Количество страниц
Стоимость

Типы данных выбрать самостоятельно.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXRECORDS 1000 /*максимальное количество записей*/

void init_catalog(void), input_data(void), output_list(void);
int find_free(void);

struct book
{
  char name[50]; /* Название */
  int year; /* год издания */
  int pages; /* количество страниц */
  float price; /* цена */
} catalog[MAXRECORDS];

int main()
{
  int choice;
  init_catalog();

  printf("Программа для ввода-вывода массива структур\n");
  printf("Массив-база хранящий в себе данные о книгах:\n");
  printf("Название, год издания, кол-во страниц и цену\n");
  for( ; ; )
    {
      printf("Выберите, что нужно сделать:\nДобавить новую запись - 1\tвывести содержимое базы - 2\tвыйти - 3\n");
      scanf("%d", &choice);
      switch (choice)
	{
	case 1:
	  input_data();
	  break;
	case 2:
	  if (catalog[0].name[0] == '\0')
	    {
	      printf("Нечего выводить!!!\n");
	      break;
	    }
	  printf("Вывод базы книг:\n");
	  output_list();
	  break;
	case 3:
	  return 0;
	default:
	  input_data();
	  break;
	}
    }
}

/* инициализация массива структур */
void init_catalog(void)
{
  register int i;

  for (i = 0; i < MAXRECORDS; ++i)
    catalog[i].name[0] = '\0';
}

/* ввод данных */
void input_data()
{
  int place;

  place = find_free();
  if (place == -1)
    {
      printf("\n список заполнен");
      return;
    }

  printf("введите название книги:\n");
  scanf("%s", catalog[place].name);

  printf("введите год издания:\n");
  scanf("%d", &catalog[place].year);

  printf("введите количество страниц:\n");
  scanf("%d", &catalog[place].pages);

  printf("введите цену:\n");
  scanf("%f", &catalog[place].price);

  printf("\nДанные успешно внесены\n\n");
}

/* поиск свободного места */
int find_free(void)
{
  register int i;
  for (i = 0; catalog[i].name[0] && i < MAXRECORDS; i++)
    ;
  if (i == MAXRECORDS)
    return -1;
  return i;
}

/* вывод содержимого */
void output_list(void)
{
  register int i;

  for (i = 0; i < MAXRECORDS; ++i)
    {
      if (catalog[i].name[0])
	{
	  printf("\n-=книга №%d:=-\n", i);
	  printf("название: %s\n", catalog[i].name);
	  printf("год: %4d\n", catalog[i].year);
	  printf("кол-во стр: %d\n", catalog[i].pages);
	  printf("цена: %4.2f\n", catalog[i].price);
	}
    }
  printf("\n");
}
