#include <stdio.h>

int main()
{ 
  int c, i, nwhite, nother, j;
  int ndigit[10];

  nwhite = nother = 0;
  for (i=0;i<10;++i)
    ndigit[i]= 0;

  while ((c = getchar())!= EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

  printf("цифры\n");
  for (i = 0; i < 10; ++i)
    printf("%d - %d \n", i, ndigit[i]);


  printf("digits\n");
  for (i = 0; i < 10; ++i)
    {
      printf("%d - *", i);
      for (j = 0; j < ndigit[i] - 1; ++j)
	printf("*");
      printf("\n");
    }
  

  printf("символы-разделители = %d\nпрочие = %d\n", nwhite, nother);

  return 0;
}
