#include <stdio.h>

int main()
{
  int c, sc;
  
  while((c = getchar()) != EOF)
    {
      if (c == ' ')
	{
	  sc++;
	}
      else
	{
	  sc=0;
	}
      if(sc == 2)
	{
	  sc--;
	  putchar('\b');
	}
      putchar(c);
    }
  return 0;
}
