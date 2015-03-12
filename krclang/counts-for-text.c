#include <stdio.h>

int main()
{
  int c, nl, tab, space;

  nl = tab = space = 0;

  while((c = getchar()) != EOF)
    {
      if (c == '\n')
	{
	  ++nl;
	}
      else if (c == '\t')
	{
	  ++tab;
	}
      else if (c == ' ')
	{
	  ++space;
	}
      else
	{
	  continue;
	}
    }
  printf("New nines: %d\nTabs: %d\nSpaces: %d\n", nl, tab, space);
  return 0;
}
