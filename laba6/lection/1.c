#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  pid_t pid;
  pid = getpid();
  printf("pid процесса - %d\n", pid);
  return 0;
}
