#include <stdlib.h>

char *test;
char *ret_test(){ return test; };
void _init()
{
  test=(char *)malloc(5);
  if (test!=NULL)
    {
      *(test+0)='g';
      *(test+1)='u';
      *(test+2)='n';
      *(test+3)='!';
      *(test+4)=0;
    }
  printf("_init() executed...\n");
}

void _fini()
{
  if (test!=NULL)
    free(test);
  printf("_fini() executed...\n");
}
