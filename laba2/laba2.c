#include <stdio.h>
/*#include <string.h>*/
#include <time.h>

#define MAXLINES 5000 /* количество строк */

char *lineptr[MAXLINES]; /* указатели на строки */
int readlines(char *lineptr[], int nlines); /* функция чтения строк, создает массив указателей на начало строк и выводит количество строк */
void writlines(char *lineptr[], int nlines); /* хз */
void qsort(char *lineptr[], int left, int right);

/* сортировка строк */
int main()
{
  int nlines; /* количество прочитанных строк */
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      qsort(lineptr, 0, nlines-1);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      printf("erorr: to much strings\n");
      return 1;
    }
}

#define MAXLEN 1000 /* максимальная длина строки */
/* читает строки и записывает указатели на них, возвращает количетсво строк*/
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL)
      return -1;
    else
      {
	line[len-1] == '\0'; /* убираем символ \n */
	strcpy(p, line); /* копируем из p в line */
	lineptr[nlines++] = p;
      }
  return nlines;
}

/* вывод строк  */
void writelines(char *lineptr[], int nlines)
{
  int i;
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* getline читает строку в s  и возвращает её длину */
int getline(char s[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* функция сортировки */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) /* ничего не делать если в массиве меньше 2-х элементов */
    return;

  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp (v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* функция делающая обмен местами в массиве */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


int strcmp(char *s, char *t) 
{ 
  int i; 
  for (i = 0; s[i] == t[i]; i++)
    { 
      if (s[i] == '\0') 
	return 0; 
      return s[i] - t[i]; 
    }
}

