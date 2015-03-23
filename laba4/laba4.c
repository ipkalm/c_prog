/*
  Оставить только строки, начинающиеся с латинских букв
  1. Имя входного файла
  2. Количество обрабатываемых строк
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 100 /* максимальная длина строки */

int main(int argc, char *argv[])
{
  char *estr; /* указатель на начало строки, который вернет fgets */
  char str[MAXLEN]; /* строка для считывания fgets */
  FILE *fp, *fm; /* указатели на файлы */
  int i = 0;
  
  fp = fopen(argv[1], "r"); /* открытие файла для чтения входных данных*/
  fm = fopen("out.txt", "w"); /* открытие файла для записи выходных данных */
  
  while ((estr = fgets(str, sizeof(str), fp)) != NULL && i < atoi(argv[2]))
    {
      if (isalpha(str[0]))
	fputs(estr, fm);
      i++;
    }
  return 0;
}
