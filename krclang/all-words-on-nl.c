#include <stdio.h>

int main()
{
  int c, count1, count2;

  while ((c = getchar()) != EOF)
    {
      if (c == '\t')
	count1++;
      else
	count1=0;
      if (count1 == 2)
	{
	  count1--;
	  putchar('\b');
	  continue;
	}

      if (c == ' ')
	count2++;
      else
	count2=0;
      if (count2 == 2)
	{
	  count2--;
	  putchar('\b');
	  continue;
	}
      if (c == '\t' || c == ' ')
	{
	  putchar('\b');
	  putchar('\n');
	}
      else
	putchar(c);
    }
  return 0;
}
