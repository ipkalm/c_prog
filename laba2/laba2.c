#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* максимальное число строк */

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int lines);
void writelines(char *lineptr[], int lines);
void qsort(char *lineptr[], int left, int fight);


/* сортировка строк */
int main()
{
  int nlines; /* количество прочианных строк */

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      qsort(lineptr, 0, nlines-1);
      writelines(lineptr, nlines);
      return 0;
    } else {
    printf("ошибка: слишком много строк \n");
    return 1;
  }
}

#define MAXLEN 1000 /* максимальная длина строк */
int getline1(char *, int);
char *alloc(int);


/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines=0;
  while ((len = getline1(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p=alloc(len)) == NULL)
      return -1;
    else {
      line[len-1]='\0'; /* убираем символ \n */
      strcpy(p, line);
      lineptr[nlines++]=p;
    }
  return nlines;
}


/* writelines: печать строк */
void writelines(char *lineptr[], int nlines)
{
  int i;
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}


/* getline1: читает строку в s, возвращает длину */
int getline1(char s[], int lim)
{
  int c, i;

  for(i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i]=c;
  if(c=='\n')
    {
      s[i]=c;
      ++i;
    }
  s[i]='\0';
  return i;
}

/* alloc */
#define ALLOCSIZE 10000 /* размер доступного пространства */

static char allocbuf[ALLOCSIZE]; /* память для alloc */
static char *allocp = allocbuf; /* указатель на свбодное место */

char *alloc(int n) /* возвращает указатель на n символов */
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
    {
      allocp += n; /* пространство есть */
      return allocp - n; /* старое p */
    } else /* пространства нет */
    return 0;
}
