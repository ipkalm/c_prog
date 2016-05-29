#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  int fd;
  unsigned int b = 0;
  unsigned int *buf = &b;

  mode_t flags = O_RDONLY;
  
  if (argc != 3) {
    fprintf(stderr, "ошибка использования\n./reader [1STFILE] [2NDFILE]\n");
    return 1;
  }
  fd = open(argv[1], flags);
  if (fd < 0)
    perror(argv[1]);
  
  read(fd, buf, sizeof(*buf));
  printf("%s = %i\n", argv[1], *buf);
  close(fd);

  fd = open(argv[2], flags);
  if (fd < 0)
    perror(argv[2]);
  
  read(fd, buf, sizeof(*buf));
  printf("%s = %i\n", argv[2], *buf);
  close(fd);

  return 0;
}
