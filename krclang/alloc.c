#define ALLOCSIZE 10000 /* размер доступного простанства */

static char allocbuf[ALLOCSIZE]; /* память для alloc */
static char *allocp = allocbuf; /* указатель на свободную позицию, в начале работы программы указывает на 1ый элемент allocbuf[] */

char *alloc(int n) /* возвращает указатель на n символов */
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
    {
      allocp += n; /* пространство есть */
      return allocp - n;
    }
  else /* пространства нет */
    return 0;
}

void afree(char *p)
{
  if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
